/********************************************************************************
** Form generated from reading UI file 'resultupdatewidgets.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTUPDATEWIDGETS_H
#define UI_RESULTUPDATEWIDGETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResultUpdateWidgets
{
public:
    QPushButton *saveResultBtn;
    QPushButton *cancelBtn;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *idEdit;
    QLabel *label_2;
    QLineEdit *userIdEdit;
    QLabel *label_3;
    QLineEdit *checkDateEdit;
    QLabel *label_4;
    QLineEdit *checkSpotEdit;
    QLabel *label_5;
    QLineEdit *docIdEdit;
    QLabel *label_6;
    QLineEdit *docNameEdit;
    QWidget *widget1;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QTextEdit *symptomEdit;
    QLabel *label_8;
    QTextEdit *decisionEdit;
    QLabel *label_9;
    QTextEdit *therapyEdit;

    void setupUi(QDialog *ResultUpdateWidgets)
    {
        if (ResultUpdateWidgets->objectName().isEmpty())
            ResultUpdateWidgets->setObjectName(QStringLiteral("ResultUpdateWidgets"));
        ResultUpdateWidgets->resize(554, 627);
        saveResultBtn = new QPushButton(ResultUpdateWidgets);
        saveResultBtn->setObjectName(QStringLiteral("saveResultBtn"));
        saveResultBtn->setGeometry(QRect(120, 560, 75, 23));
        cancelBtn = new QPushButton(ResultUpdateWidgets);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(360, 560, 75, 23));
        widget = new QWidget(ResultUpdateWidgets);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 30, 471, 91));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        idEdit = new QLineEdit(widget);
        idEdit->setObjectName(QStringLiteral("idEdit"));

        gridLayout->addWidget(idEdit, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        userIdEdit = new QLineEdit(widget);
        userIdEdit->setObjectName(QStringLiteral("userIdEdit"));

        gridLayout->addWidget(userIdEdit, 0, 3, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        checkDateEdit = new QLineEdit(widget);
        checkDateEdit->setObjectName(QStringLiteral("checkDateEdit"));

        gridLayout->addWidget(checkDateEdit, 1, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        checkSpotEdit = new QLineEdit(widget);
        checkSpotEdit->setObjectName(QStringLiteral("checkSpotEdit"));

        gridLayout->addWidget(checkSpotEdit, 1, 3, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        docIdEdit = new QLineEdit(widget);
        docIdEdit->setObjectName(QStringLiteral("docIdEdit"));

        gridLayout->addWidget(docIdEdit, 2, 1, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 2, 1, 1);

        docNameEdit = new QLineEdit(widget);
        docNameEdit->setObjectName(QStringLiteral("docNameEdit"));

        gridLayout->addWidget(docNameEdit, 2, 3, 1, 1);

        widget1 = new QWidget(ResultUpdateWidgets);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 130, 471, 411));
        gridLayout_2 = new QGridLayout(widget1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        symptomEdit = new QTextEdit(widget1);
        symptomEdit->setObjectName(QStringLiteral("symptomEdit"));

        gridLayout_2->addWidget(symptomEdit, 0, 1, 1, 1);

        label_8 = new QLabel(widget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 1, 0, 1, 1);

        decisionEdit = new QTextEdit(widget1);
        decisionEdit->setObjectName(QStringLiteral("decisionEdit"));

        gridLayout_2->addWidget(decisionEdit, 1, 1, 1, 1);

        label_9 = new QLabel(widget1);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 2, 0, 1, 1);

        therapyEdit = new QTextEdit(widget1);
        therapyEdit->setObjectName(QStringLiteral("therapyEdit"));

        gridLayout_2->addWidget(therapyEdit, 2, 1, 1, 1);


        retranslateUi(ResultUpdateWidgets);

        QMetaObject::connectSlotsByName(ResultUpdateWidgets);
    } // setupUi

    void retranslateUi(QDialog *ResultUpdateWidgets)
    {
        ResultUpdateWidgets->setWindowTitle(QApplication::translate("ResultUpdateWidgets", "Dialog", Q_NULLPTR));
        saveResultBtn->setText(QApplication::translate("ResultUpdateWidgets", "\344\277\235\345\255\230\350\257\212\346\226\255", Q_NULLPTR));
        cancelBtn->setText(QApplication::translate("ResultUpdateWidgets", "\345\217\226\346\266\210", Q_NULLPTR));
        label->setText(QApplication::translate("ResultUpdateWidgets", "\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("ResultUpdateWidgets", "\347\227\205\344\272\272id\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("ResultUpdateWidgets", "\345\260\261\350\257\212\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("ResultUpdateWidgets", "\345\260\261\350\257\212\345\234\260\347\202\271\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("ResultUpdateWidgets", "\345\214\273\347\224\237\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("ResultUpdateWidgets", "\345\214\273\347\224\237\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("ResultUpdateWidgets", "\347\227\207\347\212\266\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("ResultUpdateWidgets", "\350\257\212\346\226\255\347\273\223\350\256\272\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("ResultUpdateWidgets", "\346\262\273\347\226\227\346\226\271\346\263\225\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ResultUpdateWidgets: public Ui_ResultUpdateWidgets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTUPDATEWIDGETS_H
