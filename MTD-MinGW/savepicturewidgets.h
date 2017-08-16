#ifndef SAVEPICTUREWIDGETS_H
#define SAVEPICTUREWIDGETS_H


#include <QWidget>
#include"common.h"

namespace Ui {
class savepicturewidgets;
}

class savePictureWidgets : public QWidget
{
    Q_OBJECT

public:
    explicit savePictureWidgets(QWidget *parent = 0);
    ~savePictureWidgets();

private slots:
    void on_pushButton_save_clicked();
    void on_pushButton_cancel_clicked();

 signals:
    void sendDiagnoseInfo(Common::stDiagnoseRst);

private:
    Ui::savepicturewidgets *ui;
};

#endif // SAVEPICTUREWIDGETS_H
