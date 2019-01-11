#include "d_contributor_info.h"

DContributorInfo::DContributorInfo(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	noUnitMes = u8"工作暂未定";
	initUnitCmb();

	// 连接确认返回
	connect(ui.btn_confirm, SIGNAL(clicked()), this, SLOT(onBtnConfirm()));
	// 连接查看文章
	connect(ui.btn_paper, SIGNAL(clicked()), this, SLOT(onBtnPaper()));
}

DContributorInfo::~DContributorInfo()
{
}

void DContributorInfo::setEditRecord(QSqlRecord & recData)
{
	mRecord = recData;
	ui.line_id->setText(mRecord.value("contributor_id").toString());
	ui.line_name->setText(mRecord.value("contributor_name").toString());
	ui.line_email->setText(mRecord.value("contributor_email").toString());
	ui.line_phone->setText(mRecord.value("contributor_phone").toString());
	// 设置当前单位
	setFirstUnit(mRecord.value("unit_name").toString()); 
	ui.line_paperCount->setText(mRecord.value("contribute_sum").toString()); // 当前发paper的总数

	ui.line_id->setEnabled(false);
	ui.line_paperCount->setEnabled(false);
}

void DContributorInfo::setInsertRecord(QSqlRecord & recData)
{
	mRecord = recData;
	ui.line_id->setEnabled(true);
	ui.line_id->setText(mRecord.value("contributor_id").toString());
	ui.line_paperCount->setHidden(true);
	ui.label_paperCount->setHidden(true);
}

void DContributorInfo::setReadOnlyRecord(QSqlRecord & recData)
{
	setEditRecord(recData);
	//ui.btn_confirm->setHidden(true);
	ui.btn_confirm->setText(u8" 确认");
	ui.line_name->setFocusPolicy(Qt::NoFocus);
	ui.line_email->setFocusPolicy(Qt::NoFocus);
	ui.line_phone->setFocusPolicy(Qt::NoFocus);
}

QSqlRecord DContributorInfo::getNewData()
{
	mRecord.setValue("contributor_id", ui.line_id->text().toInt());
	mRecord.setValue("contributor_name", ui.line_name->text().trimmed());
	mRecord.setValue("contributor_email", ui.line_email->text().trimmed());
	mRecord.setValue("contributor_phone", ui.line_phone->text().trimmed());
	mRecord.setValue("unit_name", ui.cmb_unit->currentText().trimmed());

	return mRecord;
}

void DContributorInfo::onBtnPaper()
{
	emit toShowPaper(ui.line_id->text().toInt(), 1); 
	// reject()?
}

void DContributorInfo::initUnitCmb()
{
	QSqlQuery unitQ;
	unitQ.exec(
		"SELECT unit_name\n"
		"FROM Unit\n"
		"ORDER BY unit_id;"
	);

	while (unitQ.next())
	{
		ui.cmb_unit->addItem(unitQ.record().value("unit_name").toString());
	}
	ui.cmb_unit->addItem(noUnitMes);
}

void DContributorInfo::setFirstUnit(QString unit_name)
{
	if (unit_name.isNull() || unit_name.isEmpty())
		unit_name = noUnitMes;

	int i = ui.cmb_unit->findText(unit_name);
	ui.cmb_unit->setCurrentIndex(i);
}

void DContributorInfo::onBtnConfirm()
{
	accept();
}
