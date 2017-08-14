#ifndef ANALYSISWIDGETS_H
#define ANALYSISWIDGETS_H

#include <QWidget>

namespace Ui {
class analysisWidgets;
}

class analysisWidgets : public QWidget
{
    Q_OBJECT

public:
    explicit analysisWidgets(QWidget *parent = 0);
    ~analysisWidgets();

signals:
    void signal_imageAnalysis_BlackAndWhite(bool);
    void signal_imageAnalysis_160(bool);
    void signal_imageAnalysis_80(bool);
    void signal_imageAnalysis_40(bool);
    void signal_imageAnalysis_20(bool);
    void signal_imageAnalysis_polarityReversal(bool);
    void signal_imageAnalysis_filtration(bool);
    void signal_imageAnalysis_histogram(bool);
    void signal_imageAnalysis_edgeDetection(int value);
    void signal_imageAnalysis_lowerTemperature(int value);
    void signal_imageAnalysis_upperTemperature(int value);

private slots:
    void on_radioButton_blackAndWhite_toggled(bool checked);
    void on_radioButton_160_toggled(bool checked);
    void on_radioButton_80_toggled(bool checked);
    void on_radioButton_40_toggled(bool checked);
    void on_radioButton_20_toggled(bool checked);
    void on_checkBox_polarityReversal_toggled(bool checked);
    void on_checkBox_filtration_toggled(bool checked);
    void on_checkBox_histogram_toggled(bool checked);
    void on_horizontalSlider_edgeDetection_valueChanged(int value);
    void on_SpinBox_lowerTemperature_valueChanged(int arg1);
    void on_SpinBox_upperTemperature_valueChanged(int arg1);

private:
    Ui::analysisWidgets *ui;
};

#endif // ANALYSISWIDGETS_H
