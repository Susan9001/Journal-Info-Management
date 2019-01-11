#pragma once

#include <QDialog>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include "ui_d_editor_info.h"
#include "d_publisher_info.h"

class DEditorInfo : public QDialog
{
	Q_OBJECT

private:
	Ui::DEditorInfo ui;
	QSqlRecord mRecord;
	bool publisherExist(int publisher_id, QString publisher_name);
	int getNextPublisherId();

private slots:
	void onBtnPublisher();
	void onBtnJournal();
	void onBtnConfirm();

signals:
	void toJournal(int editor_id);

public:
	DEditorInfo(QWidget *parent = Q_NULLPTR);
	~DEditorInfo();

	// 出版社详情
	void updatePublisher();
	int insertPublisher(QString publisher_name = ""); // 没有这个出版社，就新增

	// 编辑自己
	void setEditRecord(QSqlRecord &recData); // 编辑已有数据
	void setInsertRecord(QSqlRecord &recData); // 插入数据
	QSqlRecord getNewData(); // 返回mRecord的值，以便在外面更新/插入界面输入的值

	int getPublisherIdFromEditor();
	int getPublisherIdFromName(); // 根据lineEdit通过输入名字获取id
	//int getJournalId();
	// 二期工程 删除editor
	// 初始化出版社cmbox
	void initCmbPublisher();
	void setCmbCurrPublisher(const QString & publisher_name);
};
