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
	QSqlRecord mRecord; // 显示旧的信息、保存修改后的返回信息
	void setTypeFromCatalog(const QString& catalog_name); // 根据大类，设置cmbox_type
	QList<int> getEditorIDs(const QString& editor_name);

	// 投稿人框cmb_editor
	void initCmbEditor();
	void setCmbCurrEditor(const QString & editor_name);

	// 新增主编相关
	int getNextEditorId(); // 获取下一个新的默认editor_id(当前最大+1)
	bool editorExist(int editor_id);

	int journal_id; //当前期刊号

signals:
	void toShowPaper(int id, int curr_index);
	void toShowJournal(int editor_id);

private slots:
	void onBtnConfirm(); // 确认修改
	void onCurrentCatalogChanged(const QString&); // 大类变了，小类也要变
	void onBtnEditor(); // 显示主编信息
	void onBtnPaper(); // emit toShowPaper 给win_journal
	void onToJournal(int); // emit toShowJournal 给win_journal

public:
	DJournalInfo(QWidget *parent = Q_NULLPTR);
	~DJournalInfo();

	// 主编信息
	void updateEditor(int editor_id = 0, bool set = true); // 默认要获取主编
	int insertEditor(const QString & editor_name); // 返回主编号

	// 自己
	void setEditRecord(QSqlRecord &recData); // 编辑已有数据
	void setInsertRecord(QSqlRecord &recData); // 插入数据
	void setReadOnlyRecord(QSqlRecord &recData); // 期刊信息只读
	QSqlRecord getNewData(); // 返回mRecord的值，以便在外面更新/插入界面输入的值
	int getEditorIdFromName(const QString& editor_name = NULL, int old_editor_id = 0); // 当重名了.返回主编号码
	int getEditorIdFromJournal(int journal_id = 0);
	bool isNameDuplicated(const QString & name = "", int id = 0); // 检查当前框框的文章名是否重复
};
