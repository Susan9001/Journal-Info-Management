#include "d_search_paper.h"

DSearchPaper::DSearchPaper(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.btn_confirm, SIGNAL(clicked()), this, SLOT(onBtnConfirm()));
}

DSearchPaper::~DSearchPaper()
{
}

QString DSearchPaper::getJournalNames()
{
	return ui.line_journal->text();
}

QString DSearchPaper::getPaperNames()
{
	return ui.line_paper->text();
}

QString DSearchPaper::getContributorNames()
{
	return ui.line_contributor->text();
}

void DSearchPaper::onBtnConfirm()
{
	accept();
}


