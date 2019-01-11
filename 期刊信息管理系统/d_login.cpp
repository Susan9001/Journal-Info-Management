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
		QMessageBox::warning(this, u8"�޴��û�", u8"�˺Ų�����Ү��\n" ,
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	else if (!isValidPassword())
	{
		QMessageBox::warning(this, u8"�������", u8"���⣬���⣡\n",
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}
	else
	{
		accept();
	}
}

/* �ж��û�id�Ƿ���� */
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
		QMessageBox::critical(this, u8"��ѯ�û�", u8"������Ϣ\n"+ query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return false;
	}
	return query.first();
}

/* �ж������Ƿ���ȷ */
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
		QMessageBox::critical(this, u8"��ѯ�û�", u8"������Ϣ\n" \
			+ query.lastError().text(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return false;
	}
	return query.first();
}
