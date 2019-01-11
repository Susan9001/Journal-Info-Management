#include "win_paper_catalog.h"

WinPaperCatalog::WinPaperCatalog(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initPaperTable();
	prv_index = 2;

	connect(ui.btn_articleInfo, SIGNAL(clicked()), this, SLOT(onBtnInfo()));
	connect(ui.btn_add, SIGNAL(clicked()), this, SLOT(onBtnAdd()));
	connect(ui.btn_delete, SIGNAL(clicked()), this, SLOT(onBtnDelete()));
	connect(ui.btn_search, SIGNAL(clicked()), this, SLOT(onBtnSearch()));
	connect(ui.btn_refresh, SIGNAL(clicked()), this, SLOT(onBntRefresh()));	// ������ʾ��ť
	connect(ui.btn_selectAll, SIGNAL(clicked()), this, SLOT(onBtnSelectAll())); // ȫѡ/ȫ��ѡ
	connect(ui.btn_back, SIGNAL(clicked()), this, SLOT(onBtnBack())); // �����ڿ�/Ͷ����ҳ
	connect(ui.btn_print, SIGNAL(clicked()), this, SLOT(onBtnPrint()));
}

WinPaperCatalog::~WinPaperCatalog()
{
}

void WinPaperCatalog::renewPaperTable(const QString & qryMes)
{
	// �ȴ򿪱�����Model
	m_qryModel = new QSqlQueryModel(this);
	QString theQryMes;

	if (qryMes == NULL || qryMes == "")
	{
		theQryMes = QString(
			"SELECT *\n"
			"FROM V_Paper\n"
			"ORDER BY paper_id;\n"
		);
	}
	else
	{
		theQryMes = qryMes;
	}

	m_qryModel->setQuery(theQryMes);
	// ����ѯʧ��
	if (m_qryModel->lastError().isValid())
	{
		QMessageBox::critical(this, u8"����", u8"��ѯ����ͳ�ƴ���\n������Ϣ��" + m_qryModel->lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}

	// ����ѯ�ɹ���������data
	m_qryModel->setHeaderData(1, Qt::Horizontal, u8"���º�");
	m_qryModel->setHeaderData(2, Qt::Horizontal, u8"������");
	m_qryModel->setHeaderData(3, Qt::Horizontal, u8"Ͷ���˺�");
	m_qryModel->setHeaderData(4, Qt::Horizontal, u8"Ͷ������");
	m_qryModel->setHeaderData(5, Qt::Horizontal, u8"�ڿ���");
	m_qryModel->setHeaderData(6, Qt::Horizontal, u8"�ڿ���");
	m_qryModel->setHeaderData(7, Qt::Horizontal, u8"��������");

	// ���븴ѡ�����
	m_qryModel->insertColumn(0);
	ui.m_paperTable->setModel(m_qryModel); // Ӧ��ģ����
	ui.m_paperTable->setColumnHidden(3, true);
	ui.m_paperTable->setColumnHidden(5, true);

	// ���븴ѡ��
	for (int i = 0; i < m_qryModel->rowCount(); i++)
		ui.m_paperTable->setIndexWidget(m_qryModel->index(i, 0), new QCheckBox(this));

	ui.m_paperTable->setColumnWidth(0, 60); // ���ø�ѡ����
	ui.m_paperTable->setColumnWidth(1, 120); // �������±�ſ���
	ui.m_paperTable->setColumnWidth(6, 260); // �����ڿ�������
	ui.m_paperTable->setSelectionMode(QAbstractItemView::SingleSelection);

}

void WinPaperCatalog::onBtnDelete()
{
	QList<QString> paper_ids = getSelectedIds();

	// ȷ�϶Ի���
	QString dlgTitle = u8"ɾ��ȷ��";
	QString strInfo = QString(u8"�Ƿ�ɾ��ѡ�е�%1ƪ���µ���Ϣ").arg(paper_ids.size());
	QMessageBox::StandardButton defaultBtn = QMessageBox::NoButton;
	QMessageBox::StandardButton result; // ����ѡ��
	result = QMessageBox::question(this, dlgTitle, strInfo, QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
		defaultBtn);

	// ��Ϊȷ����ɾ��
	if (result == QMessageBox::Yes)
	{
		QString qryStr = QString(
			"DELETE\n"
			"FROM Paper\n"
			"WHERE paper_id IN("
		);
		qryStr.append(paper_ids[0]);
		for (int i = 1; i < paper_ids.size(); i++)
			qryStr.append(", " + paper_ids[i]);
		qryStr.append(");");

		QSqlQuery query;
		if (!query.exec(qryStr))
		{
			QMessageBox::critical(this, u8"����", u8"ɾ������ʧ�ܣ�\n������Ϣ��" + m_qryModel->lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}
	}

	// ˢ��
	renewPaperTable();
}

void WinPaperCatalog::onBtnInfo()
{
	updateSinglePaper();
}

void WinPaperCatalog::onBtnSearch()
{
	DSearchPaper* searchDlg = new DSearchPaper(this);
	int ret = searchDlg->exec();

	if (ret == QDialog::Accepted)
	{
		QStringList paper_names = SharedFunctions::splitStr(searchDlg->getPaperNames());
		QStringList journal_names = SharedFunctions::splitStr(searchDlg->getJournalNames());
		QStringList contributor_names = SharedFunctions::splitStr(searchDlg->getContributorNames());

		QString qryStr = bindSearchQuery(paper_names, journal_names, contributor_names);
		renewPaperTable(qryStr);
	}
}

void WinPaperCatalog::onBntRefresh()
{
	renewPaperTable();
}

void WinPaperCatalog::onBtnSelectAll()
{
	setCheckAll();
}

void WinPaperCatalog::onBtnBack()
{
	emit goBack(this->prv_index);
	renewPaperTable();
}

void WinPaperCatalog::onBtnPrint()
{
	SharedFunctions::makeReport(m_qryModel, ui.m_paperTable, u8"���±���");
}

void WinPaperCatalog::onToWinShowJournal(int editor_id)
{
	emit toEditorShowJournal(editor_id);
}

void WinPaperCatalog::onShowPaper(int id, int prv_index)
{
	QString result; 
	this->prv_index = prv_index;
	
	if (prv_index == 0) // indexΪ0������journalҳ
		result = bindSearchQuery(QList<QString>(), QList<int>({ id }), QList<int>());
	else if (prv_index == 1) // indexΪ1������contributorҳ
		result = bindSearchQuery(QList<QString>(), QList<int>(), QList<int>({ id }));
	else
		return;

	renewPaperTable(result);
}

void WinPaperCatalog::initPaperTable()
{
	renewPaperTable();
}

QList<QString> WinPaperCatalog::getSelectedIds()
{
	QList<QString> paper_ids;

	for (int i = 0; i < m_qryModel->rowCount(); i++)
	{
		QCheckBox *checkBox = (QCheckBox *)ui.m_paperTable->indexWidget(m_qryModel->index(i, 0));
		if (checkBox->isChecked())
		{
			QSqlRecord checkedRec = m_qryModel->record(i); // ��ǰѡ�еļ�¼
			paper_ids.append(checkedRec.value("paper_id").toString());
		}
	}

	return paper_ids;
}

void WinPaperCatalog::setCheckAll()
{
	// �Ȳ鿴�Ƿ���ѡ���
	bool toCheck = ((QCheckBox *)ui.m_paperTable->indexWidget(m_qryModel->index(0, 0)))->isChecked();

	for (int i = 0; i < m_qryModel->rowCount(); i++)
	{
		QCheckBox *checkBox = (QCheckBox *)ui.m_paperTable->indexWidget(m_qryModel->index(i, 0));
		checkBox->setChecked(!toCheck);
	}
}

void WinPaperCatalog::onBtnAdd()
{
	insertSinglePaper();
}

QString WinPaperCatalog::bindSearchQuery(const QList<QString>& paper_ids, const QList<int>& journal_ids, const QList<int>& contributor_ids)
{
	QString selected_paper_ids, selected_journal_ids, selected_contributor_ids;
	QString qryStr = QString(
		"SELECT *\n"
		"FROM V_Paper\n"
		"WHERE paper_id = -1\n"
	);

	 // ��Ͷ����
	if (contributor_ids.size() > 0)
	{
		selected_contributor_ids.append(QString::number(contributor_ids[0]));
		for (int i = 1; i < contributor_ids.size(); i++)
			selected_contributor_ids.append("," + QString::number(contributor_ids[i]));
		qryStr.append(QString("OR contributor_id IN(" + selected_contributor_ids + ")\n"));
	}
	// ��paper
	if (paper_ids.size() > 0)
	{
		selected_paper_ids.append(paper_ids[0]);
		for (int i = 1; i < paper_ids.size(); i++)
			selected_paper_ids.append("," + paper_ids[i]);
		qryStr.append(QString("OR paper_id IN (" + selected_paper_ids + ")\n"));
	}
	// ���journal
	if (journal_ids.size() > 0)
	{
		selected_journal_ids.append(QString::number(journal_ids[0]));
		for (int i = 1; i < journal_ids.size(); i++)
			selected_paper_ids.append("," + QString::number(journal_ids[i]));
		qryStr.append(QString("OR journal_id IN (" + selected_journal_ids + ")\n"));
	}

	if (journal_ids.size() <= 0 && paper_ids.size() <= 0 && contributor_ids.size() <= 0)
		qryStr.append(QString("AND paper_id = -1\n"));
	return qryStr;
}

QString WinPaperCatalog::bindSearchQuery(const QStringList & paper_names, QStringList & journal_names, const QStringList & contributor_names)
{
	QString result = QString(
		"SELECT *\n"
		"FROM V_Paper\n"
		"WHERE paper_id != -1\n"
	);

	// ��paper_names
	QString unitStr = "AND (";
	if (paper_names.size() > 0)
	{
		// ��ͷû��or
		unitStr.append(QString("paper_name LIKE '%%1%'\n").arg(paper_names[0]));
		for (int i = 1; i < paper_names.size(); i++)
			unitStr.append(QString("OR paper_name LIKE '%%1%'\n").arg(paper_names[i]));
		unitStr.append(")");
		// ��ӵ�result����
		result.append(unitStr);
	}

	// ��contributor_names
	QString contributorStr = "AND (";
	if (contributor_names.size() > 0)
	{
		// ��ͷû��or
		contributorStr.append(QString("contributor_name LIKE '%%1%'\n").arg(contributor_names[0]));
		for (int i = 1; i < contributor_names.size(); i++)
			contributorStr.append(QString("OR contributor_name LIKE '%%1%'\n").arg(contributor_names[i]));
		contributorStr.append(")");
		result.append(contributorStr);
	}

	// ���journal_names
	QString journalStr = "AND (";
	if (journal_names.size() > 0)
	{
		// ��ͷû��or
		journalStr.append(QString("journal_names LIKE '%%1%'\n").arg(journal_names[0]));
		for (int i = 1; i < journal_names.size(); i++)
			journalStr.append(QString("OR journal_names LIKE '%%1%'\n").arg(journal_names[i]));
		journalStr.append(")");
		result.append(journalStr);
	}

	if (paper_names.size() <= 0 && contributor_names.size() <= 0 && journal_names.size() <= 0)
		result.append("AND contributor_id == -1");

	return result.append(";");
}

void WinPaperCatalog::insertSinglePaper()
{
	QSqlQuery query;
	query.exec(u8"SELECT * FROM V_Paper");
	query.first();

	QSqlRecord inRec = query.record();
	inRec.setValue("paper_id", getNextPaperId());
	DPaperInfo* paperDlg = new DPaperInfo(this);
	connect(paperDlg, SIGNAL(toWinShowJournal(int)), this, SLOT(onToWinShowJournal(int)));
	connect(paperDlg, SIGNAL(toShowPaper(int, int)), this, SLOT(onShowPaper(int, int)));
	paperDlg->setInsertRecord(inRec);

	int ret = paperDlg->exec();
	if (ret == QDialog::Accepted)
	{
		QSqlRecord outRec = paperDlg->getNewData();

		// ���Ͷ���˺��Ƿ��ظ�
		if (isPaperIdDuplicated(outRec.value("paper_id").toInt()))
		{
			QMessageBox::warning(this, u8"���º��ظ�", u8"�������º��ظ�����\n",
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}

		// ��ʼinsert
		query.prepare(
			"INSERT INTO Paper(paper_id, paper_name, paper_publisher_date, journal_id, contributor_id)\n"
			"VALUES (:paper_id, :paper_name, :paper_publisher_date, :journal_id, :contributor_id);"
		);
		query.bindValue(":paper_name", outRec.value("paper_name"));
		query.bindValue(":contributor_id", outRec.value("contributor_id"));
		query.bindValue(":journal_id", outRec.value("journal_id"));
		query.bindValue(":paper_publisher_date", outRec.value("paper_publisher_date"));
		query.bindValue(":paper_id", outRec.value("paper_id"));
		if (!query.exec())
		{
			QMessageBox::critical(this, u8"���´���", u8"������������\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}

		renewPaperTable();
	}
	delete paperDlg;
}

void WinPaperCatalog::updateSinglePaper()
{
	// ��ȡ��ǰ��¼
	QSqlRecord inRec = m_qryModel->record(ui.m_paperTable->currentIndex().row());
	// ��ȡ�ڿ���
	QString paper_id = inRec.value("paper_id").toString();

	QSqlQuery query;
	query.prepare(u8"SELECT * FROM V_Paper WHERE paper_id = :paper_id;");
	query.bindValue(":paper_id", paper_id);
	query.exec();
	query.first();
	if (!query.isValid())
	{
		qDebug() << "search unit not ok";
		return;
	}

	inRec = query.record();
	DPaperInfo* paperDlg = new DPaperInfo(this);
	connect(paperDlg, SIGNAL(toWinShowJournal(int)), this, SLOT(onToWinShowJournal(int)));
	connect(paperDlg, SIGNAL(toShowPaper(int, int)), this, SLOT(onShowPaper(int, int)));
	paperDlg->setEditRecord(inRec); // ���������ݵ���������Ϣ������
	int ret = paperDlg->exec(); // ģ̬����

	// ���³�������Ϣ���Ժ�Ҫ��Ϊpaper_id�ģ�
	if (ret == QDialog::Accepted)
	{
		// ��ȡ���صļ�¼
		QSqlRecord outRec = paperDlg->getNewData();
		// ��������
		query.prepare(
			u8"UPDATE Paper\n"
			"SET paper_name = :paper_name,\n"
			"contributor_id = :contributor_id,\n"
			"journal_id = :journal_id, "
			"paper_publisher_date = :paper_publisher_date\n"
			"WHERE paper_id = :paper_id;" //�ǵ÷ֺţ�����
		);
		query.bindValue(":paper_name", outRec.value("paper_name"));
		query.bindValue(":contributor_id", outRec.value("contributor_id"));
		query.bindValue(":journal_id", outRec.value("journal_id"));
		query.bindValue(":paper_publisher_date", outRec.value("paper_publisher_date"));
		query.bindValue(":paper_id", paper_id);

		if (!query.exec())
		{
			QMessageBox::critical(this, u8"����", u8"����������Ϣ����\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}
		renewPaperTable();
	}

	delete paperDlg;
}

QString WinPaperCatalog::getNextPaperId()
{
	QSqlQuery query;
	query.exec("SELECT MAX(P.paper_id) max_paper_id FROM Paper P");
	if (!query.first()) return SharedFunctions::completeId("1");
	else return SharedFunctions::completeId(QString::number(query.record().value("max_paper_id").toInt()+1));
}

bool WinPaperCatalog::isPaperIdDuplicated(int paper_id)
{
	QSqlQuery query;
	query.prepare("SELECT * FROM Paper WHERE paper_id = :paper_id;");
	query.bindValue(":paper_id", paper_id);
	if (!query.exec())
	{
		QMessageBox::critical(this, u8"����", u8"��ѯ�ڿ��Ŵ���\n" + query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return false;
	}
	return query.first();
}
