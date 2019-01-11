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
	void renewContributorTable(const QString & qryMes = ""); // 更新投稿人tableView

signals:
	void paperClicked(int id, int tabIndex); // 显示对应的文章

private slots:
	void onBtnPaper(); // 查看文章
	void onDlgPaper(int, int); // 对话框里面
	void onShowStaff(int); // 根据unit对话框显示对应员工
	void onBtnPrint(); // 报表打印

	// 投稿人操作
	void onBtnAddContributor(); // 增加投稿人
	void onBtnDelContributor(); // 删除投稿人
	void onBtnContributor(); // 查看并编辑投稿人详情

	// 单位操作
	void onBtnAddUnit(); // 增加单位
	void onBtnDelUnit();
	void onBtnUnit(); 

	// 高级搜索
	void onBtnSearch();

	// 左边tree
	void onBtnShow(); // 根据treeWidget的单位和投稿人信息
	void onContributorSelChanged(QTreeWidgetItem*, int); // 复选框联动
	void onContributorItemSelcectionChanged(); // 人点击一下选择的

private:
	Ui::WinContributorCatalog ui;
	QSqlQueryModel* m_qryModel; // SELECT后显示

	// 右边投稿人信息table
	void initContributorTable(); // 初始化显示投稿人信息
	int getUnitIdFromTable();
	int getContributorIdFromTable();
	// 删除
	QList<int> getCheckedIds(bool isContributor); // table里面被选中的投稿人id
	void deleteRec(bool isContributor); // 删除unit或contributor

	// 左边单位投稿人目录tree
	// 初始化
	void initUnitTree(); // 初始化显示类型treeView
	QTreeWidgetItem* addUnitItem(int unit_id, const QString & unit_name);
	QTreeWidgetItem* addUnitItem(const QSqlRecord & contributorRowRecord);
	QTreeWidgetItem* addContributorItem(int contributor_id, const QString & contributor_name, QTreeWidgetItem* fatherCatalog = NULL);
	// 获取被选中的单位、投稿人编号
	QList<int> getSelectedUnitIds();
	QList<int> getSelectedContributorIds();
	// 复选框联动相关
	void updateUnitState(QTreeWidgetItem * contributorItem);

	// 搜索模块
	QString bindSearchQuery(const QStringList & unit_names, const QStringList & contributor_names);
	QString bindSearchQuery(const QList<int> & unit_ids = QList<int>(), 
		const QList<int> & contributor_ids = QList<int>()); // 精确搜索，多一个unit_ids是为了那种有unit没contributor的情况
	// query的执行就在onBtnSearch里面了
	
	// 新建与更新模块
	void insertSingleUnit(); // 新建单位
	void insertSingleContributor(); // 新建投稿人
	void updateSingleUnit();
	void updateSingleContributor();
	QString getUnitIdStr(const QString & unit_name);
	// 辅助
	int getNextUnitId(); // 下一个单位号码
	int getNextContributorId(); // 下一个投稿人号码
	bool isContributorIdDuplicated(int contributor_id); // 某个contributor_id是否重复
	bool isUnitIdDuplicated(int unit_id);
	bool isUnitNameDuplicated(const QString & unit_name);
};
