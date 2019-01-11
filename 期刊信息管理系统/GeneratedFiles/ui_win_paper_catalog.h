/********************************************************************************
** Form generated from reading UI file 'win_paper_catalog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_PAPER_CATALOG_H
#define UI_WIN_PAPER_CATALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WinPaperCatalog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_back;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QToolButton *btn_selectAll;
    QToolButton *btn_refresh;
    QToolButton *btn_search;
    QToolButton *btn_print;
    QToolButton *btn_articleInfo;
    QToolButton *btn_delete;
    QToolButton *btn_add;
    QTableView *m_paperTable;

    void setupUi(QWidget *WinPaperCatalog)
    {
        if (WinPaperCatalog->objectName().isEmpty())
            WinPaperCatalog->setObjectName(QStringLiteral("WinPaperCatalog"));
        WinPaperCatalog->resize(999, 553);
        verticalLayout_2 = new QVBoxLayout(WinPaperCatalog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btn_back = new QPushButton(WinPaperCatalog);
        btn_back->setObjectName(QStringLiteral("btn_back"));
        btn_back->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/back_1152px_1143771_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_back->setIcon(icon);
        btn_back->setIconSize(QSize(38, 40));
        btn_back->setFlat(true);

        verticalLayout->addWidget(btn_back);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_selectAll = new QToolButton(WinPaperCatalog);
        btn_selectAll->setObjectName(QStringLiteral("btn_selectAll"));
        btn_selectAll->setMaximumSize(QSize(100, 16777215));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/accept_page_128px_500987_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_selectAll->setIcon(icon1);
        btn_selectAll->setIconSize(QSize(60, 50));
        btn_selectAll->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_selectAll);

        btn_refresh = new QToolButton(WinPaperCatalog);
        btn_refresh->setObjectName(QStringLiteral("btn_refresh"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/matte_white_square_icon_arrows_arrow_circle_refresh_512px_570726_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_refresh->setIcon(icon2);
        btn_refresh->setIconSize(QSize(60, 50));
        btn_refresh->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_refresh);

        btn_search = new QToolButton(WinPaperCatalog);
        btn_search->setObjectName(QStringLiteral("btn_search"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/search_black_and_white.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_search->setIcon(icon3);
        btn_search->setIconSize(QSize(45, 50));
        btn_search->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_search);

        btn_print = new QToolButton(WinPaperCatalog);
        btn_print->setObjectName(QStringLiteral("btn_print"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/printer_128px_523218_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_print->setIcon(icon4);
        btn_print->setIconSize(QSize(50, 50));
        btn_print->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_print);

        btn_articleInfo = new QToolButton(WinPaperCatalog);
        btn_articleInfo->setObjectName(QStringLiteral("btn_articleInfo"));
        btn_articleInfo->setMinimumSize(QSize(0, 66));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/book_128px_501187_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_articleInfo->setIcon(icon5);
        btn_articleInfo->setIconSize(QSize(60, 50));
        btn_articleInfo->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_articleInfo);

        btn_delete = new QToolButton(WinPaperCatalog);
        btn_delete->setObjectName(QStringLiteral("btn_delete"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/delete_page_128px_501003_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_delete->setIcon(icon6);
        btn_delete->setIconSize(QSize(60, 50));
        btn_delete->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_delete);

        btn_add = new QToolButton(WinPaperCatalog);
        btn_add->setObjectName(QStringLiteral("btn_add"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/add_page_128px_500989_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_add->setIcon(icon7);
        btn_add->setIconSize(QSize(60, 50));
        btn_add->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_add);


        verticalLayout_2->addLayout(horizontalLayout);

        m_paperTable = new QTableView(WinPaperCatalog);
        m_paperTable->setObjectName(QStringLiteral("m_paperTable"));
        m_paperTable->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(m_paperTable);


        retranslateUi(WinPaperCatalog);

        QMetaObject::connectSlotsByName(WinPaperCatalog);
    } // setupUi

    void retranslateUi(QWidget *WinPaperCatalog)
    {
        WinPaperCatalog->setWindowTitle(QApplication::translate("WinPaperCatalog", "WinArticleCatalog", Q_NULLPTR));
        btn_back->setText(QApplication::translate("WinPaperCatalog", "\350\277\224\345\233\236", Q_NULLPTR));
        btn_selectAll->setText(QApplication::translate("WinPaperCatalog", "\345\205\250\351\200\211/\344\270\215\351\200\211", Q_NULLPTR));
        btn_refresh->setText(QApplication::translate("WinPaperCatalog", "\351\207\215\347\275\256\346\230\276\347\244\272", Q_NULLPTR));
        btn_search->setText(QApplication::translate("WinPaperCatalog", "\351\253\230\347\272\247\346\220\234\347\264\242", Q_NULLPTR));
        btn_print->setText(QApplication::translate("WinPaperCatalog", "\346\212\245\350\241\250\346\211\223\345\215\260", Q_NULLPTR));
        btn_articleInfo->setText(QApplication::translate("WinPaperCatalog", "\346\226\207\347\253\240\350\257\246\346\203\205", Q_NULLPTR));
        btn_delete->setText(QApplication::translate("WinPaperCatalog", "\345\210\240\351\231\244\346\226\207\347\253\240", Q_NULLPTR));
        btn_add->setText(QApplication::translate("WinPaperCatalog", "\345\242\236\345\212\240\346\226\207\347\253\240", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WinPaperCatalog: public Ui_WinPaperCatalog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_PAPER_CATALOG_H
