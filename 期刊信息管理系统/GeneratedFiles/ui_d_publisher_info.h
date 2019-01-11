/********************************************************************************
** Form generated from reading UI file 'd_publisher_info.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_PUBLISHER_INFO_H
#define UI_D_PUBLISHER_INFO_H

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

class Ui_DPublisherInfo
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
    QToolButton *btn_confirm;

    void setupUi(QWidget *DPublisherInfo)
    {
        if (DPublisherInfo->objectName().isEmpty())
            DPublisherInfo->setObjectName(QStringLiteral("DPublisherInfo"));
        DPublisherInfo->resize(598, 343);
        verticalLayout = new QVBoxLayout(DPublisherInfo);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_title = new QLabel(DPublisherInfo);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setMaximumSize(QSize(16777215, 39));

        verticalLayout->addWidget(label_title);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_id = new QLabel(DPublisherInfo);
        label_id->setObjectName(QStringLiteral("label_id"));
        label_id->setTextFormat(Qt::RichText);

        horizontalLayout->addWidget(label_id);

        line_id = new QLineEdit(DPublisherInfo);
        line_id->setObjectName(QStringLiteral("line_id"));

        horizontalLayout->addWidget(line_id);


        horizontalLayout_8->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_name = new QLabel(DPublisherInfo);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setTextFormat(Qt::RichText);

        horizontalLayout_4->addWidget(label_name);

        line_name = new QLineEdit(DPublisherInfo);
        line_name->setObjectName(QStringLiteral("line_name"));

        horizontalLayout_4->addWidget(line_name);


        horizontalLayout_8->addLayout(horizontalLayout_4);

        horizontalLayout_8->setStretch(0, 15);
        horizontalLayout_8->setStretch(1, 1);
        horizontalLayout_8->setStretch(2, 15);

        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_phone = new QLabel(DPublisherInfo);
        label_phone->setObjectName(QStringLiteral("label_phone"));
        label_phone->setTextFormat(Qt::RichText);

        horizontalLayout_2->addWidget(label_phone);

        line_phone = new QLineEdit(DPublisherInfo);
        line_phone->setObjectName(QStringLiteral("line_phone"));

        horizontalLayout_2->addWidget(line_phone);


        horizontalLayout_9->addLayout(horizontalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_email = new QLabel(DPublisherInfo);
        label_email->setObjectName(QStringLiteral("label_email"));
        label_email->setTextFormat(Qt::RichText);

        horizontalLayout_5->addWidget(label_email);

        line_email = new QLineEdit(DPublisherInfo);
        line_email->setObjectName(QStringLiteral("line_email"));

        horizontalLayout_5->addWidget(line_email);


        horizontalLayout_9->addLayout(horizontalLayout_5);

        horizontalLayout_9->setStretch(0, 15);
        horizontalLayout_9->setStretch(1, 1);
        horizontalLayout_9->setStretch(2, 15);

        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_address = new QLabel(DPublisherInfo);
        label_address->setObjectName(QStringLiteral("label_address"));
        label_address->setTextFormat(Qt::RichText);

        horizontalLayout_3->addWidget(label_address);

        line_address = new QLineEdit(DPublisherInfo);
        line_address->setObjectName(QStringLiteral("line_address"));

        horizontalLayout_3->addWidget(line_address);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        btn_confirm = new QToolButton(DPublisherInfo);
        btn_confirm->setObjectName(QStringLiteral("btn_confirm"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/accept_approve_comfirm_ok_tick_yes.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_confirm->setIcon(icon);
        btn_confirm->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_6->addWidget(btn_confirm);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(DPublisherInfo);

        QMetaObject::connectSlotsByName(DPublisherInfo);
    } // setupUi

    void retranslateUi(QWidget *DPublisherInfo)
    {
        DPublisherInfo->setWindowTitle(QApplication::translate("DPublisherInfo", "\345\207\272\347\211\210\347\244\276\350\257\246\346\203\205", Q_NULLPTR));
        label_title->setText(QApplication::translate("DPublisherInfo", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">\345\207\272 \347\211\210 \347\244\276</span></p></body></html>", Q_NULLPTR));
        label_id->setText(QApplication::translate("DPublisherInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\274\226\345\217\267</span></p></body></html>", Q_NULLPTR));
        label_name->setText(QApplication::translate("DPublisherInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\220\215\345\255\227</span></p></body></html>", Q_NULLPTR));
        label_phone->setText(QApplication::translate("DPublisherInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\224\265\350\257\235</span></p></body></html>", Q_NULLPTR));
        label_email->setText(QApplication::translate("DPublisherInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\202\256\347\256\261</span></p></body></html>", Q_NULLPTR));
        label_address->setText(QApplication::translate("DPublisherInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\234\260\345\235\200</span></p></body></html>", Q_NULLPTR));
        btn_confirm->setText(QApplication::translate("DPublisherInfo", "\347\241\256\350\256\244\344\277\256\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DPublisherInfo: public Ui_DPublisherInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_PUBLISHER_INFO_H
