#include "d_paper_info.h"

DPaperInfo::DPaperInfo(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	noContributorMes = u8"暂无";
	noJournalMes = u8"暂无";

	// 自身改
	connect(ui.btn_confirm, SIGNAL(clicked()), this, SLOT(onBtnConfirm()));
	// 期刊和投稿人信息框
	connect(ui.btn_contributor, SIGNAL(clicked()), this, SLOT(onBtnContributor()));
	connect(ui.btn_journal, SIGNAL(clicked()), this, SLOT(onBtnJournal()));
	// 自动补全编号
	connect(ui.line_id, SIGNAL(editingFinished()), this, SLOT(onLineIdFinished()));
	// 重置显示按钮
}

DPaperInfo::~DPaperInfo()
{
}

void DPaperInfo::setEditRecord(QSqlRecord & recData)
{
	mRecord = recData;
	ui.line_id->setText(mRecord.value("paper_id").toString());
	ui.line_id->setEnabled(false);
	ui.line_name->setText(mRecord.value("paper_name").toString());
	ui.line_date->setText(mRecord.value("paper_publisher_date").toString());

	// 设置投稿人信息
	initCmbContributorName(mRecord.value("contributor_name").toString()); // 投稿人名cmbox
	setContributorIdsFromName(mRecord.value("contributor_name").toString(), // 投稿人号cmbox
		mRecord.value("contributor_id").toInt());

	// 设置期刊信息
	initCmbJournalName(mRecord.value("journal_name").toString());
	ui.line_journalId->setText(mRecord.value("journal_id").toString()); // 也可以用setFromName
}

void DPaperInfo::setInsertRecord(QSqlRecord & recData)
{
	mRecord = recData;
	ui.line_id->setText(mRecord.value("paper_id").toString());
	ui.line_id->setEnabled(true);

	// 设置投稿人信息
	initCmbContributorName(); // 投稿人名cmbox
	setContributorIdsFromName(ui.cmb_contributorName->currentText());

	// 设置期刊信息
	initCmbJournalName();
	setJournalIdFromName(ui.cmb_journal->currentText()); // 也可以用setFromName
}

QSqlRecord DPaperInfo::getNewData()
{
	mRecord.setValue("paper_id", ui.line_id->text().trimmed()); // 文章号是字符串
	mRecord.setValue("paper_name", ui.line_name->text().trimmed());
	mRecord.setValue("paper_publisher_date", ui.line_date->text().trimmed());
	mRecord.setValue("contributor_id", ui.cmb_contributorId->currentText().toInt());
	mRecord.setValue("journal_id", ui.line_journalId->text().toInt());

	return mRecord;
}

void DPaperInfo::onBtnConfirm()
{
	if (ui.cmb_contributorId->currentText().trimmed() == noContributorMes)
	{
		QMessageBox::warning(this, u8"无此投稿人", u8"暂未收录这位投稿人哦！\n" ,
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	else if (ui.line_journalId->text().trimmed() == noJournalMes)
	{
		QMessageBox::warning(this, u8"无此期刊", u8"暂未收录次期刊哦！\n",
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	else if (!SharedFunctions::isValidDate(ui.line_date->text().trimmed()))
	{
		QMessageBox::warning(this, u8"日期格式似乎不对耶~", u8"请按格式输入日期哦！\n",
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	else if (isNameDuplicated())
	{
		QMessageBox::warning(this, u8"文名不可重复哦~", u8"如题，如题！\n",
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	else
	{
		accept();
	}
}

void DPaperInfo::onCurrentContributorChanged(const QString & contributor_name)
{
	setContributorIdsFromName(contributor_name);
}

void DPaperInfo::onCurrentJournalChanged(const QString & journal_name)
{
	setJournalIdFromName(journal_name);
}

void DPaperInfo::onBtnContributor()
{
	if (ui.cmb_contributorId->currentText().trimmed() == noContributorMes)
	{
		QMessageBox::warning(this, u8"无此投稿人", u8"暂未收录这位投稿人哦！\n",
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}

	QSqlQuery query;
	query.prepare(
		"SELECT C.*, CV.*\n"
		"FROM V_Contributor CV, Contributor C\n"
		"WHERE CV.contributor_id = C.contributor_id\n"
		"AND C.contributor_id = :contributor_id;"
	);
	query.bindValue(":contributor_id", ui.cmb_contributorId->currentText().toInt());
	if (!query.exec())
	{
		QMessageBox::critical(this, u8"投稿人错误", u8"投稿人查询错误\n" + query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}

	query.first();
	QSqlRecord inRec = query.record();
	DContributorInfo* conDlg = new DContributorInfo(this);
	// 显示投稿人对应的所有文章
	connect(conDlg, SIGNAL(toShowPaper(int, int)), this, SLOT(onToShowPaper(int, int)));
	conDlg->setReadOnlyRecord(inRec);
	int ret = conDlg->exec();
}

void DPaperInfo::onBtnJournal()
{
	if (ui.line_journalId->text().trimmed() == noJournalMes)
	{
		QMessageBox::warning(this, u8"无此期刊", u8"暂未收录次期刊哦！\n",
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	
	// 获取期刊号
	int journal_id = ui.line_journalId->text().toInt();

	// 正式查询当前期刊详情
	QString qryStr = QString(
		"SELECT J.journal_id, J.journal_name, J.new_publish_date, C.catalog_name, T.typee_name, E.editor_id, E.editor_name, E.editor_email\n"
		"FROM Journal AS J, Editor AS E, Typee AS T, Catalogg AS C\n"
		"WHERE journal_id = :journal_id\n"
		"AND J.editor_id = E.editor_id\n"
		"AND J.typee_id = T.typee_id\n"
		"AND T.catalog_id = C.catalog_id;"
	);
	QSqlQuery query;
	query.prepare(qryStr);
	query.bindValue(":journal_id", journal_id);
	query.exec();
	query.first();
	if (!query.isValid())
		return;

	// 根据查询结果弹出更新对话框
	QSqlRecord currRec = query.record();
	DJournalInfo* journalDialog = new DJournalInfo(this);
	// connect跳转到journal
	connect(journalDialog, SIGNAL(toShowJournal(int)), this, SLOT(onToShowJournal(int)));
	// connect显示journal的paper
	connect(journalDialog, SIGNAL(toShowPaper(int, int)), this, SLOT(onToShowPaper(int, int)));
	journalDialog->setReadOnlyRecord(currRec);
	int ret = journalDialog->exec();
}

void DPaperInfo::onLineIdFinished()
{
	ui.line_id->setText(SharedFunctions::completeId(ui.line_id->text()));
}

void DPaperInfo::onToShowJournal(int editor_id)
{
	emit toWinShowJournal(editor_id);
}

void DPaperInfo::onToShowPaper(int id, int prv_index)
{
	emit toShowPaper(id, prv_index);
	//reject();
}

void DPaperInfo::initCmbContributorName(const QString & old_name)
{
	QSqlQuery query;
	if (!query.exec("SELECT DISTINCT contributor_name FROM Contributor ORDER BY contributor_name;"))
	{
		QMessageBox::critical(this, u8"查询投稿人错误", u8"初始化投稿人名字错误！\n" + query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	while (query.next())
		ui.cmb_contributorName->addItem(query.record().value("contributor_name").toString());
	if (old_name.length() > 0)
		ui.cmb_contributorName->setCurrentIndex(ui.cmb_contributorName->findText(old_name));

	// 投稿人
	connect(ui.cmb_contributorName, SIGNAL(currentTextChanged(const QString&)), this, SLOT(onCurrentContributorChanged(const QString&)));
}

void DPaperInfo::initCmbJournalName(const QString & old_name)
{
	QSqlQuery query;
	if (!query.exec("SELECT DISTINCT journal_name FROM Journal ORDER BY journal_name;"))
	{
		QMessageBox::critical(this, u8"查询期刊错误", u8"初始化期刊名字错误！\n" + query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	while (query.next())
		ui.cmb_journal->addItem(query.record().value("journal_name").toString());
	if (old_name.length() > 0)
		ui.cmb_journal->setCurrentIndex(ui.cmb_journal->findText(old_name));

	connect(ui.cmb_journal, SIGNAL(currentTextChanged(const QString&)), this, SLOT(onCurrentJournalChanged(const QString&)));
}

void DPaperInfo::setContributorIdsFromName(const QString & contributor_name, int old_id)
{
	ui.cmb_contributorId->clear();
	QSqlQuery query;
	query.prepare(
		"SELECT contributor_id\n"
		"FROM Contributor\n"
		"WHERE contributor_name = :contributor_name;"
	);
	query.bindValue(":contributor_name", contributor_name);
	if (!query.exec())
	{
		QMessageBox::critical(this, u8"查询投稿人错误", u8"获取投稿人号码错误！\n" + query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}

	bool exist = query.first();
	if (!exist) // 投稿人不存在
	{
		ui.cmb_contributorId->addItem(noContributorMes);
		return;
	}

	// 投稿人存在
	ui.cmb_contributorId->addItem(query.record().value("contributor_id").toString());
	while (query.next()) // 投稿人存在
		ui.cmb_contributorId->addItem(query.record().value("contributor_id").toString());
	
	// 若有默认的
	if (old_id > 0)
		ui.cmb_contributorId->setCurrentIndex(ui.cmb_contributorId->findText(QString::number(old_id)));

}

void DPaperInfo::setJournalIdFromName(const QString & journal_name)
{
	QSqlQuery query;
	query.prepare("SELECT journal_id FROM Journal WHERE journal_name = :journal_name;");
	query.bindValue(":journal_name", journal_name);
	query.exec();
	if (!query.first())
		ui.line_journalId->setText(noJournalMes);
	else
		ui.line_journalId->setText(query.record().value("journal_id").toString());
	ui.line_journalId->setFocusPolicy(Qt::NoFocus);
}

bool DPaperInfo::isNameDuplicated(const QString & name, const QString & id)
{
	QString paper_name = name.trimmed().length() > 0 ? name : ui.line_name->text();
	QString paper_id = id.trimmed().length() > 0 ? id : ui.line_id->text();
	QSqlQuery query;
	
	query.prepare(
		"SELECT *\n"
		"FROM Paper\n"
		"WHERE paper_name = :paper_name\n"
		"AND paper_id != :paper_id;"
	);
	query.bindValue(":paper_name", paper_name);
	query.bindValue(":paper_id", paper_id);
	query.exec();
	return query.first();
}
