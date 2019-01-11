#pragma once

#include <QWidget>
#include <QtSql>
#include <QDataWidgetMapper>
#include <QItemSelectionModel>
#include <QMessageBox>
#include <QCheckBox>
#include <QSqlQuery>
#include <QSqlTableModel>
//#include <QtScript/QtScript>
#include "ui_win_paper_catalog.h"
#include "d_paper_info.h"
#include "d_search_paper.h"
#include "shared_functions.h"

class WinPaperCatalog : public QWidget
{
	Q_OBJECT

public:
	WinPaperCatalog(QWidget *parent = Q_NULLPTR);
	~WinPaperCatalog();
	void renewPaperTable(const QString & qryMes = ""); // �����ڿ�paperView

signals:
	void goBack(int prv_index);
	void toEditorShowJournal(int editor_id);

private slots:
	void onBtnAdd(); // ��������
	void onBtnDelete(); // ɾ������
	void onBtnInfo(); // ��������
	void onBtnSearch(); // �߼�����
	void onBntRefresh(); // ������ʾ
	void onBtnSelectAll(); // ȫѡ��ť
	void onBtnBack(); // �����ڿ�/Ͷ����
	void onBtnPrint(); // ����
	void onToWinShowJournal(int);

public slots:
	void onShowPaper(int, int); // ��Ӧ���棬��ʾͶ���ˡ��ڿ���Ӧ������

private:
	Ui::WinPaperCatalog ui;
	QSqlQueryModel* m_qryModel; // SELECT����ʾ
	int prv_index;

	// ������Ϣtable
	void initPaperTable(); // ��ʼ����ʾ������Ϣ��
	int getJournalIdFromTable();
	int getContributorIdFromTable();
	QList<QString> getSelectedIds(); // ��ȡ��ѡ�е�paper_id
	void setCheckAll();

	// ����ģ��
	QString bindSearchQuery(const QList<QString> & paper_ids = QList<QString>(), const QList<int> & journal_ids = QList<int>(),
		const QList<int> & contributor_ids = QList<int>());
	QString bindSearchQuery(const QStringList & paper_names,  QStringList & journal_names, const QStringList & contributor_names);

	// �½������ģ��
	void insertSinglePaper(); // �½�������Ϣ
	void updateSinglePaper(); // ����������Ϣ
	// ����
	QString getNextPaperId(); // ��һ�����º���
	bool isPaperIdDuplicated(int paper_id);
};
