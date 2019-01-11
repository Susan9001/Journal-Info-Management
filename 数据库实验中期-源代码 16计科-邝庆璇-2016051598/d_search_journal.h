#pragma once

#include <QDialog>
#include "ui_d_search_journal.h"

class DSearchJournal : public QDialog
{
	Q_OBJECT

private slots:
	void onBtnConfirm();

public:
	DSearchJournal(QWidget *parent = Q_NULLPTR);
	~DSearchJournal();
	QString getJournalNames();
	QString getPublishers();
	QString getTypees();

private:
	Ui::DSearchJournal ui;
};
