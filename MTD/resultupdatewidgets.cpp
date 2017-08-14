#include "resultupdatewidgets.h"
#include "ui_resultupdatewidgets.h"
#include <QMessageBox>

ResultUpdateWidgets::ResultUpdateWidgets(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultUpdateWidgets)
{
    ui->setupUi(this);

}

ResultUpdateWidgets::~ResultUpdateWidgets()
{
    delete ui;
}

void ResultUpdateWidgets::showResult(MedCheckResult res)
{
    result = res;
    ui->idEdit->setText(QString::number(result.id));
    ui->idEdit->setEnabled(false);
    ui->userIdEdit->setText(QString::number(result.userId));
    ui->userIdEdit->setEnabled(false);
    ui->checkDateEdit->setText(result.checkDate.toString("yyyy-MM-dd hh:mm:ss"));
    ui->checkDateEdit->setEnabled(false);
    ui->checkSpotEdit->setText(result.checkSpot);
    ui->docIdEdit->setText(QString::number(result.nDoctorID));
    ui->docNameEdit->setText(result.doctorName);
    ui->symptomEdit->setText(result.symptom);
    ui->decisionEdit->setText(result.decision);
    ui->therapyEdit->setText(result.therapy);
}

void ResultUpdateWidgets::on_saveResultBtn_clicked()
{
    result.checkSpot = ui->checkSpotEdit->text();
    result.nDoctorID = ui->docIdEdit->text().toInt();
    result.doctorName = ui->docNameEdit->text();
    result.symptom = ui->symptomEdit->toPlainText();
    result.decision = ui->decisionEdit->toPlainText();
    result.therapy = ui->therapyEdit->toPlainText();
    bool flag = mtd.updateResult(result);
    if(flag)
    {
        QMessageBox::warning(this, "更新诊断", "更新诊断成功", QMessageBox::Ok);
    }
    else
    {
        QMessageBox::warning(this, "更新诊断", "更新诊断失败", QMessageBox::Ok);
    }
    this->close();
}

void ResultUpdateWidgets::on_cancelBtn_clicked()
{
    this->close();
}
