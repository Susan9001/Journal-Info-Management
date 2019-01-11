#pragma once

#include <QWidget>
#include <QtSql>
#include <QDataWidgetMapper>
#include <QItemSelectionModel>
#include <QMessageBox>
#include <QCheckBox>
#include <QSqlQuery>
#include <QSqlTableModel>
#include "ui_win_journal_catalog.h"
#include "d_journal_info.h"
#include "d_search_journal.h"
#include "shared_functions.h"

class WinJournalCatalog : public QWidget
{
	Q_OBJECT

public:
	WinJournalCatalog(QWidget *parent = Q_NULLPTR);
	~WinJournalCatalog();
	void renewJournalTable(const QString & qryMes = ""); // �����ڿ�tableView

signals:
	void paperClicked(int id, int tabIndex); // ��ʾ��Ӧ������
	void editorJournalClicked(); // ����editor��journal

private slots:
	void onBtnPaper(); // �鿴����
	void onDlgPaper(int, int); // �Ի�������
	void onBtnPrint(); // �����ӡ

	void onBtnJournalInfo(); // �鿴���༭�ڿ�����
	void onBtnAdd(); // �����ڿ�
	void onBtnDelete(); // ɾ���ڿ�
	void onBtnSearch(); // �߼�����
	void onBtnShow(); // ��������treeWidgetɸѡ�ڿ�
	void onTypeeSelChanged(QTreeWidgetItem*, int); // ��ѡ��������ص�
	void onTypeeItemSelcectionChanged(); // �˵�һ��ѡ���

public slots: // ��mainWin������԰���������win��������
	void onToShowJournal(int); // ��ʾĳλeditor��journal

private:
	Ui::WinJournalCatalog ui;
	QSqlQueryModel* m_qryModel; // SELECT����ʾ

	void initJournalTable(); // ��ʼ����ʾ�ڿ�tableView
	int getEditorIdFromJournal(int journal_id); // ���ݵ�ǰ�ڿ��Ż�ȡ�����
	QList<int> getSelectedIds(); // journal_table��ѡ���ڿ�id

	// ��ʼ��������
	void initTypeTree(); // ��ʼ����ʾ����treeView
	QTreeWidgetItem* addTypeeItem(const QString & typee_id, const QString & typee_name, QTreeWidgetItem* fatherCatalog = NULL);
	QTreeWidgetItem* addCatalogItem(const QString & catalogName);
	QTreeWidgetItem* addCatalogItem(const QSqlRecord & typeRowRecord);
	void updateCatState(QTreeWidgetItem* catItem); // ����Typeeѡ��״̬������catalog״̬
	QStringList getSelectedTyees(); // ��ȡ��ѡ�е���������

	// ����ģ��
	// ֧�ֶ�������ģ��������Ч�ʿ��ܲ�һ����ôemmm...
	QString bindSearchQuery(const QStringList & typee_names, const QStringList & journal_names, 
		const QStringList & publisher_names); 
	// query��ִ�о���onBtnSearch������

	// �����ڿ�ģ��
	int getNextJournalId();
	void insertSingleJournal();

};
