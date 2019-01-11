#pragma once

#include <QDialog>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQueryModel>
#include "ui_d_paper_info.h"
#include "d_journal_info.h"
#include "d_contributor_info.h"
#include "shared_functions.h"

class DPaperInfo : public QDialog
{
	Q_OBJECT

public:
	DPaperInfo(QWidget *parent = Q_NULLPTR);
	~DPaperInfo();

	// 自己
	void setEditRecord(QSqlRecord &recData); // 编辑已有数据
	void setInsertRecord(QSqlRecord &recData); // 插入数据
	QSqlRecord getNewData(); // 返回mRecord的值，以便在外面更新/插入界面输入的值

signals:
	void toWinShowJournal(int editor_id);
	void toShowPaper(int prv_index, int id);

private slots:
	void onBtnConfirm(); // 确认修改
	void onCurrentContributorChanged(const QString&); // 投稿人号随着人名变
	void onCurrentJournalChanged(const QString&); // 期刊号随着期刊名变
	void onBtnContributor(); // 显示投稿人信息
	void onBtnJournal(); // 显示期刊信息
	void onLineIdFinished(); // insert时，编辑文章号完成，就补全
	void onToShowJournal(int); // 跳转到journal页显示
	void onToShowPaper(int, int); // 显示Journal的paper(把信号发给win_paper)

private:
	Ui::DPaperInfo ui;
	QString noContributorMes;
	QString noJournalMes;
	QSqlRecord mRecord; // 显示旧的信息、保存修改后的返回信息

	// contributor和journal设置
	void initCmbContributorName(const QString & old_name = "");
	void initCmbJournalName(const QString & old_name = "");
	void setContributorIdsFromName(const QString& contributor_name, int old_id = -1); // 投稿人名->投稿人号
	void setJournalIdFromName(const QString& journal_name = ""); // 期刊名->期刊号

	// 辅助
	bool isNameDuplicated(const QString & name = "", const QString & id = ""); // 检查当前框框的文章名是否重复
};
