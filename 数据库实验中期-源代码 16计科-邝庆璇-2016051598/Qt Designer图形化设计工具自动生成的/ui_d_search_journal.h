/********************************************************************************
** Form generated from reading UI file 'd_search_journal.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_SEARCH_JOURNAL_H
#define UI_D_SEARCH_JOURNAL_H

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

class Ui_DSearchJournal
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_typee;
    QLineEdit *line_typee;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_name;
    QLineEdit *line_name;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_publisher;
    QLineEdit *line_publisher;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_confirm;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DSearchJournal)
    {
        if (DSearchJournal->objectName().isEmpty())
            DSearchJournal->setObjectName(QStringLiteral("DSearchJournal"));
        DSearchJournal->resize(591, 272);
        verticalLayout = new QVBoxLayout(DSearchJournal);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_typee = new QLabel(DSearchJournal);
        label_typee->setObjectName(QStringLiteral("label_typee"));
        label_typee->setMinimumSize(QSize(90, 0));

        horizontalLayout->addWidget(label_typee);

        line_typee = new QLineEdit(DSearchJournal);
        line_typee->setObjectName(QStringLiteral("line_typee"));

        horizontalLayout->addWidget(line_typee);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_name = new QLabel(DSearchJournal);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setMinimumSize(QSize(90, 0));

        horizontalLayout_2->addWidget(label_name);

        line_name = new QLineEdit(DSearchJournal);
        line_name->setObjectName(QStringLiteral("line_name"));

        horizontalLayout_2->addWidget(line_name);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_publisher = new QLabel(DSearchJournal);
        label_publisher->setObjectName(QStringLiteral("label_publisher"));
        label_publisher->setMinimumSize(QSize(90, 0));

        horizontalLayout_3->addWidget(label_publisher);

        line_publisher = new QLineEdit(DSearchJournal);
        line_publisher->setObjectName(QStringLiteral("line_publisher"));

        horizontalLayout_3->addWidget(line_publisher);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btn_confirm = new QPushButton(DSearchJournal);
        btn_confirm->setObjectName(QStringLiteral("btn_confirm"));
        btn_confirm->setMinimumSize(QSize(150, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/accept_approve_comfirm_ok_tick_yes.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_confirm->setIcon(icon);

        horizontalLayout_4->addWidget(btn_confirm);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(DSearchJournal);

        QMetaObject::connectSlotsByName(DSearchJournal);
    } // setupUi

    void retranslateUi(QDialog *DSearchJournal)
    {
        DSearchJournal->setWindowTitle(QApplication::translate("DSearchJournal", "\346\220\234\347\264\242\346\234\237\345\210\212", Q_NULLPTR));
        label_typee->setText(QApplication::translate("DSearchJournal", "\346\214\211\347\261\273\345\236\213\345\220\215", Q_NULLPTR));
        label_name->setText(QApplication::translate("DSearchJournal", "\346\214\211\346\234\237\345\210\212\345\220\215", Q_NULLPTR));
        label_publisher->setText(QApplication::translate("DSearchJournal", "\346\214\211\345\207\272\347\211\210\347\244\276\345\220\215", Q_NULLPTR));
        btn_confirm->setText(QApplication::translate("DSearchJournal", "\347\241\256\350\256\244\346\220\234\347\264\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DSearchJournal: public Ui_DSearchJournal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_SEARCH_JOURNAL_H
