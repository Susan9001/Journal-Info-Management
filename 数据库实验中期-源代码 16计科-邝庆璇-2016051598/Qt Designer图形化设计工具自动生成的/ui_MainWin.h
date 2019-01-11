/********************************************************************************
** Form generated from reading UI file 'MainWin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWinClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *stacked_p1;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *title;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *btn_firstEnter;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QWidget *stacked_p2;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *p_journal;
    QWidget *p_contributor;
    QWidget *p_article;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWinClass)
    {
        if (MainWinClass->objectName().isEmpty())
            MainWinClass->setObjectName(QStringLiteral("MainWinClass"));
        MainWinClass->resize(1196, 774);
        centralWidget = new QWidget(MainWinClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stacked_p1 = new QWidget();
        stacked_p1->setObjectName(QStringLiteral("stacked_p1"));
        verticalLayout_2 = new QVBoxLayout(stacked_p1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        title = new QLabel(stacked_p1);
        title->setObjectName(QStringLiteral("title"));
        title->setMinimumSize(QSize(500, 100));
        title->setTextFormat(Qt::RichText);
        title->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(title);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 75, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btn_firstEnter = new QToolButton(stacked_p1);
        btn_firstEnter->setObjectName(QStringLiteral("btn_firstEnter"));
        btn_firstEnter->setMinimumSize(QSize(240, 90));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/editor.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btn_firstEnter->setIcon(icon);
        btn_firstEnter->setIconSize(QSize(90, 60));
        btn_firstEnter->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(btn_firstEnter);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        horizontalLayout_2->setStretch(0, 13);
        horizontalLayout_2->setStretch(2, 13);

        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 211, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(658, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label_2 = new QLabel(stacked_p1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(stacked_p1);
        stacked_p2 = new QWidget();
        stacked_p2->setObjectName(QStringLiteral("stacked_p2"));
        verticalLayout_3 = new QVBoxLayout(stacked_p2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tabWidget = new QTabWidget(stacked_p2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        p_journal = new QWidget();
        p_journal->setObjectName(QStringLiteral("p_journal"));
        tabWidget->addTab(p_journal, QString());
        p_contributor = new QWidget();
        p_contributor->setObjectName(QStringLiteral("p_contributor"));
        tabWidget->addTab(p_contributor, QString());
        p_article = new QWidget();
        p_article->setObjectName(QStringLiteral("p_article"));
        tabWidget->addTab(p_article, QString());

        verticalLayout_3->addWidget(tabWidget);

        stackedWidget->addWidget(stacked_p2);

        verticalLayout->addWidget(stackedWidget);

        MainWinClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWinClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1196, 30));
        MainWinClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWinClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWinClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWinClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWinClass->setStatusBar(statusBar);

        retranslateUi(MainWinClass);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWinClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWinClass)
    {
        MainWinClass->setWindowTitle(QApplication::translate("MainWinClass", "\346\234\237\345\210\212\344\277\241\346\201\257\347\256\241\347\220\206", Q_NULLPTR));
        title->setText(QApplication::translate("MainWinClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:40pt; font-weight:600;\">\345\210\212\347\211\251\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", Q_NULLPTR));
        btn_firstEnter->setText(QApplication::translate("MainWinClass", "   \350\277\236\346\225\260\346\215\256\345\272\223\n"
"   \350\277\233\345\205\245\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWinClass", "<html><head/><body><p>\345\210\266\344\275\234\344\272\272\357\274\23216\350\256\241\347\247\221 \351\202\235\345\272\206\347\222\207 2016051598</p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(p_journal), QApplication::translate("MainWinClass", "\346\234\237\345\210\212\347\233\256\345\275\225", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(p_contributor), QApplication::translate("MainWinClass", "\346\212\225\347\250\277\344\272\272\347\233\256\345\275\225", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(p_article), QApplication::translate("MainWinClass", "\346\226\207\347\253\240\347\233\256\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWinClass: public Ui_MainWinClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
