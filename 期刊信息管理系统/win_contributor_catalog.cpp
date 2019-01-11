#include "win_contributor_catalog.h"

WinContributorCatalog::WinContributorCatalog(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	initContributorTable();
	initUnitTree();

	// connect����ѡ��������catalog��ѡ��typee...��
	connect(ui.m_unitTree, SIGNAL(itemChanged(QTreeWidgetItem*, int)),
		this, SLOT(onContributorSelChanged(QTreeWidgetItem*, int)));
	// connect����������ʾ
	connect(ui.btn_show, SIGNAL(clicked()), this, SLOT(onBtnShow())); // ����
	connect(ui.m_unitTree, SIGNAL(itemSelectionChanged()), this, SLOT(onContributorItemSelcectionChanged()));
	// connect��ɾ�Ĳ�
	connect(ui.btn_unit, SIGNAL(clicked()), this, SLOT(onBtnUnit()));
	connect(ui.btn_addUnit, SIGNAL(clicked()), this, SLOT(onBtnAddUnit()));
	connect(ui.btn_delUnit, SIGNAL(clicked()), this, SLOT(onBtnDelUnit()));
	connect(ui.btn_contributor, SIGNAL(clicked()), this, SLOT(onBtnContributor()));
	connect(ui.btn_addContributor, SIGNAL(clicked()), this, SLOT(onBtnAddContributor()));
	connect(ui.btn_delContributor, SIGNAL(clicked()), this, SLOT(onBtnDelContributor()));
	// connect����
	connect(ui.btn_print, SIGNAL(clicked()), this, SLOT(onBtnPrint()));
	// connect����
	connect(ui.btn_search, SIGNAL(clicked()), this, SLOT(onBtnSearch()));
	// connetct�鿴����
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
	// �ȴ򿪱�����Model
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
	// ����ѯʧ��
	if (m_qryModel->lastError().isValid())
	{
		QMessageBox::critical(this, u8"����", u8"��ѯͶ��ͳ�ƴ���\n������Ϣ��" + m_qryModel->lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}

	// ����ѯ�ɹ���������data
	m_qryModel->setHeaderData(1, Qt::Horizontal, u8"��λ��");
	m_qryModel->setHeaderData(2, Qt::Horizontal, u8"��λ��");
	m_qryModel->setHeaderData(3, Qt::Horizontal, u8"Ͷ���˺�");
	m_qryModel->setHeaderData(4, Qt::Horizontal, u8"Ͷ������");
	m_qryModel->setHeaderData(5, Qt::Horizontal, u8"�ڿ���");
	m_qryModel->setHeaderData(6, Qt::Horizontal, u8"Ͷ����");

	// ���븴ѡ�����
	m_qryModel->insertColumn(0);

	ui.m_contributeTable->setModel(m_qryModel); // Ӧ��ģ����
	//ui.m_contributeTable->setColumnHidden(1, true);

	// ���븴ѡ��
	for (int i = 0; i < m_qryModel->rowCount(); i++)
		ui.m_contributeTable->setIndexWidget(m_qryModel->index(i, 0), new QCheckBox(this));

	ui.m_contributeTable->setColumnWidth(0, 60); // ���ø�ѡ����
	ui.m_contributeTable->setColumnWidth(1, 80); // ���õ�λ��ſ���
	ui.m_contributeTable->setColumnWidth(3, 80); // ����Ͷ���˱�ſ���
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
	SharedFunctions::makeReport(m_qryModel, ui.m_contributeTable, u8"Ͷ���˱�");
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
			QSqlRecord checkedRec = m_qryModel->record(i); // ��ǰѡ�еļ�¼
			ids.append(isContributor ? checkedRec.value("contributor_id").toInt() : \
				checkedRec.value("unit_id").toInt());
		}
	}

	return ids;
}

void WinContributorCatalog::deleteRec(bool isContributor)
{
	QList<int> ids = getCheckedIds(isContributor);

	// ȷ�϶Ի���
	QString dlgTitle = u8"ɾ��ȷ��";
	QString strInfo = QString(u8"�Ƿ�ɾ��ѡ�е�%1��%2����Ϣ").arg(ids.size()).\
		arg(isContributor ? u8"�ڿ�" : u8"���˵�λ");
	QMessageBox::StandardButton defaultBtn = QMessageBox::NoButton;
	QMessageBox::StandardButton result; // ����ѡ��
	result = QMessageBox::question(this, dlgTitle, strInfo, QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
		defaultBtn);

	// ��Ϊȷ����ɾ��
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
			QMessageBox::critical(this, u8"����", u8"ɾ��ʧ�ܣ�\n������Ϣ��" + m_qryModel->lastError().text(),
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
	QStringList nameList = { u8"", u8"����", u8"���" };
	ui.m_unitTree->setHeaderLabels(nameList);

	QSqlQuery unitQuery, contributorQuery;

	if (!unitQuery.exec("SELECT unit_id, unit_name FROM Unit ORDER BY unit_id; "))
	{
		QMessageBox::critical(this, u8"����", u8"��λĿ¼ͳ�ƴ���\n������Ϣ��" + m_qryModel->lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	while (unitQuery.next()) // ����Ӹ�
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
			QMessageBox::critical(this, u8"����", u8"Ͷ������ͳ�ƴ���\n������Ϣ��" + m_qryModel->lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
		}
		while (contributorQuery.next()) // �������
			addContributorItem(contributorQuery.value("contributor_id").toInt(), contributorQuery.value("contributor_name").toString(),
				unitItem);
	}
	// ����׫����
	QTreeWidgetItem* freeUnitItem = addUnitItem(-1, u8"δ��");
	contributorQuery.exec(
		"SELECT contributor_id, contributor_name\n"
		"FROM Contributor\n"
		"WHERE unit_id IS NULL;"
	);
	while (contributorQuery.next()) // �������
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
	// ����ı���
	contributorItem->setData(1, Qt::DisplayRole, contributor_name);
	contributorItem->setData(2, Qt::DisplayRole, contributor_id);
	// ��Ӹ�ѡ��
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
				result.append(parent->child(j)->text(2).toInt()); // Ͷ����id
		}
		else
		{
			for (int j = 0; j < parent->childCount(); j++)
			{
				QTreeWidgetItem* child = parent->child(j);
				if (child->checkState(1) == Qt::Checked || child->isSelected())
					result.append(child->text(2).toInt()); // Ͷ����id
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

	// ��unit_names
	QString unitStr = "AND (";
	if (unit_names.size() > 0)
	{
		// ��ͷû��or
		unitStr.append(QString("unit_name LIKE '%%1%'\n").arg(unit_names[0]));
		for (int i = 1; i < unit_names.size(); i++)
			unitStr.append(QString("OR unit_name LIKE '%%1%'\n").arg(unit_names[i]));
		// ���Ҫ��������
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
		// ���Ҫ��������
		contributorStr.append(")");
		// ��ӵ�result����
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
		// ������λδ����
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

		// ���Ͷ���˺��Ƿ��ظ�
		if (isUnitIdDuplicated(outRec.value("unit_id").toInt()) || isUnitNameDuplicated(outRec.value("unit_name").toString()))
		{
			QMessageBox::warning(this, u8"������λ�ظ�", u8"����������λ���ƻ��Ŷ������ظ�Ŷ��\n",
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}

		// ��ʼinsert
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
			QMessageBox::critical(this, u8"���˵�λ����", u8"��λ��������\n" + query.lastError().text(),
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

		// ���Ͷ���˺��Ƿ��ظ�
		if (isContributorIdDuplicated(outRec.value("contributor_id").toInt()))
		{
			QMessageBox::warning(this, u8"Ͷ���˺��ظ�", u8"����Ͷ���˺��ظ�����\n" ,
				QMessageBox::Ok, QMessageBox::NoButton);
			return;
		}

		// ȡ��λ��
		QString unit_id_str = getUnitIdStr(outRec.value("unit_name").toString());

		// ��ʼinsert
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
			QMessageBox::critical(this, u8"Ͷ���˴���", u8"Ͷ������������\n" + query.lastError().text(),
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
	// ��ȡ��ǰ��¼
	QSqlRecord currRec = m_qryModel->record(ui.m_contributeTable->currentIndex().row());
	// ��ȡ�ڿ���
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
	unitDlg->setEditRecord(currRec); // ���������ݵ���������Ϣ������
	int ret = unitDlg->exec(); // ģ̬����

	// ���³�������Ϣ���Ժ�Ҫ��Ϊunit_id�ģ�
	if (ret == QDialog::Accepted)
	{
		// ��ȡ���صļ�¼
		QSqlRecord recData = unitDlg->getNewData();
		// ��������
		query.prepare(u8"UPDATE Unit\n"
			"SET unit_name = :unit_name, "
			"unit_email = :unit_email, "
			"unit_phone = :unit_phone, "
			"unit_address = :unit_address " // �ǵ�û�ж��ţ�����
			"WHERE unit_id = :unit_id;" //�ǵ÷ֺţ�����
		);
		query.bindValue(":unit_name", recData.value("unit_name"));
		query.bindValue(":unit_email", recData.value("unit_email"));
		query.bindValue(":unit_phone", recData.value("unit_phone"));
		query.bindValue(":unit_address", recData.value("unit_address"));
		query.bindValue(":unit_id", unit_id);

		if (!query.exec())
		{
			QMessageBox::critical(this, "����", "���µ�λ��Ϣ����\n" + query.lastError().text(),
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
		QMessageBox::critical(this, u8"Ͷ���˴���", u8"Ͷ���˲�ѯ����\n" + query.lastError().text(),
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

		// ȡ��λ��
		QString unit_id_str = getUnitIdStr(outRec.value("unit_name").toString());

		// ���˿�ʼת��
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
			QMessageBox::critical(this, "Ͷ���˴���", "Ͷ���˸��´���\n" + query.lastError().text(),
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
	if (!query.first()) // һ����λ��û��
		unit_id_str = "Null";
	else
		unit_id_str = query.record().value("unit_id").toString(); // ��֪����ôת�в���
	return unit_id_str;
}
