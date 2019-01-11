
#include "shared_functions.h"

SharedFunctions::SharedFunctions(QObject *parent)
	: QObject(parent)
{
}

SharedFunctions::~SharedFunctions()
{
}

QStringList SharedFunctions::splitStr(const QString & str)
{
	return str.split(QRegExp("[ ;,.()<>?|{}]+"), QString::SkipEmptyParts);
}

bool SharedFunctions::isValidDate(const QString & dateStr)
{
	QString rxStr = QString("^(?:(?!0000)[0-9]{4}([-/: ])(?:(?:0[1-9]|1[0-2])([-/: ])(?:0[1-9]|1[0-9]|2[0-8])|"
		"(?:0[13-9]|1[0-2])([-/: ])(?:29|30)|(?:0[13578]|1[02])([-/: ])31)|(?:[0-9]{2}(?:0[48]|[2468][048]|"
		"[13579][26])|(?:0[48]|[2468][048]|[13579][26])00)([-/: ])02([-/: ])29)$");
	QRegExp rx(rxStr);
	QRegExpValidator dateV(rx, 0);
	int pos = 0;
	return dateV.validate(QString(dateStr), pos) == QValidator::Acceptable;
}

QString SharedFunctions::completeId(const QString & idStr, int digit, const QString & filler)
{
	QString result = idStr;
	for (int i = 0; i < digit - idStr.length(); i++)
		result.insert(0, filler);
	return result;
}


void SharedFunctions::makeReport(QSqlQueryModel * qryModel, QTableView * tableView, const QString & header)
{
	
	NCReport* report = new NCReport();
	report->setReportSourceType(NCReportSource::File);
	report->setReportFile("report_formal.ncr");
	report->addItemModel("model_0",qryModel);
	report->addItemView("view_0", tableView);
	report->addParameter("header_0", header); // 设置表头

	report->runReportToPreview();

	if (!report->hasError()) 
	{
		NCReportPreviewWindow *pv = new NCReportPreviewWindow();
		pv->setOutput((NCReportPreviewOutput*)report->output());
		pv->setWindowModality(Qt::ApplicationModal);
		pv->setAttribute(Qt::WA_DeleteOnClose);
		pv->setReport(report); // sets the report objects
		pv->exec();
	}
	else 
	{
		QMessageBox::warning(nullptr, u8"报表失败", u8"错误信息\n" + report->lastErrorMsg(),
			QMessageBox::Ok, QMessageBox::NoButton);
		return;
	}

}


