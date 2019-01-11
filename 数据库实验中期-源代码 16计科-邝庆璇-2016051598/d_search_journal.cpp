#include "d_search_journal.h"

DSearchJournal::DSearchJournal(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.btn_confirm, SIGNAL(clicked()), this, SLOT(onBtnConfirm()));
	this->setWindowModality(Qt::NonModal); // ·ÇÄ£Ì¬ËÑË÷¿ò
}

DSearchJournal::~DSearchJournal()
{
}

QString DSearchJournal::getJournalNames()
{
	return ui.line_name->text();
}

QString DSearchJournal::getPublishers()
{
	return ui.line_publisher->text();
}

QString DSearchJournal::getTypees()
{
	return ui.line_typee->text();
}

void DSearchJournal::onBtnConfirm()
{
	accept();
}
