/********************************************************************************
** Form generated from reading UI file 'savepicturewidgets.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEPICTUREWIDGETS_H
#define UI_SAVEPICTUREWIDGETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_savepicturewidgets
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *Label_4;
    QLabel *Label_2;
    QLabel *Label_5;
    QLabel *Label;
    QLabel *Label_3;
    QLabel *Label_6;
    QTextEdit *textEdit_id;
    QTextEdit *textEdit_name;
    QTextEdit *textEdit_place;
    QTextEdit *textEdit_symptom;
    QTextEdit *textEdit_decision;
    QTextEdit *textEdit_therapy;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_save;
    QPushButton *pushButton_cancel;

    void setupUi(QWidget *savepicturewidgets)
    {
        if (savepicturewidgets->objectName().isEmpty())
            savepicturewidgets->setObjectName(QStringLiteral("savepicturewidgets"));
        savepicturewidgets->resize(450, 417);
        verticalLayout_2 = new QVBoxLayout(savepicturewidgets);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Label_4 = new QLabel(savepicturewidgets);
        Label_4->setObjectName(QStringLiteral("Label_4"));

        gridLayout->addWidget(Label_4, 1, 0, 1, 1);

        Label_2 = new QLabel(savepicturewidgets);
        Label_2->setObjectName(QStringLiteral("Label_2"));

        gridLayout->addWidget(Label_2, 2, 0, 1, 1);

        Label_5 = new QLabel(savepicturewidgets);
        Label_5->setObjectName(QStringLiteral("Label_5"));

        gridLayout->addWidget(Label_5, 4, 0, 1, 1);

        Label = new QLabel(savepicturewidgets);
        Label->setObjectName(QStringLiteral("Label"));

        gridLayout->addWidget(Label, 3, 0, 1, 1);

        Label_3 = new QLabel(savepicturewidgets);
        Label_3->setObjectName(QStringLiteral("Label_3"));

        gridLayout->addWidget(Label_3, 0, 0, 1, 1);

        Label_6 = new QLabel(savepicturewidgets);
        Label_6->setObjectName(QStringLiteral("Label_6"));

        gridLayout->addWidget(Label_6, 5, 0, 1, 1);

        textEdit_id = new QTextEdit(savepicturewidgets);
        textEdit_id->setObjectName(QStringLiteral("textEdit_id"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit_id->sizePolicy().hasHeightForWidth());
        textEdit_id->setSizePolicy(sizePolicy);
        textEdit_id->setMinimumSize(QSize(200, 25));
        textEdit_id->setMaximumSize(QSize(200, 25));

        gridLayout->addWidget(textEdit_id, 0, 1, 1, 1);

        textEdit_name = new QTextEdit(savepicturewidgets);
        textEdit_name->setObjectName(QStringLiteral("textEdit_name"));
        sizePolicy.setHeightForWidth(textEdit_name->sizePolicy().hasHeightForWidth());
        textEdit_name->setSizePolicy(sizePolicy);
        textEdit_name->setMaximumSize(QSize(200, 25));

        gridLayout->addWidget(textEdit_name, 1, 1, 1, 1);

        textEdit_place = new QTextEdit(savepicturewidgets);
        textEdit_place->setObjectName(QStringLiteral("textEdit_place"));

        gridLayout->addWidget(textEdit_place, 2, 1, 1, 1);

        textEdit_symptom = new QTextEdit(savepicturewidgets);
        textEdit_symptom->setObjectName(QStringLiteral("textEdit_symptom"));

        gridLayout->addWidget(textEdit_symptom, 3, 1, 1, 1);

        textEdit_decision = new QTextEdit(savepicturewidgets);
        textEdit_decision->setObjectName(QStringLiteral("textEdit_decision"));

        gridLayout->addWidget(textEdit_decision, 4, 1, 1, 1);

        textEdit_therapy = new QTextEdit(savepicturewidgets);
        textEdit_therapy->setObjectName(QStringLiteral("textEdit_therapy"));

        gridLayout->addWidget(textEdit_therapy, 5, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 10);

        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(100);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_save = new QPushButton(savepicturewidgets);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        sizePolicy.setHeightForWidth(pushButton_save->sizePolicy().hasHeightForWidth());
        pushButton_save->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_save);

        pushButton_cancel = new QPushButton(savepicturewidgets);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        sizePolicy.setHeightForWidth(pushButton_cancel->sizePolicy().hasHeightForWidth());
        pushButton_cancel->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_cancel);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(savepicturewidgets);

        QMetaObject::connectSlotsByName(savepicturewidgets);
    } // setupUi

    void retranslateUi(QWidget *savepicturewidgets)
    {
        savepicturewidgets->setWindowTitle(QApplication::translate("savepicturewidgets", "\350\257\212\346\226\255\347\273\223\346\236\234", Q_NULLPTR));
        Label_4->setText(QApplication::translate("savepicturewidgets", "\345\214\273\347\224\237\345\247\223\345\220\215", Q_NULLPTR));
        Label_2->setText(QApplication::translate("savepicturewidgets", "\345\260\261\350\257\212\345\234\260\347\202\271", Q_NULLPTR));
        Label_5->setText(QApplication::translate("savepicturewidgets", "\350\257\212\346\226\255\347\273\223\350\256\272", Q_NULLPTR));
        Label->setText(QApplication::translate("savepicturewidgets", "\347\227\207\347\212\266", Q_NULLPTR));
        Label_3->setText(QApplication::translate("savepicturewidgets", "\345\214\273\347\224\237\347\274\226\345\217\267", Q_NULLPTR));
        Label_6->setText(QApplication::translate("savepicturewidgets", "\346\262\273\347\226\227\346\226\271\346\263\225", Q_NULLPTR));
        pushButton_save->setText(QApplication::translate("savepicturewidgets", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("savepicturewidgets", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class savepicturewidgets: public Ui_savepicturewidgets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEPICTUREWIDGETS_H
