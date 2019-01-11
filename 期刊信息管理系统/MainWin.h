#pragma once

#include <QtWidgets/QMainWindow>
#include <QtSql>
#include <QDataWidgetMapper>
#include <QLayout>
#include <QSqlDatabase>
#include <QMessageBox>
#include "ui_MainWin.h"

#include "win_journal_catalog.h"
#include "win_contributor_catalog.h"
#include "win_paper_catalog.h"
#include "d_editor_info.h"
#include "d_login.h"

class MainWin : public QMainWindow
{
	Q_OBJECT

public:
	MainWin(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWinClass ui;

	// 数据库相关
	QSqlDatabase DB_JournalManagement; // 期刊管理数据库连接

	// 目录界面QWidget
	WinJournalCatalog* m_WinJournal;
	WinContributorCatalog* m_WinContributor;
	WinPaperCatalog* m_WinPaper;

signals:
	void showPaper(int id, int prv_index);

private slots:
	void onClickedEnter(); // 进入管理系统按钮
	void onPaperClicked(int, int); // 跳转到文章页
	void onGoBack(int);
	void onEditorJournalClicked(int);
};
