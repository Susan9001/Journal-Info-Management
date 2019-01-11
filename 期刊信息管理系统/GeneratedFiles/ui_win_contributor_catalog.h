/********************************************************************************
** Form generated from reading UI file 'win_contributor_catalog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_CONTRIBUTOR_CATALOG_H
#define UI_WIN_CONTRIBUTOR_CATALOG_H

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
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WinContributorCatalog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *btn_article;
    QToolButton *btn_search;
    QToolButton *btn_print;
    QToolButton *btn_delContributor;
    QToolButton *btn_addContributor;
    QToolButton *btn_contributor;
    QToolButton *btn_delUnit;
    QToolButton *btn_addUnit;
    QToolButton *btn_unit;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *m_unitTree;
    QTableView *m_contributeTable;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_show;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *WinContributorCatalog)
    {
        if (WinContributorCatalog->objectName().isEmpty())
            WinContributorCatalog->setObjectName(QStringLiteral("WinContributorCatalog"));
        WinContributorCatalog->resize(1092, 624);
        verticalLayout = new QVBoxLayout(WinContributorCatalog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_article = new QToolButton(WinContributorCatalog);
        btn_article->setObjectName(QStringLiteral("btn_article"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/new_page_128px_501019_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_article->setIcon(icon);
        btn_article->setIconSize(QSize(38, 38));
        btn_article->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_article);

        btn_search = new QToolButton(WinContributorCatalog);
        btn_search->setObjectName(QStringLiteral("btn_search"));
        btn_search->setMaximumSize(QSize(110, 16777215));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/search_user_128px_501325_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_search->setIcon(icon1);
        btn_search->setIconSize(QSize(38, 38));
        btn_search->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_search);

        btn_print = new QToolButton(WinContributorCatalog);
        btn_print->setObjectName(QStringLiteral("btn_print"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(60);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_print->sizePolicy().hasHeightForWidth());
        btn_print->setSizePolicy(sizePolicy);
        btn_print->setMinimumSize(QSize(0, 0));
        btn_print->setMaximumSize(QSize(97, 66));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/printer_128px_25992_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_print->setIcon(icon2);
        btn_print->setIconSize(QSize(40, 50));
        btn_print->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_print);

        btn_delContributor = new QToolButton(WinContributorCatalog);
        btn_delContributor->setObjectName(QStringLiteral("btn_delContributor"));
        btn_delContributor->setMaximumSize(QSize(110, 16777215));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/delete_user_128px_501301_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_delContributor->setIcon(icon3);
        btn_delContributor->setIconSize(QSize(45, 35));
        btn_delContributor->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_delContributor);

        btn_addContributor = new QToolButton(WinContributorCatalog);
        btn_addContributor->setObjectName(QStringLiteral("btn_addContributor"));
        btn_addContributor->setMaximumSize(QSize(110, 16777215));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/add_user_128px_501291_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_addContributor->setIcon(icon4);
        btn_addContributor->setIconSize(QSize(38, 35));
        btn_addContributor->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_addContributor);

        btn_contributor = new QToolButton(WinContributorCatalog);
        btn_contributor->setObjectName(QStringLiteral("btn_contributor"));
        btn_contributor->setMinimumSize(QSize(0, 66));
        btn_contributor->setMaximumSize(QSize(110, 16777215));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/business_man_consultancy_staff_user_128px_107_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btn_contributor->setIcon(icon5);
        btn_contributor->setIconSize(QSize(35, 32));
        btn_contributor->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_contributor);

        btn_delUnit = new QToolButton(WinContributorCatalog);
        btn_delUnit->setObjectName(QStringLiteral("btn_delUnit"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/data_remove_database_128px_1082308_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_delUnit->setIcon(icon6);
        btn_delUnit->setIconSize(QSize(45, 35));
        btn_delUnit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_delUnit);

        btn_addUnit = new QToolButton(WinContributorCatalog);
        btn_addUnit->setObjectName(QStringLiteral("btn_addUnit"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/data_add_database_128px_1082298_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_addUnit->setIcon(icon7);
        btn_addUnit->setIconSize(QSize(38, 35));
        btn_addUnit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_addUnit);

        btn_unit = new QToolButton(WinContributorCatalog);
        btn_unit->setObjectName(QStringLiteral("btn_unit"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/companies_128px_27316_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btn_unit->setIcon(icon8);
        btn_unit->setIconSize(QSize(36, 36));
        btn_unit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_unit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_unitTree = new QTreeWidget(WinContributorCatalog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        m_unitTree->setHeaderItem(__qtreewidgetitem);
        m_unitTree->setObjectName(QStringLiteral("m_unitTree"));

        horizontalLayout_2->addWidget(m_unitTree);

        m_contributeTable = new QTableView(WinContributorCatalog);
        m_contributeTable->setObjectName(QStringLiteral("m_contributeTable"));
        m_contributeTable->horizontalHeader()->setStretchLastSection(true);
        m_contributeTable->verticalHeader()->setStretchLastSection(false);

        horizontalLayout_2->addWidget(m_contributeTable);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btn_show = new QPushButton(WinContributorCatalog);
        btn_show->setObjectName(QStringLiteral("btn_show"));
        btn_show->setMinimumSize(QSize(200, 0));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/editor.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btn_show->setIcon(icon9);

        horizontalLayout_3->addWidget(btn_show);

        horizontalSpacer_2 = new QSpacerItem(358, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(WinContributorCatalog);

        QMetaObject::connectSlotsByName(WinContributorCatalog);
    } // setupUi

    void retranslateUi(QWidget *WinContributorCatalog)
    {
        WinContributorCatalog->setWindowTitle(QApplication::translate("WinContributorCatalog", "WinContributorCatalog", Q_NULLPTR));
        btn_article->setText(QApplication::translate("WinContributorCatalog", "\344\275\234\350\200\205\346\226\207\347\253\240", Q_NULLPTR));
        btn_search->setText(QApplication::translate("WinContributorCatalog", "\351\253\230\347\272\247\346\220\234\347\264\242", Q_NULLPTR));
        btn_print->setText(QApplication::translate("WinContributorCatalog", "\346\212\245\350\241\250\346\211\223\345\215\260", Q_NULLPTR));
        btn_delContributor->setText(QApplication::translate("WinContributorCatalog", "\345\210\240\351\231\244\346\212\225\347\250\277\344\272\272", Q_NULLPTR));
        btn_addContributor->setText(QApplication::translate("WinContributorCatalog", "\345\242\236\345\212\240\346\212\225\347\250\277\344\272\272", Q_NULLPTR));
        btn_contributor->setText(QApplication::translate("WinContributorCatalog", "\346\212\225\347\250\277\344\272\272\350\257\246\346\203\205", Q_NULLPTR));
        btn_delUnit->setText(QApplication::translate("WinContributorCatalog", "\345\210\240\351\231\244\345\215\225\344\275\215", Q_NULLPTR));
        btn_addUnit->setText(QApplication::translate("WinContributorCatalog", "\345\242\236\345\212\240\345\215\225\344\275\215", Q_NULLPTR));
        btn_unit->setText(QApplication::translate("WinContributorCatalog", "\345\215\225\344\275\215\350\257\246\346\203\205", Q_NULLPTR));
        btn_show->setText(QApplication::translate("WinContributorCatalog", "\346\230\276\347\244\272\346\212\225\347\250\277\344\277\241\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WinContributorCatalog: public Ui_WinContributorCatalog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_CONTRIBUTOR_CATALOG_H
