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

	// �Լ�
	void setEditRecord(QSqlRecord &recData); // �༭��������
	void setInsertRecord(QSqlRecord &recData); // ��������
	void setReadOnlyRecord(QSqlRecord &recData); // ֻ��
	QSqlRecord getNewData(); // ����mRecord��ֵ���Ա����������/������������ֵ

signals:
	void toShowPaper(int id, int curr_index);

private slots:
	void onBtnConfirm(); // ����ȷ�ϰ�ť
	void onBtnPaper(); // emit toShowPaper

private:
	Ui::DContributorInfo ui;
	QSqlRecord mRecord;
	QString noUnitMes;

	void initUnitCmb(); // ��ʼ����λѡ��Ի���
	void setFirstUnit(QString unit_name = ""); // ����Ĭ�ϵ�һ
};
