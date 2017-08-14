#include "recordupdatewidgets.h"
#include "ui_recordupdatewidgets.h"
#include <QMessageBox>
#include "resultupdatewidgets.h"

RecordUpdateWidgets::RecordUpdateWidgets(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecordUpdateWidgets)
{
    ui->setupUi(this);
    ui->userIdEdit->setEnabled(false);
}

RecordUpdateWidgets::~RecordUpdateWidgets()
{
    delete ui;
}

void RecordUpdateWidgets::showRecord(MedRecord record1)
{
    record = record1;
    ui->userIdEdit->setText(QString::number(record.userID));
    ui->nameEdit->setText(record.name);
    ui->ageEdit->setText(QString::number(record.age));
    int index = (true == record.bMale) ? 0 : 1;
    ui->gendleBox->setCurrentIndex(index);
    ui->addressEdit->setText(record.address);
    ui->contactEdit->setText(record.contact);
    ui->professionEdit->setText(record.profession);
    ui->personalHistoryEdit->setText(record.personalHistory);
    ui->familyHistoryEdit->setText(record.familyHistory);
}

/********************************************************************
* 函数名：on_updateBtn_clicked
* 功能：  槽函数，点击修改病例
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-14
* 作者：
*********************************************************************/
void RecordUpdateWidgets::on_updateBtn_clicked()
{
    //更新病例库
    record.name            = ui->nameEdit->text();
    record.age             = ui->ageEdit->text().toUInt();
    record.bMale           = (ui->gendleBox->currentText() == "Male") ? true : false;
    record.address         = ui->addressEdit->text();
    record.contact         = ui->contactEdit->text();
    record.profession      = ui->professionEdit->text();
    record.personalHistory = ui->personalHistoryEdit->toPlainText();
    record.familyHistory   = ui->familyHistoryEdit->toPlainText();
    bool flag = mtd.updateRecord(record);
    if(flag)
    {
        QMessageBox::warning(this, QStringLiteral("更新病历"), QStringLiteral("更新病历成功"), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::warning(this, QStringLiteral("更新病历"), QStringLiteral("更新病历失败"), QMessageBox::Ok);
    }

    emit signalUpDateRecord();//通知更新病例到界面

    this->close();
}

void RecordUpdateWidgets::on_cancleBtn_clicked()
{
    this->close();
}


