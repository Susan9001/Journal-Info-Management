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

	// �Լ�
	void setEditRecord(QSqlRecord &recData); // �༭��������
	void setInsertRecord(QSqlRecord &recData); // ��������
	QSqlRecord getNewData(); // ����mRecord��ֵ���Ա����������/������������ֵ

signals:
	void toWinShowJournal(int editor_id);
	void toShowPaper(int prv_index, int id);

private slots:
	void onBtnConfirm(); // ȷ���޸�
	void onCurrentContributorChanged(const QString&); // Ͷ���˺�����������
	void onCurrentJournalChanged(const QString&); // �ڿ��������ڿ�����
	void onBtnContributor(); // ��ʾͶ������Ϣ
	void onBtnJournal(); // ��ʾ�ڿ���Ϣ
	void onLineIdFinished(); // insertʱ���༭���º���ɣ��Ͳ�ȫ
	void onToShowJournal(int); // ��ת��journalҳ��ʾ
	void onToShowPaper(int, int); // ��ʾJournal��paper(���źŷ���win_paper)

private:
	Ui::DPaperInfo ui;
	QString noContributorMes;
	QString noJournalMes;
	QSqlRecord mRecord; // ��ʾ�ɵ���Ϣ�������޸ĺ�ķ�����Ϣ

	// contributor��journal����
	void initCmbContributorName(const QString & old_name = "");
	void initCmbJournalName(const QString & old_name = "");
	void setContributorIdsFromName(const QString& contributor_name, int old_id = -1); // Ͷ������->Ͷ���˺�
	void setJournalIdFromName(const QString& journal_name = ""); // �ڿ���->�ڿ���

	// ����
	bool isNameDuplicated(const QString & name = "", const QString & id = ""); // ��鵱ǰ�����������Ƿ��ظ�
};
