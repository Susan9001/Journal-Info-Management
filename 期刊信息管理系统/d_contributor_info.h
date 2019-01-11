#pragma once

#include <QDialog>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlError>
#include "ui_d_contributor_info.h"

class DContributorInfo : public QDialog
{
	Q_OBJECT

public:
	DContributorInfo(QWidget *parent = Q_NULLPTR);
	~DContributorInfo();

	// 自己
	void setEditRecord(QSqlRecord &recData); // 编辑已有数据
	void setInsertRecord(QSqlRecord &recData); // 插入数据
	void setReadOnlyRecord(QSqlRecord &recData); // 只读
	QSqlRecord getNewData(); // 返回mRecord的值，以便在外面更新/插入界面输入的值

signals:
	void toShowPaper(int id, int curr_index);

private slots:
	void onBtnConfirm(); // 按下确认按钮
	void onBtnPaper(); // emit toShowPaper

private:
	Ui::DContributorInfo ui;
	QSqlRecord mRecord;
	QString noUnitMes;

	void initUnitCmb(); // 初始化单位选择对话框
	void setFirstUnit(QString unit_name = ""); // 设置默认第一
};
