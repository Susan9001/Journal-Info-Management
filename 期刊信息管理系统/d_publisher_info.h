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
	QSqlRecord mRecord; // ��ʾ�ɵ���Ϣ�������޸ĺ�ķ�����Ϣ

private slots:
	void onBtnConfirm(); // ȷ���޸�

public:
	DPublisherInfo(QWidget *parent = Q_NULLPTR);
	~DPublisherInfo();
	
	void setEditRecord(QSqlRecord &recData); // �༭��������
	void setInsertRecord(QSqlRecord &recData); // ��������
	QSqlRecord getNewData(); // ����mRecord��ֵ���Ա����������/������������ֵ

	bool isNameDuplicated(const QString & name = "", int id = 0); // ��鵱ǰ�����������Ƿ��ظ�

	// ���ڹ���
	//void setDeleteRecord(QSqlRecord &recData); // ɾ����¼
};
