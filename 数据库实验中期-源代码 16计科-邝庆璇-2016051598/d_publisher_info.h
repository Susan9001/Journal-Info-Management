#pragma once

#include <QDialog>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include "ui_d_publisher_info.h"

class DPublisherInfo : public QDialog
{
	Q_OBJECT

private:
	Ui::DPublisherInfo ui;
	QSqlRecord mRecord; // 显示旧的信息、保存修改后的返回信息

private slots:
	void onBtnConfirm(); // 确认修改

public:
	DPublisherInfo(QWidget *parent = Q_NULLPTR);
	~DPublisherInfo();
	
	void setEditRecord(QSqlRecord &recData); // 编辑已有数据
	void setInsertRecord(QSqlRecord &recData); // 插入数据
	QSqlRecord getNewData(); // 返回mRecord的值，以便在外面更新/插入界面输入的值

	bool isNameDuplicated(const QString & name = "", int id = 0); // 检查当前框框的文章名是否重复

	// 二期工程
	//void setDeleteRecord(QSqlRecord &recData); // 删除记录
};
