/********************************************************************************
** Form generated from reading UI file 'd_contributor_info.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_CONTRIBUTOR_INFO_H
#define UI_D_CONTRIBUTOR_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DContributorInfo
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_title;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout;
    QLabel *label_id;
    QLineEdit *line_id;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_name;
    QLineEdit *line_name;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_phone;
    QLineEdit *line_phone;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_email;
    QLineEdit *line_email;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_workUnit;
    QComboBox *cmb_unit;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_paperCount;
    QLineEdit *line_paperCount;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_paper;
    QToolButton *btn_confirm;

    void setupUi(QDialog *DContributorInfo)
    {
        if (DContributorInfo->objectName().isEmpty())
            DContributorInfo->setObjectName(QStringLiteral("DContributorInfo"));
        DContributorInfo->resize(600, 360);
        DContributorInfo->setMinimumSize(QSize(0, 0));
        DContributorInfo->setMaximumSize(QSize(635, 360));
        verticalLayout = new QVBoxLayout(DContributorInfo);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_title = new QLabel(DContributorInfo);
        label_title->setObjectName(QStringLiteral("label_title"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_title->sizePolicy().hasHeightForWidth());
        label_title->setSizePolicy(sizePolicy);
        label_title->setMaximumSize(QSize(16777215, 39));
        label_title->setTextFormat(Qt::RichText);

        verticalLayout->addWidget(label_title);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_id = new QLabel(DContributorInfo);
        label_id->setObjectName(QStringLiteral("label_id"));
        label_id->setTextFormat(Qt::RichText);

        horizontalLayout->addWidget(label_id);

        line_id = new QLineEdit(DContributorInfo);
        line_id->setObjectName(QStringLiteral("line_id"));

        horizontalLayout->addWidget(line_id);


        horizontalLayout_8->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_name = new QLabel(DContributorInfo);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setTextFormat(Qt::RichText);

        horizontalLayout_4->addWidget(label_name);

        line_name = new QLineEdit(DContributorInfo);
        line_name->setObjectName(QStringLiteral("line_name"));

        horizontalLayout_4->addWidget(line_name);


        horizontalLayout_8->addLayout(horizontalLayout_4);

        horizontalLayout_8->setStretch(0, 11);
        horizontalLayout_8->setStretch(1, 1);
        horizontalLayout_8->setStretch(2, 11);

        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_phone = new QLabel(DContributorInfo);
        label_phone->setObjectName(QStringLiteral("label_phone"));
        label_phone->setTextFormat(Qt::RichText);

        horizontalLayout_2->addWidget(label_phone);

        line_phone = new QLineEdit(DContributorInfo);
        line_phone->setObjectName(QStringLiteral("line_phone"));

        horizontalLayout_2->addWidget(line_phone);


        horizontalLayout_9->addLayout(horizontalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_email = new QLabel(DContributorInfo);
        label_email->setObjectName(QStringLiteral("label_email"));
        label_email->setTextFormat(Qt::RichText);

        horizontalLayout_5->addWidget(label_email);

        line_email = new QLineEdit(DContributorInfo);
        line_email->setObjectName(QStringLiteral("line_email"));

        horizontalLayout_5->addWidget(line_email);


        horizontalLayout_9->addLayout(horizontalLayout_5);

        horizontalLayout_9->setStretch(0, 11);
        horizontalLayout_9->setStretch(1, 1);
        horizontalLayout_9->setStretch(2, 11);

        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_workUnit = new QLabel(DContributorInfo);
        label_workUnit->setObjectName(QStringLiteral("label_workUnit"));
        sizePolicy.setHeightForWidth(label_workUnit->sizePolicy().hasHeightForWidth());
        label_workUnit->setSizePolicy(sizePolicy);
        label_workUnit->setTextFormat(Qt::RichText);

        horizontalLayout_3->addWidget(label_workUnit);

        cmb_unit = new QComboBox(DContributorInfo);
        cmb_unit->setObjectName(QStringLiteral("cmb_unit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cmb_unit->sizePolicy().hasHeightForWidth());
        cmb_unit->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(cmb_unit);


        horizontalLayout_7->addLayout(horizontalLayout_3);

        horizontalLayout_7->setStretch(0, 12);

        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_paperCount = new QLabel(DContributorInfo);
        label_paperCount->setObjectName(QStringLiteral("label_paperCount"));
        label_paperCount->setTextFormat(Qt::RichText);

        horizontalLayout_6->addWidget(label_paperCount);

        line_paperCount = new QLineEdit(DContributorInfo);
        line_paperCount->setObjectName(QStringLiteral("line_paperCount"));
        line_paperCount->setEnabled(true);
        line_paperCount->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_6->addWidget(line_paperCount);


        horizontalLayout_10->addLayout(horizontalLayout_6);

        horizontalLayout_10->setStretch(0, 12);

        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer);

        btn_paper = new QPushButton(DContributorInfo);
        btn_paper->setObjectName(QStringLiteral("btn_paper"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/page_128px_535768_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_paper->setIcon(icon);

        horizontalLayout_11->addWidget(btn_paper);

        btn_confirm = new QToolButton(DContributorInfo);
        btn_confirm->setObjectName(QStringLiteral("btn_confirm"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/accept_approve_comfirm_ok_tick_yes.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_confirm->setIcon(icon1);
        btn_confirm->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_11->addWidget(btn_confirm);


        verticalLayout->addLayout(horizontalLayout_11);


        retranslateUi(DContributorInfo);

        QMetaObject::connectSlotsByName(DContributorInfo);
    } // setupUi

    void retranslateUi(QDialog *DContributorInfo)
    {
        DContributorInfo->setWindowTitle(QApplication::translate("DContributorInfo", "\346\212\225\347\250\277\344\272\272\350\257\246\346\203\205", Q_NULLPTR));
        label_title->setText(QApplication::translate("DContributorInfo", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">\346\212\225 \347\250\277 \344\272\272</span></p></body></html>", Q_NULLPTR));
        label_id->setText(QApplication::translate("DContributorInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\274\226\345\217\267</span></p></body></html>", Q_NULLPTR));
        label_name->setText(QApplication::translate("DContributorInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\247\223\345\220\215</span></p></body></html>", Q_NULLPTR));
        label_phone->setText(QApplication::translate("DContributorInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\224\265\350\257\235</span></p></body></html>", Q_NULLPTR));
        label_email->setText(QApplication::translate("DContributorInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\202\256\347\256\261</span></p></body></html>", Q_NULLPTR));
        label_workUnit->setText(QApplication::translate("DContributorInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\267\245\344\275\234\345\215\225\344\275\215</span></p></body></html>", Q_NULLPTR));
        label_paperCount->setText(QApplication::translate("DContributorInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\212\225\347\250\277\346\225\260\347\233\256</span></p></body></html>", Q_NULLPTR));
        btn_paper->setText(QApplication::translate("DContributorInfo", "\346\237\245\347\234\213\346\226\207\347\253\240", Q_NULLPTR));
        btn_confirm->setText(QApplication::translate("DContributorInfo", "\347\241\256\350\256\244\344\277\256\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DContributorInfo: public Ui_DContributorInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_CONTRIBUTOR_INFO_H
