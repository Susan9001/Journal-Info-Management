/********************************************************************************
** Form generated from reading UI file 'win_journal_catalog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_JOURNAL_CATALOG_H
#define UI_WIN_JOURNAL_CATALOG_H

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

class Ui_WinJournalCatalog
{
public:
    QAction *actionSearchJournal;
    QAction *actionArticle;
    QAction *actionRemoveJournal;
    QAction *actionAddJournal;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *btn_search;
    QToolButton *btn_print;
    QToolButton *btn_article;
    QToolButton *btn_journalInfo;
    QToolButton *btn_delete;
    QToolButton *btn_add;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *m_catalogTree;
    QTableView *m_journalTable;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_show;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *WinJournalCatalog)
    {
        if (WinJournalCatalog->objectName().isEmpty())
            WinJournalCatalog->setObjectName(QStringLiteral("WinJournalCatalog"));
        WinJournalCatalog->resize(852, 490);
        actionSearchJournal = new QAction(WinJournalCatalog);
        actionSearchJournal->setObjectName(QStringLiteral("actionSearchJournal"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/Search_complex.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSearchJournal->setIcon(icon);
        actionArticle = new QAction(WinJournalCatalog);
        actionArticle->setObjectName(QStringLiteral("actionArticle"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/page_128px_535768_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionArticle->setIcon(icon1);
        actionRemoveJournal = new QAction(WinJournalCatalog);
        actionRemoveJournal->setObjectName(QStringLiteral("actionRemoveJournal"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/remove_24px_35144_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemoveJournal->setIcon(icon2);
        actionAddJournal = new QAction(WinJournalCatalog);
        actionAddJournal->setObjectName(QStringLiteral("actionAddJournal"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/add_plus_128px_11093_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddJournal->setIcon(icon3);
        verticalLayout = new QVBoxLayout(WinJournalCatalog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_search = new QToolButton(WinJournalCatalog);
        btn_search->setObjectName(QStringLiteral("btn_search"));
        btn_search->setIcon(icon);
        btn_search->setIconSize(QSize(38, 38));
        btn_search->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_search);

        btn_print = new QToolButton(WinJournalCatalog);
        btn_print->setObjectName(QStringLiteral("btn_print"));
        btn_print->setMaximumSize(QSize(16777000, 67));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/printer_128px_25992_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_print->setIcon(icon4);
        btn_print->setIconSize(QSize(40, 50));
        btn_print->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_print);

        btn_article = new QToolButton(WinJournalCatalog);
        btn_article->setObjectName(QStringLiteral("btn_article"));
        btn_article->setIcon(icon1);
        btn_article->setIconSize(QSize(38, 38));
        btn_article->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_article);

        btn_journalInfo = new QToolButton(WinJournalCatalog);
        btn_journalInfo->setObjectName(QStringLiteral("btn_journalInfo"));
        btn_journalInfo->setMinimumSize(QSize(0, 66));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/book_simple.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btn_journalInfo->setIcon(icon5);
        btn_journalInfo->setIconSize(QSize(38, 38));
        btn_journalInfo->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_journalInfo);

        btn_delete = new QToolButton(WinJournalCatalog);
        btn_delete->setObjectName(QStringLiteral("btn_delete"));
        btn_delete->setIcon(icon2);
        btn_delete->setIconSize(QSize(50, 40));
        btn_delete->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_delete);

        btn_add = new QToolButton(WinJournalCatalog);
        btn_add->setObjectName(QStringLiteral("btn_add"));
        btn_add->setIcon(icon3);
        btn_add->setIconSize(QSize(38, 38));
        btn_add->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(btn_add);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_catalogTree = new QTreeWidget(WinJournalCatalog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        m_catalogTree->setHeaderItem(__qtreewidgetitem);
        m_catalogTree->setObjectName(QStringLiteral("m_catalogTree"));

        horizontalLayout_2->addWidget(m_catalogTree);

        m_journalTable = new QTableView(WinJournalCatalog);
        m_journalTable->setObjectName(QStringLiteral("m_journalTable"));
        m_journalTable->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_2->addWidget(m_journalTable);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btn_show = new QPushButton(WinJournalCatalog);
        btn_show->setObjectName(QStringLiteral("btn_show"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/Magazine_simple.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_show->setIcon(icon6);

        horizontalLayout_3->addWidget(btn_show);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(WinJournalCatalog);

        QMetaObject::connectSlotsByName(WinJournalCatalog);
    } // setupUi

    void retranslateUi(QWidget *WinJournalCatalog)
    {
        WinJournalCatalog->setWindowTitle(QApplication::translate("WinJournalCatalog", "WinJournalCatalog", Q_NULLPTR));
        actionSearchJournal->setText(QApplication::translate("WinJournalCatalog", "\351\253\230\347\272\247\346\220\234\347\264\242", Q_NULLPTR));
        actionArticle->setText(QApplication::translate("WinJournalCatalog", "\346\234\237\345\210\212\346\226\207\347\253\240", Q_NULLPTR));
        actionRemoveJournal->setText(QApplication::translate("WinJournalCatalog", "\345\210\240\351\231\244\346\234\237\345\210\212", Q_NULLPTR));
        actionAddJournal->setText(QApplication::translate("WinJournalCatalog", "\345\242\236\345\212\240\346\234\237\345\210\212", Q_NULLPTR));
        btn_search->setText(QApplication::translate("WinJournalCatalog", "\351\253\230\347\272\247\346\220\234\347\264\242", Q_NULLPTR));
        btn_print->setText(QApplication::translate("WinJournalCatalog", "\346\212\245\350\241\250\346\211\223\345\215\260", Q_NULLPTR));
        btn_article->setText(QApplication::translate("WinJournalCatalog", "\346\234\237\345\210\212\346\226\207\347\253\240", Q_NULLPTR));
        btn_journalInfo->setText(QApplication::translate("WinJournalCatalog", "\346\234\237\345\210\212\350\257\246\346\203\205", Q_NULLPTR));
        btn_delete->setText(QApplication::translate("WinJournalCatalog", "\345\210\240\351\231\244\346\234\237\345\210\212", Q_NULLPTR));
        btn_add->setText(QApplication::translate("WinJournalCatalog", "\345\242\236\345\212\240\346\234\237\345\210\212", Q_NULLPTR));
        btn_show->setText(QApplication::translate("WinJournalCatalog", "\346\230\276\347\244\272\346\234\237\345\210\212", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WinJournalCatalog: public Ui_WinJournalCatalog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_JOURNAL_CATALOG_H
