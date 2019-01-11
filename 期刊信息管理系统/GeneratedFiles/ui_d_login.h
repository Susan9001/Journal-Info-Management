/********************************************************************************
** Form generated from reading UI file 'd_login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_LOGIN_H
#define UI_D_LOGIN_H

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

class Ui_DLogin
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_id;
    QLineEdit *line_id;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_password;
    QLineEdit *line_password;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_confirm;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DLogin)
    {
        if (DLogin->objectName().isEmpty())
            DLogin->setObjectName(QStringLiteral("DLogin"));
        DLogin->resize(526, 224);
        verticalLayout = new QVBoxLayout(DLogin);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_id = new QLabel(DLogin);
        label_id->setObjectName(QStringLiteral("label_id"));

        horizontalLayout->addWidget(label_id);

        line_id = new QLineEdit(DLogin);
        line_id->setObjectName(QStringLiteral("line_id"));

        horizontalLayout->addWidget(line_id);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_password = new QLabel(DLogin);
        label_password->setObjectName(QStringLiteral("label_password"));

        horizontalLayout_2->addWidget(label_password);

        line_password = new QLineEdit(DLogin);
        line_password->setObjectName(QStringLiteral("line_password"));
        line_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(line_password);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btn_confirm = new QPushButton(DLogin);
        btn_confirm->setObjectName(QStringLiteral("btn_confirm"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_confirm->sizePolicy().hasHeightForWidth());
        btn_confirm->setSizePolicy(sizePolicy);
        btn_confirm->setMinimumSize(QSize(150, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Resources/\345\233\276\346\240\207/accept_approve_comfirm_ok_tick_yes.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_confirm->setIcon(icon);

        horizontalLayout_4->addWidget(btn_confirm);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(DLogin);

        QMetaObject::connectSlotsByName(DLogin);
    } // setupUi

    void retranslateUi(QDialog *DLogin)
    {
        DLogin->setWindowTitle(QApplication::translate("DLogin", "\347\231\273\345\275\225", Q_NULLPTR));
        label_id->setText(QApplication::translate("DLogin", "<html><head/><body><p><span style=\" font-size:12pt;\">\350\264\246\345\217\267</span></p></body></html>", Q_NULLPTR));
        line_id->setPlaceholderText(QApplication::translate("DLogin", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267:", Q_NULLPTR));
        label_password->setText(QApplication::translate("DLogin", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\257\206\347\240\201</span></p></body></html>", Q_NULLPTR));
        line_password->setPlaceholderText(QApplication::translate("DLogin", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201\357\274\232(\344\270\215\345\260\221\344\272\2166\344\275\215\345\223\246)", Q_NULLPTR));
        btn_confirm->setText(QApplication::translate("DLogin", "\347\241\256\350\256\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DLogin: public Ui_DLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_LOGIN_H
