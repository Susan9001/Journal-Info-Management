#include "d_publisher_info.h"

DPublisherInfo::DPublisherInfo(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	// 确认修改
	connect(ui.btn_confirm, SIGNAL(clicked()), this, SLOT(onBtnConfirm()));
}

DPublisherInfo::~DPublisherInfo()
{
}

void DPublisherInfo::setEditRecord(QSqlRecord &recData)
{
	mRecord = recData; // 先获取当前信息
	ui.line_id->setEnabled(false); // 出版社号不允许修改
	
	// 显示
	ui.line_id->setText(mRecord.value("publisher_id").toString());
	ui.line_name->setText(mRecord.value("publisher_name").toString());
	ui.line_email->setText(mRecord.value("publisher_email").toString());
	ui.line_phone->setText(mRecord.value("publisher_phone").toString());
	ui.line_address->setText(mRecord.value("publisher_address").toString());
	return;
}

void DPublisherInfo::setInsertRecord(QSqlRecord &recData)
{
	mRecord = recData;
	ui.line_id->setEnabled(true); //可以编辑
	ui.line_name->setText(mRecord.value("publisher_name").toString());
	ui.line_id->setText(mRecord.value("publisher_id").toString());
}

QSqlRecord DPublisherInfo::getNewData()
{
	// 一期工程：把界面的数据保存到mRecord里
	mRecord.setValue("publisher_name", ui.line_name->text());
	mRecord.setValue("publisher_email", ui.line_email->text());
	mRecord.setValue("publisher_phone", ui.line_phone->text());
	mRecord.setValue("publisher_address", ui.line_address->text());

	// 二期工程：检查是否合法

	return mRecord;
}

bool DPublisherInfo::isNameDuplicated(const QString & name, int id)
{
	QString publisher_name = name.trimmed().length() > 0 ? name : ui.line_name->text();
	int publisher_id = id > 0 ? id : ui.line_id->text().toInt();
	QSqlQuery query;
	query.prepare(
		"SELECT *\n"
		"FROM Publisher\n"
		"WHERE publisher_name = :publisher_name\n"
		"AND publisher_id != :publisher_id;"
	);
	query.bindValue(":publisher_name", publisher_name);
	query.bindValue(":publisher_id", publisher_id);
	query.exec();
	return query.first();
}

void DPublisherInfo::onBtnConfirm()
{
	accept();
}
