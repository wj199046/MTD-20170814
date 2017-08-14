#include "analysiswidgets.h"
#include "ui_analysiswidgets.h"
#include<QDebug>

analysisWidgets::analysisWidgets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::analysisWidgets)
{
    ui->setupUi(this);
    this->resize(271, 258);

    ui->SpinBox_lowerTemperature->setValue(0);
    ui->SpinBox_upperTemperature->setValue(255);
}

analysisWidgets::~analysisWidgets()
{
    delete ui;
}

void analysisWidgets::on_radioButton_blackAndWhite_toggled(bool checked)
{
    if(true == checked)
    {
        emit signal_imageAnalysis_BlackAndWhite(checked);
    }
}

void analysisWidgets::on_radioButton_160_toggled(bool checked)
{
    if(true == checked)
    {
        emit signal_imageAnalysis_160(checked);
    }
}

void analysisWidgets::on_radioButton_80_toggled(bool checked)
{
    if(true == checked)
    {
        emit signal_imageAnalysis_80(checked);
    }
}

void analysisWidgets::on_radioButton_40_toggled(bool checked)
{
    if(true == checked)
    {
        emit signal_imageAnalysis_40(checked);
    }
}

void analysisWidgets::on_radioButton_20_toggled(bool checked)
{
    if(true == checked)
    {
        emit signal_imageAnalysis_20(checked);
    }
}

void analysisWidgets::on_checkBox_polarityReversal_toggled(bool checked)
{
    emit signal_imageAnalysis_polarityReversal(checked);
}

void analysisWidgets::on_checkBox_filtration_toggled(bool checked)
{
    emit signal_imageAnalysis_filtration(checked);
}

void analysisWidgets::on_checkBox_histogram_toggled(bool checked)
{
    emit signal_imageAnalysis_histogram(checked);
}

void analysisWidgets::on_horizontalSlider_edgeDetection_valueChanged(int value)
{
    emit signal_imageAnalysis_edgeDetection(value);
}

void analysisWidgets::on_SpinBox_lowerTemperature_valueChanged(int arg1)
{
    emit signal_imageAnalysis_lowerTemperature(arg1);
}

void analysisWidgets::on_SpinBox_upperTemperature_valueChanged(int arg1)
{
    emit signal_imageAnalysis_upperTemperature(arg1);
}
