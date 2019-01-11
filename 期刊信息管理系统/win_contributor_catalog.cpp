#include "win_contributor_catalog.h"

WinContributorCatalog::WinContributorCatalog(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	initContributorTable();
	initUnitTree();

	// connect类型选联动（父catalog必选子typee...）
	connect(ui.m_unitTree, SIGNAL(itemChanged(QTreeWidgetItem*, int)),
		this, SLOT(onContributorSelChanged(QTreeWidgetItem*, int)));
	// connect根据类型显示
	connect(ui.btn_show, SIGNAL(clicked()), this, SLOT(onBtnShow())); // 按键
	connect(ui.m_unitTree, SIGNAL(itemSelectionChanged()), this, SLOT(onContributorItemSelcectionChanged()));
	// connect增删改查
	connect(ui.btn_unit, SIGNAL(clicked()), this, SLOT(onBtnUnit()));
	connect(ui.btn_addUnit, SIGNAL(clicked()), this, SLOT(onBtnAddUnit()));
	connect(ui.btn_delUnit, SIGNAL(clicked()), this, SLOT(onBtnDelUnit()));
	connect(ui.btn_contributor, SIGNAL(clicked()), this, SLOT(onBtnContributor()));
	connect(ui.btn_addContributor, SIGNAL(clicked()), this, SLOT(onBtnAddContributor()));
	connect(ui.btn_delContributor, SIGNAL(clicked()), this, SLOT(onBtnDelContributor()));
	// connect报表
	connect(ui.btn_print, SIGNAL(clicked()), this, SLOT(onBtnPrint()));
	// connect搜索
	connect(ui.btn_search, SIGNAL(clicked()), this, SLOT(onBtnSearch()));
	// connetct查看文章
	connect(ui.btn_article, SIGNAL(clicked()), this, SLOT(onBtnPaper()));
}

void WinContributorCatalog::onBtnPaper()
{
	if (ui.m_contributeTable->currentIndex().row() < 0) return;
	QSqlRecord tmp = m_qryModel->record(ui.m_contributeTable->currentIndex().row());
	int contributor_id = tmp.value("contributor_id").toInt();
	int current_index = 1;
	emit paperClicked(contributor_id, current_index);
}

WinContributorCatalog::~WinContributorCatalog()
{
}

void WinContributorCatalog::renewContributorTable(const QString & qryMes)
{
	// 先打开表并创建Model
	m_qryModel = new QSqlQueryModel(this);
	QString theQryMes;

	if (qryMes == NULL || qryMes == "")
	{
		theQryMes = QString(
			"SELECT *\n"
			"FROM V_Contributor_Journal\n"
			"ORDER BY\n"
			"CASE WHEN unit_id IS NULL THEN 1 ELSE 0 END ASC,\n"
			"CASE WHEN contributor_id IS NULL THEN 1 ELSE 0 END ASC;"
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
		QMessageBox::critical(this, u8"错错错！", u8"查询投稿统计错误！\n错误信息：" + m_qryModel->lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}

	// 若查询成功，则设置data
	m_qryModel->setHeaderData(1, Qt::Horizontal, u8"单位号");
	m_qryModel->setHeaderData(2, Qt::Horizontal, u8"单位名");
	m_qryModel->setHeaderData(3, Qt::Horizontal, u8"投稿人号");
	m_qryModel->setHeaderData(4, Qt::Horizontal, u8"投稿人名");
	m_qryModel->setHeaderData(5, Qt::Horizontal, u8"期刊名");
	m_qryModel->setHeaderData(6, Qt::Horizontal, u8"投稿数");

	// 插入复选框的列
	m_qryModel->insertColumn(0);

	ui.m_contributeTable->setModel(m_qryModel); // 应用模型了
	//ui.m_contributeTable->setColumnHidden(1, true);

	// 插入复选框
	for (int i = 0; i < m_qryModel->rowCount(); i++)
		ui.m_contributeTable->setIndexWidget(m_qryModel->index(i, 0), new QCheckBox(this));

	ui.m_contributeTable->setColumnWidth(0, 60); // 设置复选框宽度
	ui.m_contributeTable->setColumnWidth(1, 80); // 设置单位编号框宽度
	ui.m_contributeTable->setColumnWidth(3, 80); // 设置投稿人编号框宽度
	ui.m_contributeTable->setSelectionMode(QAbstractItemView::SingleSelection);
}

void WinContributorCatalog::onDlgPaper(int id, int curr_index)
{
	emit paperClicked(id, curr_index);
}

void WinContributorCatalog::onShowStaff(int unit_id)
{
	qDebug() << unit_id;
	QString result = bindSearchQuery(QList<int>({ unit_id }));
	renewContributorTable(result);
}

void WinContributorCatalog::onBtnPrint()
{
	SharedFunctions::makeReport(m_qryModel, ui.m_contributeTable, u8"投稿人表");
}

void WinContributorCatalog::onBtnAddContributor()
{
	insertSingleContributor();
}

void WinContributorCatalog::onBtnDelContributor()
{
	deleteRec(true);
}

void WinContributorCatalog::onBtnContributor()
{
	updateSingleContributor();
}

void WinContributorCatalog::onBtnAddUnit()
{
	insertSingleUnit();
}

void WinContributorCatalog::onBtnDelUnit()
{
	deleteRec(false);
}

void WinContributorCatalog::onBtnUnit()
{
	updateSingleUnit();
}

void WinContributorCatalog::onBtnSearch()
{
	DSearchContributor* searchDlg = new DSearchContributor(this);
	int ret = searchDlg->exec();

	if (ret == QDialog::Accepted)
	{
		QStringList contributor_names = SharedFunctions::splitStr(searchDlg->getContributorNames());
		QStringList unit_names = SharedFunctions::splitStr(searchDlg->getUnitNames());

		QString qryStr = bindSearchQuery(unit_names, contributor_names);
		renewContributorTable(qryStr);
	}
}

void WinContributorCatalog::onBtnShow()
{
	QList<int> contributor_ids = getSelectedContributorIds();
	QList<int> unit_ids = getSelectedUnitIds();
	QString mes = bindSearchQuery(unit_ids, contributor_ids);
	renewContributorTable(mes);
}

void WinContributorCatalog::onContributorSelChanged(QTreeWidgetItem * item, int col)
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
		updateUnitState(parent);
	}
}

void WinContributorCatalog::onContributorItemSelcectionChanged()
{
	onBtnShow();
}

void WinContributorCatalog::initContributorTable()
{
	renewContributorTable();
}

QList<int> WinContributorCatalog::getCheckedIds(bool isContributor)
{
	QList<int> ids;

	for (int i = 0; i < m_qryModel->rowCount(); i++)
	{
		QCheckBox *checkBox = (QCheckBox *)ui.m_contributeTable->indexWidget(m_qryModel->index(i, 0));
		if (checkBox->isChecked())
		{
			QSqlRecord checkedRec = m_qryModel->record(i); // 当前选中的记录
			ids.append(isContributor ? checkedRec.value("contributor_id").toInt() : \
				checkedRec.value("unit_id").toInt());
		}
	}

	return ids;
}

void WinContributorCatalog::deleteRec(bool isContributor)
{
	QList<int> ids = getCheckedIds(isContributor);

	// 确认对话框
	QString dlgTitle = u8"删除确认";
	QString strInfo = QString(u8"是否删除选中的%1个%2的信息").arg(ids.size()).\
		arg(isContributor ? u8"期刊" : u8"用人单位");
	QMessageBox::StandardButton defaultBtn = QMessageBox::NoButton;
	QMessageBox::StandardButton result; // 返回选项
	result = QMessageBox::question(this, dlgTitle, strInfo, QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
		defaultBtn);

	// 若为确认则删除
	if (result == QMessageBox::Yes)
	{
		QString qryStr = QString(
			"DELETE\n"
			"FROM %1\n"
			"WHERE %2 IN("
		).arg(isContributor ? "Contributor" : "Unit").\
			arg(isContributor ? "contributor_id" : "unit_id");
		qryStr.append(QString::number(ids[0]));
		for (int i = 1; i < ids.size(); i++)
			qryStr.append(", " + QString::number(ids[i]));
		qryStr.append(");");

		QSqlQuery query;
		if (!query.exec(qryStr))
		{
			QMessageBox::critical(this, u8"错错错！", u8"删除失败！\n错误信息：" + m_qryModel->lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}
	}

	renewContributorTable();
	initUnitTree();
}

void WinContributorCatalog::initUnitTree()
{
	ui.m_unitTree->clear();
	ui.m_unitTree->setColumnCount(3);
	ui.m_unitTree->setColumnWidth(0, 60);
	QStringList nameList = { u8"", u8"名称", u8"编号" };
	ui.m_unitTree->setHeaderLabels(nameList);

	QSqlQuery unitQuery, contributorQuery;

	if (!unitQuery.exec("SELECT unit_id, unit_name FROM Unit ORDER BY unit_id; "))
	{
		QMessageBox::critical(this, u8"错错错！", u8"单位目录统计错误！\n错误信息：" + m_qryModel->lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	while (unitQuery.next()) // 外添加父
	{
		QTreeWidgetItem* unitItem = addUnitItem(unitQuery.record());
		contributorQuery.prepare(
			"SELECT contributor_id, contributor_name\n"
			"FROM Contributor\n"
			"WHERE unit_id IN (\n"
			"SELECT unit_id\n"
			"FROM Unit\n"
			"WHERE unit_id = :unit_id);"
		);
		contributorQuery.bindValue(":unit_id", unitItem->text(0).toInt());
		if (!contributorQuery.exec())
		{
			QMessageBox::critical(this, u8"错错错！", u8"投稿人项统计错误！\n错误信息：" + m_qryModel->lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
		}
		while (contributorQuery.next()) // 内添加子
			addContributorItem(contributorQuery.value("contributor_id").toInt(), contributorQuery.value("contributor_name").toString(),
				unitItem);
	}
	// 自由撰稿人
	QTreeWidgetItem* freeUnitItem = addUnitItem(-1, u8"未定");
	contributorQuery.exec(
		"SELECT contributor_id, contributor_name\n"
		"FROM Contributor\n"
		"WHERE unit_id IS NULL;"
	);
	while (contributorQuery.next()) // 内添加子
		addContributorItem(contributorQuery.value("contributor_id").toInt(), contributorQuery.value("contributor_name").toString(),
			freeUnitItem);


	ui.m_unitTree->expandAll();
	ui.m_unitTree->setSelectionMode(QAbstractItemView::ExtendedSelection);
}

QTreeWidgetItem * WinContributorCatalog::addUnitItem(const QSqlRecord & contributorRowRecord)
{
	return addUnitItem(contributorRowRecord.value("unit_id").toInt(), 
		contributorRowRecord.value("unit_name").toString());
}

QTreeWidgetItem * WinContributorCatalog::addUnitItem(int unit_id, const QString & unit_name)
{
	QTreeWidgetItem* unitItem = new QTreeWidgetItem(NULL);
	if (unit_id > 0)
	{
		unitItem->setText(0, QString::number(unit_id));
		unitItem->setData(0, Qt::UserRole, unit_id);
	}
	unitItem->setCheckState(0, Qt::Unchecked); 
	unitItem->setText(1, unit_name);
	ui.m_unitTree->addTopLevelItem(unitItem);
	return unitItem;
}

QTreeWidgetItem * WinContributorCatalog::addContributorItem(int contributor_id, const QString & contributor_name, QTreeWidgetItem * fatherCatalog)
{
	QTreeWidgetItem* contributorItem = new QTreeWidgetItem(fatherCatalog);
	// 添加文本等
	contributorItem->setData(1, Qt::DisplayRole, contributor_name);
	contributorItem->setData(2, Qt::DisplayRole, contributor_id);
	// 添加复选框
	contributorItem->setCheckState(1, Qt::Unchecked);

	fatherCatalog->addChild(contributorItem);
	return contributorItem;
}

QList<int> WinContributorCatalog::getSelectedUnitIds()
{
	QList<int> result;
	for (int i = 0; i < ui.m_unitTree->topLevelItemCount() ; i++)
	{
		if (ui.m_unitTree->topLevelItem(i)->isSelected())
			result.append(ui.m_unitTree->topLevelItem(i)->text(0).toInt());
	}
	return result;
}

QList<int> WinContributorCatalog::getSelectedContributorIds()
{
	QList<int> result;
	for (int i = 0; i < ui.m_unitTree->topLevelItemCount(); i++)
	{
		QTreeWidgetItem* parent = ui.m_unitTree->topLevelItem(i);
		if (parent->checkState(0) == Qt::Checked || parent->isSelected())
		{
			for (int j = 0; j < parent->childCount(); j++)
				result.append(parent->child(j)->text(2).toInt()); // 投稿人id
		}
		else
		{
			for (int j = 0; j < parent->childCount(); j++)
			{
				QTreeWidgetItem* child = parent->child(j);
				if (child->checkState(1) == Qt::Checked || child->isSelected())
					result.append(child->text(2).toInt()); // 投稿人id
			}
		}
	}

	return result;
}

void WinContributorCatalog::updateUnitState(QTreeWidgetItem * unitItem)
{
	if (!unitItem) return;
	int checkedCount = 0;
	for (int i = 0; i < unitItem->childCount(); i++)
	{
		if (unitItem->child(i)->checkState(1) == Qt::Checked)
			checkedCount++;
	}

	if (checkedCount == unitItem->childCount())
		unitItem->setCheckState(0, Qt::Checked);
	else if (checkedCount == 0)
		unitItem->setCheckState(0, Qt::Unchecked);
	else
		unitItem->setCheckState(0, Qt::PartiallyChecked);
}

QString WinContributorCatalog::bindSearchQuery(const QStringList & unit_names, const QStringList & contributor_names)
{
	QString result = QString(
		"SELECT *\n"
		"FROM V_Contributor_Journal\n"
		"WHERE contributor_id != -1\n"
	);

	// 先unit_names
	QString unitStr = "AND (";
	if (unit_names.size() > 0)
	{
		// 开头没有or
		unitStr.append(QString("unit_name LIKE '%%1%'\n").arg(unit_names[0]));
		for (int i = 1; i < unit_names.size(); i++)
			unitStr.append(QString("OR unit_name LIKE '%%1%'\n").arg(unit_names[i]));
		// 最后还要加上括号
		unitStr.append(")");
		// 添加到result里面
		result.append(unitStr);
	}

	// 后contributor_names
	QString contributorStr = "AND (";
	if (contributor_names.size() > 0)
	{
		// 开头没有or
		contributorStr.append(QString("contributor_name LIKE '%%1%'\n").arg(contributor_names[0]));
		for (int i = 1; i < contributor_names.size(); i++)
			contributorStr.append(QString("OR contributor_name LIKE '%%1%'\n").arg(contributor_names[i]));
		// 最后还要加上括号
		contributorStr.append(")");
		// 添加到result里面
		result.append(contributorStr);
	}
	
	if (unit_names.size() <= 0 && contributor_names.size() <= 0)
		result.append("AND contributor_id == -1");

	return result.append(";");
}

QString WinContributorCatalog::bindSearchQuery(const QList<int> & unit_ids, const QList<int> & contributor_ids)
{
	QString selected_ids, selected_unit_ids;
	QString qryStr = QString(
		"SELECT *\n"
		"FROM V_Contributor_Journal\n"
		"WHERE contributor_id = -1\n"
	);

	if (contributor_ids.size() > 0)
	{
		selected_ids.append(QString::number(contributor_ids[0]));
		for (int i = 1; i < contributor_ids.size(); i++)
			selected_ids.append("," + QString::number(contributor_ids[i]));
		qryStr.append(QString("OR contributor_id IN(" + selected_ids + ")\n"));
	}
	if (unit_ids.size() > 0)
	{
		selected_unit_ids.append(QString::number(unit_ids[0]));
		for (int i = 1; i < unit_ids.size(); i++)
			selected_unit_ids.append("," + QString::number(unit_ids[i]));
		qryStr.append(QString("OR unit_id IN (" + selected_unit_ids + ")\n"));
		// 工作单位未定的
		for (int i = 0; i < unit_ids.size(); i++)
		{
			if (unit_ids[i] <= 0)
			{
				qryStr.append(QString("OR unit_id IS NULL"));
				break;
			}
		}
	}
	if(contributor_ids.size() <= 0 && unit_ids.size() <= 0)
		qryStr.append(QString("AND unit_id = -1\n"));
	return qryStr;
}

int WinContributorCatalog::getNextUnitId()
{
	QSqlQuery query;
	query.exec("SELECT MAX(unit_id) max_unit_id FROM Unit;");
	query.first();

	return query.record().value("max_unit_id").toInt() + 1;
}

int WinContributorCatalog::getNextContributorId()
{
	QSqlQuery query;
	query.exec("SELECT MAX(contributor_id) max_contributor_id FROM Contributor;");
	query.first();

	return query.record().value("max_contributor_id").toInt() + 1;
}

bool WinContributorCatalog::isContributorIdDuplicated(int contributor_id)
{
	QSqlQuery query;
	query.prepare("SELECT * FROM Contributor WHERE contributor_id = :contributor_id;");
	query.bindValue(":contributor_id", contributor_id);
	query.exec();
	return query.first();
}

bool WinContributorCatalog::isUnitIdDuplicated(int unit_id)
{
	QSqlQuery query;
	query.prepare("SELECT * FROM Unit WHERE unit_id = :unit_id;");
	query.bindValue(":unit_id", unit_id);
	query.exec();
	return query.first();
}

bool WinContributorCatalog::isUnitNameDuplicated(const QString & unit_name)
{
	QSqlQuery query;
	query.exec("SELECT * FROM Unit WHERE unit_name = " + unit_name + ";");
	return query.first();
}

void WinContributorCatalog::insertSingleUnit()
{
	QSqlQuery query;
	query.exec("SELECT * FROM Unit;");
	query.first();

	QSqlRecord inRec = query.record();
	inRec.setValue("unit_id", getNextUnitId());
	DUnitInfo* unitDlg = new DUnitInfo(this);
	unitDlg->setInsertRecord(inRec);

	int ret = unitDlg->exec();
	if (ret == QDialog::Accepted)
	{
		QSqlRecord outRec = unitDlg->getNewData();

		// 检查投稿人号是否重复
		if (isUnitIdDuplicated(outRec.value("unit_id").toInt()) || isUnitNameDuplicated(outRec.value("unit_name").toString()))
		{
			QMessageBox::warning(this, u8"工作单位重复", u8"新增工作单位名称或编号都不能重复哦！\n",
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}

		// 开始insert
		query.prepare(
			"INSERT INTO Unit(unit_id, unit_name, unit_email, unit_phone, unit_address)\n"
			"VALUES (:unit_id, :unit_name, :unit_email, :unit_phone, :unit_address);"
		);
		query.bindValue(":unit_name", outRec.value("unit_name"));
		query.bindValue(":unit_email", outRec.value("unit_email"));
		query.bindValue(":unit_id", outRec.value("unit_id"));
		query.bindValue(":unit_phone", outRec.value("unit_phone"));
		query.bindValue(":unit__address", outRec.value("unit_address"));
		if (!query.exec())
		{
			QMessageBox::critical(this, u8"用人单位错误", u8"单位新增错误\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}

		renewContributorTable();
		initUnitTree();
	}
	delete unitDlg;
}

void WinContributorCatalog::insertSingleContributor()
{
	QSqlQuery query;
	query.exec(
		"SELECT C.*, CV.*\n"
		"FROM V_Contributor CV, Contributor C\n"
		"WHERE CV.contributor_id = C.contributor_id;"
	);
	query.first();

	QSqlRecord inRec = query.record();
	inRec.setValue("contributor_id", getNextContributorId());
	DContributorInfo* conDlg = new DContributorInfo(this);
	conDlg->setInsertRecord(inRec);

	int ret = conDlg->exec();
	if (ret == QDialog::Accepted)
	{
		QSqlRecord outRec = conDlg->getNewData();

		// 检查投稿人号是否重复
		if (isContributorIdDuplicated(outRec.value("contributor_id").toInt()))
		{
			QMessageBox::warning(this, u8"投稿人号重复", u8"新增投稿人号重复啦！\n" ,
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}

		// 取单位号
		QString unit_id_str = getUnitIdStr(outRec.value("unit_name").toString());

		// 开始insert
		query.prepare(
			"INSERT INTO Contributor(contributor_id, contributor_name, contributor_email, contributor_phone, unit_id)\n"
			"VALUES (:contributor_id, :contributor_name, :contributor_email, :contributor_phone, " + unit_id_str +");"
		);
		query.bindValue(":contributor_name", outRec.value("contributor_name"));
		query.bindValue(":contributor_email", outRec.value("contributor_email"));
		query.bindValue(":contributor_id", outRec.value("contributor_id"));
		query.bindValue(":contributor_phone", outRec.value("contributor_phone"));
		if (!query.exec())
		{
			QMessageBox::critical(this, u8"投稿人错误", u8"投稿人新增错误\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}

		renewContributorTable();
		initUnitTree();
	}
	delete conDlg;
}

void WinContributorCatalog::updateSingleUnit()
{
	// 获取当前记录
	QSqlRecord currRec = m_qryModel->record(ui.m_contributeTable->currentIndex().row());
	// 获取期刊号
	int unit_id = currRec.value("unit_id").toInt();

	QSqlQuery query;
	query.prepare(u8"SELECT * FROM Unit WHERE unit_id = :unit_id;");
	query.bindValue(":unit_id", unit_id);
	query.exec();
	query.first();
	if (!query.isValid())
	{
		qDebug() << "search unit not ok";
		return;
	}

	currRec = query.record();
	DUnitInfo* unitDlg = new DUnitInfo(this);
	connect(unitDlg, SIGNAL(showStaff(int)), this, SLOT(onShowStaff(int)));
	unitDlg->setEditRecord(currRec); // 设置新数据到出版社信息框里面
	int ret = unitDlg->exec(); // 模态窗口

	// 更新出版社信息（以后要改为unit_id的）
	if (ret == QDialog::Accepted)
	{
		// 获取返回的记录
		QSqlRecord recData = unitDlg->getNewData();
		// 更新数据
		query.prepare(u8"UPDATE Unit\n"
			"SET unit_name = :unit_name, "
			"unit_email = :unit_email, "
			"unit_phone = :unit_phone, "
			"unit_address = :unit_address " // 记得没有逗号！！！
			"WHERE unit_id = :unit_id;" //记得分号！！！
		);
		query.bindValue(":unit_name", recData.value("unit_name"));
		query.bindValue(":unit_email", recData.value("unit_email"));
		query.bindValue(":unit_phone", recData.value("unit_phone"));
		query.bindValue(":unit_address", recData.value("unit_address"));
		query.bindValue(":unit_id", unit_id);

		if (!query.exec())
		{
			QMessageBox::critical(this, "错错错", "更新单位信息错误！\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}
		renewContributorTable();
		initUnitTree();
	}

	delete unitDlg;
}

void WinContributorCatalog::updateSingleContributor()
{
	if (ui.m_contributeTable->currentIndex().row() < 0) return;
	QSqlRecord tmp = m_qryModel->record(ui.m_contributeTable->currentIndex().row());
	int contributor_id = tmp.value("contributor_id").toInt();

	QSqlQuery query;
	query.prepare(
		"SELECT C.*, CV.*\n"
		"FROM V_Contributor CV, Contributor C\n"
		"WHERE CV.contributor_id = C.contributor_id\n"
		"AND C.contributor_id = :contributor_id;"
	);
	query.bindValue(":contributor_id", contributor_id);
	if (!query.exec())
	{
		QMessageBox::critical(this, u8"投稿人错误", u8"投稿人查询错误\n" + query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}

	query.first();
	QSqlRecord inRec = query.record();
	DContributorInfo* conDlg = new DContributorInfo(this);
	conDlg->setEditRecord(inRec);
	connect(conDlg, SIGNAL(toShowPaper(int, int)), this, SLOT(onDlgPaper(int, int)));

	int ret = conDlg->exec();
	if (ret == QDialog::Accepted)
	{
		QSqlRecord outRec = conDlg->getNewData();

		// 取单位号
		QString unit_id_str = getUnitIdStr(outRec.value("unit_name").toString());

		// 好了开始转了
		query.prepare(
			"UPDATE Contributor\n"
			"SET unit_id = " + unit_id_str + ",\n"
			"contributor_name = :contributor_name,\n"
			"contributor_phone = :contributor_phone,\n"
			"contributor_email = :contributor_email\n"
			"WHERE contributor_id = :contributor_id;"
		);
		query.bindValue(":contributor_name", outRec.value("contributor_name"));
		query.bindValue(":contributor_phone", outRec.value("contributor_phone"));
		query.bindValue(":contributor_email", outRec.value("contributor_email"));
		query.bindValue(":contributor_id", contributor_id);
		if (!query.exec())
		{
			QMessageBox::critical(this, "投稿人错误", "投稿人更新错误\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}
		renewContributorTable();
		initUnitTree();
	}
	delete conDlg;
}

QString WinContributorCatalog::getUnitIdStr(const QString & unit_name)
{
	QString unit_id_str;
	QSqlQuery query;

	query.prepare("SELECT unit_id FROM Unit WHERE unit_name = :unit_name;");
	query.bindValue(":unit_name", unit_name);
	query.exec();
	if (!query.first()) // 一个单位都没有
		unit_id_str = "Null";
	else
		unit_id_str = query.record().value("unit_id").toString(); // 不知道这么转行不行
	return unit_id_str;
}
