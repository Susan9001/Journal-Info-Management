#include "d_search_contributor.h"

DSearchContributor::DSearchContributor(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.btn_confirm, SIGNAL(clicked()), this, SLOT(onBtnConfirm()));
}

DSearchContributor::~DSearchContributor()
{
}

QString DSearchContributor::getContributorNames()
{
	return ui.line_name->text();
}

QString DSearchContributor::getUnitNames()
{
	return ui.line_unit->text();
}

void DSearchContributor::onBtnConfirm()
{
	accept();
}
