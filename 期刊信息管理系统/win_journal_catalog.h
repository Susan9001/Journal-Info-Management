#pragma once

#include <QWidget>
#include <QtSql>
#include <QDataWidgetMapper>
#include <QItemSelectionModel>
#include <QMessageBox>
#include <QCheckBox>
#include <QSqlQuery>
#include <QSqlTableModel>
#include "ui_win_journal_catalog.h"
#include "d_journal_info.h"
#include "d_search_journal.h"
#include "shared_functions.h"

class WinJournalCatalog : public QWidget
{
	Q_OBJECT

public:
	WinJournalCatalog(QWidget *parent = Q_NULLPTR);
	~WinJournalCatalog();
	void renewJournalTable(const QString & qryMes = ""); // 更新期刊tableView

signals:
	void paperClicked(int id, int tabIndex); // 显示对应的文章
	void editorJournalClicked(); // 回显editor的journal

private slots:
	void onBtnPaper(); // 查看文章
	void onDlgPaper(int, int); // 对话框里面
	void onBtnPrint(); // 报表打印

	void onBtnJournalInfo(); // 查看并编辑期刊详情
	void onBtnAdd(); // 增加期刊
	void onBtnDelete(); // 删除期刊
	void onBtnSearch(); // 高级搜索
	void onBtnShow(); // 根据类型treeWidget筛选期刊
	void onTypeeSelChanged(QTreeWidgetItem*, int); // 复选框联动相关的
	void onTypeeItemSelcectionChanged(); // 人点一下选择的

public slots: // 在mainWin里面可以把它跟其他win连接起来
	void onToShowJournal(int); // 显示某位editor的journal

private:
	Ui::WinJournalCatalog ui;
	QSqlQueryModel* m_qryModel; // SELECT后显示

	void initJournalTable(); // 初始化显示期刊tableView
	int getEditorIdFromJournal(int journal_id); // 根据当前期刊号获取主编号
	QList<int> getSelectedIds(); // journal_table所选的期刊id

	// 初始化分类树
	void initTypeTree(); // 初始化显示类型treeView
	QTreeWidgetItem* addTypeeItem(const QString & typee_id, const QString & typee_name, QTreeWidgetItem* fatherCatalog = NULL);
	QTreeWidgetItem* addCatalogItem(const QString & catalogName);
	QTreeWidgetItem* addCatalogItem(const QSqlRecord & typeRowRecord);
	void updateCatState(QTreeWidgetItem* catItem); // 根据Typee选中状态，更新catalog状态
	QStringList getSelectedTyees(); // 获取被选中的类型名称

	// 搜索模块
	// 支持多搜索和模糊搜索但效率可能不一定那么emmm...
	QString bindSearchQuery(const QStringList & typee_names, const QStringList & journal_names, 
		const QStringList & publisher_names); 
	// query的执行就在onBtnSearch里面了

	// 插入期刊模块
	int getNextJournalId();
	void insertSingleJournal();

};
