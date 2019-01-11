#pragma once

#include <QDialog>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QMessageBox>
#include "ui_d_unit_info.h"

class DUnitInfo : public QDialog
{
	Q_OBJECT

public:
	DUnitInfo(QWidget *parent = Q_NULLPTR);
	~DUnitInfo();

	void setEditRecord(QSqlRecord &recData); // 编辑已有数据
	void setInsertRecord(QSqlRecord &recData); // 插入数据
	QSqlRecord getNewData(); // 返回mRecord的值，以便在外面更新/插入界面输入的值
	bool isNameDuplicated(const QString & name = "", int id = 0); 

signals:
	void showStaff(int unit_id);

private slots:
	void onBtnConfirm();
	void onBtnStaff();

private:
	Ui::DUnitInfo ui;

	QSqlRecord mRecord;

};
