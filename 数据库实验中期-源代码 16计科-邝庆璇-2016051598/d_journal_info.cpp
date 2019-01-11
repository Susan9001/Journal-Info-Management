#include "d_journal_info.h"

DJournalInfo::DJournalInfo(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	// Ͷ���ַ���������ַ�˴���ʱ���ɱ༭�����������������������ʱ�����
	ui.line_email->setFocusPolicy(Qt::NoFocus);

	// ��ʼ����cmbox_catalog
	QSqlQueryModel *catalogBoxModel = new QSqlQueryModel(this);
	catalogBoxModel->setQuery(
		"SELECT catalog_name\n"
		"FROM Catalogg\n"
		"ORDER BY catalog_id"
	);
	if (catalogBoxModel->lastError().isValid())
	{
		QMessageBox::information(this, "��Ŀ����", "��Ŀ��ѯ����\n������Ϣ��" + catalogBoxModel->lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	ui.cmbox_catalog->setModel(catalogBoxModel);

	// ��ʼ��Сcmbox_type����setEditRecord�����

	/// ��ʼ��cmb_editor
	initCmbEditor();

	// ��cmbox_catalog�ĸı���������
	connect(ui.cmbox_catalog, SIGNAL(currentIndexChanged(const QString &)), 
		this, SLOT(onCurrentCatalogChanged(const QString&)));
	// ��ȷ�ϰ�ť��������
	connect(ui.btn_confirm, SIGNAL(clicked()),
		this, SLOT(onBtnConfirm()));
	// ���������鵯����������
	connect(ui.btn_editor, SIGNAL(clicked()), this, SLOT(onBtnEditor()));
	// ��ת������
	connect(ui.btn_paper, SIGNAL(clicked()), this, SLOT(onBtnPaper()));

}

DJournalInfo::~DJournalInfo()
{
}

void DJournalInfo::updateEditor(int editor_id, bool set)
{
	QSqlQuery query;
	// ���Ȼ�ȡ������ĺ���
	if(!editor_id)
		editor_id = getEditorIdFromName(NULL, getEditorIdFromJournal());

	query.prepare(
		u8"SELECT E.*, P.publisher_name\n"
		"FROM Editor AS E, Publisher AS P\n"
		"WHERE editor_id = :editor_id\n"
			"AND E.publisher_id = P.publisher_id;"
	);
	query.bindValue(":editor_id", editor_id);
	query.exec();
	query.first();
	if (!query.isValid())
	{
		qDebug() << "search publisher not ok";
		return;
	}

	QSqlRecord currRec = query.record();
	DEditorInfo* editorDlg = new DEditorInfo(this);
	// connect����ȥeditor��journal
	connect(editorDlg, SIGNAL(toJournal(int)), this, SLOT(onToJournal(int)));
	editorDlg->setEditRecord(currRec); // ���������ݵ���������Ϣ������
	int ret = editorDlg->exec(); // ģ̬����

	// ����������Ϣ
	if (ret == QDialog::Accepted)
	{
		// ��ȡ���صļ�¼
		QSqlRecord recData = editorDlg->getNewData();

		// ��������
		query.prepare(u8"UPDATE Editor "
			"SET editor_name = :editor_name, "
			"editor_email = :editor_email, "
			"editor_phone = :editor_phone, "
			"publisher_id = :publisher_id\n" // �ǵ�û�ж��ţ�����
			"WHERE editor_id = :editor_id;" //�ǵ÷ֺţ�����
		);
		query.bindValue(":editor_name", recData.value("editor_name"));
		query.bindValue(":editor_email", recData.value("editor_email"));
		query.bindValue(":editor_phone", recData.value("editor_phone"));
		query.bindValue(":publisher_id", editorDlg->getPublisherIdFromName());
		query.bindValue(":editor_id", editor_id); 

		if (!query.exec())
		{
			QMessageBox::critical(this, "����", "������Ϣ����\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
		}
		// ˢ��
		if (set)
		{
			initCmbEditor();
			setCmbCurrEditor(recData.value("editor_name").toString());
			ui.line_email->setText(recData.value("editor_email").toString());
			//mRecord.setValue("editor_id", recData.value("editor_id").toInt()); // ����journal��editor_id��һ�������
		}
	}

	// ������Ի��������ڴ�
	delete editorDlg;
}

int DJournalInfo::insertEditor(const QString & editor_name)
{
	QSqlQuery query;
	
	query.prepare(
		u8"SELECT E.*, P.publisher_name\n"
		"FROM Editor AS E, Publisher AS P\n"
		"WHERE E.publisher_id = P.publisher_id;"
	); // ��ֵ���ǿձ�������
	query.exec();
	query.first();

	// ���ռ�¼�����ֵ
	QSqlRecord currRec = query.record();
	currRec.setValue("editor_name", editor_name);
	currRec.setValue("editor_id", getNextEditorId()); // ��ǰ���id + 1

	// ����Editor����
	DEditorInfo* editorDlg = new DEditorInfo(this);
	editorDlg->setInsertRecord(currRec); // ���������ݵ���������Ϣ������
	int ret = editorDlg->exec(); // ģ̬����

	QSqlRecord retRec; // ׼�����շ��ص�
	if (ret == QDialog::Accepted)
	{
		QSqlRecord retRec = editorDlg->getNewData();
		int editor_id = retRec.value("editor_id").toInt();

		// ����ظ�editor_id, editor_name
		bool alreadyHas = editorExist(editor_id);
		if (alreadyHas)
		{
			QMessageBox::critical(this, "�ظ�", "����ظ��ˣ�\n",
				QMessageBox::Ok, QMessageBox::NoButton);
			return 0;
		}

		// ��ʼ�½�Editor
		query.prepare(
			"INSERT INTO Editor(editor_id, editor_name, editor_email, editor_phone, publisher_id)\n"
			"VALUES (:editor_id, :editor_name, :editor_email, :editor_phone, :publisher_id);"
		);
		query.bindValue(":editor_id", retRec.value("editor_id"));
		query.bindValue(":editor_name", retRec.value("editor_name"));
		query.bindValue(":editor_email", retRec.value("editor_email"));
		query.bindValue(":editor_phone", retRec.value("editor_phone"));
		query.bindValue(":publisher_id", editorDlg->getPublisherIdFromName());
		if (!query.exec())
		{
			QMessageBox::critical(this, u8"�½��������", u8"INSERT����\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return 0;
		}
		// ˢ��
		initCmbEditor();
		setCmbCurrEditor(retRec.value("editor_name").toString());
		ui.line_email->setText(retRec.value("editor_email").toString());
		mRecord.setValue("editor_id", retRec.value("editor_id").toInt());
	}

	delete editorDlg; // ����editor�Ի����ڴ�
	return retRec.value("editor_id").toInt();
}

void DJournalInfo::setTypeFromCatalog(const QString & catalog_name)
{
	QSqlQueryModel *typeBoxModel = new QSqlQueryModel(this);
	typeBoxModel->setQuery(
		"SELECT typee_name\n"
		"FROM Typee\n"
		"WHERE catalog_id IN (\n"
		"SELECT catalog_id\n"
		"FROM Catalogg\n"
		"WHERE catalog_name = '" + catalog_name + "');"
	);
	if (typeBoxModel->lastError().isValid())
	{
		QMessageBox::information(this, "���ʹ���", "���Ͳ�ѯ����\n������Ϣ��" + typeBoxModel->lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}

	ui.cmbox_type->setModel(typeBoxModel);

}

int DJournalInfo::getEditorIdFromName(const QString & editor_name, int old_editor_id)
{
	QString cur_editor_name;
	if (editor_name == NULL)
		cur_editor_name = ui.cmb_editor->currentText();
	else
		cur_editor_name = editor_name;
	QList<int> editorIdList = getEditorIDs(cur_editor_name);
	if (!editorIdList.size())
		return 0; // �����0������
	if (editorIdList.size() == 1) // û������
		return editorIdList[0];

	QStringList editorIdStrList;
	for (auto editor_id : editorIdList)
		editorIdStrList.append(QString::number(editor_id));
	
	QString dlgTitle = u8"��������";
	QString txtLabel = u8"��ѡ�����ࣨĬ����ʾ���ǵ�ǰ�ڿ������ࣩ";
	// ���ó�ʼ��ѡ������old_editor_id��Ϊ�Ǹ���
	int currIndex = 0;
	if (old_editor_id)
	{
		for (int i = 0; i < editorIdList.size(); i++)
		{
			if (old_editor_id == editorIdList[i])
			{
				currIndex = i;
				break;
			}
		}
	}
	// false1--û�а�ok���ͷ����޸�
	// false2--�����Լ�����
	bool isOk = false;
	QString text = QInputDialog::getItem(this, dlgTitle, txtLabel,
		editorIdStrList, currIndex, false, &isOk); 

	if(isOk) return text.toInt();
	else return -1;
}

int DJournalInfo::getEditorIdFromJournal(int journal_id)
{
	if (!journal_id)
		journal_id = ui.line_id->text().toInt();
	QString qryStr = QString(
		"SELECT editor_id\n"
		"FROM Journal\n"
		"WHERE journal_id = :journal_id"
	);
	QSqlQuery query;
	query.prepare(qryStr);
	query.bindValue(":journal_id", journal_id);
	if (!query.exec())
	{
		QMessageBox::critical(this, u8"��ѯ�������", u8"���ڿ���ȡ������Ϣ����\n" + query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return 0;
	}
	query.first();
	return query.value("editor_id").toInt();
}

bool DJournalInfo::isNameDuplicated(const QString & name, int id)
{
	QString journal_name = name.trimmed().length() > 0 ? name : ui.line_name->text();
	int journal_id = id > 0 ? id : ui.line_id->text().toInt();
	QSqlQuery query;

	query.prepare(
		"SELECT *\n"
		"FROM Journal\n"
		"WHERE journal_name = :journal_name\n"
		"AND journal_id != :journal_id;"
	);
	query.bindValue(":journal_name", journal_name);
	query.bindValue(":journal_id", journal_id);
	if (!query.exec())
	{
		QMessageBox::critical(this, u8"����ڿ�������~", u8"���⣡\n" + query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return false;
	}
	return query.first();
}

void DJournalInfo::onBtnConfirm()
{
	if (!SharedFunctions::isValidDate(ui.line_date->text())) // �������
	{
		QMessageBox::warning(this, u8"���ڸ�ʽ�ƺ�����Ү~", u8"�밴��ʽ��������Ŷ��\n",
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	else if (isNameDuplicated()) // ����ڿ��Ƿ�����
	{
		QMessageBox::warning(this, u8"�ڿ��������ظ�Ŷ~", u8"�ڿ����������ظ����أ�\n",
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}

	QString editor_name = ui.cmb_editor->currentText().trimmed();
	int editor_id = getEditorIdFromName(editor_name, getEditorIdFromJournal(ui.line_id->text().toInt()));
	if (editor_id < 0) return;

	// ��������ڵĻ����editor
	if (!editorExist(editor_id))
	{
		QMessageBox::StandardButton btn_ret = QMessageBox::question(this, u8"�������", u8"��������δ¼�룬�����Ƿ�������",
			QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::Yes);
		if (btn_ret == QMessageBox::Yes)
		{
			if (insertEditor(editor_name))
			{
				mRecord.setValue("editor_id", editor_id);
				accept();
			}
			else return;
		}
		else return;
	}
	
	mRecord.setValue("editor_id", editor_id);
	accept();
}

void DJournalInfo::onCurrentCatalogChanged(const QString & catalog_name)
{
	setTypeFromCatalog(catalog_name);
}

void DJournalInfo::onBtnEditor()
{
	QString editor_name = ui.cmb_editor->currentText().trimmed();
	int editor_id = getEditorIdFromName(editor_name, getEditorIdFromJournal(ui.line_id->text().toInt()));
	if (editor_id < 0) return; // ��ȡ����

	if (editorExist(editor_id))
	{
		bool toSet = true;
		// ���޸���ͬ����ͬ����
		if (getEditorIDs(editor_name).size() >= 2 && editor_id != getEditorIdFromJournal(ui.line_id->text().toInt()))
			toSet = false;
		updateEditor(editor_id, toSet); // ����ı�
	}
	else
	{
		QMessageBox::StandardButton btn_ret = QMessageBox::question(this, u8"�������", u8"��������δ¼�룬�����Ƿ�������",
			QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::Yes);
		if (btn_ret == QMessageBox::Yes)
			insertEditor(editor_name);
	}
}

void DJournalInfo::onBtnPaper()
{
	emit toShowPaper(ui.line_id->text().toInt(), 0);
	//reject();
}

void DJournalInfo::onToJournal(int editor_id)
{
	emit toShowJournal(editor_id);
	//reject();
}

QList<int> DJournalInfo::getEditorIDs(const QString & editor_name)
{
	QSqlQuery query;
	QString qryStr = QString(
		"SELECT editor_id\n"
		"FROM Editor\n"
		"WHERE editor_name = :editor_name;"
	);
	query.prepare(qryStr);
	query.bindValue(":editor_name", editor_name);
	if (!query.exec())
	{
		QMessageBox::critical(this, "�������", "����id��ѯ����\n" + query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return QList<int>();
	}

	QList<int> editor_ids; // ���
	while (query.next())
		editor_ids.append(query.value("editor_id").toInt());
	return editor_ids;
}

void DJournalInfo::initCmbEditor()
{
	QSqlQuery query;
	query.exec("SELECT DISTINCT editor_name FROM Editor;");
	while (query.next())
		ui.cmb_editor->addItem(query.record().value("editor_name").toString());
}

void DJournalInfo::setCmbCurrEditor(const QString & editor_name)
{
	ui.cmb_editor->setCurrentIndex(ui.cmb_editor->findText(editor_name));
}

int DJournalInfo::getNextEditorId()
{
	QSqlQuery query;
	query.exec("SELECT MAX(editor_id) max_editor_id FROM Editor;");
	query.first();

	return query.value("max_editor_id").toInt() + 1;
}

bool DJournalInfo::editorExist(int editor_id)
{
	QSqlQuery query;
	query.prepare(
		"SELECT *\n"
		"FROM Editor\n"
		"WHERE editor_id = :editor_id;"
	);
	query.bindValue(":editor_id", editor_id);
	if (!query.exec())
	{
		QMessageBox::critical(this, u8"�����ѯʧ��", query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
	}
	query.first();
	if (query.record().value("editor_id").isNull()) return false;
	else return true;
}

void DJournalInfo::setEditRecord(QSqlRecord & recData)
{
	mRecord = recData; // �Ȼ�ȡ��ǰ��Ϣ
	ui.line_id->setEnabled(false); // �ڿ��Ų������޸�

	// ������ʾline_edit��
	//ui.line_id->setText(mRecord.value("publisher_id").toString());
	ui.line_id->setText(mRecord.value("journal_id").toString());
	journal_id = mRecord.value("journal_id").toInt();
	ui.line_name->setText(mRecord.value("journal_name").toString());
	setCmbCurrEditor(mRecord.value("editor_name").toString());
	ui.line_email->setText(mRecord.value("editor_email").toString());
	ui.line_date->setText(mRecord.value("new_publish_date").toString()); 

	// ���ô���cmbox_catalog
	QString currCatalog = mRecord.value("catalog_name").toString();
	for (int i = 0; i < ui.cmbox_catalog->count(); i++)
	{
		if (ui.cmbox_catalog->itemText(i) == currCatalog)
		{
			ui.cmbox_catalog->setCurrentIndex(i);
			break;
		}
	}

	// ��ʼ��С��cmbox_type
	setTypeFromCatalog(currCatalog);
	// ����С��cmbox_type
	QString currType = mRecord.value("typee_name").toString();
	for (int i = 0; i < ui.cmbox_type->count(); i++)
	{
		if (ui.cmbox_type->itemText(i) == currType)
		{
			ui.cmbox_type->setCurrentIndex(i);
			break;
		}
	}
	return;
}

void DJournalInfo::setInsertRecord(QSqlRecord & recData)
{
	mRecord = recData;
	ui.line_id->setEnabled(true); //���Ա༭
	ui.line_id->setText(mRecord.value("journal_id").toString());
}

void DJournalInfo::setReadOnlyRecord(QSqlRecord & recData)
{
	setEditRecord(recData);
	ui.btn_confirm->setText(u8" ȷ��");
	ui.line_name->setFocusPolicy(Qt::NoFocus); // ���ɱ༭
	ui.line_date->setFocusPolicy(Qt::NoFocus);
	ui.line_email->setFocusPolicy(Qt::NoFocus);
	ui.cmbox_catalog->setFocusPolicy(Qt::NoFocus);
	ui.cmbox_type->setFocusPolicy(Qt::NoFocus);
	ui.cmb_editor->setFocusPolicy(Qt::NoFocus);
}

QSqlRecord DJournalInfo::getNewData()
{
	mRecord.setValue("journal_id", ui.line_id->text().toInt());
	mRecord.setValue("journal_name", ui.line_name->text().trimmed());
	mRecord.setValue("editor_email", ui.line_email->text().trimmed()); //Ҳ��journal_email
	mRecord.setValue("editor_name", ui.cmb_editor->currentText().trimmed()); // ���������۸ñ༭�����ڵ����

	// ��������Ƿ���Ч

	mRecord.setValue("new_publish_date", ui.line_date->text());
	mRecord.setValue("catalog_name", ui.cmbox_catalog->currentText());
	mRecord.setValue("typee_name", ui.cmbox_type->currentText());

	// ���� ����Ƿ�Ϸ�

	return mRecord;
}
