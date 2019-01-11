/********************************************************************************
** Form generated from reading UI file 'd_unit_info.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_UNIT_INFO_H
#define UI_D_UNIT_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DUnitInfo
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
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_address;
    QLineEdit *line_address;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QToolButton *btn_staff;
    QToolButton *btn_confirm;

    void setupUi(QWidget *DUnitInfo)
    {
        if (DUnitInfo->objectName().isEmpty())
            DUnitInfo->setObjectName(QStringLiteral("DUnitInfo"));
        DUnitInfo->resize(602, 340);
        verticalLayout = new QVBoxLayout(DUnitInfo);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_title = new QLabel(DUnitInfo);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setMaximumSize(QSize(16777215, 39));

        verticalLayout->addWidget(label_title);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_id = new QLabel(DUnitInfo);
        label_id->setObjectName(QStringLiteral("label_id"));
        label_id->setTextFormat(Qt::RichText);

        horizontalLayout->addWidget(label_id);

        line_id = new QLineEdit(DUnitInfo);
        line_id->setObjectName(QStringLiteral("line_id"));

        horizontalLayout->addWidget(line_id);


        horizontalLayout_8->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_name = new QLabel(DUnitInfo);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setTextFormat(Qt::RichText);

        horizontalLayout_4->addWidget(label_name);

        line_name = new QLineEdit(DUnitInfo);
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
        label_phone = new QLabel(DUnitInfo);
        label_phone->setObjectName(QStringLiteral("label_phone"));
        label_phone->setTextFormat(Qt::RichText);

        horizontalLayout_2->addWidget(label_phone);

        line_phone = new QLineEdit(DUnitInfo);
        line_phone->setObjectName(QStringLiteral("line_phone"));

        horizontalLayout_2->addWidget(line_phone);


        horizontalLayout_9->addLayout(horizontalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_email = new QLabel(DUnitInfo);
        label_email->setObjectName(QStringLiteral("label_email"));
        label_email->setTextFormat(Qt::RichText);

        horizontalLayout_5->addWidget(label_email);

        line_email = new QLineEdit(DUnitInfo);
        line_email->setObjectName(QStringLiteral("line_email"));

        horizontalLayout_5->addWidget(line_email);


        horizontalLayout_9->addLayout(horizontalLayout_5);

        horizontalLayout_9->setStretch(0, 11);
        horizontalLayout_9->setStretch(1, 1);
        horizontalLayout_9->setStretch(2, 11);

        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_address = new QLabel(DUnitInfo);
        label_address->setObjectName(QStringLiteral("label_address"));
        label_address->setTextFormat(Qt::RichText);

        horizontalLayout_3->addWidget(label_address);

        line_address = new QLineEdit(DUnitInfo);
        line_address->setObjectName(QStringLiteral("line_address"));

        horizontalLayout_3->addWidget(line_address);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        btn_staff = new QToolButton(DUnitInfo);
        btn_staff->setObjectName(QStringLiteral("btn_staff"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/business_man_consultancy_staff_user_128px_107_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btn_staff->setIcon(icon);
        btn_staff->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_6->addWidget(btn_staff);

        btn_confirm = new QToolButton(DUnitInfo);
        btn_confirm->setObjectName(QStringLiteral("btn_confirm"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/accept_approve_comfirm_ok_tick_yes.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_confirm->setIcon(icon1);
        btn_confirm->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_6->addWidget(btn_confirm);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(DUnitInfo);

        QMetaObject::connectSlotsByName(DUnitInfo);
    } // setupUi

    void retranslateUi(QWidget *DUnitInfo)
    {
        DUnitInfo->setWindowTitle(QApplication::translate("DUnitInfo", "\345\215\225\344\275\215\350\257\246\346\203\205", Q_NULLPTR));
        label_title->setText(QApplication::translate("DUnitInfo", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">\345\267\245 \344\275\234 \345\215\225 \344\275\215</span></p></body></html>", Q_NULLPTR));
        label_id->setText(QApplication::translate("DUnitInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\274\226\345\217\267</span></p></body></html>", Q_NULLPTR));
        label_name->setText(QApplication::translate("DUnitInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\220\215\345\255\227</span></p></body></html>", Q_NULLPTR));
        label_phone->setText(QApplication::translate("DUnitInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\224\265\350\257\235</span></p></body></html>", Q_NULLPTR));
        label_email->setText(QApplication::translate("DUnitInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\202\256\347\256\261</span></p></body></html>", Q_NULLPTR));
        label_address->setText(QApplication::translate("DUnitInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\234\260\345\235\200</span></p></body></html>", Q_NULLPTR));
        btn_staff->setText(QApplication::translate("DUnitInfo", "\344\272\272\345\221\230\347\273\237\350\256\241", Q_NULLPTR));
        btn_confirm->setText(QApplication::translate("DUnitInfo", "\347\241\256\350\256\244\344\277\256\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DUnitInfo: public Ui_DUnitInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_UNIT_INFO_H
