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
    ui->tableWidget_result->setColumnCount(7);
    QStringList diagnoseHeader;
    diagnoseHeader << QStringLiteral("编号") << "UserId" << QStringLiteral("就诊时间") << QStringLiteral("就诊地点") << QStringLiteral("医生编号") << QStringLiteral("医生姓名")
                   << QStringLiteral("症状") << QStringLiteral("诊断结论") << QStringLiteral("诊断方法");
    ui->tableWidget_result->setHorizontalHeaderLabels(diagnoseHeader);
    ui->tableWidget_result->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表头等宽
    ui->tableWidget_result->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中的方式
    ui->tableWidget_result->setEditTriggers(QAbstractItemView::NoEditTriggers); //禁止修改
    //设置表头字体加粗
    QFont fontDiagnose = ui->tableWidget_result->horizontalHeader()->font();
    fontDiagnose.setBold(true);
    ui->tableWidget_result->horizontalHeader()->setFont(fontDiagnose);
    ui->tableWidget_result->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头背景色
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

    for(int i = 0; i < record.allCheckResults.size(); i ++)
    {
        int rowCount = ui->tableWidget_result->rowCount();
        ui->tableWidget_result->setRowCount(rowCount + 1);
        ui->tableWidget_result->setItem(rowCount, 0, new QTableWidgetItem(QString::number(record.allCheckResults.at(i).id)));
        ui->tableWidget_result->setItem(rowCount, 1, new QTableWidgetItem(QString::number(record.allCheckResults.at(i).userId)));

        ui->tableWidget_result->setItem(rowCount, 2, new QTableWidgetItem(record.allCheckResults.at(i).checkDate.toString("yyyy-MM-dd hh:mm:ss")));
        ui->tableWidget_result->setItem(rowCount, 3, new QTableWidgetItem(record.allCheckResults.at(i).checkSpot));
        ui->tableWidget_result->setItem(rowCount, 4, new QTableWidgetItem(QString::number(record.allCheckResults.at(i).nDoctorID)));
        ui->tableWidget_result->setItem(rowCount, 5, new QTableWidgetItem(record.allCheckResults.at(i).doctorName));
        ui->tableWidget_result->setItem(rowCount, 6, new QTableWidgetItem(record.allCheckResults.at(i).symptom));
        ui->tableWidget_result->setItem(rowCount, 7, new QTableWidgetItem(record.allCheckResults.at(i).decision));
        ui->tableWidget_result->setItem(rowCount, 8, new QTableWidgetItem(record.allCheckResults.at(i).therapy));
    }
}

void RecordUpdateWidgets::on_updateBtn_clicked()
{
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
    this->close();
}

void RecordUpdateWidgets::on_cancleBtn_clicked()
{
    this->close();
}

void RecordUpdateWidgets::on_deleteResultBtn_clicked()
{
    int id = 0;
    //删除当前选中的诊断
    int rowIndex = ui->tableWidget_result->currentRow();
    if (rowIndex != -1)
    {
        //删除数据库数据
        id = ui->tableWidget_result->item(rowIndex, 0)->text().toInt();
        mtd.deleteResult(id);
        //删除table表中的数据
        ui->tableWidget_result->removeRow(rowIndex);//删除当前行
    }
}

void RecordUpdateWidgets::on_updateResultBtn_clicked()
{
    int rowIndex = ui->tableWidget_result->currentRow();
    if(rowIndex == -1) return;
    int id = ui->tableWidget_result->item(rowIndex, 0)->text().toInt();
    MedCheckResult res;
    mtd.selectResultById(id, res);

    ResultUpdateWidgets *resultWidgets = new ResultUpdateWidgets;

    resultWidgets->showResult(res);

    resultWidgets->show();
}
