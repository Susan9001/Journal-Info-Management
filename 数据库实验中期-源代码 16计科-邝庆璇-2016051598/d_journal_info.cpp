#include "d_journal_info.h"

DJournalInfo::DJournalInfo(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	// 投稿地址就是主编地址此处暂时不可编辑！否则当主编重名、改主编的时候会乱
	ui.line_email->setFocusPolicy(Qt::NoFocus);

	// 初始化大cmbox_catalog
	QSqlQueryModel *catalogBoxModel = new QSqlQueryModel(this);
	catalogBoxModel->setQuery(
		"SELECT catalog_name\n"
		"FROM Catalogg\n"
		"ORDER BY catalog_id"
	);
	if (catalogBoxModel->lastError().isValid())
	{
		QMessageBox::information(this, "编目错误", "编目查询错误\n错误信息：" + catalogBoxModel->lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	ui.cmbox_catalog->setModel(catalogBoxModel);

	// 初始化小cmbox_type放在setEditRecord里进行

	/// 初始化cmb_editor
	initCmbEditor();

	// 把cmbox_catalog的改变连接起来
	connect(ui.cmbox_catalog, SIGNAL(currentIndexChanged(const QString &)), 
		this, SLOT(onCurrentCatalogChanged(const QString&)));
	// 把确认按钮连接起来
	connect(ui.btn_confirm, SIGNAL(clicked()),
		this, SLOT(onBtnConfirm()));
	// 把主编详情弹框连接起来
	connect(ui.btn_editor, SIGNAL(clicked()), this, SLOT(onBtnEditor()));
	// 跳转到文章
	connect(ui.btn_paper, SIGNAL(clicked()), this, SLOT(onBtnPaper()));

}

DJournalInfo::~DJournalInfo()
{
}

void DJournalInfo::updateEditor(int editor_id, bool set)
{
	QSqlQuery query;
	// 首先获取当主编的号码
	if(!editor_id)
		editor_id = getEditorIdFromName(NULL, getEditorIdFromJournal());

	query.prepare(
		u8"SELECT E.*, P.publisher_name\n"
		"FROM Editor AS E, Publisher AS P\n"
		"WHERE editor_id = :editor_id\n"
			"AND E.publisher_id = P.publisher_id;"
	);
	query.bindValue(":editor_id", editor_id);
	query.exec();
	query.first();
	if (!query.isValid())
	{
		qDebug() << "search publisher not ok";
		return;
	}

	QSqlRecord currRec = query.record();
	DEditorInfo* editorDlg = new DEditorInfo(this);
	// connect它跟去editor的journal
	connect(editorDlg, SIGNAL(toJournal(int)), this, SLOT(onToJournal(int)));
	editorDlg->setEditRecord(currRec); // 设置新数据到出版社信息框里面
	int ret = editorDlg->exec(); // 模态窗口

	// 更新主编信息
	if (ret == QDialog::Accepted)
	{
		// 获取返回的记录
		QSqlRecord recData = editorDlg->getNewData();

		// 更新数据
		query.prepare(u8"UPDATE Editor "
			"SET editor_name = :editor_name, "
			"editor_email = :editor_email, "
			"editor_phone = :editor_phone, "
			"publisher_id = :publisher_id\n" // 记得没有逗号！！！
			"WHERE editor_id = :editor_id;" //记得分号！！！
		);
		query.bindValue(":editor_name", recData.value("editor_name"));
		query.bindValue(":editor_email", recData.value("editor_email"));
		query.bindValue(":editor_phone", recData.value("editor_phone"));
		query.bindValue(":publisher_id", editorDlg->getPublisherIdFromName());
		query.bindValue(":editor_id", editor_id); 

		if (!query.exec())
		{
			QMessageBox::critical(this, "错错错", "更新信息错误！\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
		}
		// 刷新
		if (set)
		{
			initCmbEditor();
			setCmbCurrEditor(recData.value("editor_name").toString());
			ui.line_email->setText(recData.value("editor_email").toString());
			//mRecord.setValue("editor_id", recData.value("editor_id").toInt()); // 设置journal的editor_id这一步外面管
		}
	}

	// 出版社对话框清理内存
	delete editorDlg;
}

int DJournalInfo::insertEditor(const QString & editor_name)
{
	QSqlQuery query;
	
	query.prepare(
		u8"SELECT E.*, P.publisher_name\n"
		"FROM Editor AS E, Publisher AS P\n"
		"WHERE E.publisher_id = P.publisher_id;"
	); // 空值不是空表啊。。。
	query.exec();
	query.first();

	// 给空记录赋点初值
	QSqlRecord currRec = query.record();
	currRec.setValue("editor_name", editor_name);
	currRec.setValue("editor_id", getNextEditorId()); // 当前最大id + 1

	// 插入Editor窗口
	DEditorInfo* editorDlg = new DEditorInfo(this);
	editorDlg->setInsertRecord(currRec); // 设置新数据到出版社信息框里面
	int ret = editorDlg->exec(); // 模态窗口

	QSqlRecord retRec; // 准备接收返回的
	if (ret == QDialog::Accepted)
	{
		QSqlRecord retRec = editorDlg->getNewData();
		int editor_id = retRec.value("editor_id").toInt();

		// 检查重复editor_id, editor_name
		bool alreadyHas = editorExist(editor_id);
		if (alreadyHas)
		{
			QMessageBox::critical(this, "重复", "编号重复了！\n",
				QMessageBox::Ok, QMessageBox::NoButton);
			return 0;
		}

		// 开始新建Editor
		query.prepare(
			"INSERT INTO Editor(editor_id, editor_name, editor_email, editor_phone, publisher_id)\n"
			"VALUES (:editor_id, :editor_name, :editor_email, :editor_phone, :publisher_id);"
		);
		query.bindValue(":editor_id", retRec.value("editor_id"));
		query.bindValue(":editor_name", retRec.value("editor_name"));
		query.bindValue(":editor_email", retRec.value("editor_email"));
		query.bindValue(":editor_phone", retRec.value("editor_phone"));
		query.bindValue(":publisher_id", editorDlg->getPublisherIdFromName());
		if (!query.exec())
		{
			QMessageBox::critical(this, u8"新建主编错误", u8"INSERT错误！\n" + query.lastError().text(),
				QMessageBox::Ok, QMessageBox::NoButton);
			return 0;
		}
		// 刷新
		initCmbEditor();
		setCmbCurrEditor(retRec.value("editor_name").toString());
		ui.line_email->setText(retRec.value("editor_email").toString());
		mRecord.setValue("editor_id", retRec.value("editor_id").toInt());
	}

	delete editorDlg; // 清理editor对话框内存
	return retRec.value("editor_id").toInt();
}

void DJournalInfo::setTypeFromCatalog(const QString & catalog_name)
{
	QSqlQueryModel *typeBoxModel = new QSqlQueryModel(this);
	typeBoxModel->setQuery(
		"SELECT typee_name\n"
		"FROM Typee\n"
		"WHERE catalog_id IN (\n"
		"SELECT catalog_id\n"
		"FROM Catalogg\n"
		"WHERE catalog_name = '" + catalog_name + "');"
	);
	if (typeBoxModel->lastError().isValid())
	{
		QMessageBox::information(this, "类型错误", "类型查询错误\n错误信息：" + typeBoxModel->lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}

	ui.cmbox_type->setModel(typeBoxModel);

}

int DJournalInfo::getEditorIdFromName(const QString & editor_name, int old_editor_id)
{
	QString cur_editor_name;
	if (editor_name == NULL)
		cur_editor_name = ui.cmb_editor->currentText();
	else
		cur_editor_name = editor_name;
	QList<int> editorIdList = getEditorIDs(cur_editor_name);
	if (!editorIdList.size())
		return 0; // 主编号0不存在
	if (editorIdList.size() == 1) // 没有重名
		return editorIdList[0];

	QStringList editorIdStrList;
	for (auto editor_id : editorIdList)
		editorIdStrList.append(QString::number(editor_id));
	
	QString dlgTitle = u8"重名主编";
	QString txtLabel = u8"请选择主编（默认显示的是当前期刊的主编）";
	// 设置初始化选项（如果有old_editor_id则为那个）
	int currIndex = 0;
	if (old_editor_id)
	{
		for (int i = 0; i < editorIdList.size(); i++)
		{
			if (old_editor_id == editorIdList[i])
			{
				currIndex = i;
				break;
			}
		}
	}
	// false1--没有按ok，就放弃修改
	// false2--不可自己输入
	bool isOk = false;
	QString text = QInputDialog::getItem(this, dlgTitle, txtLabel,
		editorIdStrList, currIndex, false, &isOk); 

	if(isOk) return text.toInt();
	else return -1;
}

int DJournalInfo::getEditorIdFromJournal(int journal_id)
{
	if (!journal_id)
		journal_id = ui.line_id->text().toInt();
	QString qryStr = QString(
		"SELECT editor_id\n"
		"FROM Journal\n"
		"WHERE journal_id = :journal_id"
	);
	QSqlQuery query;
	query.prepare(qryStr);
	query.bindValue(":journal_id", journal_id);
	if (!query.exec())
	{
		QMessageBox::critical(this, u8"查询主编错误", u8"从期刊获取主编信息错误！\n" + query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return 0;
	}
	query.first();
	return query.value("editor_id").toInt();
}

bool DJournalInfo::isNameDuplicated(const QString & name, int id)
{
	QString journal_name = name.trimmed().length() > 0 ? name : ui.line_name->text();
	int journal_id = id > 0 ? id : ui.line_id->text().toInt();
	QSqlQuery query;

	query.prepare(
		"SELECT *\n"
		"FROM Journal\n"
		"WHERE journal_name = :journal_name\n"
		"AND journal_id != :journal_id;"
	);
	query.bindValue(":journal_name", journal_name);
	query.bindValue(":journal_id", journal_id);
	if (!query.exec())
	{
		QMessageBox::critical(this, u8"检查期刊名错误~", u8"如题！\n" + query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return false;
	}
	return query.first();
}

void DJournalInfo::onBtnConfirm()
{
	if (!SharedFunctions::isValidDate(ui.line_date->text())) // 检查日期
	{
		QMessageBox::warning(this, u8"日期格式似乎不对耶~", u8"请按格式输入日期哦！\n",
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	else if (isNameDuplicated()) // 检查期刊是否重名
	{
		QMessageBox::warning(this, u8"期刊名不可重复哦~", u8"期刊名不可以重复的呢！\n",
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}

	QString editor_name = ui.cmb_editor->currentText().trimmed();
	int editor_id = getEditorIdFromName(editor_name, getEditorIdFromJournal(ui.line_id->text().toInt()));
	if (editor_id < 0) return;

	// 如果不存在的话添加editor
	if (!editorExist(editor_id))
	{
		QMessageBox::StandardButton btn_ret = QMessageBox::question(this, u8"添加主编", u8"该主编尚未录入，请问是否新增？",
			QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::Yes);
		if (btn_ret == QMessageBox::Yes)
		{
			if (insertEditor(editor_name))
			{
				mRecord.setValue("editor_id", editor_id);
				accept();
			}
			else return;
		}
		else return;
	}
	
	mRecord.setValue("editor_id", editor_id);
	accept();
}

void DJournalInfo::onCurrentCatalogChanged(const QString & catalog_name)
{
	setTypeFromCatalog(catalog_name);
}

void DJournalInfo::onBtnEditor()
{
	QString editor_name = ui.cmb_editor->currentText().trimmed();
	int editor_id = getEditorIdFromName(editor_name, getEditorIdFromJournal(ui.line_id->text().toInt()));
	if (editor_id < 0) return; // 被取消了

	if (editorExist(editor_id))
	{
		bool toSet = true;
		// 若修改了同名不同主编
		if (getEditorIDs(editor_name).size() >= 2 && editor_id != getEditorIdFromJournal(ui.line_id->text().toInt()))
			toSet = false;
		updateEditor(editor_id, toSet); // 否则改变
	}
	else
	{
		QMessageBox::StandardButton btn_ret = QMessageBox::question(this, u8"添加主编", u8"该主编尚未录入，请问是否新增？",
			QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::Yes);
		if (btn_ret == QMessageBox::Yes)
			insertEditor(editor_name);
	}
}

void DJournalInfo::onBtnPaper()
{
	emit toShowPaper(ui.line_id->text().toInt(), 0);
	//reject();
}

void DJournalInfo::onToJournal(int editor_id)
{
	emit toShowJournal(editor_id);
	//reject();
}

QList<int> DJournalInfo::getEditorIDs(const QString & editor_name)
{
	QSqlQuery query;
	QString qryStr = QString(
		"SELECT editor_id\n"
		"FROM Editor\n"
		"WHERE editor_name = :editor_name;"
	);
	query.prepare(qryStr);
	query.bindValue(":editor_name", editor_name);
	if (!query.exec())
	{
		QMessageBox::critical(this, "主编错误", "主编id查询错误\n" + query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return QList<int>();
	}

	QList<int> editor_ids; // 结果
	while (query.next())
		editor_ids.append(query.value("editor_id").toInt());
	return editor_ids;
}

void DJournalInfo::initCmbEditor()
{
	QSqlQuery query;
	query.exec("SELECT DISTINCT editor_name FROM Editor;");
	while (query.next())
		ui.cmb_editor->addItem(query.record().value("editor_name").toString());
}

void DJournalInfo::setCmbCurrEditor(const QString & editor_name)
{
	ui.cmb_editor->setCurrentIndex(ui.cmb_editor->findText(editor_name));
}

int DJournalInfo::getNextEditorId()
{
	QSqlQuery query;
	query.exec("SELECT MAX(editor_id) max_editor_id FROM Editor;");
	query.first();

	return query.value("max_editor_id").toInt() + 1;
}

bool DJournalInfo::editorExist(int editor_id)
{
	QSqlQuery query;
	query.prepare(
		"SELECT *\n"
		"FROM Editor\n"
		"WHERE editor_id = :editor_id;"
	);
	query.bindValue(":editor_id", editor_id);
	if (!query.exec())
	{
		QMessageBox::critical(this, u8"主编查询失败", query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
	}
	query.first();
	if (query.record().value("editor_id").isNull()) return false;
	else return true;
}

void DJournalInfo::setEditRecord(QSqlRecord & recData)
{
	mRecord = recData; // 先获取当前信息
	ui.line_id->setEnabled(false); // 期刊号不允许修改

	// 设置显示line_edit们
	//ui.line_id->setText(mRecord.value("publisher_id").toString());
	ui.line_id->setText(mRecord.value("journal_id").toString());
	journal_id = mRecord.value("journal_id").toInt();
	ui.line_name->setText(mRecord.value("journal_name").toString());
	setCmbCurrEditor(mRecord.value("editor_name").toString());
	ui.line_email->setText(mRecord.value("editor_email").toString());
	ui.line_date->setText(mRecord.value("new_publish_date").toString()); 

	// 设置大类cmbox_catalog
	QString currCatalog = mRecord.value("catalog_name").toString();
	for (int i = 0; i < ui.cmbox_catalog->count(); i++)
	{
		if (ui.cmbox_catalog->itemText(i) == currCatalog)
		{
			ui.cmbox_catalog->setCurrentIndex(i);
			break;
		}
	}

	// 初始化小类cmbox_type
	setTypeFromCatalog(currCatalog);
	// 设置小类cmbox_type
	QString currType = mRecord.value("typee_name").toString();
	for (int i = 0; i < ui.cmbox_type->count(); i++)
	{
		if (ui.cmbox_type->itemText(i) == currType)
		{
			ui.cmbox_type->setCurrentIndex(i);
			break;
		}
	}
	return;
}

void DJournalInfo::setInsertRecord(QSqlRecord & recData)
{
	mRecord = recData;
	ui.line_id->setEnabled(true); //可以编辑
	ui.line_id->setText(mRecord.value("journal_id").toString());
}

void DJournalInfo::setReadOnlyRecord(QSqlRecord & recData)
{
	setEditRecord(recData);
	ui.btn_confirm->setText(u8" 确认");
	ui.line_name->setFocusPolicy(Qt::NoFocus); // 不可编辑
	ui.line_date->setFocusPolicy(Qt::NoFocus);
	ui.line_email->setFocusPolicy(Qt::NoFocus);
	ui.cmbox_catalog->setFocusPolicy(Qt::NoFocus);
	ui.cmbox_type->setFocusPolicy(Qt::NoFocus);
	ui.cmb_editor->setFocusPolicy(Qt::NoFocus);
}

QSqlRecord DJournalInfo::getNewData()
{
	mRecord.setValue("journal_id", ui.line_id->text().toInt());
	mRecord.setValue("journal_name", ui.line_name->text().trimmed());
	mRecord.setValue("editor_email", ui.line_email->text().trimmed()); //也是journal_email
	mRecord.setValue("editor_name", ui.cmb_editor->currentText().trimmed()); // 在外面讨论该编辑不存在的情况

	// 检查日期是否有效

	mRecord.setValue("new_publish_date", ui.line_date->text());
	mRecord.setValue("catalog_name", ui.cmbox_catalog->currentText());
	mRecord.setValue("typee_name", ui.cmbox_type->currentText());

	// 二期 检查是否合法

	return mRecord;
}
