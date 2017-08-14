/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "pixlabelwidget.h"
#include "scrollimagewidget.h"
#include "splitscreenlabelwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    UserLabel *label_userInfo;
    QVBoxLayout *verticalLayout;
    QLabel *label_userInfoID;
    QLabel *label_userInfoName;
    QHBoxLayout *horizontalLayout;
    PixLabel *label_operate;
    PixLabel *label_analyze;
    PixLabel *label_dataBase;
    PixLabel *label_report;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_video;
    QLabel *label_coloredTape;
    QGridLayout *gridLayout;
    QPushButton *pushButton_up;
    QPushButton *pushButton_capture;
    QPushButton *pushButton_down;
    QPushButton *pushButton_focus_plus;
    QPushButton *pushButton_focus_minus;
    QPushButton *pushButton_captureAgain;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    SplitScreenLabelWidget *label_analysisPicture;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_printScreen;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_splitScreen_1;
    QPushButton *pushButton_splitScreen_2;
    QComboBox *comboBox_printScreenForm;
    QPushButton *pushButton_maniTool;
    QPushButton *pushButton_pictureReset;
    QPushButton *pushButton_splitScreen_4;
    QLabel *label_6;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_11;
    scrollImageWidget *listWidget_dataBasePicture;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QTableWidget *tableWidget_case;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEdit_search;
    QPushButton *pushButton_search;
    QPushButton *pushButton_modifyCase;
    QPushButton *pushButton_deleteCase;
    QLabel *label;
    QHBoxLayout *horizontalLayout_10;
    QTableWidget *tableWidget_diagnose;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton_modifyDiagnose;
    QPushButton *pushButton_deleteDiagnose;
    QPushButton *pushButton_4;
    QWidget *tab_4;
    QHBoxLayout *horizontalLayout_12;
    scrollImageWidget *listWidget;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_PictureToDataBase;
    QPushButton *pushButton_10;
    QPushButton *pushButton_deleteScrollImage;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1073, 767);
        verticalLayout_11 = new QVBoxLayout(Widget);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(60);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_userInfo = new UserLabel(Widget);
        label_userInfo->setObjectName(QStringLiteral("label_userInfo"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_userInfo->sizePolicy().hasHeightForWidth());
        label_userInfo->setSizePolicy(sizePolicy);
        label_userInfo->setMinimumSize(QSize(50, 50));
        label_userInfo->setMaximumSize(QSize(50, 50));
        label_userInfo->setTextFormat(Qt::AutoText);
        label_userInfo->setPixmap(QPixmap(QString::fromUtf8(":/images/l5.png")));
        label_userInfo->setScaledContents(false);

        horizontalLayout_2->addWidget(label_userInfo);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_userInfoID = new QLabel(Widget);
        label_userInfoID->setObjectName(QStringLiteral("label_userInfoID"));
        sizePolicy.setHeightForWidth(label_userInfoID->sizePolicy().hasHeightForWidth());
        label_userInfoID->setSizePolicy(sizePolicy);
        label_userInfoID->setMinimumSize(QSize(65, 20));
        label_userInfoID->setMaximumSize(QSize(65, 20));
        label_userInfoID->setFrameShape(QFrame::NoFrame);

        verticalLayout->addWidget(label_userInfoID);

        label_userInfoName = new QLabel(Widget);
        label_userInfoName->setObjectName(QStringLiteral("label_userInfoName"));
        sizePolicy.setHeightForWidth(label_userInfoName->sizePolicy().hasHeightForWidth());
        label_userInfoName->setSizePolicy(sizePolicy);
        label_userInfoName->setMinimumSize(QSize(65, 20));
        label_userInfoName->setMaximumSize(QSize(65, 20));
        label_userInfoName->setFrameShape(QFrame::NoFrame);

        verticalLayout->addWidget(label_userInfoName);


        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_operate = new PixLabel(Widget);
        label_operate->setObjectName(QStringLiteral("label_operate"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_operate->sizePolicy().hasHeightForWidth());
        label_operate->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_operate);

        label_analyze = new PixLabel(Widget);
        label_analyze->setObjectName(QStringLiteral("label_analyze"));
        sizePolicy1.setHeightForWidth(label_analyze->sizePolicy().hasHeightForWidth());
        label_analyze->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_analyze);

        label_dataBase = new PixLabel(Widget);
        label_dataBase->setObjectName(QStringLiteral("label_dataBase"));
        sizePolicy1.setHeightForWidth(label_dataBase->sizePolicy().hasHeightForWidth());
        label_dataBase->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_dataBase);

        label_report = new PixLabel(Widget);
        label_report->setObjectName(QStringLiteral("label_report"));
        sizePolicy1.setHeightForWidth(label_report->sizePolicy().hasHeightForWidth());
        label_report->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_report);


        horizontalLayout_7->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(horizontalLayout_7);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_5 = new QHBoxLayout(tab);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(25);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_video = new QLabel(tab);
        label_video->setObjectName(QStringLiteral("label_video"));
        label_video->setFrameShape(QFrame::Box);

        horizontalLayout_3->addWidget(label_video);

        label_coloredTape = new QLabel(tab);
        label_coloredTape->setObjectName(QStringLiteral("label_coloredTape"));
        label_coloredTape->setFrameShape(QFrame::Box);

        horizontalLayout_3->addWidget(label_coloredTape);

        horizontalLayout_3->setStretch(0, 10);
        horizontalLayout_3->setStretch(1, 1);

        horizontalLayout_4->addLayout(horizontalLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(0);
        pushButton_up = new QPushButton(tab);
        pushButton_up->setObjectName(QStringLiteral("pushButton_up"));
        sizePolicy.setHeightForWidth(pushButton_up->sizePolicy().hasHeightForWidth());
        pushButton_up->setSizePolicy(sizePolicy);
        pushButton_up->setMinimumSize(QSize(80, 80));
        pushButton_up->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(pushButton_up, 0, 0, 1, 1);

        pushButton_capture = new QPushButton(tab);
        pushButton_capture->setObjectName(QStringLiteral("pushButton_capture"));
        pushButton_capture->setMinimumSize(QSize(80, 80));
        pushButton_capture->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(pushButton_capture, 2, 0, 1, 1);

        pushButton_down = new QPushButton(tab);
        pushButton_down->setObjectName(QStringLiteral("pushButton_down"));
        sizePolicy.setHeightForWidth(pushButton_down->sizePolicy().hasHeightForWidth());
        pushButton_down->setSizePolicy(sizePolicy);
        pushButton_down->setMinimumSize(QSize(80, 80));
        pushButton_down->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(pushButton_down, 0, 1, 1, 1);

        pushButton_focus_plus = new QPushButton(tab);
        pushButton_focus_plus->setObjectName(QStringLiteral("pushButton_focus_plus"));
        sizePolicy.setHeightForWidth(pushButton_focus_plus->sizePolicy().hasHeightForWidth());
        pushButton_focus_plus->setSizePolicy(sizePolicy);
        pushButton_focus_plus->setMinimumSize(QSize(80, 80));
        pushButton_focus_plus->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(pushButton_focus_plus, 1, 0, 1, 1);

        pushButton_focus_minus = new QPushButton(tab);
        pushButton_focus_minus->setObjectName(QStringLiteral("pushButton_focus_minus"));
        sizePolicy.setHeightForWidth(pushButton_focus_minus->sizePolicy().hasHeightForWidth());
        pushButton_focus_minus->setSizePolicy(sizePolicy);
        pushButton_focus_minus->setMinimumSize(QSize(80, 80));
        pushButton_focus_minus->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(pushButton_focus_minus, 1, 1, 1, 1);

        pushButton_captureAgain = new QPushButton(tab);
        pushButton_captureAgain->setObjectName(QStringLiteral("pushButton_captureAgain"));
        sizePolicy.setHeightForWidth(pushButton_captureAgain->sizePolicy().hasHeightForWidth());
        pushButton_captureAgain->setSizePolicy(sizePolicy);
        pushButton_captureAgain->setMinimumSize(QSize(80, 80));
        pushButton_captureAgain->setMaximumSize(QSize(80, 80));

        gridLayout->addWidget(pushButton_captureAgain, 2, 1, 1, 1);


        horizontalLayout_4->addLayout(gridLayout);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(50);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_analysisPicture = new SplitScreenLabelWidget(tab_2);
        label_analysisPicture->setObjectName(QStringLiteral("label_analysisPicture"));

        horizontalLayout_6->addWidget(label_analysisPicture);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_printScreen = new QLabel(tab_2);
        label_printScreen->setObjectName(QStringLiteral("label_printScreen"));
        label_printScreen->setFrameShape(QFrame::NoFrame);

        verticalLayout_3->addWidget(label_printScreen);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setVerticalSpacing(6);
        pushButton_splitScreen_1 = new QPushButton(tab_2);
        pushButton_splitScreen_1->setObjectName(QStringLiteral("pushButton_splitScreen_1"));
        sizePolicy.setHeightForWidth(pushButton_splitScreen_1->sizePolicy().hasHeightForWidth());
        pushButton_splitScreen_1->setSizePolicy(sizePolicy);
        pushButton_splitScreen_1->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(pushButton_splitScreen_1, 0, 0, 1, 1);

        pushButton_splitScreen_2 = new QPushButton(tab_2);
        pushButton_splitScreen_2->setObjectName(QStringLiteral("pushButton_splitScreen_2"));
        sizePolicy.setHeightForWidth(pushButton_splitScreen_2->sizePolicy().hasHeightForWidth());
        pushButton_splitScreen_2->setSizePolicy(sizePolicy);
        pushButton_splitScreen_2->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(pushButton_splitScreen_2, 0, 1, 1, 1);

        comboBox_printScreenForm = new QComboBox(tab_2);
        comboBox_printScreenForm->setObjectName(QStringLiteral("comboBox_printScreenForm"));
        sizePolicy.setHeightForWidth(comboBox_printScreenForm->sizePolicy().hasHeightForWidth());
        comboBox_printScreenForm->setSizePolicy(sizePolicy);
        comboBox_printScreenForm->setMinimumSize(QSize(75, 30));
        comboBox_printScreenForm->setMaximumSize(QSize(16777215, 30));

        gridLayout_2->addWidget(comboBox_printScreenForm, 1, 1, 1, 1);

        pushButton_maniTool = new QPushButton(tab_2);
        pushButton_maniTool->setObjectName(QStringLiteral("pushButton_maniTool"));
        sizePolicy.setHeightForWidth(pushButton_maniTool->sizePolicy().hasHeightForWidth());
        pushButton_maniTool->setSizePolicy(sizePolicy);
        pushButton_maniTool->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(pushButton_maniTool, 2, 0, 1, 1);

        pushButton_pictureReset = new QPushButton(tab_2);
        pushButton_pictureReset->setObjectName(QStringLiteral("pushButton_pictureReset"));
        sizePolicy.setHeightForWidth(pushButton_pictureReset->sizePolicy().hasHeightForWidth());
        pushButton_pictureReset->setSizePolicy(sizePolicy);
        pushButton_pictureReset->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(pushButton_pictureReset, 2, 1, 1, 1);

        pushButton_splitScreen_4 = new QPushButton(tab_2);
        pushButton_splitScreen_4->setObjectName(QStringLiteral("pushButton_splitScreen_4"));
        sizePolicy.setHeightForWidth(pushButton_splitScreen_4->sizePolicy().hasHeightForWidth());
        pushButton_splitScreen_4->setSizePolicy(sizePolicy);
        pushButton_splitScreen_4->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(pushButton_splitScreen_4, 1, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFrameShape(QFrame::Box);

        verticalLayout_3->addWidget(label_6);


        horizontalLayout_6->addLayout(verticalLayout_3);

        horizontalLayout_6->setStretch(0, 2);
        horizontalLayout_6->setStretch(1, 1);

        verticalLayout_4->addLayout(horizontalLayout_6);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_10 = new QVBoxLayout(tab_3);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        listWidget_dataBasePicture = new scrollImageWidget(tab_3);
        listWidget_dataBasePicture->setObjectName(QStringLiteral("listWidget_dataBasePicture"));

        horizontalLayout_11->addWidget(listWidget_dataBasePicture);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        tableWidget_case = new QTableWidget(tab_3);
        tableWidget_case->setObjectName(QStringLiteral("tableWidget_case"));

        horizontalLayout_8->addWidget(tableWidget_case);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        lineEdit_search = new QLineEdit(tab_3);
        lineEdit_search->setObjectName(QStringLiteral("lineEdit_search"));
        sizePolicy.setHeightForWidth(lineEdit_search->sizePolicy().hasHeightForWidth());
        lineEdit_search->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(lineEdit_search);

        pushButton_search = new QPushButton(tab_3);
        pushButton_search->setObjectName(QStringLiteral("pushButton_search"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_search->sizePolicy().hasHeightForWidth());
        pushButton_search->setSizePolicy(sizePolicy2);
        pushButton_search->setMinimumSize(QSize(0, 0));
        pushButton_search->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_6->addWidget(pushButton_search);

        pushButton_modifyCase = new QPushButton(tab_3);
        pushButton_modifyCase->setObjectName(QStringLiteral("pushButton_modifyCase"));
        sizePolicy2.setHeightForWidth(pushButton_modifyCase->sizePolicy().hasHeightForWidth());
        pushButton_modifyCase->setSizePolicy(sizePolicy2);
        pushButton_modifyCase->setMinimumSize(QSize(0, 0));
        pushButton_modifyCase->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_6->addWidget(pushButton_modifyCase);

        pushButton_deleteCase = new QPushButton(tab_3);
        pushButton_deleteCase->setObjectName(QStringLiteral("pushButton_deleteCase"));
        sizePolicy2.setHeightForWidth(pushButton_deleteCase->sizePolicy().hasHeightForWidth());
        pushButton_deleteCase->setSizePolicy(sizePolicy2);
        pushButton_deleteCase->setMinimumSize(QSize(0, 0));
        pushButton_deleteCase->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_6->addWidget(pushButton_deleteCase);


        horizontalLayout_8->addLayout(verticalLayout_6);

        horizontalLayout_8->setStretch(0, 6);
        horizontalLayout_8->setStretch(1, 1);

        horizontalLayout_9->addLayout(horizontalLayout_8);

        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::NoFrame);

        horizontalLayout_9->addWidget(label);

        horizontalLayout_9->setStretch(0, 3);
        horizontalLayout_9->setStretch(1, 1);

        verticalLayout_8->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        tableWidget_diagnose = new QTableWidget(tab_3);
        tableWidget_diagnose->setObjectName(QStringLiteral("tableWidget_diagnose"));

        horizontalLayout_10->addWidget(tableWidget_diagnose);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        pushButton_modifyDiagnose = new QPushButton(tab_3);
        pushButton_modifyDiagnose->setObjectName(QStringLiteral("pushButton_modifyDiagnose"));

        verticalLayout_7->addWidget(pushButton_modifyDiagnose);

        pushButton_deleteDiagnose = new QPushButton(tab_3);
        pushButton_deleteDiagnose->setObjectName(QStringLiteral("pushButton_deleteDiagnose"));

        verticalLayout_7->addWidget(pushButton_deleteDiagnose);

        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_7->addWidget(pushButton_4);


        horizontalLayout_10->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(horizontalLayout_10);


        horizontalLayout_11->addLayout(verticalLayout_8);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 5);

        verticalLayout_10->addLayout(horizontalLayout_11);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());

        verticalLayout_2->addWidget(tabWidget);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 10);

        verticalLayout_9->addLayout(verticalLayout_2);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        listWidget = new scrollImageWidget(Widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout_12->addWidget(listWidget);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        pushButton_PictureToDataBase = new QPushButton(Widget);
        pushButton_PictureToDataBase->setObjectName(QStringLiteral("pushButton_PictureToDataBase"));

        verticalLayout_5->addWidget(pushButton_PictureToDataBase);

        pushButton_10 = new QPushButton(Widget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        verticalLayout_5->addWidget(pushButton_10);

        pushButton_deleteScrollImage = new QPushButton(Widget);
        pushButton_deleteScrollImage->setObjectName(QStringLiteral("pushButton_deleteScrollImage"));

        verticalLayout_5->addWidget(pushButton_deleteScrollImage);


        horizontalLayout_12->addLayout(verticalLayout_5);


        verticalLayout_9->addLayout(horizontalLayout_12);

        verticalLayout_9->setStretch(0, 7);
        verticalLayout_9->setStretch(1, 1);

        verticalLayout_11->addLayout(verticalLayout_9);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "MTD", Q_NULLPTR));
        label_userInfo->setText(QString());
        label_userInfoID->setText(QString());
        label_userInfoName->setText(QString());
        label_operate->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_analyze->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_dataBase->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_report->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_video->setText(QApplication::translate("Widget", "\350\247\206\351\242\221\345\214\272", Q_NULLPTR));
        label_coloredTape->setText(QString());
        pushButton_up->setText(QApplication::translate("Widget", "\344\270\212", Q_NULLPTR));
        pushButton_capture->setText(QApplication::translate("Widget", "\346\212\223\345\233\276", Q_NULLPTR));
        pushButton_down->setText(QApplication::translate("Widget", "\344\270\213", Q_NULLPTR));
        pushButton_focus_plus->setText(QApplication::translate("Widget", "\350\201\232\347\204\246+", Q_NULLPTR));
        pushButton_focus_minus->setText(QApplication::translate("Widget", "\350\201\232\347\204\246\342\200\224", Q_NULLPTR));
        pushButton_captureAgain->setText(QApplication::translate("Widget", "\351\207\215\346\226\260\350\216\267\345\217\226", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "1", Q_NULLPTR));
        label_printScreen->setText(QString());
        pushButton_splitScreen_1->setText(QApplication::translate("Widget", "1", Q_NULLPTR));
        pushButton_splitScreen_2->setText(QApplication::translate("Widget", "2", Q_NULLPTR));
        pushButton_maniTool->setText(QApplication::translate("Widget", "\345\233\276\350\261\241\345\244\204\347\220\206", Q_NULLPTR));
        pushButton_pictureReset->setText(QApplication::translate("Widget", "\345\233\276\350\261\241\351\207\215\347\275\256", Q_NULLPTR));
        pushButton_splitScreen_4->setText(QApplication::translate("Widget", "4", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "\347\224\250\344\272\216\346\230\276\347\244\272\346\270\251\345\272\246", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "2", Q_NULLPTR));
        pushButton_search->setText(QApplication::translate("Widget", "\346\220\234\347\264\242", Q_NULLPTR));
        pushButton_modifyCase->setText(QApplication::translate("Widget", "\344\277\256\346\224\271\347\227\205\344\276\213", Q_NULLPTR));
        pushButton_deleteCase->setText(QApplication::translate("Widget", "\345\210\240\351\231\244\347\227\205\344\276\213", Q_NULLPTR));
        label->setText(QString());
        pushButton_modifyDiagnose->setText(QApplication::translate("Widget", "\344\277\256\346\224\271\350\257\212\346\226\255", Q_NULLPTR));
        pushButton_deleteDiagnose->setText(QApplication::translate("Widget", "\345\210\240\351\231\244\350\257\212\346\226\255", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Widget", "\345\210\240\351\231\244\345\233\276\347\211\207", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Widget", "3", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Widget", "4", Q_NULLPTR));
        pushButton_PictureToDataBase->setText(QApplication::translate("Widget", "\344\277\235\345\255\230", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("Widget", "\345\257\274\345\205\245", Q_NULLPTR));
        pushButton_deleteScrollImage->setText(QApplication::translate("Widget", "\345\210\240\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
