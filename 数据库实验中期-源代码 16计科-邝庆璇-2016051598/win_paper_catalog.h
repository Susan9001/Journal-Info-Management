#pragma once

#include <QWidget>
#include <QtSql>
#include <QDataWidgetMapper>
#include <QItemSelectionModel>
#include <QMessageBox>
#include <QCheckBox>
#include <QSqlQuery>
#include <QSqlTableModel>
//#include <QtScript/QtScript>
#include "ui_win_paper_catalog.h"
#include "d_paper_info.h"
#include "d_search_paper.h"
#include "shared_functions.h"

class WinPaperCatalog : public QWidget
{
	Q_OBJECT

public:
	WinPaperCatalog(QWidget *parent = Q_NULLPTR);
	~WinPaperCatalog();
	void renewPaperTable(const QString & qryMes = ""); // 更新期刊paperView

signals:
	void goBack(int prv_index);
	void toEditorShowJournal(int editor_id);

private slots:
	void onBtnAdd(); // 增加文章
	void onBtnDelete(); // 删除文章
	void onBtnInfo(); // 文章详情
	void onBtnSearch(); // 高级搜索
	void onBntRefresh(); // 重置显示
	void onBtnSelectAll(); // 全选按钮
	void onBtnBack(); // 返回期刊/投稿人
	void onBtnPrint(); // 报表
	void onToWinShowJournal(int);

public slots:
	void onShowPaper(int, int); // 响应外面，显示投稿人、期刊对应的文章

private:
	Ui::WinPaperCatalog ui;
	QSqlQueryModel* m_qryModel; // SELECT后显示
	int prv_index;

	// 论文信息table
	void initPaperTable(); // 初始化显示论文信息表
	int getJournalIdFromTable();
	int getContributorIdFromTable();
	QList<QString> getSelectedIds(); // 获取被选中的paper_id
	void setCheckAll();

	// 搜索模块
	QString bindSearchQuery(const QList<QString> & paper_ids = QList<QString>(), const QList<int> & journal_ids = QList<int>(),
		const QList<int> & contributor_ids = QList<int>());
	QString bindSearchQuery(const QStringList & paper_names,  QStringList & journal_names, const QStringList & contributor_names);

	// 新建与更新模块
	void insertSinglePaper(); // 新建文章信息
	void updateSinglePaper(); // 更新文章信息
	// 辅助
	QString getNextPaperId(); // 下一个文章号码
	bool isPaperIdDuplicated(int paper_id);
};
