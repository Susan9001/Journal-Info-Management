#pragma once

#include <QDialog>
#include <QSqlQuery>
#include <QVariant>
#include <QMessageBox>
#include <QSqlError>
#include "ui_d_login.h"

class DLogin : public QDialog
{
	Q_OBJECT

public:
	DLogin(QWidget *parent = Q_NULLPTR);
	~DLogin();

private slots:
	void onBtnConfirm();

private:
	Ui::DLogin ui;

	bool hasId(const QString & id = QString());
	bool isValidPassword(const QString & id = QString(), const QString & password = QString());
};
