/********************************************************************************
** Form generated from reading UI file 'analysiswidgets.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYSISWIDGETS_H
#define UI_ANALYSISWIDGETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_analysisWidgets
{
public:
    QLabel *label;
    QSlider *horizontalSlider_edgeDetection;
    QLabel *Label_3;
    QSpinBox *SpinBox_lowerTemperature;
    QLabel *Label_4;
    QSpinBox *SpinBox_upperTemperature;
    QWidget *widget;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_blackAndWhite;
    QRadioButton *radioButton_160;
    QRadioButton *radioButton_80;
    QRadioButton *radioButton_40;
    QRadioButton *radioButton_20;
    QCheckBox *checkBox_polarityReversal;
    QCheckBox *checkBox_filtration;
    QCheckBox *checkBox_histogram;

    void setupUi(QWidget *analysisWidgets)
    {
        if (analysisWidgets->objectName().isEmpty())
            analysisWidgets->setObjectName(QStringLiteral("analysisWidgets"));
        analysisWidgets->resize(271, 258);
        label = new QLabel(analysisWidgets);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(16, 139, 50, 12));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(50, 12));
        label->setMaximumSize(QSize(50, 12));
        horizontalSlider_edgeDetection = new QSlider(analysisWidgets);
        horizontalSlider_edgeDetection->setObjectName(QStringLiteral("horizontalSlider_edgeDetection"));
        horizontalSlider_edgeDetection->setGeometry(QRect(80, 134, 160, 22));
        sizePolicy.setHeightForWidth(horizontalSlider_edgeDetection->sizePolicy().hasHeightForWidth());
        horizontalSlider_edgeDetection->setSizePolicy(sizePolicy);
        horizontalSlider_edgeDetection->setMinimumSize(QSize(160, 22));
        horizontalSlider_edgeDetection->setMaximumSize(QSize(160, 22));
        horizontalSlider_edgeDetection->setOrientation(Qt::Horizontal);
        Label_3 = new QLabel(analysisWidgets);
        Label_3->setObjectName(QStringLiteral("Label_3"));
        Label_3->setGeometry(QRect(16, 184, 48, 16));
        SpinBox_lowerTemperature = new QSpinBox(analysisWidgets);
        SpinBox_lowerTemperature->setObjectName(QStringLiteral("SpinBox_lowerTemperature"));
        SpinBox_lowerTemperature->setGeometry(QRect(80, 180, 80, 20));
        sizePolicy.setHeightForWidth(SpinBox_lowerTemperature->sizePolicy().hasHeightForWidth());
        SpinBox_lowerTemperature->setSizePolicy(sizePolicy);
        SpinBox_lowerTemperature->setMinimumSize(QSize(80, 20));
        SpinBox_lowerTemperature->setMaximumSize(QSize(80, 20));
        SpinBox_lowerTemperature->setMaximum(255);
        Label_4 = new QLabel(analysisWidgets);
        Label_4->setObjectName(QStringLiteral("Label_4"));
        Label_4->setGeometry(QRect(16, 220, 48, 16));
        SpinBox_upperTemperature = new QSpinBox(analysisWidgets);
        SpinBox_upperTemperature->setObjectName(QStringLiteral("SpinBox_upperTemperature"));
        SpinBox_upperTemperature->setGeometry(QRect(80, 220, 80, 20));
        sizePolicy.setHeightForWidth(SpinBox_upperTemperature->sizePolicy().hasHeightForWidth());
        SpinBox_upperTemperature->setSizePolicy(sizePolicy);
        SpinBox_upperTemperature->setMinimumSize(QSize(80, 20));
        SpinBox_upperTemperature->setMaximumSize(QSize(80, 20));
        SpinBox_upperTemperature->setMaximum(255);
        widget = new QWidget(analysisWidgets);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(11, 11, 251, 111));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_blackAndWhite = new QRadioButton(widget);
        radioButton_blackAndWhite->setObjectName(QStringLiteral("radioButton_blackAndWhite"));
        sizePolicy.setHeightForWidth(radioButton_blackAndWhite->sizePolicy().hasHeightForWidth());
        radioButton_blackAndWhite->setSizePolicy(sizePolicy);
        radioButton_blackAndWhite->setMinimumSize(QSize(50, 16));
        radioButton_blackAndWhite->setMaximumSize(QSize(50, 16));

        gridLayout->addWidget(radioButton_blackAndWhite, 0, 0, 1, 1);

        radioButton_160 = new QRadioButton(widget);
        radioButton_160->setObjectName(QStringLiteral("radioButton_160"));
        sizePolicy.setHeightForWidth(radioButton_160->sizePolicy().hasHeightForWidth());
        radioButton_160->setSizePolicy(sizePolicy);

        gridLayout->addWidget(radioButton_160, 0, 1, 1, 1);

        radioButton_80 = new QRadioButton(widget);
        radioButton_80->setObjectName(QStringLiteral("radioButton_80"));
        sizePolicy.setHeightForWidth(radioButton_80->sizePolicy().hasHeightForWidth());
        radioButton_80->setSizePolicy(sizePolicy);

        gridLayout->addWidget(radioButton_80, 0, 2, 1, 1);

        radioButton_40 = new QRadioButton(widget);
        radioButton_40->setObjectName(QStringLiteral("radioButton_40"));

        gridLayout->addWidget(radioButton_40, 1, 0, 1, 1);

        radioButton_20 = new QRadioButton(widget);
        radioButton_20->setObjectName(QStringLiteral("radioButton_20"));

        gridLayout->addWidget(radioButton_20, 1, 1, 1, 1);

        checkBox_polarityReversal = new QCheckBox(widget);
        checkBox_polarityReversal->setObjectName(QStringLiteral("checkBox_polarityReversal"));
        sizePolicy.setHeightForWidth(checkBox_polarityReversal->sizePolicy().hasHeightForWidth());
        checkBox_polarityReversal->setSizePolicy(sizePolicy);

        gridLayout->addWidget(checkBox_polarityReversal, 2, 0, 1, 1);

        checkBox_filtration = new QCheckBox(widget);
        checkBox_filtration->setObjectName(QStringLiteral("checkBox_filtration"));
        sizePolicy.setHeightForWidth(checkBox_filtration->sizePolicy().hasHeightForWidth());
        checkBox_filtration->setSizePolicy(sizePolicy);

        gridLayout->addWidget(checkBox_filtration, 2, 1, 1, 1);

        checkBox_histogram = new QCheckBox(widget);
        checkBox_histogram->setObjectName(QStringLiteral("checkBox_histogram"));

        gridLayout->addWidget(checkBox_histogram, 2, 2, 1, 1);


        retranslateUi(analysisWidgets);

        QMetaObject::connectSlotsByName(analysisWidgets);
    } // setupUi

    void retranslateUi(QWidget *analysisWidgets)
    {
        analysisWidgets->setWindowTitle(QApplication::translate("analysisWidgets", "\345\233\276\347\211\207\345\210\206\346\236\220", Q_NULLPTR));
        label->setText(QApplication::translate("analysisWidgets", "\350\276\271\347\274\230\346\243\200\346\265\213", Q_NULLPTR));
        Label_3->setText(QApplication::translate("analysisWidgets", "\346\270\251\345\272\246\344\270\213\351\231\220", Q_NULLPTR));
        Label_4->setText(QApplication::translate("analysisWidgets", "\346\270\251\345\272\246\344\270\212\351\231\220", Q_NULLPTR));
        radioButton_blackAndWhite->setText(QApplication::translate("analysisWidgets", "\351\273\221\347\231\275", Q_NULLPTR));
        radioButton_160->setText(QApplication::translate("analysisWidgets", "160\350\211\262", Q_NULLPTR));
        radioButton_80->setText(QApplication::translate("analysisWidgets", "80\350\211\262", Q_NULLPTR));
        radioButton_40->setText(QApplication::translate("analysisWidgets", "40\350\211\262", Q_NULLPTR));
        radioButton_20->setText(QApplication::translate("analysisWidgets", "20\350\211\262", Q_NULLPTR));
        checkBox_polarityReversal->setText(QApplication::translate("analysisWidgets", "\346\236\201\346\200\247\344\272\244\346\215\242", Q_NULLPTR));
        checkBox_filtration->setText(QApplication::translate("analysisWidgets", "\346\273\244\346\263\242", Q_NULLPTR));
        checkBox_histogram->setText(QApplication::translate("analysisWidgets", "\347\233\264\346\226\271\345\233\276\346\213\211\344\274\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class analysisWidgets: public Ui_analysisWidgets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYSISWIDGETS_H
