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

	// ����������
	void updatePublisher();
	int insertPublisher(QString publisher_name = ""); // û����������磬������

	// �༭�Լ�
	void setEditRecord(QSqlRecord &recData); // �༭��������
	void setInsertRecord(QSqlRecord &recData); // ��������
	QSqlRecord getNewData(); // ����mRecord��ֵ���Ա����������/������������ֵ

	int getPublisherIdFromEditor();
	int getPublisherIdFromName(); // ����lineEditͨ���������ֻ�ȡid
	//int getJournalId();
	// ���ڹ��� ɾ��editor
	// ��ʼ��������cmbox
	void initCmbPublisher();
	void setCmbCurrPublisher(const QString & publisher_name);
};
