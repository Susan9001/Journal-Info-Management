#pragma once

#include <QDialog>
#include "ui_d_search_paper.h"

class DSearchPaper : public QDialog
{
	Q_OBJECT

public:
	DSearchPaper(QWidget *parent = Q_NULLPTR);
	~DSearchPaper();
	QString getJournalNames();
	QString getPaperNames();
	QString getContributorNames();

private slots:
	void onBtnConfirm();

private:
	Ui::DSearchPaper ui;
};
