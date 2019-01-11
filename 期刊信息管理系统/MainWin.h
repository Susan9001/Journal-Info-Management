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

	// ���ݿ����
	QSqlDatabase DB_JournalManagement; // �ڿ��������ݿ�����

	// Ŀ¼����QWidget
	WinJournalCatalog* m_WinJournal;
	WinContributorCatalog* m_WinContributor;
	WinPaperCatalog* m_WinPaper;

signals:
	void showPaper(int id, int prv_index);

private slots:
	void onClickedEnter(); // �������ϵͳ��ť
	void onPaperClicked(int, int); // ��ת������ҳ
	void onGoBack(int);
	void onEditorJournalClicked(int);
};
