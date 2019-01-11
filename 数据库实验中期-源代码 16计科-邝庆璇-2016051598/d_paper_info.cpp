#include "d_paper_info.h"

DPaperInfo::DPaperInfo(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	noContributorMes = u8"����";
	noJournalMes = u8"����";

	// �����
	connect(ui.btn_confirm, SIGNAL(clicked()), this, SLOT(onBtnConfirm()));
	// �ڿ���Ͷ������Ϣ��
	connect(ui.btn_contributor, SIGNAL(clicked()), this, SLOT(onBtnContributor()));
	connect(ui.btn_journal, SIGNAL(clicked()), this, SLOT(onBtnJournal()));
	// �Զ���ȫ���
	connect(ui.line_id, SIGNAL(editingFinished()), this, SLOT(onLineIdFinished()));
	// ������ʾ��ť
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

	// ����Ͷ������Ϣ
	initCmbContributorName(mRecord.value("contributor_name").toString()); // Ͷ������cmbox
	setContributorIdsFromName(mRecord.value("contributor_name").toString(), // Ͷ���˺�cmbox
		mRecord.value("contributor_id").toInt());

	// �����ڿ���Ϣ
	initCmbJournalName(mRecord.value("journal_name").toString());
	ui.line_journalId->setText(mRecord.value("journal_id").toString()); // Ҳ������setFromName
}

void DPaperInfo::setInsertRecord(QSqlRecord & recData)
{
	mRecord = recData;
	ui.line_id->setText(mRecord.value("paper_id").toString());
	ui.line_id->setEnabled(true);

	// ����Ͷ������Ϣ
	initCmbContributorName(); // Ͷ������cmbox
	setContributorIdsFromName(ui.cmb_contributorName->currentText());

	// �����ڿ���Ϣ
	initCmbJournalName();
	setJournalIdFromName(ui.cmb_journal->currentText()); // Ҳ������setFromName
}

QSqlRecord DPaperInfo::getNewData()
{
	mRecord.setValue("paper_id", ui.line_id->text().trimmed()); // ���º����ַ���
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
		QMessageBox::warning(this, u8"�޴�Ͷ����", u8"��δ��¼��λͶ����Ŷ��\n" ,
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	else if (ui.line_journalId->text().trimmed() == noJournalMes)
	{
		QMessageBox::warning(this, u8"�޴��ڿ�", u8"��δ��¼���ڿ�Ŷ��\n",
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	else if (!SharedFunctions::isValidDate(ui.line_date->text().trimmed()))
	{
		QMessageBox::warning(this, u8"���ڸ�ʽ�ƺ�����Ү~", u8"�밴��ʽ��������Ŷ��\n",
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	else if (isNameDuplicated())
	{
		QMessageBox::warning(this, u8"���������ظ�Ŷ~", u8"���⣬���⣡\n",
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
		QMessageBox::warning(this, u8"�޴�Ͷ����", u8"��δ��¼��λͶ����Ŷ��\n",
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
		QMessageBox::critical(this, u8"Ͷ���˴���", u8"Ͷ���˲�ѯ����\n" + query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}

	query.first();
	QSqlRecord inRec = query.record();
	DContributorInfo* conDlg = new DContributorInfo(this);
	// ��ʾͶ���˶�Ӧ����������
	connect(conDlg, SIGNAL(toShowPaper(int, int)), this, SLOT(onToShowPaper(int, int)));
	conDlg->setReadOnlyRecord(inRec);
	int ret = conDlg->exec();
}

void DPaperInfo::onBtnJournal()
{
	if (ui.line_journalId->text().trimmed() == noJournalMes)
	{
		QMessageBox::warning(this, u8"�޴��ڿ�", u8"��δ��¼���ڿ�Ŷ��\n",
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	
	// ��ȡ�ڿ���
	int journal_id = ui.line_journalId->text().toInt();

	// ��ʽ��ѯ��ǰ�ڿ�����
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

	// ���ݲ�ѯ����������¶Ի���
	QSqlRecord currRec = query.record();
	DJournalInfo* journalDialog = new DJournalInfo(this);
	// connect��ת��journal
	connect(journalDialog, SIGNAL(toShowJournal(int)), this, SLOT(onToShowJournal(int)));
	// connect��ʾjournal��paper
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
		QMessageBox::critical(this, u8"��ѯͶ���˴���", u8"��ʼ��Ͷ�������ִ���\n" + query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	while (query.next())
		ui.cmb_contributorName->addItem(query.record().value("contributor_name").toString());
	if (old_name.length() > 0)
		ui.cmb_contributorName->setCurrentIndex(ui.cmb_contributorName->findText(old_name));

	// Ͷ����
	connect(ui.cmb_contributorName, SIGNAL(currentTextChanged(const QString&)), this, SLOT(onCurrentContributorChanged(const QString&)));
}

void DPaperInfo::initCmbJournalName(const QString & old_name)
{
	QSqlQuery query;
	if (!query.exec("SELECT DISTINCT journal_name FROM Journal ORDER BY journal_name;"))
	{
		QMessageBox::critical(this, u8"��ѯ�ڿ�����", u8"��ʼ���ڿ����ִ���\n" + query.lastError().text(),
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
		QMessageBox::critical(this, u8"��ѯͶ���˴���", u8"��ȡͶ���˺������\n" + query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}

	bool exist = query.first();
	if (!exist) // Ͷ���˲�����
	{
		ui.cmb_contributorId->addItem(noContributorMes);
		return;
	}

	// Ͷ���˴���
	ui.cmb_contributorId->addItem(query.record().value("contributor_id").toString());
	while (query.next()) // Ͷ���˴���
		ui.cmb_contributorId->addItem(query.record().value("contributor_id").toString());
	
	// ����Ĭ�ϵ�
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
