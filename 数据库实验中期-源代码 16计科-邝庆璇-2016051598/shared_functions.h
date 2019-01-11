#pragma once

#include <QObject>
#include <QString>
#include <QStringList>
#include <QList>
#include <QRegExp>
#include <QValidator>
#include <QDebug>
#include <QSqlQueryModel>
#include <QAbstractItemModel>
#include <QMessageBox>
#include <QTableView>

#include "ncreport.h"
#include "ncreportoutput.h"
#include "ncreportpreviewoutput.h"
#include "ncreportpreviewwindow.h"

class SharedFunctions : public QObject
{
	Q_OBJECT

public:
	SharedFunctions(QObject *parent);
	~SharedFunctions();

	static QStringList splitStr(const QString &str); // 对搜索得来的字符串进行拆分
	static bool isValidDate(const QString &dateStr); // 检查日期是否有效
	static	QString completeId(const QString &idStr, int digit = 6, const QString &filler = "0");
	// 报表
	static void makeReport(QSqlQueryModel * qryModel, QTableView * tableVies);
};
