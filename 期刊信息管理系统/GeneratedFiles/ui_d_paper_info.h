/********************************************************************************
** Form generated from reading UI file 'd_paper_info.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_PAPER_INFO_H
#define UI_D_PAPER_INFO_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DPaperInfo
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label_id;
    QLineEdit *line_id;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_name;
    QLineEdit *line_name;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_date;
    QLineEdit *line_date;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_contributor;
    QComboBox *cmb_contributorName;
    QComboBox *cmb_contributorId;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *btn_contributor;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_journal;
    QComboBox *cmb_journal;
    QLineEdit *line_journalId;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *btn_journal;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *btn_confirm;

    void setupUi(QDialog *DPaperInfo)
    {
        if (DPaperInfo->objectName().isEmpty())
            DPaperInfo->setObjectName(QStringLiteral("DPaperInfo"));
        DPaperInfo->resize(744, 424);
        DPaperInfo->setMinimumSize(QSize(638, 381));
        DPaperInfo->setMaximumSize(QSize(900, 600));
        verticalLayout = new QVBoxLayout(DPaperInfo);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(DPaperInfo);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(label);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_id = new QLabel(DPaperInfo);
        label_id->setObjectName(QStringLiteral("label_id"));
        label_id->setMinimumSize(QSize(95, 0));
        label_id->setTextFormat(Qt::AutoText);

        horizontalLayout->addWidget(label_id);

        line_id = new QLineEdit(DPaperInfo);
        line_id->setObjectName(QStringLiteral("line_id"));

        horizontalLayout->addWidget(line_id);


        horizontalLayout_7->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_name = new QLabel(DPaperInfo);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setMinimumSize(QSize(80, 0));
        label_name->setTextFormat(Qt::AutoText);

        horizontalLayout_3->addWidget(label_name);

        line_name = new QLineEdit(DPaperInfo);
        line_name->setObjectName(QStringLiteral("line_name"));

        horizontalLayout_3->addWidget(line_name);


        horizontalLayout_7->addLayout(horizontalLayout_3);

        horizontalLayout_7->setStretch(0, 11);
        horizontalLayout_7->setStretch(1, 1);
        horizontalLayout_7->setStretch(2, 11);

        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_date = new QLabel(DPaperInfo);
        label_date->setObjectName(QStringLiteral("label_date"));
        label_date->setMinimumSize(QSize(95, 0));
        label_date->setTextFormat(Qt::AutoText);

        horizontalLayout_2->addWidget(label_date);

        line_date = new QLineEdit(DPaperInfo);
        line_date->setObjectName(QStringLiteral("line_date"));
        line_date->setInputMethodHints(Qt::ImhDate);

        horizontalLayout_2->addWidget(line_date);


        horizontalLayout_8->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_contributor = new QLabel(DPaperInfo);
        label_contributor->setObjectName(QStringLiteral("label_contributor"));
        label_contributor->setMinimumSize(QSize(95, 0));
        label_contributor->setTextFormat(Qt::AutoText);

        horizontalLayout_5->addWidget(label_contributor);

        cmb_contributorName = new QComboBox(DPaperInfo);
        cmb_contributorName->setObjectName(QStringLiteral("cmb_contributorName"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cmb_contributorName->sizePolicy().hasHeightForWidth());
        cmb_contributorName->setSizePolicy(sizePolicy);
        cmb_contributorName->setEditable(true);

        horizontalLayout_5->addWidget(cmb_contributorName);

        cmb_contributorId = new QComboBox(DPaperInfo);
        cmb_contributorId->setObjectName(QStringLiteral("cmb_contributorId"));
        cmb_contributorId->setMinimumSize(QSize(99, 0));
        cmb_contributorId->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_5->addWidget(cmb_contributorId);


        horizontalLayout_9->addLayout(horizontalLayout_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        btn_contributor = new QToolButton(DPaperInfo);
        btn_contributor->setObjectName(QStringLiteral("btn_contributor"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/writer_128px_43469_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btn_contributor->setIcon(icon);
        btn_contributor->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_9->addWidget(btn_contributor);

        horizontalLayout_9->setStretch(0, 18);
        horizontalLayout_9->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_journal = new QLabel(DPaperInfo);
        label_journal->setObjectName(QStringLiteral("label_journal"));
        label_journal->setMinimumSize(QSize(95, 0));
        label_journal->setTextFormat(Qt::AutoText);

        horizontalLayout_6->addWidget(label_journal);

        cmb_journal = new QComboBox(DPaperInfo);
        cmb_journal->setObjectName(QStringLiteral("cmb_journal"));
        sizePolicy.setHeightForWidth(cmb_journal->sizePolicy().hasHeightForWidth());
        cmb_journal->setSizePolicy(sizePolicy);
        cmb_journal->setEditable(true);

        horizontalLayout_6->addWidget(cmb_journal);

        line_journalId = new QLineEdit(DPaperInfo);
        line_journalId->setObjectName(QStringLiteral("line_journalId"));
        line_journalId->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line_journalId->sizePolicy().hasHeightForWidth());
        line_journalId->setSizePolicy(sizePolicy1);
        line_journalId->setMinimumSize(QSize(99, 0));
        line_journalId->setMaximumSize(QSize(99, 16777215));

        horizontalLayout_6->addWidget(line_journalId);


        horizontalLayout_10->addLayout(horizontalLayout_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);

        btn_journal = new QToolButton(DPaperInfo);
        btn_journal->setObjectName(QStringLiteral("btn_journal"));
        btn_journal->setMinimumSize(QSize(143, 0));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/book_books.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btn_journal->setIcon(icon1);
        btn_journal->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_10->addWidget(btn_journal);

        horizontalLayout_10->setStretch(0, 18);
        horizontalLayout_10->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_5 = new QSpacerItem(248, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_5);

        btn_confirm = new QToolButton(DPaperInfo);
        btn_confirm->setObjectName(QStringLiteral("btn_confirm"));
        btn_confirm->setMinimumSize(QSize(147, 0));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/accept_approve_comfirm_ok_tick_yes.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_confirm->setIcon(icon2);
        btn_confirm->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_11->addWidget(btn_confirm);


        verticalLayout->addLayout(horizontalLayout_11);


        retranslateUi(DPaperInfo);

        QMetaObject::connectSlotsByName(DPaperInfo);
    } // setupUi

    void retranslateUi(QDialog *DPaperInfo)
    {
        DPaperInfo->setWindowTitle(QApplication::translate("DPaperInfo", "\346\226\207\347\253\240\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("DPaperInfo", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600;\">\346\226\207 \347\253\240 \344\277\241 \346\201\257</span></p></body></html>", Q_NULLPTR));
        label_id->setText(QApplication::translate("DPaperInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\274\226\345\217\267</span></p></body></html>", Q_NULLPTR));
        line_id->setPlaceholderText(QApplication::translate("DPaperInfo", "6\344\275\215\345\246\202\357\274\232000123", Q_NULLPTR));
        label_name->setText(QApplication::translate("DPaperInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\220\215\347\247\260</span></p></body></html>", Q_NULLPTR));
        line_name->setPlaceholderText(QApplication::translate("DPaperInfo", "\346\226\207\347\253\240\345\220\215\344\270\215\350\246\201\351\207\215\345\244\215\345\223\237~", Q_NULLPTR));
        label_date->setText(QApplication::translate("DPaperInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\210\212\347\231\273\346\227\245\346\234\237</span></p></body></html>", Q_NULLPTR));
        line_date->setPlaceholderText(QApplication::translate("DPaperInfo", "\346\240\274\345\274\217\345\246\202: 1926/08/17", Q_NULLPTR));
        label_contributor->setText(QApplication::translate("DPaperInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\212\225\347\250\277\344\272\272</span></p></body></html>", Q_NULLPTR));
        btn_contributor->setText(QApplication::translate("DPaperInfo", "\346\212\225\347\250\277\344\272\272\350\257\246\346\203\205", Q_NULLPTR));
        label_journal->setText(QApplication::translate("DPaperInfo", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\234\237\345\210\212</span></p></body></html>", Q_NULLPTR));
        btn_journal->setText(QApplication::translate("DPaperInfo", "\346\234\237\345\210\212\350\257\246\346\203\205", Q_NULLPTR));
        btn_confirm->setText(QApplication::translate("DPaperInfo", "\347\241\256\350\256\244\344\277\256\346\224\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DPaperInfo: public Ui_DPaperInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_PAPER_INFO_H
