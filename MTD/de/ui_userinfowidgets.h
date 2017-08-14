/********************************************************************************
** Form generated from reading UI file 'userinfowidgets.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFOWIDGETS_H
#define UI_USERINFOWIDGETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "pixlabelwidget.h"

QT_BEGIN_NAMESPACE

class Ui_userInfoWidgets
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    PixLabel *label_login;
    PixLabel *label_signIn;
    QLabel *label;
    QLabel *label_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *iDLabel;
    QLineEdit *idLineEdit;
    QPushButton *pushButton_cancel_1;
    QPushButton *pushButton_makeSure_1;
    QLabel *label_icon;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *nameLineEdit;
    QLabel *label_4;
    QComboBox *sexComboBox;
    QLabel *label_12;
    QLineEdit *ageLineEdit;
    QLabel *label_6;
    QLineEdit *professionEdit;
    QLabel *label_5;
    QLineEdit *contactEdit;
    QLabel *label_7;
    QLineEdit *addressEdit;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QLabel *label_9;
    QTextEdit *personalHistoryEdit;
    QTextEdit *familyHistoryEdit;
    QLabel *label_10;
    QTextEdit *addtextEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_makeSure_2;
    QPushButton *pushButton_cancel_2;

    void setupUi(QWidget *userInfoWidgets)
    {
        if (userInfoWidgets->objectName().isEmpty())
            userInfoWidgets->setObjectName(QStringLiteral("userInfoWidgets"));
        userInfoWidgets->resize(502, 624);
        verticalLayout_5 = new QVBoxLayout(userInfoWidgets);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_login = new PixLabel(userInfoWidgets);
        label_login->setObjectName(QStringLiteral("label_login"));

        verticalLayout->addWidget(label_login);

        label_signIn = new PixLabel(userInfoWidgets);
        label_signIn->setObjectName(QStringLiteral("label_signIn"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_signIn->sizePolicy().hasHeightForWidth());
        label_signIn->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_signIn);

        label = new QLabel(userInfoWidgets);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(userInfoWidgets);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 2);

        horizontalLayout->addLayout(verticalLayout);

        tabWidget = new QTabWidget(userInfoWidgets);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        iDLabel = new QLabel(tab);
        iDLabel->setObjectName(QStringLiteral("iDLabel"));
        iDLabel->setGeometry(QRect(50, 200, 61, 20));
        idLineEdit = new QLineEdit(tab);
        idLineEdit->setObjectName(QStringLiteral("idLineEdit"));
        idLineEdit->setGeometry(QRect(110, 200, 181, 20));
        pushButton_cancel_1 = new QPushButton(tab);
        pushButton_cancel_1->setObjectName(QStringLiteral("pushButton_cancel_1"));
        pushButton_cancel_1->setGeometry(QRect(230, 290, 75, 23));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_cancel_1->sizePolicy().hasHeightForWidth());
        pushButton_cancel_1->setSizePolicy(sizePolicy1);
        pushButton_makeSure_1 = new QPushButton(tab);
        pushButton_makeSure_1->setObjectName(QStringLiteral("pushButton_makeSure_1"));
        pushButton_makeSure_1->setGeometry(QRect(100, 290, 75, 23));
        sizePolicy1.setHeightForWidth(pushButton_makeSure_1->sizePolicy().hasHeightForWidth());
        pushButton_makeSure_1->setSizePolicy(sizePolicy1);
        label_icon = new QLabel(tab);
        label_icon->setObjectName(QStringLiteral("label_icon"));
        label_icon->setGeometry(QRect(150, 50, 100, 100));
        sizePolicy1.setHeightForWidth(label_icon->sizePolicy().hasHeightForWidth());
        label_icon->setSizePolicy(sizePolicy1);
        label_icon->setFrameShape(QFrame::NoFrame);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setMinimumSize(QSize(48, 0));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        nameLineEdit = new QLineEdit(tab_2);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        sizePolicy1.setHeightForWidth(nameLineEdit->sizePolicy().hasHeightForWidth());
        nameLineEdit->setSizePolicy(sizePolicy1);
        nameLineEdit->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(nameLineEdit, 0, 1, 1, 1);

        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        sexComboBox = new QComboBox(tab_2);
        sexComboBox->setObjectName(QStringLiteral("sexComboBox"));
        sizePolicy1.setHeightForWidth(sexComboBox->sizePolicy().hasHeightForWidth());
        sexComboBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(sexComboBox, 0, 3, 1, 1);

        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 1, 0, 1, 1);

        ageLineEdit = new QLineEdit(tab_2);
        ageLineEdit->setObjectName(QStringLiteral("ageLineEdit"));
        sizePolicy1.setHeightForWidth(ageLineEdit->sizePolicy().hasHeightForWidth());
        ageLineEdit->setSizePolicy(sizePolicy1);
        ageLineEdit->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(ageLineEdit, 1, 1, 1, 1);

        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        professionEdit = new QLineEdit(tab_2);
        professionEdit->setObjectName(QStringLiteral("professionEdit"));
        sizePolicy1.setHeightForWidth(professionEdit->sizePolicy().hasHeightForWidth());
        professionEdit->setSizePolicy(sizePolicy1);
        professionEdit->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(professionEdit, 1, 3, 1, 1);

        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        contactEdit = new QLineEdit(tab_2);
        contactEdit->setObjectName(QStringLiteral("contactEdit"));
        sizePolicy1.setHeightForWidth(contactEdit->sizePolicy().hasHeightForWidth());
        contactEdit->setSizePolicy(sizePolicy1);
        contactEdit->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(contactEdit, 2, 1, 1, 1);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        addressEdit = new QLineEdit(tab_2);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));
        sizePolicy1.setHeightForWidth(addressEdit->sizePolicy().hasHeightForWidth());
        addressEdit->setSizePolicy(sizePolicy1);
        addressEdit->setMinimumSize(QSize(250, 0));
        addressEdit->setMaximumSize(QSize(563, 16777215));

        gridLayout->addWidget(addressEdit, 3, 1, 1, 3);


        verticalLayout_3->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);

        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 1, 0, 1, 1);

        personalHistoryEdit = new QTextEdit(tab_2);
        personalHistoryEdit->setObjectName(QStringLiteral("personalHistoryEdit"));
        sizePolicy1.setHeightForWidth(personalHistoryEdit->sizePolicy().hasHeightForWidth());
        personalHistoryEdit->setSizePolicy(sizePolicy1);
        personalHistoryEdit->setMaximumSize(QSize(561, 84));

        gridLayout_2->addWidget(personalHistoryEdit, 0, 1, 1, 1);

        familyHistoryEdit = new QTextEdit(tab_2);
        familyHistoryEdit->setObjectName(QStringLiteral("familyHistoryEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(familyHistoryEdit->sizePolicy().hasHeightForWidth());
        familyHistoryEdit->setSizePolicy(sizePolicy4);
        familyHistoryEdit->setMinimumSize(QSize(0, 0));
        familyHistoryEdit->setMaximumSize(QSize(561, 84));

        gridLayout_2->addWidget(familyHistoryEdit, 1, 1, 1, 1);

        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 2, 0, 1, 1);

        addtextEdit = new QTextEdit(tab_2);
        addtextEdit->setObjectName(QStringLiteral("addtextEdit"));
        sizePolicy4.setHeightForWidth(addtextEdit->sizePolicy().hasHeightForWidth());
        addtextEdit->setSizePolicy(sizePolicy4);
        addtextEdit->setMaximumSize(QSize(561, 84));

        gridLayout_2->addWidget(addtextEdit, 2, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);


        verticalLayout_2->addLayout(verticalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_makeSure_2 = new QPushButton(tab_2);
        pushButton_makeSure_2->setObjectName(QStringLiteral("pushButton_makeSure_2"));
        sizePolicy1.setHeightForWidth(pushButton_makeSure_2->sizePolicy().hasHeightForWidth());
        pushButton_makeSure_2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(pushButton_makeSure_2);

        pushButton_cancel_2 = new QPushButton(tab_2);
        pushButton_cancel_2->setObjectName(QStringLiteral("pushButton_cancel_2"));
        sizePolicy1.setHeightForWidth(pushButton_cancel_2->sizePolicy().hasHeightForWidth());
        pushButton_cancel_2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(pushButton_cancel_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_2);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 10);

        verticalLayout_5->addLayout(horizontalLayout);


        retranslateUi(userInfoWidgets);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(userInfoWidgets);
    } // setupUi

    void retranslateUi(QWidget *userInfoWidgets)
    {
        userInfoWidgets->setWindowTitle(QApplication::translate("userInfoWidgets", "\347\224\250\346\210\267\344\277\241\346\201\257", Q_NULLPTR));
        label_login->setText(QApplication::translate("userInfoWidgets", "TextLabel", Q_NULLPTR));
        label_signIn->setText(QApplication::translate("userInfoWidgets", "TextLabel", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        iDLabel->setText(QApplication::translate("userInfoWidgets", "UserId", Q_NULLPTR));
        pushButton_cancel_1->setText(QApplication::translate("userInfoWidgets", "\345\217\226\346\266\210", Q_NULLPTR));
        pushButton_makeSure_1->setText(QApplication::translate("userInfoWidgets", "\347\241\256\350\256\244", Q_NULLPTR));
        label_icon->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("userInfoWidgets", "\347\231\273\345\275\225", Q_NULLPTR));
        label_3->setText(QApplication::translate("userInfoWidgets", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("userInfoWidgets", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        sexComboBox->clear();
        sexComboBox->insertItems(0, QStringList()
         << QApplication::translate("userInfoWidgets", "Male", Q_NULLPTR)
         << QApplication::translate("userInfoWidgets", "Female", Q_NULLPTR)
        );
        label_12->setText(QApplication::translate("userInfoWidgets", "\345\271\264\351\276\204\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("userInfoWidgets", "\350\201\214\344\270\232\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("userInfoWidgets", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("userInfoWidgets", "\344\275\217\345\235\200", Q_NULLPTR));
        label_8->setText(QApplication::translate("userInfoWidgets", "\344\270\252\344\272\272\347\227\205\345\217\262\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("userInfoWidgets", "\345\256\266\346\227\217\347\227\205\345\217\262\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("userInfoWidgets", "\351\231\204\345\212\240\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        pushButton_makeSure_2->setText(QApplication::translate("userInfoWidgets", "\347\241\256\350\256\244", Q_NULLPTR));
        pushButton_cancel_2->setText(QApplication::translate("userInfoWidgets", "\345\217\226\346\266\210", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("userInfoWidgets", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class userInfoWidgets: public Ui_userInfoWidgets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOWIDGETS_H
