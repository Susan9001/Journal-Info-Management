/********************************************************************************
** Form generated from reading UI file 'd_editor_info.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_EDITOR_INFO_H
#define UI_D_EDITOR_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DEditorInfo
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
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_email;
    QLineEdit *line_email;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_publisher;
    QComboBox *cmb_publisher;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *btn_publisher;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer;
    QToolButton *btn_journal;
    QToolButton *btn_confirm;

    void setupUi(QWidget *DEditorInfo)
    {
        if (DEditorInfo->objectName().isEmpty())
            DEditorInfo->setObjectName(QStringLiteral("DEditorInfo"));
        DEditorInfo->resize(629, 345);
        verticalLayout = new QVBoxLayout(DEditorInfo);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_title = new QLabel(DEditorInfo);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setMaximumSize(QSize(16777215, 39));

        verticalLayout->addWidget(label_title);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_id = new QLabel(DEditorInfo);
        label_id->setObjectName(QStringLiteral("label_id"));
        label_id->setMinimumSize(QSize(80, 0));
        label_id->setTextFormat(Qt::RichText);

        horizontalLayout->addWidget(label_id);

        line_id = new QLineEdit(DEditorInfo);
        line_id->setObjectName(QStringLiteral("line_id"));
        line_id->setEnabled(false);

        horizontalLayout->addWidget(line_id);


        horizontalLayout_8->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_name = new QLabel(DEditorInfo);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setTextFormat(Qt::RichText);

        horizontalLayout_4->addWidget(label_name);

        line_name = new QLineEdit(DEditorInfo);
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
        label_phone = new QLabel(DEditorInfo);
        label_phone->setObjectName(QStringLiteral("label_phone"));
        label_phone->setMinimumSize(QSize(80, 0));
        label_phone->setMaximumSize(QSize(80, 16777215));
        label_phone->setTextFormat(Qt::RichText);

        horizontalLayout_2->addWidget(label_phone);

        line_phone = new QLineEdit(DEditorInfo);
        line_phone->setObjectName(QStringLiteral("line_phone"));

        horizontalLayout_2->addWidget(line_phone);


        horizontalLayout_9->addLayout(horizontalLayout_2);

        horizontalLayout_9->setStretch(0, 15);

        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_email = new QLabel(DEditorInfo);
        label_email->setObjectName(QStringLiteral("label_email"));
        label_email->setMinimumSize(QSize(80, 0));
        label_email->setMaximumSize(QSize(16777215, 16777215));
        label_email->setTextFormat(Qt::RichText);

        horizontalLayout_5->addWidget(label_email);

        line_email = new QLineEdit(DEditorInfo);
        line_email->setObjectName(QStringLiteral("line_email"));

        horizontalLayout_5->addWidget(line_email);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_publisher = new QLabel(DEditorInfo);
        label_publisher->setObjectName(QStringLiteral("label_publisher"));
        label_publisher->setMinimumSize(QSize(80, 0));
        label_publisher->setMaximumSize(QSize(80, 16777215));
        label_publisher->setTextFormat(Qt::RichText);

        horizontalLayout_6->addWidget(label_publisher);

        cmb_publisher = new QComboBox(DEditorInfo);
        cmb_publisher->setObjectName(QStringLiteral("cmb_publisher"));
        cmb_publisher->setEditable(true);

        horizontalLayout_6->addWidget(cmb_publisher);


        horizontalLayout_7->addLayout(horizontalLayout_6);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        btn_publisher = new QToolButton(DEditorInfo);
        btn_publisher->setObjectName(QStringLiteral("btn_publisher"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/printer_128px_25992_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_publisher->setIcon(icon);
        btn_publisher->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_7->addWidget(btn_publisher);

        horizontalLayout_7->setStretch(0, 22);
        horizontalLayout_7->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);

        btn_journal = new QToolButton(DEditorInfo);
        btn_journal->setObjectName(QStringLiteral("btn_journal"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/book_books.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btn_journal->setIcon(icon1);
        btn_journal->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_12->addWidget(btn_journal);

        btn_confirm = new QToolButton(DEditorInfo);
        btn_confirm->setObjectName(QStringLiteral("btn_confirm"));
        btn_confirm->setMinimumSize(QSize(143, 0));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/accept_approve_comfirm_ok_tick_yes.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_confirm->setIcon(icon2);
        btn_confirm->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_12->addWidget(btn_confirm);


        verticalLayout->addLayout(horizontalLayout_12);


        retranslateUi(DEditorInfo);

        QMetaObject::connectSlotsByName(DEditorInfo);
    } // setupUi

    void retranslateUi(QWidget *DEditorInfo)
    {
        DEditorInfo->setWindowTitle(QApplication::translate("DEditorInfo", "\344\270\273\347\274\226\350\257\246\346\203\205", Q_NULLPTR));
        label_title->setText(QApplication::translate("DEditorInfo", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">\344\270\273 \347\274\226</span></p></body></html>", Q_NULLPTR));
        label_id->setText(QApplication::translate("DEditorInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\274\226\345\217\267</span></p></body></html>", Q_NULLPTR));
        label_name->setText(QApplication::translate("DEditorInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\247\223\345\220\215</span></p></body></html>", Q_NULLPTR));
        label_phone->setText(QApplication::translate("DEditorInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\224\265\350\257\235</span></p></body></html>", Q_NULLPTR));
        label_email->setText(QApplication::translate("DEditorInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\202\256\347\256\261</span></p></body></html>", Q_NULLPTR));
        label_publisher->setText(QApplication::translate("DEditorInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\207\272\347\211\210\347\244\276</span></p></body></html>", Q_NULLPTR));
        btn_publisher->setText(QApplication::translate("DEditorInfo", "\345\207\272\347\211\210\347\244\276\350\257\246\346\203\205", Q_NULLPTR));
        btn_journal->setText(QApplication::translate("DEditorInfo", "\350\264\237\350\264\243\345\210\212\347\211\251", Q_NULLPTR));
        btn_confirm->setText(QApplication::translate("DEditorInfo", "\347\241\256\350\256\244\344\277\256\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DEditorInfo: public Ui_DEditorInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_EDITOR_INFO_H
