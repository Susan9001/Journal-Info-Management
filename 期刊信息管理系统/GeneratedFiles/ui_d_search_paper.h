/********************************************************************************
** Form generated from reading UI file 'd_search_paper.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_SEARCH_PAPER_H
#define UI_D_SEARCH_PAPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DSearchPaper
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_paper;
    QLineEdit *line_paper;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_contributor;
    QLineEdit *line_contributor;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_name;
    QLineEdit *line_journal;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_confirm;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DSearchPaper)
    {
        if (DSearchPaper->objectName().isEmpty())
            DSearchPaper->setObjectName(QStringLiteral("DSearchPaper"));
        DSearchPaper->resize(591, 272);
        verticalLayout = new QVBoxLayout(DSearchPaper);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_paper = new QLabel(DSearchPaper);
        label_paper->setObjectName(QStringLiteral("label_paper"));
        label_paper->setMinimumSize(QSize(90, 0));

        horizontalLayout->addWidget(label_paper);

        line_paper = new QLineEdit(DSearchPaper);
        line_paper->setObjectName(QStringLiteral("line_paper"));

        horizontalLayout->addWidget(line_paper);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_contributor = new QLabel(DSearchPaper);
        label_contributor->setObjectName(QStringLiteral("label_contributor"));
        label_contributor->setMinimumSize(QSize(90, 0));

        horizontalLayout_3->addWidget(label_contributor);

        line_contributor = new QLineEdit(DSearchPaper);
        line_contributor->setObjectName(QStringLiteral("line_contributor"));

        horizontalLayout_3->addWidget(line_contributor);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_name = new QLabel(DSearchPaper);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setMinimumSize(QSize(90, 0));

        horizontalLayout_2->addWidget(label_name);

        line_journal = new QLineEdit(DSearchPaper);
        line_journal->setObjectName(QStringLiteral("line_journal"));

        horizontalLayout_2->addWidget(line_journal);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btn_confirm = new QPushButton(DSearchPaper);
        btn_confirm->setObjectName(QStringLiteral("btn_confirm"));
        btn_confirm->setMinimumSize(QSize(150, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/accept_approve_comfirm_ok_tick_yes.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_confirm->setIcon(icon);

        horizontalLayout_4->addWidget(btn_confirm);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(DSearchPaper);

        QMetaObject::connectSlotsByName(DSearchPaper);
    } // setupUi

    void retranslateUi(QDialog *DSearchPaper)
    {
        DSearchPaper->setWindowTitle(QApplication::translate("DSearchPaper", "\346\220\234\347\264\242\350\256\272\346\226\207", Q_NULLPTR));
        label_paper->setText(QApplication::translate("DSearchPaper", "\346\214\211\346\226\207\347\253\240\345\220\215", Q_NULLPTR));
        label_contributor->setText(QApplication::translate("DSearchPaper", "\346\214\211\346\212\225\347\250\277\344\272\272\345\220\215", Q_NULLPTR));
        label_name->setText(QApplication::translate("DSearchPaper", "\346\214\211\346\234\237\345\210\212\345\220\215", Q_NULLPTR));
        btn_confirm->setText(QApplication::translate("DSearchPaper", "\347\241\256\350\256\244\346\220\234\347\264\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DSearchPaper: public Ui_DSearchPaper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_SEARCH_PAPER_H
