#include "d_unit_info.h"

DUnitInfo::DUnitInfo(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.btn_confirm, SIGNAL(clicked()), this, SLOT(onBtnConfirm()));
	connect(ui.btn_staff, SIGNAL(clicked()), this, SLOT(onBtnStaff()));
}

DUnitInfo::~DUnitInfo()
{
}

void DUnitInfo::setEditRecord(QSqlRecord & recData)
{
	mRecord = recData; // 先获取当前信息
	ui.line_id->setEnabled(false); // 出版社号不允许修改

	// 显示
	ui.line_id->setText(mRecord.value("unit_id").toString());
	ui.line_name->setText(mRecord.value("unit_name").toString());
	ui.line_email->setText(mRecord.value("unit_email").toString());
	ui.line_phone->setText(mRecord.value("unit_phone").toString());
	ui.line_address->setText(mRecord.value("unit_address").toString());
	return;
}

void DUnitInfo::setInsertRecord(QSqlRecord & recData)
{
	mRecord = recData;
	ui.line_id->setEnabled(true);
	ui.line_id->setText(mRecord.value("unit_id").toString());
}

QSqlRecord DUnitInfo::getNewData()
{
	// 一期工程：把界面的数据保存到mRecord里
	mRecord.setValue("unit_name", ui.line_name->text().trimmed());
	mRecord.setValue("unit_email", ui.line_email->text().trimmed());
	mRecord.setValue("unit_phone", ui.line_phone->text().trimmed());
	mRecord.setValue("unit_address", ui.line_address->text().trimmed());

	// 二期工程：检查是否合法

	return mRecord;
}

bool DUnitInfo::isNameDuplicated(const QString & name, int id)
{
	QString unit_name = name.trimmed().length() > 0 ? name : ui.line_name->text();
	int unit_id = id > 0 ? id : ui.line_id->text().toInt();
	QSqlQuery query;
	query.prepare("SELECT *\n""FROM Unit\n""WHERE unit_name = :unit_name\n""AND unit_id != :unit_id;");
	query.bindValue(":unit_name", unit_name);
	query.bindValue(":unit_id", unit_id);
	query.exec();
	return query.first();
}

void DUnitInfo::onBtnStaff()
{
	emit showStaff(ui.line_id->text().toInt());
}

void DUnitInfo::onBtnConfirm()
{
	accept();
}
