#pragma once

#include <QDialog>
#include <QInputDialog>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQueryModel>
#include "ui_d_journal_info.h"
#include "d_editor_info.h"
#include "shared_functions.h"

class DJournalInfo : public QDialog
{
	Q_OBJECT

private:
	Ui::DJournalInfo ui;
	QSqlRecord mRecord; // ��ʾ�ɵ���Ϣ�������޸ĺ�ķ�����Ϣ
	void setTypeFromCatalog(const QString& catalog_name); // ���ݴ��࣬����cmbox_type
	QList<int> getEditorIDs(const QString& editor_name);

	// Ͷ���˿�cmb_editor
	void initCmbEditor();
	void setCmbCurrEditor(const QString & editor_name);

	// �����������
	int getNextEditorId(); // ��ȡ��һ���µ�Ĭ��editor_id(��ǰ���+1)
	bool editorExist(int editor_id);

	int journal_id; //��ǰ�ڿ���

signals:
	void toShowPaper(int id, int curr_index);
	void toShowJournal(int editor_id);

private slots:
	void onBtnConfirm(); // ȷ���޸�
	void onCurrentCatalogChanged(const QString&); // ������ˣ�С��ҲҪ��
	void onBtnEditor(); // ��ʾ������Ϣ
	void onBtnPaper(); // emit toShowPaper ��win_journal
	void onToJournal(int); // emit toShowJournal ��win_journal

public:
	DJournalInfo(QWidget *parent = Q_NULLPTR);
	~DJournalInfo();

	// ������Ϣ
	void updateEditor(int editor_id = 0, bool set = true); // Ĭ��Ҫ��ȡ����
	int insertEditor(const QString & editor_name); // ���������

	// �Լ�
	void setEditRecord(QSqlRecord &recData); // �༭��������
	void setInsertRecord(QSqlRecord &recData); // ��������
	void setReadOnlyRecord(QSqlRecord &recData); // �ڿ���Ϣֻ��
	QSqlRecord getNewData(); // ����mRecord��ֵ���Ա����������/������������ֵ
	int getEditorIdFromName(const QString& editor_name = NULL, int old_editor_id = 0); // ��������.�����������
	int getEditorIdFromJournal(int journal_id = 0);
	bool isNameDuplicated(const QString & name = "", int id = 0); // ��鵱ǰ�����������Ƿ��ظ�
};
