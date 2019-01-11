#pragma once

#include <QDialog>
#include "ui_d_search_contributor.h"

class DSearchContributor : public QDialog
{
	Q_OBJECT

public:
	DSearchContributor(QWidget *parent = Q_NULLPTR);
	~DSearchContributor();

	QString getContributorNames();
	QString getUnitNames();

private slots:
	void onBtnConfirm();

private:
	Ui::DSearchContributor ui;
};
