#include "savepicturewidgets.h"
#include "ui_savepicturewidgets.h"

savePictureWidgets::savePictureWidgets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::savepicturewidgets)
{
    ui->setupUi(this);
    this->resize(450, 471);
}

savePictureWidgets::~savePictureWidgets()
{
    delete ui;
}

void savePictureWidgets::on_pushButton_save_clicked()
{
    Common::stDiagnoseRst stResult;

    stResult.strDoctorId   = ui->textEdit_id->toPlainText();
    stResult.strDoctorName = ui->textEdit_name->toPlainText();
    stResult.strPlace      = ui->textEdit_place->toPlainText();
    stResult.strSymptom    = ui->textEdit_symptom->toPlainText();
    stResult.strDecision   = ui->textEdit_decision->toPlainText();
    stResult.strTherapy    = ui->textEdit_therapy->toPlainText();

    emit sendDiagnoseInfo(stResult);
}

void savePictureWidgets::on_pushButton_cancel_clicked()
{
    this->close();
}
