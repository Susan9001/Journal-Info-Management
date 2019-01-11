/********************************************************************************
** Form generated from reading UI file 'win_article_catalog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_ARTICLE_CATALOG_H
#define UI_WIN_ARTICLE_CATALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WinArticleCatalog
{
public:

    void setupUi(QWidget *WinArticleCatalog)
    {
        if (WinArticleCatalog->objectName().isEmpty())
            WinArticleCatalog->setObjectName(QStringLiteral("WinArticleCatalog"));
        WinArticleCatalog->resize(400, 300);

        retranslateUi(WinArticleCatalog);

        QMetaObject::connectSlotsByName(WinArticleCatalog);
    } // setupUi

    void retranslateUi(QWidget *WinArticleCatalog)
    {
        WinArticleCatalog->setWindowTitle(QApplication::translate("WinArticleCatalog", "WinArticleCatalog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WinArticleCatalog: public Ui_WinArticleCatalog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_ARTICLE_CATALOG_H
