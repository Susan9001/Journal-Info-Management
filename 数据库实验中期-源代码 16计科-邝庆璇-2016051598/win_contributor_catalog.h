#pragma once

#include <QWidget>
#include <QtSql>
#include <QDataWidgetMapper>
#include <QItemSelectionModel>
#include <QMessageBox>
#include <QCheckBox>
#include <QSqlQuery>
#include <QSqlTableModel>
#include "ui_win_contributor_catalog.h"
#include "d_contributor_info.h"
#include "d_unit_info.h"
#include "d_search_contributor.h"
#include "shared_functions.h"

class WinContributorCatalog : public QWidget
{
	Q_OBJECT

public:
	WinContributorCatalog(QWidget *parent = Q_NULLPTR);
	~WinContributorCatalog();
	void renewContributorTable(const QString & qryMes = ""); // ����Ͷ����tableView

signals:
	void paperClicked(int id, int tabIndex); // ��ʾ��Ӧ������

private slots:
	void onBtnPaper(); // �鿴����
	void onDlgPaper(int, int); // �Ի�������
	void onShowStaff(int); // ����unit�Ի�����ʾ��ӦԱ��
	void onBtnPrint(); // �����ӡ

	// Ͷ���˲���
	void onBtnAddContributor(); // ����Ͷ����
	void onBtnDelContributor(); // ɾ��Ͷ����
	void onBtnContributor(); // �鿴���༭Ͷ��������

	// ��λ����
	void onBtnAddUnit(); // ���ӵ�λ
	void onBtnDelUnit();
	void onBtnUnit(); 

	// �߼�����
	void onBtnSearch();

	// ���tree
	void onBtnShow(); // ����treeWidget�ĵ�λ��Ͷ������Ϣ
	void onContributorSelChanged(QTreeWidgetItem*, int); // ��ѡ������
	void onContributorItemSelcectionChanged(); // �˵��һ��ѡ���

private:
	Ui::WinContributorCatalog ui;
	QSqlQueryModel* m_qryModel; // SELECT����ʾ

	// �ұ�Ͷ������Ϣtable
	void initContributorTable(); // ��ʼ����ʾͶ������Ϣ
	int getUnitIdFromTable();
	int getContributorIdFromTable();
	// ɾ��
	QList<int> getCheckedIds(bool isContributor); // table���汻ѡ�е�Ͷ����id
	void deleteRec(bool isContributor); // ɾ��unit��contributor

	// ��ߵ�λͶ����Ŀ¼tree
	// ��ʼ��
	void initUnitTree(); // ��ʼ����ʾ����treeView
	QTreeWidgetItem* addUnitItem(int unit_id, const QString & unit_name);
	QTreeWidgetItem* addUnitItem(const QSqlRecord & contributorRowRecord);
	QTreeWidgetItem* addContributorItem(int contributor_id, const QString & contributor_name, QTreeWidgetItem* fatherCatalog = NULL);
	// ��ȡ��ѡ�еĵ�λ��Ͷ���˱��
	QList<int> getSelectedUnitIds();
	QList<int> getSelectedContributorIds();
	// ��ѡ���������
	void updateUnitState(QTreeWidgetItem * contributorItem);

	// ����ģ��
	QString bindSearchQuery(const QStringList & unit_names, const QStringList & contributor_names);
	QString bindSearchQuery(const QList<int> & unit_ids = QList<int>(), 
		const QList<int> & contributor_ids = QList<int>()); // ��ȷ��������һ��unit_ids��Ϊ��������unitûcontributor�����
	// query��ִ�о���onBtnSearch������
	
	// �½������ģ��
	void insertSingleUnit(); // �½���λ
	void insertSingleContributor(); // �½�Ͷ����
	void updateSingleUnit();
	void updateSingleContributor();
	QString getUnitIdStr(const QString & unit_name);
	// ����
	int getNextUnitId(); // ��һ����λ����
	int getNextContributorId(); // ��һ��Ͷ���˺���
	bool isContributorIdDuplicated(int contributor_id); // ĳ��contributor_id�Ƿ��ظ�
	bool isUnitIdDuplicated(int unit_id);
	bool isUnitNameDuplicated(const QString & unit_name);
};
