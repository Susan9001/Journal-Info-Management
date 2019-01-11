#include "d_editor_info.h"

DEditorInfo::DEditorInfo(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	// ����������
	connect(ui.btn_publisher, SIGNAL(clicked()), this, SLOT(onBtnPublisher()));
	// ��ʼ��������combobox
	initCmbPublisher();
	connect(ui.btn_confirm, SIGNAL(clicked()), this, SLOT(onBtnConfirm()));
	connect(ui.btn_journal, SIGNAL(clicked()), this, SLOT(onBtnJournal()));
}

DEditorInfo::~DEditorInfo()
{
}

bool DEditorInfo::publisherExist(int publisher_id, QString publisher_name)
{ // ����Ƿ�publisher_id��publisher_name�ظ�
	QSqlQuery query;

	query.prepare(
		"SELECT *\n"
		"FROM Publisher\n"
		"WHERE publisher_id = :publisher_id\n"
		"OR publisher_name = :publisher_name;"
	);
	query.bindValue(":publisher_id", publisher_id);
	query.bindValue(":publisher_name", publisher_name);
	if (!query.exec())
	{
		QMessageBox::critical(this, u8"�������ѯʧ��", query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
	}
	query.first();

	if (query.record().value("publisher_id").isNull()) return false;
	else return true;
}

int DEditorInfo::getNextPublisherId()
{
	QSqlQuery query;
	query.exec("SELECT MAX(publisher_id) max_publisher_id FROM Publisher; ");
	query.first();

	return query.record().value("max_publisher_id").toInt() + 1;
}

void DEditorInfo::onBtnJournal()
{
	emit toJournal(ui.line_id->text().toInt());
	reject();
}

void DEditorInfo::onBtnConfirm()
{
	QString publisher_name = ui.cmb_publisher->currentText().trimmed();
	if (!publisherExist(-1, publisher_name))
	{
		QMessageBox::StandardButton btn_ret = QMessageBox::question(this, u8"��ӳ�����", u8"�ó�������δ¼�룬�����Ƿ�������",
			QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::Yes);
		if (btn_ret == QMessageBox::Yes)
		{
			if(insertPublisher(publisher_name)) accept();
			else return;
		}
		else return;
	}
	accept();
}

void DEditorInfo::onBtnPublisher()
{
	QString publisher_name = ui.cmb_publisher->currentText().trimmed();

	if(publisherExist(-1, publisher_name))
		updatePublisher();
	else
	{
		QMessageBox::StandardButton btn_ret = QMessageBox::question(this, u8"��ӳ�����", u8"�ó�������δ¼�룬�����Ƿ�������", 
			QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::Yes);
		if (btn_ret == QMessageBox::Yes) 
			insertPublisher(publisher_name);
	}
}

void DEditorInfo::updatePublisher()
{
	QSqlQuery query;
	// ���Ȼ�ȡ��ǰ��־�ĺ���

	// ���ԡ��ȸ�����־����������ɡ�����
	int testPublisherid = getPublisherIdFromName();
	query.prepare(u8"SELECT * FROM Publisher WHERE publisher_id = :testPublisherid;");
	query.bindValue(":testPublisherid", testPublisherid);
	query.exec();
	query.first();
	if (!query.isValid())
	{
		qDebug() << "search publisher not ok";
		return;
	}

	QSqlRecord currRec = query.record();
	DPublisherInfo* publisherDialog = new DPublisherInfo(this);
	publisherDialog->setEditRecord(currRec); // ���������ݵ���������Ϣ������
	int ret = publisherDialog->exec(); // ģ̬����

	// ���³�������Ϣ���Ժ�Ҫ��Ϊpublisher_id�ģ�
	if (ret == QDialog::Accepted)
	{
		// ��ȡ���صļ�¼
		QSqlRecord recData = publisherDialog->getNewData();
		// ��������
		query.prepare(u8"UPDATE Publisher "
			"SET publisher_name = :publisher_name, "
			"publisher_email = :publisher_email, "
			"publisher_phone = :publisher_phone, "
			"publisher_address = :publisher_address " // �ǵ�û�ж��ţ�����
			"WHERE publisher_id = :testPublisherid;" //�ǵ÷ֺţ�����
		);
		query.bindValue(":publisher_name", recData.value("publisher_name"));
		query.bindValue(":publisher_email", recData.value("publisher_email"));
		query.bindValue(":publisher_phone", recData.value("publisher_phone"));
		query.bindValue(":publisher_address", recData.value("publisher_address"));
		query.bindValue(":testPublisherid", testPublisherid);

		if (!query.exec())
		{
			QMessageBox::critical(this, "����", "������Ϣ����\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
		}
	}
	
	// ������Ի��������ڴ�
	delete publisherDialog;
}

int DEditorInfo::insertPublisher(QString publisher_name)
{
	QSqlQuery query;

	query.prepare(u8"SELECT * FROM Publisher WHERE publisher_id = -1"); // ��
	query.exec();
	query.first();

	// ���ռ�¼�����ֵ
	QSqlRecord currRec = query.record();
	currRec.setValue("publisher_name", publisher_name);
	currRec.setValue("publisher_id", getNextPublisherId()); // ��ǰ���id + 1

	// ����Publisher����
	DPublisherInfo* publisherDialog = new DPublisherInfo(this);
	publisherDialog->setInsertRecord(currRec); // ���������ݵ���������Ϣ������
	int ret = publisherDialog->exec(); // ģ̬����

	if (ret == QDialog::Accepted)
	{
		currRec = publisherDialog->getNewData();
		int publisher_id = currRec.value("publisher_id").toInt();
		
		// ����ظ�publisher_id, publisher_name
		bool alreadyHas = publisherExist(publisher_id, currRec.value("publisher_name").toString());
		if (alreadyHas)
		{
			QMessageBox::critical(this, "�ظ�", "�������������ظ��ˣ�\n", 
				QMessageBox::Ok, QMessageBox::NoButton);
			return 0;
		}

		// ��ʼ�½�Publisher
		query.prepare(
			"INSERT INTO Publisher(publisher_id, publisher_name, publisher_email, publisher_phone, publisher_address)\n"
			"VALUES (:publisher_id, :publisher_name, :publisher_email, :publisher_phone, :publisher_address);"
		);
		query.bindValue(":publisher_id", publisher_id);
		query.bindValue(":publisher_name", currRec.value("publisher_name"));
		query.bindValue(":publisher_email", currRec.value("publisher_email"));
		query.bindValue(":publisher_phone", currRec.value("publisher_phone"));
		query.bindValue(":publisher_address", currRec.value("publisher_address"));
		if (!query.exec())
		{
			QMessageBox::critical(this, u8"�½����������", u8"INSERT����\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return 0;
		}

		// ���õ�ǰeditor��publisher_id
		query.prepare(
			"UPDATE Editor\n"
			"SET publisher_id = :publisher_id\n"
			"WHERE editor_id = :editor_id;"
		);
		query.bindValue(":publisher_id", publisher_id);
		query.bindValue("editor_id", ui.line_id->text().toInt());
		if (!query.exec())
		{
			QMessageBox::critical(this, "���±༭���ڿ��Ŵ���", "���´���\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return 0;
		}
		// ���û�publisher������
		setCmbCurrPublisher(currRec.value("publisher_name").toString());
	}
	delete publisherDialog; // ������Ի��������ڴ�
	return currRec.value("publisher_id").toInt();
}

void DEditorInfo::setEditRecord(QSqlRecord & recData)
{
	mRecord = recData; // �Ȼ�ȡ��ǰ��Ϣ
	ui.line_id->setEnabled(false); // ������Ų������޸�
	// ��ʾ
	ui.line_id->setText(mRecord.value("editor_id").toString());
	ui.line_name->setText(mRecord.value("editor_name").toString());
	ui.line_email->setText(mRecord.value("editor_email").toString());
	ui.line_phone->setText(mRecord.value("editor_phone").toString());
	setCmbCurrPublisher(mRecord.value("publisher_name").toString());

	return;
}

void DEditorInfo::setInsertRecord(QSqlRecord & recData)
{
	mRecord = recData;
	ui.line_id->setEnabled(true);
	ui.line_id->setText(mRecord.value("editor_id").toString());
	ui.line_name->setText(mRecord.value("editor_name").toString());
	ui.line_phone->setText(mRecord.value("editor_phone").toString());
	ui.line_email->setText(mRecord.value("editor_email").toString());

	return;
}

QSqlRecord DEditorInfo::getNewData()
{
	// ����
	mRecord.setValue("editor_id", ui.line_id->text().toInt());
	mRecord.setValue("editor_name", ui.line_name->text().trimmed()); // ���������۸ñ༭�����ڵ����
	mRecord.setValue("editor_email", ui.line_email->text().trimmed());
	mRecord.setValue("editor_phone", ui.line_phone->text().trimmed());
	mRecord.setValue("publisher_id", getPublisherIdFromName());

	// ���� ����Ƿ�Ϸ�

	return mRecord;
}

int DEditorInfo::getPublisherIdFromEditor()
{
	int editor_id = ui.line_id->text().toInt();
	QSqlQuery query;
	query.prepare(
		"SELECT publisher_id\n"
		"FROM Editor\n"
		"WHERE editor_id = :editor_id"
	);
	query.bindValue(":editor_id", editor_id);
	query.exec();
	query.first();
	return query.value("publisher_id").toInt();
}

int DEditorInfo::getPublisherIdFromName()
{
	QString publisher_name = ui.cmb_publisher->currentText().trimmed();
	QSqlQuery query;
	query.prepare(
		"SELECT publisher_id\n"
		"FROM Publisher\n"
		"WHERE publisher_name = :publisher_name"
	);
	query.bindValue(":publisher_name", publisher_name);
	query.exec();
	query.first();
	return query.value("publisher_id").toInt();
}

void DEditorInfo::initCmbPublisher()
{
	QSqlQuery query;
	query.exec("SELECT P.publisher_name FROM Publisher P;");
	while (query.next())
		ui.cmb_publisher->addItem(query.value("publisher_name").toString());
}

void DEditorInfo::setCmbCurrPublisher(const QString & publisher_name)
{
	ui.cmb_publisher->setCurrentIndex(ui.cmb_publisher->findText(publisher_name));
}
