/********************************************************************************
** Form generated from reading UI file 'd_journal_info.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_JOURNAL_INFO_H
#define UI_D_JOURNAL_INFO_H

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

class Ui_DJournalInfo
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_title;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_id;
    QLineEdit *line_id;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_name;
    QLineEdit *line_name;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout;
    QLabel *label_catalog;
    QComboBox *cmbox_catalog;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_type;
    QComboBox *cmbox_type;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_editor;
    QComboBox *cmb_editor;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *btn_editor;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_date;
    QLineEdit *line_date;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_email;
    QLineEdit *line_email;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_paper;
    QToolButton *btn_confirm;

    void setupUi(QDialog *DJournalInfo)
    {
        if (DJournalInfo->objectName().isEmpty())
            DJournalInfo->setObjectName(QStringLiteral("DJournalInfo"));
        DJournalInfo->resize(677, 412);
        DJournalInfo->setMinimumSize(QSize(550, 330));
        DJournalInfo->setMaximumSize(QSize(900, 600));
        verticalLayout = new QVBoxLayout(DJournalInfo);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_title = new QLabel(DJournalInfo);
        label_title->setObjectName(QStringLiteral("label_title"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_title->sizePolicy().hasHeightForWidth());
        label_title->setSizePolicy(sizePolicy);
        label_title->setMinimumSize(QSize(6, 0));
        label_title->setMaximumSize(QSize(16777215, 45));
        label_title->setTextFormat(Qt::RichText);

        verticalLayout->addWidget(label_title);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_id = new QLabel(DJournalInfo);
        label_id->setObjectName(QStringLiteral("label_id"));
        label_id->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_5->addWidget(label_id);

        line_id = new QLineEdit(DJournalInfo);
        line_id->setObjectName(QStringLiteral("line_id"));
        line_id->setEnabled(true);
        line_id->setMaximumSize(QSize(239, 16777215));

        horizontalLayout_5->addWidget(line_id);


        horizontalLayout_8->addLayout(horizontalLayout_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_name = new QLabel(DJournalInfo);
        label_name->setObjectName(QStringLiteral("label_name"));

        horizontalLayout_4->addWidget(label_name);

        line_name = new QLineEdit(DJournalInfo);
        line_name->setObjectName(QStringLiteral("line_name"));

        horizontalLayout_4->addWidget(line_name);


        horizontalLayout_8->addLayout(horizontalLayout_4);

        horizontalLayout_8->setStretch(0, 10);
        horizontalLayout_8->setStretch(1, 1);
        horizontalLayout_8->setStretch(2, 10);

        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_catalog = new QLabel(DJournalInfo);
        label_catalog->setObjectName(QStringLiteral("label_catalog"));
        label_catalog->setMinimumSize(QSize(0, 0));
        label_catalog->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(label_catalog);

        cmbox_catalog = new QComboBox(DJournalInfo);
        cmbox_catalog->setObjectName(QStringLiteral("cmbox_catalog"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cmbox_catalog->sizePolicy().hasHeightForWidth());
        cmbox_catalog->setSizePolicy(sizePolicy1);
        cmbox_catalog->setMaximumSize(QSize(239, 16777215));

        horizontalLayout->addWidget(cmbox_catalog);


        horizontalLayout_9->addLayout(horizontalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_type = new QLabel(DJournalInfo);
        label_type->setObjectName(QStringLiteral("label_type"));
        label_type->setMinimumSize(QSize(20, 0));
        label_type->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label_type);

        cmbox_type = new QComboBox(DJournalInfo);
        cmbox_type->setObjectName(QStringLiteral("cmbox_type"));
        cmbox_type->setEnabled(true);
        cmbox_type->setMinimumSize(QSize(50, 0));

        horizontalLayout_3->addWidget(cmbox_type);


        horizontalLayout_9->addLayout(horizontalLayout_3);

        horizontalLayout_9->setStretch(0, 10);
        horizontalLayout_9->setStretch(1, 1);
        horizontalLayout_9->setStretch(2, 10);

        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_editor = new QLabel(DJournalInfo);
        label_editor->setObjectName(QStringLiteral("label_editor"));
        label_editor->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(label_editor);

        cmb_editor = new QComboBox(DJournalInfo);
        cmb_editor->setObjectName(QStringLiteral("cmb_editor"));
        sizePolicy1.setHeightForWidth(cmb_editor->sizePolicy().hasHeightForWidth());
        cmb_editor->setSizePolicy(sizePolicy1);
        cmb_editor->setMaximumSize(QSize(239, 16777215));
        cmb_editor->setEditable(true);

        horizontalLayout_2->addWidget(cmb_editor);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        btn_editor = new QToolButton(DJournalInfo);
        btn_editor->setObjectName(QStringLiteral("btn_editor"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_editor->sizePolicy().hasHeightForWidth());
        btn_editor->setSizePolicy(sizePolicy2);
        btn_editor->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/editor.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btn_editor->setIcon(icon);
        btn_editor->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(btn_editor);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        horizontalLayout_2->setStretch(0, 10);
        horizontalLayout_2->setStretch(1, 30);
        horizontalLayout_2->setStretch(2, 5);
        horizontalLayout_2->setStretch(4, 11);

        horizontalLayout_10->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_date = new QLabel(DJournalInfo);
        label_date->setObjectName(QStringLiteral("label_date"));
        label_date->setMinimumSize(QSize(150, 0));

        horizontalLayout_6->addWidget(label_date);

        line_date = new QLineEdit(DJournalInfo);
        line_date->setObjectName(QStringLiteral("line_date"));
        line_date->setInputMethodHints(Qt::ImhDate);

        horizontalLayout_6->addWidget(line_date);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_email = new QLabel(DJournalInfo);
        label_email->setObjectName(QStringLiteral("label_email"));
        label_email->setMinimumSize(QSize(150, 0));

        horizontalLayout_7->addWidget(label_email);

        line_email = new QLineEdit(DJournalInfo);
        line_email->setObjectName(QStringLiteral("line_email"));
        line_email->setEnabled(false);

        horizontalLayout_7->addWidget(line_email);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer);

        btn_paper = new QPushButton(DJournalInfo);
        btn_paper->setObjectName(QStringLiteral("btn_paper"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/page_128px_535768_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_paper->setIcon(icon1);

        horizontalLayout_11->addWidget(btn_paper);

        btn_confirm = new QToolButton(DJournalInfo);
        btn_confirm->setObjectName(QStringLiteral("btn_confirm"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/accept_approve_comfirm_ok_tick_yes.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_confirm->setIcon(icon2);
        btn_confirm->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_11->addWidget(btn_confirm);


        verticalLayout->addLayout(horizontalLayout_11);


        retranslateUi(DJournalInfo);

        QMetaObject::connectSlotsByName(DJournalInfo);
    } // setupUi

    void retranslateUi(QDialog *DJournalInfo)
    {
        DJournalInfo->setWindowTitle(QApplication::translate("DJournalInfo", "\346\234\237\345\210\212\350\257\246\346\203\205", Q_NULLPTR));
        label_title->setText(QApplication::translate("DJournalInfo", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">\346\234\237 \345\210\212</span></p></body></html>", Q_NULLPTR));
        label_id->setText(QApplication::translate("DJournalInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\274\226\345\217\267</span></p></body></html>", Q_NULLPTR));
        line_id->setPlaceholderText(QApplication::translate("DJournalInfo", "\346\225\264\346\225\260~", Q_NULLPTR));
        label_name->setText(QApplication::translate("DJournalInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\220\215\347\247\260</span></p></body></html>", Q_NULLPTR));
        line_name->setPlaceholderText(QApplication::translate("DJournalInfo", "\346\234\237\345\210\212\345\220\215\344\270\215\345\217\257\351\207\215\345\244\215\345\223\237~", Q_NULLPTR));
        label_catalog->setText(QApplication::translate("DJournalInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\274\226\347\233\256</span></p></body></html>", Q_NULLPTR));
        label_type->setText(QApplication::translate("DJournalInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\261\273\345\210\253</span></p></body></html>", Q_NULLPTR));
        label_editor->setText(QApplication::translate("DJournalInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\344\270\273\347\274\226</span></p></body></html>", Q_NULLPTR));
        btn_editor->setText(QApplication::translate("DJournalInfo", "\347\274\226\350\276\221\344\270\273\347\274\226(\345\207\272\347\211\210\347\244\276)", Q_NULLPTR));
        label_date->setText(QApplication::translate("DJournalInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\234\200\346\226\260\345\207\272\347\211\210\346\227\245\346\234\237</span></p></body></html>", Q_NULLPTR));
        line_date->setText(QString());
        line_date->setPlaceholderText(QApplication::translate("DJournalInfo", "\346\240\274\345\274\217\345\246\202: 1926/08/17", Q_NULLPTR));
        label_email->setText(QApplication::translate("DJournalInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\212\225\347\250\277\351\202\256\347\256\261</span></p></body></html>", Q_NULLPTR));
        btn_paper->setText(QApplication::translate("DJournalInfo", "\346\237\245\347\234\213\346\226\207\347\253\240", Q_NULLPTR));
        btn_confirm->setText(QApplication::translate("DJournalInfo", "\347\241\256\350\256\244\344\277\256\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DJournalInfo: public Ui_DJournalInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_JOURNAL_INFO_H
