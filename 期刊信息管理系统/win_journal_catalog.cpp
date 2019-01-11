#include "win_journal_catalog.h"

WinJournalCatalog::WinJournalCatalog(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	initJournalTable();
	initTypeTree();

	// connect显示详情
	connect(ui.btn_journalInfo, SIGNAL(clicked()), this, SLOT(onBtnJournalInfo()));
	// connect增删改
	connect(ui.btn_add, SIGNAL(clicked()), this, SLOT(onBtnAdd()));
	connect(ui.btn_delete, SIGNAL(clicked()), this, SLOT(onBtnDelete()));
	connect(ui.btn_search, SIGNAL(clicked()), this, SLOT(onBtnSearch()));
	// connect类型选联动（父catalog必选子typee...）
	connect(ui.m_catalogTree, SIGNAL(itemChanged(QTreeWidgetItem*, int)), 
		this, SLOT(onTypeeSelChanged(QTreeWidgetItem*, int)));
	// connect根据类型显示
	connect(ui.btn_show, SIGNAL(clicked()), this, SLOT(onBtnShow())); // 按键
	connect(ui.m_catalogTree, SIGNAL(itemSelectionChanged()), this, SLOT(onTypeeItemSelcectionChanged()));
	// connect文章
	connect(ui.btn_article, SIGNAL(clicked()), this, SLOT(onBtnPaper()));
	// connect打印报表
	connect(ui.btn_print, SIGNAL(clicked()), this, SLOT(onBtnPrint()));
}

WinJournalCatalog::~WinJournalCatalog()
{
}

void WinJournalCatalog::renewJournalTable(const QString & qryMes) // 可以为NULL
{
	// 先打开表并创建Model
	m_qryModel = new QSqlQueryModel(this);
	QString theQryMes;

	if (qryMes == NULL || qryMes == "")
	{
		theQryMes = QString(
			// 到时还要考虑editor_id空的情况
			"SELECT * FROM V_Journal;"
		);
	}
	else
	{
		theQryMes = qryMes;
	}

	m_qryModel->setQuery(theQryMes);
	// 若查询失败
	if (m_qryModel->lastError().isValid())
	{
		QMessageBox::critical(this, "错错错！", "打开期刊表错误！\n错误信息：" + m_qryModel->lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}

	// 若查询成功，则设置data
	m_qryModel->setHeaderData(1, Qt::Horizontal, u8"期刊号");
	m_qryModel->setHeaderData(2, Qt::Horizontal, u8"期刊名");
	m_qryModel->setHeaderData(3, Qt::Horizontal, u8"类型");
	m_qryModel->setHeaderData(4, Qt::Horizontal, u8"出版社");
	m_qryModel->setHeaderData(5, Qt::Horizontal, u8"主编");
	m_qryModel->setHeaderData(6, Qt::Horizontal, u8"最新出版日期");

	// 插入复选框的列
	m_qryModel->insertColumn(0);

	ui.m_journalTable->setModel(m_qryModel); // 应用模型了

	for (int i = 0; i < m_qryModel->rowCount(); i++)
	{
		// 插入复选框
		ui.m_journalTable->setIndexWidget(m_qryModel->index(i, 0), new QCheckBox(this));
		// 设置居中（但没有成功uuu）
		/*for (int j = 0; j < m_qryModel->columnCount(); j++)
			m_qryModel->setData(m_qryModel->index(i, j), Qt::AlignHCenter, Qt::TextAlignmentRole);*/
	}
	ui.m_journalTable->setColumnWidth(0, 60); // 设置复选框宽度
	ui.m_journalTable->setColumnWidth(1, 100); // 设置编号框宽度
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
	SharedFunctions::makeReport(m_qryModel, ui.m_journalTable, u8"期刊报表");
}

void WinJournalCatalog::onBtnJournalInfo()
{
	// 获取当前记录
	QSqlRecord currRec = m_qryModel->record(ui.m_journalTable->currentIndex().row());
	// 获取期刊号
	int journal_id = currRec.value("journal_id").toInt();

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

	// 暂存当前主编号，应对更新重名主编的情况
	int old_editor_id = getEditorIdFromJournal(journal_id); // 必须是动态的

	// 根据查询结果弹出更新对话框
	currRec = query.record();
	DJournalInfo* journalDialog = new DJournalInfo(this);
	journalDialog->setEditRecord(currRec);
	connect(journalDialog, SIGNAL(toShowPaper(int, int)), this, SLOT(onDlgPaper(int, int)));
	connect(journalDialog, SIGNAL(toShowJournal(int)), this, SLOT(onToShowJournal(int)));
	int ret = journalDialog->exec();

	// 更新编辑完成后
	if (ret == QDialog::Accepted)
	{
		QSqlRecord outRec = journalDialog->getNewData();

		// 获取分类号
		qryStr = QString(
			"SELECT typee_id\n"
			"FROM Typee\n"
			"WHERE typee_name = :typee_name;"
		);
		query.prepare(qryStr);
		query.bindValue(":typee_name", outRec.value("typee_name"));
		if (!query.exec())
		{
			QMessageBox::critical(this, "类型错误", "类型id查询错误\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}
		query.first();
		QString typee_id = query.record().value("typee_id").toString();

		// 从名字获取主编号
		//int new_editor_id = journalDialog->getEditorIdFromName(outRec.value("editor_name").toString(), old_editor_id);

		// 更新journal表
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
			QMessageBox::critical(this, "更新错误", "记录更新错误\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}
		renewJournalTable(); // 重新更新
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

	// 确认对话框
	QString dlgTitle = u8"删除确认";
	QString strInfo = QString(u8"是否删除选中的%1个期刊的信息").arg(journal_ids.size());
	QMessageBox::StandardButton defaultBtn = QMessageBox::NoButton;
	QMessageBox::StandardButton result; // 返回选项
	result = QMessageBox::question(this, dlgTitle, strInfo, QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
		defaultBtn);

	// 若为确认则删除
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
			QMessageBox::critical(this, u8"错错错！", u8"删除期刊失败！\n错误信息：" + m_qryModel->lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}
	}

	// 刷新
	renewJournalTable();
}

void WinJournalCatalog::onBtnSearch()
{
	DSearchJournal* searchDlg = new DSearchJournal(this);
	int ret = searchDlg->exec();

	if (ret == QDialog::Accepted)
	{
		// 把待搜索关键字分成词（按照空格和";,.()<>?|{}"这些符号）
		QStringList journal_names = SharedFunctions::splitStr(searchDlg->getJournalNames());
		QStringList typee_names = SharedFunctions::splitStr(searchDlg->getTypees());
		QStringList publisher_names = SharedFunctions::splitStr(searchDlg->getPublishers());

		// 合成搜索语句
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

	//若变化的是父catalog
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
	// 若变化的是子typee
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
		QMessageBox::critical(this, "获取主编号错误", "主编id查询错误\n" + query.lastError().text(),
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
			QSqlRecord checkedRec = m_qryModel->record(i); // 当前选中的记录
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
	// 随便获得一个record，后面传入insert对话框里头，再在里面插入新的数据
	QString qryStr = QString(
		"SELECT J.journal_id, J.journal_name, J.new_publish_date, C.catalog_name, T.*, E.*\n"
		"FROM Journal AS J, Editor AS E, Typee AS T, Catalogg AS C\n"
		//"WHERE journal_id = :journal_id\n" --他不会返回全NULL的记录，而是没有记录；没办法传参，就很尴尬了
	);
	QSqlQuery query;
	query.prepare(qryStr);
	query.bindValue(":journal_id", getNextJournalId());
	query.exec();
	query.first();
	if (!query.isValid())
		return;

	// 根据查询结果弹出更新对话框
	QSqlRecord currRec = query.record();
	currRec.setValue("journal_id", getNextJournalId());
	DJournalInfo* journalDialog = new DJournalInfo(this);
	journalDialog->setInsertRecord(currRec);
	int ret = journalDialog->exec();

	// 对话框编辑完成后
	if (ret == QDialog::Accepted)
	{
		QSqlRecord recData = journalDialog->getNewData();

		// 获取分类号
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
			QMessageBox::critical(this, "类型错误", "类型id查询错误\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}
		query.first();
		QString typee_id = query.record().value("typee_id").toString();
		qDebug() << query.record().value("typee_id").toString();

		// 从名字获取主编号
		int new_editor_id = journalDialog->getEditorIdFromName(recData.value("editor_name").toString());
		// 如果没有改变就不用再获取咯

		if (!new_editor_id)
		{
			QMessageBox::warning(this, "主编不存在的", "不存在的主编\n",
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}

		// 更新journal表
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
			QMessageBox::critical(this, u8"添加期刊错误", "记录插入错误\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}
		renewJournalTable(); // 重新更新
	}
	delete journalDialog;

}

void WinJournalCatalog::initTypeTree()
{
	ui.m_catalogTree->clear();
	ui.m_catalogTree->setColumnCount(3);
	ui.m_catalogTree->setColumnWidth(0, 60);
	QStringList headers = { "", u8"编目及类型", u8"类型编号" };
	ui.m_catalogTree->setHeaderLabels(headers);

	QSqlQuery catQuery, typeeQuery;

	catQuery.exec("SELECT catalog_name FROM Catalogg ORDER BY catalog_id; ");
	while (catQuery.next()) // 先添加父
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
		while (typeeQuery.next()) // 后添加子
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
					result.append(parent->child(j)->text(1)); // 类名
		}
		else
		{
			for (int j = 0; j < parent->childCount(); j++)
			{
				QTreeWidgetItem* child = parent->child(j);
				if (child->checkState(1) == Qt::Checked || child->isSelected()) 
				{
					result.append(child->text(1)); // 类名
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

	// 先typee_names
	QString typeeStr = "AND (";
	if (typee_names.size() > 0)
	{
		// 开头没有or
		typeeStr.append(QString("typee_name LIKE '%%1%'\n").arg(typee_names[0]));
		for (int i = 1; i < typee_names.size(); i++)
			typeeStr.append(QString("OR typee_name LIKE '%%1%'\n").arg(typee_names[i]));
		// 最后还要加上括号
		typeeStr.append(")");
		// 添加到result里面
		result.append(typeeStr);
	}

	// 中journal_names
	QString journalStr = "AND (";
	if (journal_names.size() > 0)
	{
		journalStr.append(QString("journal_name LIKE '%%1%'\n").arg(journal_names[0]));
		for (int i = 1; i < journal_names.size(); i++)
			journalStr.append(QString("OR journal_name LIKE '%%1%'\n").arg(journal_names[i]));
		journalStr.append(")");
		result.append(journalStr);
	}

	// 后publisher_names
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
	catItem->setCheckState(0, Qt::Unchecked); // 一直搞不清从多少开始
	catItem->setData(0, Qt::UserRole, 0); // 累加选了的子节点数目
	ui.m_catalogTree->addTopLevelItem(catItem);
	return catItem;
}

QTreeWidgetItem * WinJournalCatalog::addTypeeItem(const QString & typee_id, const QString & typee_name, QTreeWidgetItem * fatherCatalog)
{
	QTreeWidgetItem* typeeItem = new QTreeWidgetItem(fatherCatalog);
	// 添加文本等
	typeeItem->setData(1, Qt::DisplayRole, typee_name);
	typeeItem->setData(2, Qt::DisplayRole, typee_id);
	// 添加复选框
	typeeItem->setCheckState(1, Qt::Unchecked);
	
	fatherCatalog->addChild(typeeItem);
	return typeeItem;
}


