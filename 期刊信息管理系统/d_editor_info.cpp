#include "d_editor_info.h"

DEditorInfo::DEditorInfo(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	// 出版社详情
	connect(ui.btn_publisher, SIGNAL(clicked()), this, SLOT(onBtnPublisher()));
	// 初始化出版社combobox
	initCmbPublisher();
	connect(ui.btn_confirm, SIGNAL(clicked()), this, SLOT(onBtnConfirm()));
	connect(ui.btn_journal, SIGNAL(clicked()), this, SLOT(onBtnJournal()));
}

DEditorInfo::~DEditorInfo()
{
}

bool DEditorInfo::publisherExist(int publisher_id, QString publisher_name)
{ // 检查是否publisher_id，publisher_name重复
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
		QMessageBox::critical(this, u8"出版社查询失败", query.lastError().text(),
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
		QMessageBox::StandardButton btn_ret = QMessageBox::question(this, u8"添加出版社", u8"该出版社尚未录入，请问是否新增？",
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
		QMessageBox::StandardButton btn_ret = QMessageBox::question(this, u8"添加出版社", u8"该出版社尚未录入，请问是否新增？", 
			QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::Yes);
		if (btn_ret == QMessageBox::Yes) 
			insertPublisher(publisher_name);
	}
}

void DEditorInfo::updatePublisher()
{
	QSqlQuery query;
	// 首先获取当前杂志的号码

	// 测试。先根据杂志编号来搜索吧。。。
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
	publisherDialog->setEditRecord(currRec); // 设置新数据到出版社信息框里面
	int ret = publisherDialog->exec(); // 模态窗口

	// 更新出版社信息（以后要改为publisher_id的）
	if (ret == QDialog::Accepted)
	{
		// 获取返回的记录
		QSqlRecord recData = publisherDialog->getNewData();
		// 更新数据
		query.prepare(u8"UPDATE Publisher "
			"SET publisher_name = :publisher_name, "
			"publisher_email = :publisher_email, "
			"publisher_phone = :publisher_phone, "
			"publisher_address = :publisher_address " // 记得没有逗号！！！
			"WHERE publisher_id = :testPublisherid;" //记得分号！！！
		);
		query.bindValue(":publisher_name", recData.value("publisher_name"));
		query.bindValue(":publisher_email", recData.value("publisher_email"));
		query.bindValue(":publisher_phone", recData.value("publisher_phone"));
		query.bindValue(":publisher_address", recData.value("publisher_address"));
		query.bindValue(":testPublisherid", testPublisherid);

		if (!query.exec())
		{
			QMessageBox::critical(this, "错错错", "更新信息错误！\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
		}
	}
	
	// 出版社对话框清理内存
	delete publisherDialog;
}

int DEditorInfo::insertPublisher(QString publisher_name)
{
	QSqlQuery query;

	query.prepare(u8"SELECT * FROM Publisher WHERE publisher_id = -1"); // 空
	query.exec();
	query.first();

	// 给空记录赋点初值
	QSqlRecord currRec = query.record();
	currRec.setValue("publisher_name", publisher_name);
	currRec.setValue("publisher_id", getNextPublisherId()); // 当前最大id + 1

	// 插入Publisher窗口
	DPublisherInfo* publisherDialog = new DPublisherInfo(this);
	publisherDialog->setInsertRecord(currRec); // 设置新数据到出版社信息框里面
	int ret = publisherDialog->exec(); // 模态窗口

	if (ret == QDialog::Accepted)
	{
		currRec = publisherDialog->getNewData();
		int publisher_id = currRec.value("publisher_id").toInt();
		
		// 检查重复publisher_id, publisher_name
		bool alreadyHas = publisherExist(publisher_id, currRec.value("publisher_name").toString());
		if (alreadyHas)
		{
			QMessageBox::critical(this, "重复", "出版社名或编号重复了！\n", 
				QMessageBox::Ok, QMessageBox::NoButton);
			return 0;
		}

		// 开始新建Publisher
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
			QMessageBox::critical(this, u8"新建出版社错误", u8"INSERT错误！\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return 0;
		}

		// 设置当前editor的publisher_id
		query.prepare(
			"UPDATE Editor\n"
			"SET publisher_id = :publisher_id\n"
			"WHERE editor_id = :editor_id;"
		);
		query.bindValue(":publisher_id", publisher_id);
		query.bindValue("editor_id", ui.line_id->text().toInt());
		if (!query.exec())
		{
			QMessageBox::critical(this, "更新编辑的期刊号错误", "更新错误！\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return 0;
		}
		// 设置回publisher的名字
		setCmbCurrPublisher(currRec.value("publisher_name").toString());
	}
	delete publisherDialog; // 出版社对话框清理内存
	return currRec.value("publisher_id").toInt();
}

void DEditorInfo::setEditRecord(QSqlRecord & recData)
{
	mRecord = recData; // 先获取当前信息
	ui.line_id->setEnabled(false); // 出版社号不允许修改
	// 显示
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
	// 测试
	mRecord.setValue("editor_id", ui.line_id->text().toInt());
	mRecord.setValue("editor_name", ui.line_name->text().trimmed()); // 在外面讨论该编辑不存在的情况
	mRecord.setValue("editor_email", ui.line_email->text().trimmed());
	mRecord.setValue("editor_phone", ui.line_phone->text().trimmed());
	mRecord.setValue("publisher_id", getPublisherIdFromName());

	// 二期 检查是否合法

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
