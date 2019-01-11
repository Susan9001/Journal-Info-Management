#include "d_login.h"

DLogin::DLogin(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btn_confirm, SIGNAL(clicked()), this, SLOT(onBtnConfirm()));
}

DLogin::~DLogin()
{
}

void DLogin::onBtnConfirm()
{
	if (!hasId())
	{
		QMessageBox::warning(this, u8"无此用户", u8"账号不存在耶！\n" ,
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	else if (!isValidPassword())
	{
		QMessageBox::warning(this, u8"密码错误", u8"如题，如题！\n",
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	else
	{
		accept();
	}
}

/* 判断用户id是否存在 */
bool DLogin::hasId(const QString & id)
{
	QString theId;
	theId = ((id.isNull() || id.isEmpty())) ? ui.line_id->text() : id;

	QSqlQuery query;
	query.prepare(
		"SELECT *\n"
		"FROM Userr\n"
		"WHERE userr_id = :userr_id;"
	);
	query.bindValue(":userr_id", QVariant::fromValue(theId));
	if (!query.exec())
	{
		QMessageBox::critical(this, u8"查询用户", u8"错误信息\n"+ query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return false;
	}
	return query.first();
}

/* 判断密码是否正确 */
bool DLogin::isValidPassword(const QString & id, const QString & password)
{
	QString theId, thiePassword;
	theId = ((id.isNull() || id.isEmpty())) ? ui.line_id->text() : id;
	thiePassword = ((password.isNull() || password.isEmpty())) ? \
		ui.line_password->text() : password;

	QSqlQuery query;
	query.prepare(
		"SELECT *\n"
		"FROM Userr\n"
		"WHERE userr_id = :userr_id\n"
		"AND userr_password = :userr_password;"
	);
	query.bindValue(":userr_id", QVariant::fromValue(theId));
	query.bindValue(":userr_password", QVariant::fromValue(thiePassword));
	if (!query.exec())
	{
		QMessageBox::critical(this, u8"查询用户", u8"错误信息\n" \
			+ query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return false;
	}
	return query.first();
}
