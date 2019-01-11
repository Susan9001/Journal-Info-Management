#include "win_journal_catalog.h"

WinJournalCatalog::WinJournalCatalog(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	initJournalTable();
	initTypeTree();

	// connect��ʾ����
	connect(ui.btn_journalInfo, SIGNAL(clicked()), this, SLOT(onBtnJournalInfo()));
	// connect��ɾ��
	connect(ui.btn_add, SIGNAL(clicked()), this, SLOT(onBtnAdd()));
	connect(ui.btn_delete, SIGNAL(clicked()), this, SLOT(onBtnDelete()));
	connect(ui.btn_search, SIGNAL(clicked()), this, SLOT(onBtnSearch()));
	// connect����ѡ��������catalog��ѡ��typee...��
	connect(ui.m_catalogTree, SIGNAL(itemChanged(QTreeWidgetItem*, int)), 
		this, SLOT(onTypeeSelChanged(QTreeWidgetItem*, int)));
	// connect����������ʾ
	connect(ui.btn_show, SIGNAL(clicked()), this, SLOT(onBtnShow())); // ����
	connect(ui.m_catalogTree, SIGNAL(itemSelectionChanged()), this, SLOT(onTypeeItemSelcectionChanged()));
	// connect����
	connect(ui.btn_article, SIGNAL(clicked()), this, SLOT(onBtnPaper()));
	// connect��ӡ����
	connect(ui.btn_print, SIGNAL(clicked()), this, SLOT(onBtnPrint()));
}

WinJournalCatalog::~WinJournalCatalog()
{
}

void WinJournalCatalog::renewJournalTable(const QString & qryMes) // ����ΪNULL
{
	// �ȴ򿪱�����Model
	m_qryModel = new QSqlQueryModel(this);
	QString theQryMes;

	if (qryMes == NULL || qryMes == "")
	{
		theQryMes = QString(
			// ��ʱ��Ҫ����editor_id�յ����
			"SELECT * FROM V_Journal;"
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
		QMessageBox::critical(this, "����", "���ڿ������\n������Ϣ��" + m_qryModel->lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}

	// ����ѯ�ɹ���������data
	m_qryModel->setHeaderData(1, Qt::Horizontal, u8"�ڿ���");
	m_qryModel->setHeaderData(2, Qt::Horizontal, u8"�ڿ���");
	m_qryModel->setHeaderData(3, Qt::Horizontal, u8"����");
	m_qryModel->setHeaderData(4, Qt::Horizontal, u8"������");
	m_qryModel->setHeaderData(5, Qt::Horizontal, u8"����");
	m_qryModel->setHeaderData(6, Qt::Horizontal, u8"���³�������");

	// ���븴ѡ�����
	m_qryModel->insertColumn(0);

	ui.m_journalTable->setModel(m_qryModel); // Ӧ��ģ����

	for (int i = 0; i < m_qryModel->rowCount(); i++)
	{
		// ���븴ѡ��
		ui.m_journalTable->setIndexWidget(m_qryModel->index(i, 0), new QCheckBox(this));
		// ���þ��У���û�гɹ�uuu��
		/*for (int j = 0; j < m_qryModel->columnCount(); j++)
			m_qryModel->setData(m_qryModel->index(i, j), Qt::AlignHCenter, Qt::TextAlignmentRole);*/
	}
	ui.m_journalTable->setColumnWidth(0, 60); // ���ø�ѡ����
	ui.m_journalTable->setColumnWidth(1, 100); // ���ñ�ſ���
	ui.m_journalTable->setSelectionMode(QAbstractItemView::SingleSelection);

	return;
}

void WinJournalCatalog::onBtnPaper()
{
	if (ui.m_journalTable->currentIndex().row() < 0) return;
	QSqlRecord tmp = m_qryModel->record(ui.m_journalTable->currentIndex().row());
	int journal_id = tmp.value("journal_id").toInt();
	emit paperClicked(journal_id, 0);
}

void WinJournalCatalog::onDlgPaper(int id, int curr_index)
{
	emit paperClicked(id, curr_index);
}

void WinJournalCatalog::onBtnPrint()
{
	SharedFunctions::makeReport(m_qryModel, ui.m_journalTable, u8"�ڿ�����");
}

void WinJournalCatalog::onBtnJournalInfo()
{
	// ��ȡ��ǰ��¼
	QSqlRecord currRec = m_qryModel->record(ui.m_journalTable->currentIndex().row());
	// ��ȡ�ڿ���
	int journal_id = currRec.value("journal_id").toInt();

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

	// �ݴ浱ǰ����ţ�Ӧ�Ը���������������
	int old_editor_id = getEditorIdFromJournal(journal_id); // �����Ƕ�̬��

	// ���ݲ�ѯ����������¶Ի���
	currRec = query.record();
	DJournalInfo* journalDialog = new DJournalInfo(this);
	journalDialog->setEditRecord(currRec);
	connect(journalDialog, SIGNAL(toShowPaper(int, int)), this, SLOT(onDlgPaper(int, int)));
	connect(journalDialog, SIGNAL(toShowJournal(int)), this, SLOT(onToShowJournal(int)));
	int ret = journalDialog->exec();

	// ���±༭��ɺ�
	if (ret == QDialog::Accepted)
	{
		QSqlRecord outRec = journalDialog->getNewData();

		// ��ȡ�����
		qryStr = QString(
			"SELECT typee_id\n"
			"FROM Typee\n"
			"WHERE typee_name = :typee_name;"
		);
		query.prepare(qryStr);
		query.bindValue(":typee_name", outRec.value("typee_name"));
		if (!query.exec())
		{
			QMessageBox::critical(this, "���ʹ���", "����id��ѯ����\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}
		query.first();
		QString typee_id = query.record().value("typee_id").toString();

		// �����ֻ�ȡ�����
		//int new_editor_id = journalDialog->getEditorIdFromName(outRec.value("editor_name").toString(), old_editor_id);

		// ����journal��
		qryStr = QString(
			"UPDATE Journal\n"
			"SET journal_name = :journal_name,\n"
			"new_publish_date = :new_publish_date,\n"
			"editor_id = :editor_id,\n"
			"typee_id = :typee_id\n"
			"WHERE journal_id = :journal_id;\n"
		);
		query.prepare(qryStr);
		query.bindValue(":journal_name", outRec.value("journal_name"));
		query.bindValue(":new_publish_date", outRec.value("new_publish_date"));
		query.bindValue(":editor_id", outRec.value("editor_id"));
		query.bindValue(":typee_id", typee_id);
		query.bindValue(":journal_id", journal_id);
		if (!query.exec())
		{
			QMessageBox::critical(this, "���´���", "��¼���´���\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}
		renewJournalTable(); // ���¸���
		initTypeTree();
	}
	delete journalDialog;
}

void WinJournalCatalog::onBtnAdd()
{
	insertSingleJournal();
}

void WinJournalCatalog::onBtnDelete()
{
	QList<int> journal_ids = getSelectedIds();

	// ȷ�϶Ի���
	QString dlgTitle = u8"ɾ��ȷ��";
	QString strInfo = QString(u8"�Ƿ�ɾ��ѡ�е�%1���ڿ�����Ϣ").arg(journal_ids.size());
	QMessageBox::StandardButton defaultBtn = QMessageBox::NoButton;
	QMessageBox::StandardButton result; // ����ѡ��
	result = QMessageBox::question(this, dlgTitle, strInfo, QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
		defaultBtn);

	// ��Ϊȷ����ɾ��
	if (result == QMessageBox::Yes)
	{
		QString qryStr = QString(
			"DELETE\n"
			"FROM Journal\n"
			"WHERE journal_id IN("
		);
		qryStr.append(QString::number(journal_ids[0]));
		for (int i = 1; i < journal_ids.size(); i++)
			qryStr.append(", " + QString::number(journal_ids[i]));
		qryStr.append(");");

		QSqlQuery query;
		if (!query.exec(qryStr))
		{
			QMessageBox::critical(this, u8"����", u8"ɾ���ڿ�ʧ�ܣ�\n������Ϣ��" + m_qryModel->lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}
	}

	// ˢ��
	renewJournalTable();
}

void WinJournalCatalog::onBtnSearch()
{
	DSearchJournal* searchDlg = new DSearchJournal(this);
	int ret = searchDlg->exec();

	if (ret == QDialog::Accepted)
	{
		// �Ѵ������ؼ��ֳַɴʣ����տո��";,.()<>?|{}"��Щ���ţ�
		QStringList journal_names = SharedFunctions::splitStr(searchDlg->getJournalNames());
		QStringList typee_names = SharedFunctions::splitStr(searchDlg->getTypees());
		QStringList publisher_names = SharedFunctions::splitStr(searchDlg->getPublishers());

		// �ϳ��������
		QString qryStr = bindSearchQuery(typee_names, journal_names, publisher_names);
		renewJournalTable(qryStr);
	}
}

void WinJournalCatalog::onBtnShow()
{
	QStringList typee_names = getSelectedTyees();
	QString appendMes = bindSearchQuery(typee_names, QStringList(), QStringList());
	renewJournalTable(appendMes);
}

void WinJournalCatalog::onTypeeSelChanged(QTreeWidgetItem* item, int col)
{
	int childCount = item->childCount();

	//���仯���Ǹ�catalog
	if (childCount > 0)
	{
		if (item->checkState(0) == Qt::Checked)
		{
			for (int i = 0; i < childCount; i++)
				item->child(i)->setCheckState(1, Qt::Checked);
		}
		else if (item->checkState(0) == Qt::Unchecked)
		{
			for (int i = 0; i < childCount; i++)
				item->child(i)->setCheckState(1, Qt::Unchecked);
		}
	}
	// ���仯������typee
	else
	{
		QTreeWidgetItem* parent = item->parent();
		updateCatState(parent);
	}
}

void WinJournalCatalog::onTypeeItemSelcectionChanged()
{
	onBtnShow();
}

void WinJournalCatalog::onToShowJournal(int editor_id)
{
	QString result = QString(
		"SELECT *\n"
		"FROM V_Journal\n"
		"WHERE editor_name IN\n"
		"	(SELECT editor_name\n"
		"	FROM Editor\n"
		"	WHERE editor_id = %1);"
	).arg(editor_id);
	renewJournalTable(result);
}

void WinJournalCatalog::initJournalTable()
{
	renewJournalTable();
}

int WinJournalCatalog::getEditorIdFromJournal(int journal_id)
{
	QString qryStr = QString(
		"SELECT editor_id\n"
		"FROM Journal\n"
		"WHERE journal_id = :journal_id;"
	);
	QSqlQuery query;
	query.prepare(qryStr);
	query.bindValue(":journal_id", journal_id);
	query.exec();
	if (!query.exec())
	{
		QMessageBox::critical(this, "��ȡ����Ŵ���", "����id��ѯ����\n" + query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return 0;
	}
	query.first();
	return query.value("editor_id").toInt();
}

QList<int> WinJournalCatalog::getSelectedIds()
{
	QList<int> journal_ids;

	for (int i = 0; i < m_qryModel->rowCount(); i++)
	{
		QCheckBox *checkBox = (QCheckBox *)ui.m_journalTable->indexWidget(m_qryModel->index(i, 0));
		if (checkBox->isChecked())
		{
			QSqlRecord checkedRec = m_qryModel->record(i); // ��ǰѡ�еļ�¼
			journal_ids.append(checkedRec.value("journal_id").toInt());
		}
	}

	return journal_ids;
}

int WinJournalCatalog::getNextJournalId()
{
	QSqlQuery query;
	query.exec("SELECT MAX(journal_id) max_journal_id FROM Journal;");
	query.first();

	return query.record().value("max_journal_id").toInt() + 1;
}

void WinJournalCatalog::insertSingleJournal()
{
	// �����һ��record�����洫��insert�Ի�����ͷ��������������µ�����
	QString qryStr = QString(
		"SELECT J.journal_id, J.journal_name, J.new_publish_date, C.catalog_name, T.*, E.*\n"
		"FROM Journal AS J, Editor AS E, Typee AS T, Catalogg AS C\n"
		//"WHERE journal_id = :journal_id\n" --�����᷵��ȫNULL�ļ�¼������û�м�¼��û�취���Σ��ͺ�������
	);
	QSqlQuery query;
	query.prepare(qryStr);
	query.bindValue(":journal_id", getNextJournalId());
	query.exec();
	query.first();
	if (!query.isValid())
		return;

	// ���ݲ�ѯ����������¶Ի���
	QSqlRecord currRec = query.record();
	currRec.setValue("journal_id", getNextJournalId());
	DJournalInfo* journalDialog = new DJournalInfo(this);
	journalDialog->setInsertRecord(currRec);
	int ret = journalDialog->exec();

	// �Ի���༭��ɺ�
	if (ret == QDialog::Accepted)
	{
		QSqlRecord recData = journalDialog->getNewData();

		// ��ȡ�����
		qryStr = QString(
			"SELECT typee_id\n"
			"FROM Typee\n"
			"WHERE typee_name = :typee_name;"
		);
		query.prepare(qryStr);
		query.bindValue(":typee_name", recData.value("typee_name"));
		qDebug() << recData.value("typee_name").toString();
		if (!query.exec())
		{
			QMessageBox::critical(this, "���ʹ���", "����id��ѯ����\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}
		query.first();
		QString typee_id = query.record().value("typee_id").toString();
		qDebug() << query.record().value("typee_id").toString();

		// �����ֻ�ȡ�����
		int new_editor_id = journalDialog->getEditorIdFromName(recData.value("editor_name").toString());
		// ���û�иı�Ͳ����ٻ�ȡ��

		if (!new_editor_id)
		{
			QMessageBox::warning(this, "���಻���ڵ�", "�����ڵ�����\n",
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}

		// ����journal��
		qryStr = QString(
			"INSERT INTO Journal (journal_id, journal_name, new_publish_date, editor_id, typee_id)\n"
			"VALUES (:journal_id, :journal_name, :new_publish_date, :editor_id, :typee_id);"
		);
		query.prepare(qryStr);
		query.bindValue(":journal_id", recData.value("journal_id").toInt());
		query.bindValue(":journal_name", recData.value("journal_name"));
		query.bindValue(":new_publish_date", recData.value("new_publish_date").toString());
		query.bindValue(":editor_id", new_editor_id);
		query.bindValue(":typee_id", typee_id);
		if (!query.exec())
		{
			QMessageBox::critical(this, u8"����ڿ�����", "��¼�������\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}
		renewJournalTable(); // ���¸���
	}
	delete journalDialog;

}

void WinJournalCatalog::initTypeTree()
{
	ui.m_catalogTree->clear();
	ui.m_catalogTree->setColumnCount(3);
	ui.m_catalogTree->setColumnWidth(0, 60);
	QStringList headers = { "", u8"��Ŀ������", u8"���ͱ��" };
	ui.m_catalogTree->setHeaderLabels(headers);

	QSqlQuery catQuery, typeeQuery;

	catQuery.exec("SELECT catalog_name FROM Catalogg ORDER BY catalog_id; ");
	while (catQuery.next()) // ����Ӹ�
	{
		QTreeWidgetItem* catItem = addCatalogItem(catQuery.record());
		typeeQuery.exec(
			"SELECT typee_id, typee_name\n"
			"FROM Typee\n"
			"WHERE catalog_id IN (\n"
			"SELECT catalog_id\n"
			"FROM Catalogg\n"
			"WHERE catalog_name = '" + catItem->text(1) + "');"
			);
		while (typeeQuery.next()) // �������
			addTypeeItem(typeeQuery.value("typee_id").toString(), typeeQuery.value("typee_name").toString(),
				catItem);
	}

	ui.m_catalogTree->expandAll();
	ui.m_catalogTree->setSelectionMode(QAbstractItemView::ExtendedSelection);
}

QTreeWidgetItem * WinJournalCatalog::addCatalogItem(const QSqlRecord & typeRowRecord)
{
	return addCatalogItem(typeRowRecord.value("catalog_name").toString());
}

void WinJournalCatalog::updateCatState(QTreeWidgetItem * catItem)
{
	if (!catItem) return;
	int checkedCount = 0;
	for (int i = 0; i < catItem->childCount(); i++)
	{
		if (catItem->child(i)->checkState(1) == Qt::Checked)
			checkedCount++;
	}

	if (checkedCount == catItem->childCount())
		catItem->setCheckState(0, Qt::Checked);
	else if (checkedCount == 0)
		catItem->setCheckState(0, Qt::Unchecked);
	else
		catItem->setCheckState(0, Qt::PartiallyChecked);
}

QStringList WinJournalCatalog::getSelectedTyees()
{
	QStringList result;
	for (int i = 0; i < ui.m_catalogTree->topLevelItemCount(); i++)
	{
		QTreeWidgetItem* parent = ui.m_catalogTree->topLevelItem(i);
		if (parent->checkState(0) == Qt::Checked||parent->isSelected())
		{
			for (int j = 0; j < parent->childCount(); j++)
					result.append(parent->child(j)->text(1)); // ����
		}
		else
		{
			for (int j = 0; j < parent->childCount(); j++)
			{
				QTreeWidgetItem* child = parent->child(j);
				if (child->checkState(1) == Qt::Checked || child->isSelected()) 
				{
					result.append(child->text(1)); // ����
				}
			}
		}
	}

	return result;
}

QString WinJournalCatalog::bindSearchQuery(const QStringList & typee_names, const QStringList & journal_names, const QStringList & publisher_names)
{
	QString result = QString(
		"SELECT *\n"
		"FROM V_Journal\n"
		"WHERE journal_id != -1\n"
	);

	// ��typee_names
	QString typeeStr = "AND (";
	if (typee_names.size() > 0)
	{
		// ��ͷû��or
		typeeStr.append(QString("typee_name LIKE '%%1%'\n").arg(typee_names[0]));
		for (int i = 1; i < typee_names.size(); i++)
			typeeStr.append(QString("OR typee_name LIKE '%%1%'\n").arg(typee_names[i]));
		// ���Ҫ��������
		typeeStr.append(")");
		// ��ӵ�result����
		result.append(typeeStr);
	}

	// ��journal_names
	QString journalStr = "AND (";
	if (journal_names.size() > 0)
	{
		journalStr.append(QString("journal_name LIKE '%%1%'\n").arg(journal_names[0]));
		for (int i = 1; i < journal_names.size(); i++)
			journalStr.append(QString("OR journal_name LIKE '%%1%'\n").arg(journal_names[i]));
		journalStr.append(")");
		result.append(journalStr);
	}

	// ��publisher_names
	QString publisherStr = "AND (";
	if (publisher_names.size() > 0)
	{
		publisherStr.append(QString("publisher_name LIKE '%%1%'\n").arg(publisher_names[0]));
		for (int i = 1; i < publisher_names.size(); i++)
			publisherStr.append(QString("OR publisher_name LIKE '%%1%'\n").arg(publisher_names[i]));
		publisherStr.append(")");
		result.append(publisherStr);
	}
	if (typee_names.size() <= 0 && publisher_names.size() <= 0 && journal_names.size() <= 0)
		result.append("AND journal_id = -1");

	return result.append(";");
}

QTreeWidgetItem * WinJournalCatalog::addCatalogItem(const QString & catalogName)
{
	QTreeWidgetItem* catItem = new QTreeWidgetItem(NULL);
	catItem->setData(1, Qt::DisplayRole, catalogName);
	catItem->setText(1, catalogName);
	catItem->setCheckState(0, Qt::Unchecked); // һֱ�㲻��Ӷ��ٿ�ʼ
	catItem->setData(0, Qt::UserRole, 0); // �ۼ�ѡ�˵��ӽڵ���Ŀ
	ui.m_catalogTree->addTopLevelItem(catItem);
	return catItem;
}

QTreeWidgetItem * WinJournalCatalog::addTypeeItem(const QString & typee_id, const QString & typee_name, QTreeWidgetItem * fatherCatalog)
{
	QTreeWidgetItem* typeeItem = new QTreeWidgetItem(fatherCatalog);
	// ����ı���
	typeeItem->setData(1, Qt::DisplayRole, typee_name);
	typeeItem->setData(2, Qt::DisplayRole, typee_id);
	// ��Ӹ�ѡ��
	typeeItem->setCheckState(1, Qt::Unchecked);
	
	fatherCatalog->addChild(typeeItem);
	return typeeItem;
}


