/********************************************************************************
** Form generated from reading UI file 'd_search_contributor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_SEARCH_CONTRIBUTOR_H
#define UI_D_SEARCH_CONTRIBUTOR_H

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

class Ui_DSearchContributor
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_unit;
    QLineEdit *line_unit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_name;
    QLineEdit *line_name;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_confirm;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DSearchContributor)
    {
        if (DSearchContributor->objectName().isEmpty())
            DSearchContributor->setObjectName(QStringLiteral("DSearchContributor"));
        DSearchContributor->resize(499, 218);
        verticalLayout = new QVBoxLayout(DSearchContributor);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_unit = new QLabel(DSearchContributor);
        label_unit->setObjectName(QStringLiteral("label_unit"));
        label_unit->setMinimumSize(QSize(90, 0));

        horizontalLayout->addWidget(label_unit);

        line_unit = new QLineEdit(DSearchContributor);
        line_unit->setObjectName(QStringLiteral("line_unit"));

        horizontalLayout->addWidget(line_unit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_name = new QLabel(DSearchContributor);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setMinimumSize(QSize(90, 0));

        horizontalLayout_2->addWidget(label_name);

        line_name = new QLineEdit(DSearchContributor);
        line_name->setObjectName(QStringLiteral("line_name"));

        horizontalLayout_2->addWidget(line_name);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btn_confirm = new QPushButton(DSearchContributor);
        btn_confirm->setObjectName(QStringLiteral("btn_confirm"));
        btn_confirm->setMinimumSize(QSize(150, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/accept_approve_comfirm_ok_tick_yes.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_confirm->setIcon(icon);

        horizontalLayout_4->addWidget(btn_confirm);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(DSearchContributor);

        QMetaObject::connectSlotsByName(DSearchContributor);
    } // setupUi

    void retranslateUi(QDialog *DSearchContributor)
    {
        DSearchContributor->setWindowTitle(QApplication::translate("DSearchContributor", "\346\220\234\347\264\242\346\212\225\347\250\277\344\272\272", Q_NULLPTR));
        label_unit->setText(QApplication::translate("DSearchContributor", "\346\214\211\345\267\245\344\275\234\345\215\225\344\275\215", Q_NULLPTR));
        label_name->setText(QApplication::translate("DSearchContributor", "\346\214\211\346\212\225\347\250\277\344\272\272\345\220\215", Q_NULLPTR));
        btn_confirm->setText(QApplication::translate("DSearchContributor", "\347\241\256\350\256\244\346\220\234\347\264\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DSearchContributor: public Ui_DSearchContributor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_SEARCH_CONTRIBUTOR_H
