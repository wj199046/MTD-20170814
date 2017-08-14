/********************************************************************************
** Form generated from reading UI file 'recordupdatewidgets.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDUPDATEWIDGETS_H
#define UI_RECORDUPDATEWIDGETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecordUpdateWidgets
{
public:
    QLabel *label;
    QLineEdit *userIdEdit;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QLabel *label_3;
    QLineEdit *ageEdit;
    QLabel *label_4;
    QComboBox *gendleBox;
    QLabel *label_5;
    QLineEdit *contactEdit;
    QLabel *label_6;
    QLineEdit *professionEdit;
    QLabel *label_7;
    QLineEdit *addressEdit;
    QPushButton *cancleBtn;
    QPushButton *updateResultBtn;
    QPushButton *deleteResultBtn;
    QPushButton *updateBtn;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QTextEdit *personalHistoryEdit;
    QLabel *label_9;
    QTextEdit *familyHistoryEdit;
    QLabel *label_10;
    QTableWidget *tableWidget_result;

    void setupUi(QDialog *RecordUpdateWidgets)
    {
        if (RecordUpdateWidgets->objectName().isEmpty())
            RecordUpdateWidgets->setObjectName(QStringLiteral("RecordUpdateWidgets"));
        RecordUpdateWidgets->resize(752, 639);
        label = new QLabel(RecordUpdateWidgets);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(22, 12, 48, 16));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        userIdEdit = new QLineEdit(RecordUpdateWidgets);
        userIdEdit->setObjectName(QStringLiteral("userIdEdit"));
        userIdEdit->setGeometry(QRect(90, 12, 200, 20));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(userIdEdit->sizePolicy().hasHeightForWidth());
        userIdEdit->setSizePolicy(sizePolicy1);
        userIdEdit->setMinimumSize(QSize(200, 0));
        label_2 = new QLabel(RecordUpdateWidgets);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(400, 16, 48, 16));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setMinimumSize(QSize(48, 0));
        nameEdit = new QLineEdit(RecordUpdateWidgets);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setGeometry(QRect(454, 12, 200, 20));
        sizePolicy1.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy1);
        nameEdit->setMinimumSize(QSize(200, 0));
        label_3 = new QLabel(RecordUpdateWidgets);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(22, 42, 36, 16));
        ageEdit = new QLineEdit(RecordUpdateWidgets);
        ageEdit->setObjectName(QStringLiteral("ageEdit"));
        ageEdit->setGeometry(QRect(90, 42, 200, 20));
        sizePolicy1.setHeightForWidth(ageEdit->sizePolicy().hasHeightForWidth());
        ageEdit->setSizePolicy(sizePolicy1);
        ageEdit->setMinimumSize(QSize(200, 0));
        label_4 = new QLabel(RecordUpdateWidgets);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(400, 42, 36, 16));
        gendleBox = new QComboBox(RecordUpdateWidgets);
        gendleBox->setObjectName(QStringLiteral("gendleBox"));
        gendleBox->setGeometry(QRect(454, 42, 62, 20));
        sizePolicy1.setHeightForWidth(gendleBox->sizePolicy().hasHeightForWidth());
        gendleBox->setSizePolicy(sizePolicy1);
        label_5 = new QLabel(RecordUpdateWidgets);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(22, 72, 60, 16));
        contactEdit = new QLineEdit(RecordUpdateWidgets);
        contactEdit->setObjectName(QStringLiteral("contactEdit"));
        contactEdit->setGeometry(QRect(90, 72, 200, 20));
        sizePolicy1.setHeightForWidth(contactEdit->sizePolicy().hasHeightForWidth());
        contactEdit->setSizePolicy(sizePolicy1);
        contactEdit->setMinimumSize(QSize(200, 0));
        label_6 = new QLabel(RecordUpdateWidgets);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(400, 72, 36, 16));
        professionEdit = new QLineEdit(RecordUpdateWidgets);
        professionEdit->setObjectName(QStringLiteral("professionEdit"));
        professionEdit->setGeometry(QRect(454, 72, 200, 20));
        sizePolicy1.setHeightForWidth(professionEdit->sizePolicy().hasHeightForWidth());
        professionEdit->setSizePolicy(sizePolicy1);
        professionEdit->setMinimumSize(QSize(200, 0));
        label_7 = new QLabel(RecordUpdateWidgets);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(22, 100, 24, 16));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy3);
        addressEdit = new QLineEdit(RecordUpdateWidgets);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));
        addressEdit->setGeometry(QRect(90, 100, 563, 20));
        sizePolicy1.setHeightForWidth(addressEdit->sizePolicy().hasHeightForWidth());
        addressEdit->setSizePolicy(sizePolicy1);
        addressEdit->setMinimumSize(QSize(563, 0));
        addressEdit->setMaximumSize(QSize(563, 16777215));
        cancleBtn = new QPushButton(RecordUpdateWidgets);
        cancleBtn->setObjectName(QStringLiteral("cancleBtn"));
        cancleBtn->setGeometry(QRect(400, 590, 75, 23));
        updateResultBtn = new QPushButton(RecordUpdateWidgets);
        updateResultBtn->setObjectName(QStringLiteral("updateResultBtn"));
        updateResultBtn->setGeometry(QRect(660, 490, 81, 23));
        deleteResultBtn = new QPushButton(RecordUpdateWidgets);
        deleteResultBtn->setObjectName(QStringLiteral("deleteResultBtn"));
        deleteResultBtn->setGeometry(QRect(660, 530, 81, 23));
        updateBtn = new QPushButton(RecordUpdateWidgets);
        updateBtn->setObjectName(QStringLiteral("updateBtn"));
        updateBtn->setGeometry(QRect(200, 590, 75, 23));
        widget = new QWidget(RecordUpdateWidgets);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(21, 129, 629, 431));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);

        personalHistoryEdit = new QTextEdit(widget);
        personalHistoryEdit->setObjectName(QStringLiteral("personalHistoryEdit"));

        gridLayout_2->addWidget(personalHistoryEdit, 0, 1, 1, 1);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 1, 0, 1, 1);

        familyHistoryEdit = new QTextEdit(widget);
        familyHistoryEdit->setObjectName(QStringLiteral("familyHistoryEdit"));

        gridLayout_2->addWidget(familyHistoryEdit, 1, 1, 1, 1);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 2, 0, 1, 1);

        tableWidget_result = new QTableWidget(widget);
        tableWidget_result->setObjectName(QStringLiteral("tableWidget_result"));

        gridLayout_2->addWidget(tableWidget_result, 2, 1, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setRowStretch(2, 3);
        label->raise();
        userIdEdit->raise();
        label_2->raise();
        nameEdit->raise();
        label_3->raise();
        ageEdit->raise();
        label_4->raise();
        gendleBox->raise();
        label_5->raise();
        contactEdit->raise();
        label_6->raise();
        professionEdit->raise();
        label_7->raise();
        addressEdit->raise();
        label_8->raise();
        label_9->raise();
        personalHistoryEdit->raise();
        familyHistoryEdit->raise();
        label_10->raise();
        tableWidget_result->raise();
        updateBtn->raise();
        cancleBtn->raise();
        updateResultBtn->raise();
        deleteResultBtn->raise();
        updateBtn->raise();
        addressEdit->raise();
        label_7->raise();

        retranslateUi(RecordUpdateWidgets);

        QMetaObject::connectSlotsByName(RecordUpdateWidgets);
    } // setupUi

    void retranslateUi(QDialog *RecordUpdateWidgets)
    {
        RecordUpdateWidgets->setWindowTitle(QApplication::translate("RecordUpdateWidgets", "\344\277\256\346\224\271\347\227\205\344\276\213", Q_NULLPTR));
        label->setText(QApplication::translate("RecordUpdateWidgets", "userId\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("RecordUpdateWidgets", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("RecordUpdateWidgets", "\345\271\264\351\276\204\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("RecordUpdateWidgets", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        gendleBox->clear();
        gendleBox->insertItems(0, QStringList()
         << QApplication::translate("RecordUpdateWidgets", "Male", Q_NULLPTR)
         << QApplication::translate("RecordUpdateWidgets", "Female", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("RecordUpdateWidgets", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("RecordUpdateWidgets", "\350\201\214\344\270\232\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("RecordUpdateWidgets", "\344\275\217\345\235\200", Q_NULLPTR));
        cancleBtn->setText(QApplication::translate("RecordUpdateWidgets", "\345\217\226\346\266\210", Q_NULLPTR));
        updateResultBtn->setText(QApplication::translate("RecordUpdateWidgets", "\344\277\256\346\224\271\345\260\261\350\257\212\350\256\260\345\275\225", Q_NULLPTR));
        deleteResultBtn->setText(QApplication::translate("RecordUpdateWidgets", "\345\210\240\351\231\244\345\260\261\350\257\212\350\256\260\345\275\225", Q_NULLPTR));
        updateBtn->setText(QApplication::translate("RecordUpdateWidgets", "\344\277\235\345\255\230\344\277\256\346\224\271", Q_NULLPTR));
        label_8->setText(QApplication::translate("RecordUpdateWidgets", "\344\270\252\344\272\272\347\227\205\345\217\262\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("RecordUpdateWidgets", "\345\256\266\346\227\217\347\227\205\345\217\262\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("RecordUpdateWidgets", "\345\260\261\350\257\212\350\256\260\345\275\225\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RecordUpdateWidgets: public Ui_RecordUpdateWidgets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDUPDATEWIDGETS_H
