#ifndef RESULTUPDATEWIDGETS_H
#define RESULTUPDATEWIDGETS_H

#include "MTDMed/mtdmed.h"
#include <QDialog>

namespace Ui {
class ResultUpdateWidgets;
}

class ResultUpdateWidgets : public QDialog
{
    Q_OBJECT

public:
    explicit ResultUpdateWidgets(bool bHidden, QWidget *parent = 0);
    ~ResultUpdateWidgets();

    void showResult(MedCheckResult res);

signals:
    void signalUpDateCheck();

private slots:
    void on_saveResultBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::ResultUpdateWidgets *ui;
    MtdMed mtd;
    MedCheckResult result;
};

#endif // RESULTUPDATEWIDGETS_H
