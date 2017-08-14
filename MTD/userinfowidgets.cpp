#include "userinfowidgets.h"
#include "ui_userinfowidgets.h"

userInfoWidgets::userInfoWidgets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userInfoWidgets)
{
    ui->setupUi(this);
    //this->resize(507, 421);
    ui->sexComboBox->addItem("Male");
    ui->sexComboBox->addItem("Female");

    ui->tabWidget->tabBar()->hide();
    ui->tabWidget->setCurrentIndex(0);

    ui->label_login->setText("登录");
    ui->label_login->setMousePressFlag(true);
    ui->label_login->setTab(0);
    ui->label_login->setPixmap(QPixmap(QString(":/images/l7")));

    ui->label_signIn->setText("注册");
    ui->label_signIn->setTab(1);
    ui->label_signIn->setPixmap(QPixmap(QString(":/images/l8")));

    ui->label_icon->setPixmap(QPixmap(QString("../images/l10")));
    ui->label_icon->setScaledContents(true);

    connect(ui->label_signIn, SIGNAL(signalLabelPress(PixLabel*)), this, SLOT(changeCurrentTab(PixLabel*)));
    connect(ui->label_login, SIGNAL(signalLabelPress(PixLabel*)), this, SLOT(changeCurrentTab(PixLabel*)));
}

userInfoWidgets::~userInfoWidgets()
{
    delete ui;
}

/********************************************************************
* 函数名：changeCurrentTab
* 功能：  切换当前的tabwidgets
* 参数：  pix
* 返回值：无
*
* 时间： 2017-8-11
* 作者：
*********************************************************************/
void userInfoWidgets::changeCurrentTab(PixLabel *pix)
{
    int indexTab = pix->getTab();

    switch (indexTab)
    {
    case 0:
        ui->tabWidget->setCurrentIndex(0);
        ui->label_signIn->setMousePressFlag(false);
        break;

    case 1:
        ui->tabWidget->setCurrentIndex(1);
        ui->label_login->setMousePressFlag(false);
        break;

    default:
        break;
    }
}
/********************************************************************
* 函数名：on_pushButton_makeSure_2_clicked
* 功能：  槽函数，确认注册信息
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-11
* 作者：
*********************************************************************/
void userInfoWidgets::on_pushButton_makeSure_2_clicked()
{
    QString strNameContent, strAgeContent, strSexContent;

    strNameContent = ui->nameLineEdit->text();
    strAgeContent  = ui->ageLineEdit->text();
    strSexContent  = ui->sexComboBox->currentText();

    emit SendUserInfoContent(strNameContent, strAgeContent, strSexContent);

    this->close();
}

/********************************************************************
* 函数名：on_pushButton_cancel_2_clicked
* 功能：  槽函数，取消注册信息
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-11
* 作者：
*********************************************************************/
void userInfoWidgets::on_pushButton_cancel_2_clicked()
{
    this->close();
}

/********************************************************************
* 函数名：on_pushButton_makeSure_1_clicked
* 功能：  槽函数，确认登录
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-11
* 作者：
*********************************************************************/
void userInfoWidgets::on_pushButton_makeSure_1_clicked()
{
    QString strId = ui->idLineEdit->text();
    if(strId == NULL) return;
    emit signalLogInUserId(strId);
    this->close();
}

/********************************************************************
* 函数名：on_pushButton_cancel_1_clicked
* 功能：  槽函数，取消登录
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-11
* 作者：
*********************************************************************/
void userInfoWidgets::on_pushButton_cancel_1_clicked()
{
    this->close();
}
