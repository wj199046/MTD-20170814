#ifndef RECORDUPDATEWIDGETS_H
#define RECORDUPDATEWIDGETS_H

#include <QDialog>
#include"MTDMed/mtdmed.h"

namespace Ui {
class RecordUpdateWidgets;
}

class RecordUpdateWidgets : public QDialog
{
    Q_OBJECT

public:
    explicit RecordUpdateWidgets(QWidget *parent = 0);
    ~RecordUpdateWidgets();

    void showRecord(MedRecord record);

signals:
    void signalUpDateRecord();

private slots:
    void on_updateBtn_clicked();
    void on_cancleBtn_clicked();

private:
    Ui::RecordUpdateWidgets *ui;
    MedRecord record;
    MtdMed mtd;
};

#endif // RECORDUPDATEWIDGETS_H
