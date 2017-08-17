#include "widget.h"
#include "ui_widget.h"
#include<QInputDialog>
#include<QDebug>
#include<QMessageBox>
#include "include/camera/mtd_util.h"
#include <QPrinter>
#include<QPrintDialog>
#include<QPrintPreviewDialog>

/********************************************************************
* 函数名：Widget
* 功能：  Widget构造函数
* 参数：  parent
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*********************************************************************/
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_pVideo(NULL), m_userInfo(NULL), m_recordShow(NULL), m_resultShow(NULL),
    m_bUpDownStop(false), m_bFocusStop(false), m_pMtdDataBase(NULL), m_pSaveDiagnose(NULL),
    m_recordUpdate(NULL), m_resultUpdate(NULL)
{
    ui->setupUi(this);

    ui->listWidget->init(1, true);
    ui->listWidget_dataBasePicture->init(2, false);

    //隐藏TabBar控件
    ui->tabWidget->tabBar()->hide();    
    ui->tabWidget->setCurrentIndex(EN_OPERATE_TAB);

    //四个标题控件
    ui->label_operate->setPixmap(QPixmap(QString(":/images/l1")));
    ui->label_operate->setText("数据采集");
    ui->label_operate->setTab(EN_OPERATE_TAB);
    ui->label_operate->setMousePressFlag(true);

    ui->label_analyze->setPixmap(QPixmap(QString(":/images/l2")));
    ui->label_analyze->setText("图像处理");
    ui->label_analyze->setTab(EN_ANALYSIS_TAB);

    ui->label_dataBase->setPixmap(QPixmap(QString(":/images/l3")));
    ui->label_dataBase->setText("病历管理");
    ui->label_dataBase->setTab(EN_DATABASE_TAB);

    ui->label_report->setPixmap(QPixmap(QString(":/images/l4")));
    ui->label_report->setText("诊断输出");
    ui->label_report->setTab(EN_REPORT_TAB);

    QPixmap userInfoPixmap(QString(":/images/l5"));
    ui->label_userInfo->setPixmap(userInfoPixmap.scaled(QSize(38, 38), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->label_userInfo->setAlignment(Qt::AlignCenter);
    connect(ui->label_userInfo, SIGNAL(signalLabelPress(UserLabel *)), this, SLOT(showUserInfo(UserLabel*)));

    connect(ui->label_operate, SIGNAL(signalLabelPress(PixLabel*)), this, SLOT(changeCurrentTab(PixLabel*)));
    connect(ui->label_analyze, SIGNAL(signalLabelPress(PixLabel*)), this, SLOT(changeCurrentTab(PixLabel*)));
    connect(ui->label_dataBase, SIGNAL(signalLabelPress(PixLabel*)), this, SLOT(changeCurrentTab(PixLabel*)));
    connect(ui->label_report, SIGNAL(signalLabelPress(PixLabel*)), this, SLOT(changeCurrentTab(PixLabel*)));

    m_pSaveDiagnose = new savePictureWidgets;

    connect(m_pSaveDiagnose, SIGNAL(sendDiagnoseInfo(Common::stDiagnoseRst)), this, SLOT(receiveDiagnoseInfo(Common::stDiagnoseRst)));

    m_userInfo      = new userInfoWidgets;

    connect(m_userInfo, SIGNAL(SendUserInfoContent(Common::stUserSigninInfo)), this, SLOT(ReceiveUserInfo(Common::stUserSigninInfo)));
    connect(m_userInfo, SIGNAL(signalLogInUserId(QString)), this, SLOT(slotLogInUserId(QString)));
    connect(ui->listWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem *)), this, SLOT(doubleClickedShowPicture(QTableWidgetItem*)));

    connect(this, SIGNAL(sendSplitScreenCount(int)), ui->label_analysisPicture, SLOT(splitScreen(int)));
    connect(this, SIGNAL(sendPicture(QPixmap, int)), ui->label_analysisPicture, SLOT(receivePicture(QPixmap , int)));
    connect(ui->label_analysisPicture, SIGNAL(signalSendPrintScreen(QPixmap, QPoint, QPoint, QPoint)), this, SLOT(slotSendPrintScreen(QPixmap, QPoint, QPoint, QPoint)));
    connect(ui->label_analysisPicture, SIGNAL(signalTempMeasCoordinate(QPoint, QPoint, QPoint)), this, SLOT(slotTempMeasCoordinate(QPoint, QPoint, QPoint)));

    //视频label功能
    m_pVideo = new MTDCameraCore((HWND)ui->label_video->winId(), tr("IRSysdll.dll"), tr("0000_8.xml"));
    m_pCurrentImage = m_pVideo->getImage();
    //调色盘
    ui->label_coloredTape->setPixmap(QPixmap::fromImage(m_pCurrentImage->getPalette()));
    ui->label_coloredTape->setScaledContents(true);
    m_MtdImageVec.clear();

    connect(m_pVideo, SIGNAL(capture()), this, SLOT(playVideo()));

    connect(ui->pushButton_up, SIGNAL(pressed()), this, SLOT(controlCameraUp()));
    connect(ui->pushButton_down, SIGNAL(pressed()), this, SLOT(controlCameraDown()));
    connect(ui->pushButton_focus_plus, SIGNAL(pressed()), this, SLOT(controlCameraFocusPlus()));
    connect(ui->pushButton_focus_minus, SIGNAL(pressed()), this, SLOT(controlCameraFocusMinus()));
    connect(ui->pushButton_up, SIGNAL(released()), this, SLOT(controlCameraStop()));
    connect(ui->pushButton_down, SIGNAL(released()), this, SLOT(controlCameraStop()));
    connect(ui->pushButton_focus_plus, SIGNAL(released()), this, SLOT(controlCameraStop()));
    connect(ui->pushButton_focus_minus, SIGNAL(released()), this, SLOT(controlCameraStop()));

    ui->tableWidget_TemperatureMessure->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表头等宽
    ui->tableWidget_TemperatureMessure->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中的方式
    ui->tableWidget_TemperatureMessure->setEditTriggers(QAbstractItemView::NoEditTriggers); //禁止修改

    ui->tableWidget_pictureTemperatureMessure->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表头等宽
    ui->tableWidget_pictureTemperatureMessure->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中的方式
    ui->tableWidget_pictureTemperatureMessure->setEditTriggers(QAbstractItemView::NoEditTriggers); //禁止修改
    ui->tableWidget_pictureTemperatureMessure->verticalHeader()->setHidden(true);
    ui->tableWidget_pictureTemperatureMessure->horizontalHeader()->setStyleSheet("QHeaderView::section{background:green;}"); //设置表头背景色

    //病例库
    ui->tableWidget_case->setColumnCount(4);
    QStringList caseHeader;
    caseHeader << "UserID" << "姓名" << "性别" << "年龄";
    ui->tableWidget_case->setHorizontalHeaderLabels(caseHeader);
    ui->tableWidget_case->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表头等宽
    ui->tableWidget_case->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中的方式
    ui->tableWidget_case->setEditTriggers(QAbstractItemView::NoEditTriggers); //禁止修改
    //设置表头字体加粗
    QFont fontCase = ui->tableWidget_case->horizontalHeader()->font();
    fontCase.setBold(true);
    ui->tableWidget_case->horizontalHeader()->setFont(fontCase);
    ui->tableWidget_case->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头背景色
    //ui->tableWidget_case->setFrameShape(QFrame::NoFrame); //设置无边框
    //ui->tableWidget_case->setShowGrid(false); //设置不显示格子线
    connect(ui->tableWidget_case, SIGNAL(itemClicked(QTableWidgetItem *)), this, SLOT(clickedShowDiagnose(QTableWidgetItem*)));
    connect(ui->tableWidget_case, SIGNAL(itemDoubleClicked(QTableWidgetItem *)), this, SLOT(doubleClickedShowRecord(QTableWidgetItem*)));

    ui->tableWidget_diagnose->setColumnCount(7);
    QStringList diagnoseHeader;
    diagnoseHeader << "编号" << "UserId" << "就诊时间" << "就诊地点" << "医生编号" << "医生姓名" << "诊断结论";
    ui->tableWidget_diagnose->setHorizontalHeaderLabels(diagnoseHeader);
    ui->tableWidget_diagnose->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表头等宽
    ui->tableWidget_diagnose->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中的方式
    ui->tableWidget_diagnose->setEditTriggers(QAbstractItemView::NoEditTriggers); //禁止修改
    //设置表头字体加粗
    QFont fontDiagnose = ui->tableWidget_diagnose->horizontalHeader()->font();
    fontDiagnose.setBold(true);
    ui->tableWidget_diagnose->horizontalHeader()->setFont(fontDiagnose);
    ui->tableWidget_diagnose->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头背景色
    connect(ui->tableWidget_diagnose, SIGNAL(itemClicked(QTableWidgetItem *)), this, SLOT(clickedShowDiagnosePicture(QTableWidgetItem*)));
    connect(ui->tableWidget_diagnose, SIGNAL(itemDoubleClicked(QTableWidgetItem *)), this, SLOT(doubleClickedShowResult(QTableWidgetItem*)));

    //数据库
    m_pMtdDataBase = new MtdMed();

    //建信号槽，将鼠标拖动的图片的列数，传递给图片分析区
    connect(ui->listWidget, SIGNAL(signal_currentColumn(int)), ui->label_analysisPicture, SLOT(getColumn(int)));


    ui->scrollAreaWidgetContents->setLayout(ui->reportLayout);
    ui->reportLayout->setContentsMargins(150, 80, 150,80);
    // 设置输入框的边框为无边框
    ui->idEdit->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    ui->nameEdit->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    ui->ageEdit->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    ui->genderEdit->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    QString companyName = "戈睿医疗有限公司";
    ui->hospitalNameLabel->setText(companyName);

    ui->temDataTable->setColumnCount(5);
    QStringList temDataHeader;
    temDataHeader << "编号" << "最低" << "最高" << "平均" << "温差";
    ui->temDataTable->setHorizontalHeaderLabels(temDataHeader);
    ui->temDataTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表头等宽
    ui->temDataTable->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中的方式
    ui->temDataTable->setEditTriggers(QAbstractItemView::NoEditTriggers); //禁止修改

    connect(this, SIGNAL(sendSplitScreenCount2(int)), ui->pictureLabel, SLOT(splitScreen(int)));
    connect(this, SIGNAL(sendPicture2(QPixmap,int)), ui->pictureLabel, SLOT(receivePicture(QPixmap,int)));
}
/********************************************************************
* 函数名：~Widget
* 功能：  Widget析构函数
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*********************************************************************/
Widget::~Widget()
{
    delete ui;
    delete m_userInfo;
    delete m_pVideo;
    delete m_pMtdDataBase;
    delete m_pSaveDiagnose;    
    delete m_recordUpdate;
    delete m_resultUpdate;
    delete m_recordShow;
    delete m_resultShow;
    m_pCurrentImage = NULL;
    if(true != m_MtdImageVec.empty())
    {
        for(int i = 0; i < m_MtdImageVec.size(); i++)
        {
            //删除vector中的图片
            delete m_MtdImageVec.at(i);
            m_MtdImageVec.remove(i);
        }
    }
}

/********************************************************************
* 函数名：ReceiveUserInfo
* 功能：  槽函数，添加用户注册信息
* 参数：  stInfo 结构体，注册信息
* 返回值：无
*
* 时间： 2017-8-16
* 作者：
*********************************************************************/
void Widget::ReceiveUserInfo(Common::stUserSigninInfo stInfo)
{
    if(NULL != stInfo.strName)
    {
        //添加病例
        MedRecord stCaseRecord;
        stCaseRecord.name            = stInfo.strName;
        stCaseRecord.age             = stInfo.strAge.toInt();
        stCaseRecord.bMale           = ("Male" == stInfo.strGender) ? true : false;
        stCaseRecord.contact         = stInfo.strPhone;
        stCaseRecord.address         = stInfo.strPlace;
        stCaseRecord.profession      = stInfo.strProfession;
        stCaseRecord.personalHistory = stInfo.strPersonalHistory;
        stCaseRecord.familyHistory   = stInfo.strFamilyHistory;
        stCaseRecord.comment         = stInfo.strComment;

        m_pMtdDataBase->addRecord(stCaseRecord);

        //用户信息界面
        QString strIdInfo = QString::number(stCaseRecord.userID);
        ui->label_userInfoID->setText(strIdInfo);
        ui->label_userInfoName->setText(stInfo.strName);

        //显示到数据库界面
        ui->tableWidget_case->clearContents();
        ui->tableWidget_case->setRowCount(0);
        ui->tableWidget_diagnose->clearContents();
        ui->tableWidget_diagnose->setRowCount(0);        
        ui->tableWidget_case->setRowCount(ui->tableWidget_case->rowCount() + 1);

        ui->tableWidget_case->setItem(0, 0, new QTableWidgetItem(strIdInfo));
        ui->tableWidget_case->setItem(0, 1, new QTableWidgetItem(stInfo.strName));
        ui->tableWidget_case->setItem(0, 2, new QTableWidgetItem(stInfo.strGender));
        ui->tableWidget_case->setItem(0, 3, new QTableWidgetItem(stInfo.strAge));

        //显示到结果输出界面
        ui->idEdit->setText(QString::number(stCaseRecord.userID));
        ui->idEdit->setEnabled(false);
        ui->nameEdit->setText(stCaseRecord.name);
        ui->nameEdit->setEnabled(false);
        ui->ageEdit->setText(QString::number(stCaseRecord.age));
        ui->ageEdit->setEnabled(false);
        ui->genderEdit->setText(stCaseRecord.bMale ? "男" : "女");
        ui->genderEdit->setEnabled(false);
        QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
        QString timeStr = time.toString("yyyy-MM-dd"); //设置显示格式
        ui->dateLabel->setText(timeStr);
    }

    m_userInfo->close();
}

/********************************************************************
* 函数名：on_pushButton_capture_clicked
* 功能：  槽函数，抓图功能
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-16
* 作者：
*********************************************************************/
void Widget::on_pushButton_capture_clicked()
{
    bool isOK;
    QString strText = QInputDialog::getText(NULL, "InputDialog", "Please input your comment:", QLineEdit::Normal, "", &isOK);

    const QPixmap *screen = ui->label_video->pixmap(); //QPixmap::grabWidget(ui->label_video);
    //QIcon icon(screen);
    ui->listWidget->addImage(*screen, strText);

    //将图片保存到vec中
    m_MtdImageVec.push_back(m_pCurrentImage->clone());
}

 void Widget::doubleClickedShowPicture(QTableWidgetItem* pItem)
 {
    int column = ui->listWidget->currentColumn();//当前列号，从0开始
    QImage image = qvariant_cast<QImage>(pItem->data(Qt::DisplayRole));
    QPixmap pixmap(QPixmap::fromImage(image.scaled(278, 330)));


    //跳转到图片分析界面
    ui->tabWidget->setCurrentIndex(EN_ANALYSIS_TAB);
    ui->label_operate->setMousePressFlag(false);
    ui->label_dataBase->setMousePressFlag(false);
    ui->label_report->setMousePressFlag(false);
    ui->label_analyze->setMousePressFlag(true);

    emit sendPicture(pixmap, column);

 }

 void Widget::changeCurrentTab(PixLabel * pixLabel)
 {
    int indexTab = pixLabel->getTab();

    switch (indexTab)
    {
    case EN_OPERATE_TAB:
        ui->tabWidget->setCurrentIndex(EN_OPERATE_TAB);
        ui->label_dataBase->setMousePressFlag(false);
        ui->label_report->setMousePressFlag(false);
        ui->label_analyze->setMousePressFlag(false);
        break;

    case EN_ANALYSIS_TAB:
        ui->tabWidget->setCurrentIndex(EN_ANALYSIS_TAB);
        ui->label_operate->setMousePressFlag(false);
        ui->label_dataBase->setMousePressFlag(false);
        ui->label_report->setMousePressFlag(false);
        break;

    case EN_DATABASE_TAB:
        ui->tabWidget->setCurrentIndex(EN_DATABASE_TAB);
        ui->label_operate->setMousePressFlag(false);
        ui->label_report->setMousePressFlag(false);
        ui->label_analyze->setMousePressFlag(false);
        break;

    case EN_REPORT_TAB:
        ui->tabWidget->setCurrentIndex(EN_REPORT_TAB);
        ui->label_operate->setMousePressFlag(false);
        ui->label_dataBase->setMousePressFlag(false);
        ui->label_analyze->setMousePressFlag(false);
        break;

    default:
        break;
    }
 }

 void Widget::showUserInfo(UserLabel *)
 {
     m_userInfo->show();
 }

void Widget::controlCameraUp()
{
    if(NULL == m_pVideo) return;
    m_pVideo->cameraControl(MTD::Camera_Up);
    m_bUpDownStop = true;
}

void Widget::controlCameraDown()
{
   if(NULL == m_pVideo) return;
   m_pVideo->cameraControl(MTD::Camera_Down);
   m_bUpDownStop = true;
}

void Widget::controlCameraFocusPlus()
{
    if(NULL == m_pVideo) return;
    m_pVideo->cameraControl(MTD::Focus_Up);
    m_bFocusStop = true;

}

void Widget::controlCameraFocusMinus()
{
    if(NULL == m_pVideo) return;
    m_pVideo->cameraControl(MTD::Focus_Down);
    m_bFocusStop = true;
}

void Widget::controlCameraStop()
{
    if(NULL == m_pVideo) return;

    if(true == m_bUpDownStop)
    {
        m_pVideo->cameraControl(MTD::Camera_Stop);
        m_bUpDownStop = false;
    }
    if(true == m_bFocusStop)
    {
        m_pVideo->cameraControl(MTD::Focus_Stop);
        m_bFocusStop = false;
    }
}

/********************************************************************
* 函数名：on_pushButton_search_clicked
* 功能：  槽函数，搜索病例
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-14
* 作者：
**********************************************************************/
void Widget::on_pushButton_search_clicked()
{
    if(NULL == m_pMtdDataBase) return;
    QString strSearchText = ui->lineEdit_search->text();
    QVector<MedRecord> searchRecordVec;
    searchRecordVec.clear();
    m_pMtdDataBase->searchRecord(strSearchText, searchRecordVec);
    if(true == searchRecordVec.empty()) return;

    int rowCount = ui->tableWidget_case->rowCount();//获取当前行数

    for(int searchLoop = 0; searchLoop < searchRecordVec.size(); searchLoop ++)
    {
        //如果界面中有相同的Id，就不显示
        int userId = searchRecordVec.at(searchLoop).userID;
        for(int tableLoop = 0; tableLoop < rowCount; tableLoop++)
        {
             if(userId == ui->tableWidget_case->item(tableLoop, 0)->text().toInt()) return;
        }

        int caseRowCount = ui->tableWidget_case->rowCount();
        ui->tableWidget_case->setRowCount(caseRowCount + 1);

        //在界面上显示
        ui->tableWidget_case->setItem(caseRowCount, 0, new QTableWidgetItem(QString::number(userId)));
        ui->tableWidget_case->setItem(caseRowCount, 1, new QTableWidgetItem(searchRecordVec.at(searchLoop).name));
        QString strSex = (true == searchRecordVec.at(searchLoop).bMale) ? "Male" : "Female";
        ui->tableWidget_case->setItem(caseRowCount, 2, new QTableWidgetItem(strSex));
        ui->tableWidget_case->setItem(caseRowCount, 3, new QTableWidgetItem(QString::number(searchRecordVec.at(searchLoop).age)));
    }
}

void Widget::on_pushButton_deleteCase_clicked()
{
    if(NULL == m_pMtdDataBase) return;
    int userIdCase = 0;
    //删除当前选中的病例
    int rowIndex = ui->tableWidget_case->currentRow();

    if (rowIndex != -1)
    {
        //删除数据库数据
        userIdCase = ui->tableWidget_case->item(rowIndex, 0)->text().toInt();
        m_pMtdDataBase->deleteUser(userIdCase);
        //删除table表中的数据
        ui->tableWidget_case->removeRow(rowIndex);//删除当前行
    }
    //当病例删除时，相对应的诊断也需要删除，但是需要判断诊断界面是否有数据，如果有，还需要判断是否是当前病例的诊断
    if(0 != ui->tableWidget_diagnose->rowCount())
    {
        int userId = ui->tableWidget_diagnose->item(0, 1)->text().toInt();
        if(userId == userIdCase)
        {
            ui->tableWidget_diagnose->clearContents();
            ui->tableWidget_diagnose->setRowCount(0);
            //将图片也删除
            ui->listWidget_dataBasePicture->clearContents();
            ui->listWidget_dataBasePicture->setRowCount(0);
        }
    }
}
/********************************************************************
* 函数名：on_pushButton_modifyCase_clicked
* 功能：  槽函数，修改病例
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-10
* 作者：
**********************************************************************/
void Widget::on_pushButton_modifyCase_clicked()
{
    if(NULL == m_pMtdDataBase) return;

    int rowIndex = ui->tableWidget_case->currentRow();
    if(rowIndex == -1) return;
    int userId = ui->tableWidget_case->item(rowIndex, 0)->text().toInt();

    QVector<MedRecord> vector;
    vector.clear();
    m_pMtdDataBase->searchRecord(QString::number(userId), vector);

    if(NULL == m_recordUpdate)
    {
        m_recordUpdate = new RecordUpdateWidgets(false);
        connect(m_recordUpdate, SIGNAL(signalUpDateRecord()), this, SLOT(slotUpDateRecord()));
    }

    if(vector.size() == 0 || userId == 0)
    {
        return;
    }
    else
    {
        m_recordUpdate->showRecord(vector.at(0));
    }
    m_recordUpdate->show();
}

void Widget::on_pushButton_PictureToDataBase_clicked()
{
    if(NULL == m_pSaveDiagnose) return;
    m_pSaveDiagnose->show();
}
/********************************************************************
* 函数名：clickedShowDiagnosePicture
* 功能：  槽函数，点击诊断，将对应诊断中处理过的图片显示在tablewidgets上
* 参数：  pItem  tablewidget中的item
* 返回值：无
*
* 时间： 2017-8-10
* 作者：
**********************************************************************/
void Widget::clickedShowDiagnosePicture(QTableWidgetItem *pItem)
{
    if(NULL == m_pMtdDataBase) return;

    int rowIndex   = ui->tableWidget_diagnose->currentRow();//获取当前行
    int userId     = ui->tableWidget_diagnose->item(rowIndex, 1)->text().toInt();
    int id         = ui->tableWidget_diagnose->item(rowIndex, 0)->text().toInt();
    int columnFlag = 0;
    //为了防止双击同一个id的诊断，图片依然出现,若不是同一个id，先清空之前的数据
    if(ui->listWidget_dataBasePicture->getCurrentId() == id)
    {
        return;
    }
    else
    {
        ui->listWidget_dataBasePicture->clearContents();
        ui->listWidget_dataBasePicture->setRowCount(0);
    }
    ui->listWidget_dataBasePicture->setCurrentId(id);
    //根据UserId到数据库中查询
    QVector<MedCheckResult> resultVec;
    resultVec.clear();
    m_pMtdDataBase->selectResult(userId, resultVec);
    //将数据库中的图片显示出来
    ui->listWidget_dataBasePicture->horizontalHeader()->setVisible(false);
    ui->listWidget_dataBasePicture->verticalHeader()->setVisible(false);

    int imagesCount = resultVec.at(rowIndex).allCheckedImages.size();//获取图片数量

    for(int imageLoop = 0; imageLoop < imagesCount; imageLoop++)
    {
        //QString strUrl = resultVec.at(rowIndex).allCheckedImages.at(imageLoop).url;
        MedCheckImage checkImage = resultVec.at(rowIndex).allCheckedImages.at(imageLoop);
        MTDImage *pImage = MTDUtil::loadImage(checkImage);
        //QImage image(strUrl);
        int rowCount = ui->listWidget_dataBasePicture->rowCount();
        if(0 == columnFlag || 0 == rowCount)
        {
            ui->listWidget_dataBasePicture->setRowCount(rowCount + 1);
        }
        rowCount = ui->listWidget_dataBasePicture->rowCount();//更新下当前行数
        ui->listWidget_dataBasePicture->setColumnWidth(0, 100);
        ui->listWidget_dataBasePicture->setColumnWidth(1, 100);
        ui->listWidget_dataBasePicture->setRowHeight(rowCount - 1, 100);

        QTableWidgetItem *item = new QTableWidgetItem();
        ui->listWidget_dataBasePicture->setItem(rowCount - 1, columnFlag, item);

        QPixmap pix = QPixmap::fromImage(pImage->dst2QImage());
        item->setData(Qt::DisplayRole, QVariant::fromValue(QPixmap(pix).scaled(278, 330)));

        columnFlag = (columnFlag == 0) ? 1 : 0;

        delete pImage;
    }
}

void Widget::doubleClickedShowRecord(QTableWidgetItem *)
{
    if(NULL == m_pMtdDataBase) return;

    int rowIndex = ui->tableWidget_case->currentRow();
    if(rowIndex == -1) return;
    int userId = ui->tableWidget_case->item(rowIndex, 0)->text().toInt();

    QVector<MedRecord> vector;
    vector.clear();
    m_pMtdDataBase->searchRecord(QString::number(userId), vector);

    if(NULL == m_recordShow)
    {
        m_recordShow = new RecordUpdateWidgets(true);
    }

    if(vector.size() == 0 || userId == 0)
    {
        return;
    }
    else
    {
        m_recordShow->showRecord(vector.at(0));
    }
    m_recordShow->show();
}
/********************************************************************
* 函数名：receiveDiagnoseInfo
* 功能：  槽函数，保存图片和诊断信息，并显示在数据库诊断页面上
* 参数：  stRst  诊断信息
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*********************************************************************/
void Widget::receiveDiagnoseInfo(Common::stDiagnoseRst stRst)
{
    if(NULL == m_pMtdDataBase) return;
    //先获取userId，如果没有，不保存
    QString strUserId = ui->label_userInfoID->text();
    if(NULL == strUserId) return;
    //判断图片栏是否有图片，没有图片不保存
    int columnCount = ui->listWidget->columnCount();
    if(0 == columnCount) return;
    //开始保存图片
//    QVector<QImage> imagesVec;
//    imagesVec.clear();
    QVector<MedCheckImage> checkImageVec;
    checkImageVec.clear();
//    for(int columnLoop = 0; columnLoop < columnCount; columnLoop++)
//    {
//        QTableWidgetItem *pItem = ui->listWidget->item(0, columnLoop);
//        QPixmap pix = pItem->data(Qt::DisplayRole).value<QPixmap>();
//        imagesVec.push_back(pix.toImage());
//    }
    MTDUtil::insertAllImage(m_pMtdDataBase, strUserId.toInt(), "", m_MtdImageVec, checkImageVec);//保存图片到数据库

    //开始保存诊断信息
    MedCheckResult stResult;
    stResult.userId           = strUserId.toInt();
    stResult.allCheckedImages = checkImageVec;
    stResult.checkSpot        = stRst.strPlace;
    stResult.doctorName       = stRst.strDoctorName;
    stResult.nDoctorID        = stRst.strDoctorId.toInt();
    stResult.decision         = stRst.strDecision;
    stResult.symptom          = stRst.strSymptom;
    stResult.therapy          = stRst.strTherapy;
    m_pMtdDataBase->saveResult(stResult); 

    //将信息显示在数据库界面
    int rowCount = ui->tableWidget_diagnose->rowCount();
    ui->tableWidget_diagnose->setRowCount(rowCount + 1);
    ui->tableWidget_diagnose->setItem(rowCount, 0, new QTableWidgetItem(QString::number(stResult.id)));
    ui->tableWidget_diagnose->setItem(rowCount, 1, new QTableWidgetItem(strUserId));
    ui->tableWidget_diagnose->setItem(rowCount, 2, new QTableWidgetItem(stResult.checkDate.toString("yyyy-MM-dd hh:mm:ss")));
    ui->tableWidget_diagnose->setItem(rowCount, 3, new QTableWidgetItem(stRst.strPlace));
    ui->tableWidget_diagnose->setItem(rowCount, 4, new QTableWidgetItem(stRst.strDoctorId));
    ui->tableWidget_diagnose->setItem(rowCount, 5, new QTableWidgetItem(stRst.strDoctorName));
    ui->tableWidget_diagnose->setItem(rowCount, 6, new QTableWidgetItem(stRst.strDecision));
    //关闭对话框
    m_pSaveDiagnose->close();
}

/********************************************************************
* 函数名：clickedShowDiagnose
* 功能：  槽函数，点击显示病例所对应的诊断
* 参数：  pItem  tablewidget中的item
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
********************************************************************/
void Widget::clickedShowDiagnose(QTableWidgetItem *pItem)
{
    if(NULL == m_pMtdDataBase) return;

    //将diagnose中的内容删除
    ui->tableWidget_diagnose->clearContents();
    ui->tableWidget_diagnose->setRowCount(0);

    int rowIndex   = ui->tableWidget_case->currentRow();//获取当前行
    int userId     = ui->tableWidget_case->item(rowIndex, 0)->text().toInt();//获取当前行UserId
    //根据当前userid获取此病例的所有诊断
    QVector<MedCheckResult> medVec;
    medVec.clear();

    m_pMtdDataBase->selectResult(userId, medVec);
    if(true == medVec.empty()) return;

    for(int searchLoop = 0; searchLoop < medVec.size(); searchLoop ++)
    {
        int caseRowCount = ui->tableWidget_diagnose->rowCount();
        ui->tableWidget_diagnose->setRowCount(caseRowCount + 1);

        ui->tableWidget_diagnose->setItem(caseRowCount, 0, new QTableWidgetItem(QString::number(medVec.at(searchLoop).id)));
        ui->tableWidget_diagnose->setItem(caseRowCount, 1, new QTableWidgetItem(QString::number(medVec.at(searchLoop).userId)));
        ui->tableWidget_diagnose->setItem(caseRowCount, 2, new QTableWidgetItem(medVec.at(searchLoop).checkDate.toString("yyyy-MM-dd hh:mm:ss")));
        ui->tableWidget_diagnose->setItem(caseRowCount, 3, new QTableWidgetItem(medVec.at(searchLoop).checkSpot));
        ui->tableWidget_diagnose->setItem(caseRowCount, 4, new QTableWidgetItem(QString::number(medVec.at(searchLoop).nDoctorID)));
        ui->tableWidget_diagnose->setItem(caseRowCount, 5, new QTableWidgetItem(medVec.at(searchLoop).doctorName));
        ui->tableWidget_diagnose->setItem(caseRowCount, 6, new QTableWidgetItem(medVec.at(searchLoop).decision));

    }
}

void Widget::doubleClickedShowResult(QTableWidgetItem *)
{
    if(NULL == m_pMtdDataBase) return;

    int rowIndex = ui->tableWidget_diagnose->currentRow();
    if(rowIndex == -1) return;
    int id = ui->tableWidget_diagnose->item(rowIndex, 0)->text().toInt();
    MedCheckResult result;
    m_pMtdDataBase->selectResultById(id, result);

    if(NULL == m_resultShow)
    {
        m_resultShow = new ResultUpdateWidgets(true);
    }

    m_resultShow->showResult(result);

    m_resultShow->show();
}

/********************************************************************
* 函数名：on_pushButton_deleteDiagnose_clicked
* 功能：  槽函数，删除诊断
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*******************************************************************/
void Widget::on_pushButton_deleteDiagnose_clicked()
{
    if(NULL == m_pMtdDataBase) return;
    int id = 0;
    //删除当前选中的病例
    int rowIndex = ui->tableWidget_diagnose->currentRow();
    if (rowIndex != -1)
    {
        //删除数据库数据
        id = ui->tableWidget_diagnose->item(rowIndex, 0)->text().toInt();
        m_pMtdDataBase->deleteResult(id);
        //删除table表中的数据
        ui->tableWidget_diagnose->removeRow(rowIndex);//删除当前行
    }
    //如果当前图片显示的是要删除的诊断，需要将图片区删除
    if(id == ui->listWidget_dataBasePicture->getCurrentId())
    {
        //将图片也删除
        ui->listWidget_dataBasePicture->clearContents();
        ui->listWidget_dataBasePicture->setRowCount(0);
    }
}

/********************************************************************
* 函数名：on_pushButton_deleteScrollImage_clicked
* 功能：  槽函数，用于删除底部图片展示栏的图片
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*******************************************************************/
void Widget::on_pushButton_deleteScrollImage_clicked()
{
    //删除当前选中图片
    int column = ui->listWidget->currentColumn();//从0开始
    if(-1 == column) return;//没有图片，或者没有选中图片
    ui->listWidget->removeColumn(column);

    //删除vector中的图片
    delete m_MtdImageVec.at(column);
    m_MtdImageVec.remove(column);
    //删除图片分析栏的图片
    int index[4] = {-1};
    for(int i = 0; i < 4; i++)
    {
        index[i] = ui->label_analysisPicture->getCurrentColumn(i);
        if(column == index[i])
        {
            ui->label_analysisPicture->clearLabelContent(i + 1);
        }
    }

}

/********************************************************************
* 函数名：playVideo
* 功能：  槽函数，显示视频
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*******************************************************************/
void Widget::playVideo()
{
    if(NULL == m_pVideo || NULL == m_pCurrentImage)
        return;
    m_resizedVideoFrame = QPixmap::fromImage(m_pCurrentImage->dst2QImage().scaled(ui->label_video->size(),Qt::KeepAspectRatio));

//    QImage myImage;
//    bool r = myImage.load("..\\111.jpg");
    //m_resizedVideoFrame = QPixmap::fromImage(myImage).scaled(ui->label_video->size(),Qt::KeepAspectRatio);
//    qDebug("Widget::playVideo()::m_pCurrentImage w=%d,h=%d,\nm_resizedVideoFrame w=%d,h=%d,\nui->label_video w=%d,h=%d",m_pCurrentImage->dst2QImage().width(),m_pCurrentImage->dst2QImage().height()
//           ,m_resizedVideoFrame.width(),m_resizedVideoFrame.height(),ui->label_video->width(),ui->label_video->height());
//    qDebug("aspect ratio =%f",(float)m_resizedVideoFrame.height()/(float)m_resizedVideoFrame.width());
    ui->label_video->setCaptureImage(m_resizedVideoFrame);
    //ui->label_video->setScaledContents(true);
}

/********************************************************************
* 函数名：on_radioButton_GrayScale_2_toggled
* 功能：  槽函数，图片处理，将图片以黑白方式显示
* 参数：  checked  radiobutton
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*******************************************************************/
void Widget::on_radioButton_GrayScale_2_toggled(bool checked)
{
    if(false == checked) return;

    //获取当前屏幕对应的列号
    int index = ui->label_analysisPicture->getCurrentColumn(0);
    if(-1 == index) return;

    MTD::ImageParamer stImagePara = m_MtdImageVec.at(index)->getParamer();
    stImagePara.gradation = MTD::Gray;
    m_MtdImageVec[index]->setParamer(stImagePara);

    //由comboBox_analysisArea控件决定对整张图片还是截图进行处理
    if(0 == ui->comboBox_analysisArea->currentIndex())
    {
        //更新图片
        QImage image = m_MtdImageVec[index]->dst2QImage();
        ui->listWidget->replacePicture(index, image);
        ui->label_analysisPicture->upDatePicture(image, 1);
    }
    else
    {
       MTDImage image = m_MtdImageVec[index]->getMTDPartialEnhance(m_topLeftPoint.x(), m_topLeftPoint.y(), m_bottomRightPoint.x(), m_bottomRightPoint.y());
       ui->label_printScreen->setPixmap(QPixmap::fromImage(image.res2QImage()));
       ui->label_printScreen->setScaledContents(true);
    }
}
/********************************************************************
* 函数名：on_radioButton_PseudoColor_2_toggled
* 功能：  槽函数，图片处理，将图片以伪彩色显示
* 参数：  checked  radiobutton
* 返回值：无
*
* 时间： 2017-8-15
* 作者：
*******************************************************************/
void Widget::on_radioButton_PseudoColor_2_toggled(bool checked)
{
    if(false == checked) return;

    if(NULL == m_pCurrentImage) return;

    //获取当前屏幕对应的列号
    int columnIndex = ui->label_analysisPicture->getCurrentColumn(0);
    if(-1 == columnIndex) return;

    MTD::ImageParamer stImagePara = m_MtdImageVec.at(columnIndex)->getParamer();
    int index = ui->comboBox_PseudoColorSelector_2->currentIndex();
    switch(index)
    {
    case 0:
        stImagePara.gradation = MTD::Color20;
        break;
    case 1:
        stImagePara.gradation = MTD::Color40;
        break;
    case 2:
        stImagePara.gradation = MTD::Color80;
        break;
    case 3:
        stImagePara.gradation = MTD::Color160;
    default:
        break;
    }
    m_MtdImageVec[columnIndex]->setParamer(stImagePara);

    //由comboBox_analysisArea控件决定对整张图片还是截图进行处理
    if(0 == ui->comboBox_analysisArea->currentIndex())
    {
        //更新图片
        QImage image = m_MtdImageVec[columnIndex]->dst2QImage();
        ui->listWidget->replacePicture(columnIndex, image);
        ui->label_analysisPicture->upDatePicture(image, 1);
    }
    else
    {
       MTDImage image = m_MtdImageVec[columnIndex]->getMTDPartialEnhance(m_topLeftPoint.x(), m_topLeftPoint.y(), m_bottomRightPoint.x(), m_bottomRightPoint.y());
       ui->label_printScreen->setPixmap(QPixmap::fromImage(image.dst2QImage()));
       ui->label_printScreen->setScaledContents(true);
    }
}

/********************************************************************
* 函数名：on_comboBox_PseudoColorSelector_2_currentIndexChanged
* 功能：  槽函数，图片处理，将图片以伪彩色显示
* 参数：  index
* 返回值：无
*
* 时间： 2017-8-15
* 作者：
*******************************************************************/
void Widget::on_comboBox_PseudoColorSelector_2_currentIndexChanged(int index)
{
    on_radioButton_PseudoColor_2_toggled(true);
}

/********************************************************************
* 函数名：on_checkBox_polarityReversal_toggled
* 功能：  槽函数，图片处理，极性交换
* 参数：  checked  radiobutton
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*********************************************************************/
void Widget::on_checkBox_polarityReversal_toggled(bool checked)
{
    //获取当前屏幕对应的列号
    int index = ui->label_analysisPicture->getCurrentColumn(0);
    if(-1 == index) return;

    MTD::ImageParamer stImagePara = m_MtdImageVec.at(index)->getParamer();
    stImagePara.polarChange = checked;
    m_MtdImageVec[index]->setParamer(stImagePara);    

    //由comboBox_analysisArea控件决定对整张图片还是截图进行处理
    if(0 == ui->comboBox_analysisArea->currentIndex())
    {
        //更新图片
        QImage image = m_MtdImageVec[index]->dst2QImage();
        ui->listWidget->replacePicture(index, image);
        ui->label_analysisPicture->upDatePicture(image, 1);
    }
    else
    {
        MTDImage image = m_MtdImageVec[index]->getMTDPartialEnhance(m_topLeftPoint.x(), m_topLeftPoint.y(), m_bottomRightPoint.x(), m_bottomRightPoint.y());
        ui->label_printScreen->setPixmap(QPixmap::fromImage(image.dst2QImage()));
        ui->label_printScreen->setScaledContents(true);
    }
}
/********************************************************************
* 函数名：on_checkBox_filtration_toggled
* 功能：  槽函数，图片处理，滤波
* 参数：  checked  radiobutton
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*********************************************************************/
void Widget::on_checkBox_filtration_toggled(bool checked)
{
    //获取当前屏幕对应的列号
    int index = ui->label_analysisPicture->getCurrentColumn(0);
    if(-1 == index) return;

    MTD::ImageParamer stImagePara = m_MtdImageVec.at(index)->getParamer();
    stImagePara.waveFilter        = checked;
    m_MtdImageVec[index]->setParamer(stImagePara);

    //由comboBox_analysisArea控件决定对整张图片还是截图进行处理
    if(0 == ui->comboBox_analysisArea->currentIndex())
    {
        //更新图片
        QImage image = m_MtdImageVec[index]->dst2QImage();
        ui->listWidget->replacePicture(index, image);
        ui->label_analysisPicture->upDatePicture(image, 1);
    }
    else
    {
       MTDImage image = m_MtdImageVec[index]->getMTDPartialEnhance(m_topLeftPoint.x(), m_topLeftPoint.y(), m_bottomRightPoint.x(), m_bottomRightPoint.y());
       ui->label_printScreen->setPixmap(QPixmap::fromImage(image.dst2QImage()));
       ui->label_printScreen->setScaledContents(true);
    }
}
/********************************************************************
* 函数名：on_checkBox_histogram_toggled
* 功能：  槽函数，图片处理，直方图均衡
* 参数：  checked  radiobutton
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*********************************************************************/
void Widget::on_checkBox_histogram_toggled(bool checked)
{
    //获取当前屏幕对应的列号
    int index = ui->label_analysisPicture->getCurrentColumn(0);
    if(-1 == index) return;

    MTD::ImageParamer stImagePara = m_MtdImageVec.at(index)->getParamer();
    stImagePara.histogramStretch  = checked;
    m_MtdImageVec[index]->setParamer(stImagePara);

    //由comboBox_analysisArea控件决定对整张图片还是截图进行处理
    if(0 == ui->comboBox_analysisArea->currentIndex())
    {
        //更新图片
        QImage image = m_MtdImageVec[index]->dst2QImage();
        ui->listWidget->replacePicture(index, image);
        ui->label_analysisPicture->upDatePicture(image, 1);
    }
    else
    {
        MTDImage image = m_MtdImageVec[index]->getMTDPartialEnhance(m_topLeftPoint.x(), m_topLeftPoint.y(), m_bottomRightPoint.x(), m_bottomRightPoint.y());
        ui->label_printScreen->setPixmap(QPixmap::fromImage(image.dst2QImage()));
        ui->label_printScreen->setScaledContents(true);
    }

}
/********************************************************************
* 函数名：on_horizontalSlider_edgeDetection_valueChanged
* 功能：  槽函数，图片处理，边缘检测
* 参数：  checked  radiobutton
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*********************************************************************/
void Widget::on_horizontalSlider_edgeDetection_valueChanged(int value)
{
    //获取当前屏幕对应的列号
    int index = ui->label_analysisPicture->getCurrentColumn(0);
    if(-1 == index) return;

    MTD::ImageParamer stImagePara = m_MtdImageVec.at(index)->getParamer();
    stImagePara.canndy            = value;
    m_MtdImageVec[index]->setParamer(stImagePara);

    //由comboBox_analysisArea控件决定对整张图片还是截图进行处理
    if(0 == ui->comboBox_analysisArea->currentIndex())
    {
        //更新图片
        QImage image = m_MtdImageVec[index]->dst2QImage();
        ui->listWidget->replacePicture(index, image);
        ui->label_analysisPicture->upDatePicture(image, 1);
    }
    else
    {
        MTDImage image = m_MtdImageVec[index]->getMTDPartialEnhance(m_topLeftPoint.x(), m_topLeftPoint.y(), m_bottomRightPoint.x(), m_bottomRightPoint.y());
        ui->label_printScreen->setPixmap(QPixmap::fromImage(image.dst2QImage()));
        ui->label_printScreen->setScaledContents(true);
    }
}
/********************************************************************
* 函数名：on_SpinBox_lowerTemperature_valueChanged
* 功能：  槽函数，图片处理，温度下限
* 参数：  checked  radiobutton
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*********************************************************************/
void Widget::on_SpinBox_lowerTemperature_valueChanged(int arg1)
{
    //获取当前屏幕对应的列号
    int index = ui->label_analysisPicture->getCurrentColumn(0);
    if(-1 == index) return;

    MTD::ImageParamer stImagePara = m_MtdImageVec.at(index)->getParamer();
    stImagePara.temLow            = arg1;
    m_MtdImageVec[index]->setParamer(stImagePara);

    //由comboBox_analysisArea控件决定对整张图片还是截图进行处理
    if(0 == ui->comboBox_analysisArea->currentIndex())
    {
        //更新图片
        QImage image = m_MtdImageVec[index]->dst2QImage();
        ui->listWidget->replacePicture(index, image);
        ui->label_analysisPicture->upDatePicture(image, 1);
    }
    else
    {
        MTDImage image = m_MtdImageVec[index]->getMTDPartialEnhance(m_topLeftPoint.x(), m_topLeftPoint.y(), m_bottomRightPoint.x(), m_bottomRightPoint.y());
        ui->label_printScreen->setPixmap(QPixmap::fromImage(image.dst2QImage()));
        ui->label_printScreen->setScaledContents(true);
    }

    int max = ui->SpinBox_upperTemperature->value();
    ui->SpinBox_upperTemperature->setRange(arg1, 255);// 范围
    ui->SpinBox_lowerTemperature->setRange(0, max);// 范围
}
/********************************************************************
* 函数名：imageAnalysis_upperTemperature
* 功能：  槽函数，图片处理，温度上限
* 参数：  checked  radiobutton
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*********************************************************************/
void Widget::on_SpinBox_upperTemperature_valueChanged(int arg1)
{
    //获取当前屏幕对应的列号
    int index = ui->label_analysisPicture->getCurrentColumn(0);
    if(-1 == index) return;

    MTD::ImageParamer stImagePara = m_MtdImageVec.at(index)->getParamer();
    stImagePara.temHigh           = arg1;
    m_MtdImageVec[index]->setParamer(stImagePara);

    //由comboBox_analysisArea控件决定对整张图片还是截图进行处理
    if(0 == ui->comboBox_analysisArea->currentIndex())
    {
        //更新图片
        QImage image = m_MtdImageVec[index]->dst2QImage();
        ui->listWidget->replacePicture(index, image);
        ui->label_analysisPicture->upDatePicture(image, 1);
    }
    else
    {
        MTDImage image = m_MtdImageVec[index]->getMTDPartialEnhance(m_topLeftPoint.x(), m_topLeftPoint.y(), m_bottomRightPoint.x(), m_bottomRightPoint.y());
        ui->label_printScreen->setPixmap(QPixmap::fromImage(image.dst2QImage()));
        ui->label_printScreen->setScaledContents(true);
    }

    int min = ui->SpinBox_lowerTemperature->value();
    ui->SpinBox_lowerTemperature->setRange(0, arg1);  // 范围
    ui->SpinBox_upperTemperature->setRange(min, 255);  // 范围
}
/********************************************************************
* 函数名：on_pushButton_modifyDiagnose_clicked
* 功能：  槽函数，修改诊断
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*********************************************************************/
void Widget::on_pushButton_modifyDiagnose_clicked()
{
    if(NULL == m_pMtdDataBase) return;

    int rowIndex = ui->tableWidget_diagnose->currentRow();
    if(rowIndex == -1) return;
    int id = ui->tableWidget_diagnose->item(rowIndex, 0)->text().toInt();
    MedCheckResult result;
    m_pMtdDataBase->selectResultById(id, result);

    if(NULL == m_resultUpdate)
    {
        m_resultUpdate = new ResultUpdateWidgets(false);
        connect(m_resultUpdate, SIGNAL(signalUpDateCheck()), this, SLOT(slotUpDateCheck()));
    }

    m_resultUpdate->showResult(result);

    m_resultUpdate->show();
}
/********************************************************************
* 函数名：slotSendPrintScreen
* 功能：  槽函数，接收截取图片，并显示
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-11
* 作者：
*********************************************************************/
void Widget::slotSendPrintScreen(QPixmap captureimage, QPoint top, QPoint bottom, QPoint labelPoint)
{
    if(NULL == m_pCurrentImage) return;

    float scaledW = (float) m_pCurrentImage->getWidth() / labelPoint.x();
    float scaledH = (float) m_pCurrentImage->getHeight() / labelPoint.y();

    m_topLeftPoint.setX(scaledW * top.x());
    m_topLeftPoint.setY(scaledH * top.y());

    m_bottomRightPoint.setX(scaledW * bottom.x());
    m_bottomRightPoint.setY(scaledH * bottom.y());

    ui->label_printScreen->setPixmap(captureimage);
    ui->label_printScreen->setScaledContents(true);
}

/********************************************************************
* 函数名：slotTempMeasCoordinate
* 功能：  槽函数，获取区域温度
* 参数：  top bottom 区域坐标
* 返回值：无
*
* 时间： 2017-8-11
* 作者：
*********************************************************************/
void Widget::slotTempMeasCoordinate(QPoint top, QPoint bottom, QPoint labelPoint)
{

    if(NULL == m_pCurrentImage) return;
    if((top.isNull() == true) && (bottom.isNull() == true)) return;

    QPoint topPoint, bottomPoint;

    float scaledW = (float) m_pCurrentImage->getWidth() / labelPoint.x();
    float scaledH = (float) m_pCurrentImage->getHeight() / labelPoint.y();

    topPoint.setX(scaledW * top.x());
    topPoint.setY(scaledH * top.y());

    bottomPoint.setX(scaledW * bottom.x());
    bottomPoint.setY(scaledH * bottom.y());

    //获取区域温度
    double *pTemp;
    pTemp =  m_pCurrentImage->getTemperature(topPoint.x(), topPoint.y(), bottomPoint.x(), bottomPoint.y());

    int caseRowCount = ui->tableWidget_pictureTemperatureMessure->rowCount();
    ui->tableWidget_pictureTemperatureMessure->setRowCount(caseRowCount + 1);

    //在界面上显示
    ui->tableWidget_pictureTemperatureMessure->setItem(caseRowCount, 1, new QTableWidgetItem(QString::number(*(pTemp))));
    ui->tableWidget_pictureTemperatureMessure->setItem(caseRowCount, 2, new QTableWidgetItem(QString::number(*(pTemp + 1))));
    ui->tableWidget_pictureTemperatureMessure->setItem(caseRowCount, 3, new QTableWidgetItem(QString::number(*(pTemp + 2))));
    ui->tableWidget_pictureTemperatureMessure->setItem(caseRowCount, 4, new QTableWidgetItem(QString::number(*(pTemp + 1) - *pTemp)));
}

/********************************************************************
* 函数名：on_comboBox_printScreenForm_currentIndexChanged
* 功能：  槽函数，设置截图形状
* 参数：  index 组件index
* 返回值：无
*
* 时间： 2017-8-11
* 作者：
*********************************************************************/
void Widget::on_comboBox_printScreenForm_currentIndexChanged(int index)
{
    ui->label_analysisPicture->setCaptureShape(index);
}

/********************************************************************
* 函数名：slotLogInUserId
* 功能：  槽函数，接收登录UserId
* 参数：  strId 用户Id
* 返回值：无
*
* 时间： 2017-8-11
* 作者：
*********************************************************************/
void Widget::slotLogInUserId(QString strId)
{
    if(NULL == m_pMtdDataBase) return;
    //用UserId查询病例
    QVector<MedRecord> searchRecordVec;
    searchRecordVec.clear();
    m_pMtdDataBase->searchRecord(strId, searchRecordVec);
    if(true == searchRecordVec.empty()) return;

    //用户信息界面
    QString strIdInfo = QString::number(searchRecordVec.at(0).userID);
    QString strName   = searchRecordVec.at(0).name;
    QString strSex    = searchRecordVec.at(0).bMale ? "Male" : "Fmale";
    QString strAge    = QString::number(searchRecordVec.at(0).age);

    ui->label_userInfoID->setText(strIdInfo);
    ui->label_userInfoName->setText(strName);

    //显示到数据库界面
    ui->tableWidget_case->clearContents();
    ui->tableWidget_case->setRowCount(0);
    ui->tableWidget_diagnose->clearContents();
    ui->tableWidget_diagnose->setRowCount(0);
    ui->tableWidget_case->setRowCount(ui->tableWidget_case->rowCount() + 1);
    ui->tableWidget_case->setItem(0, 0, new QTableWidgetItem(strIdInfo));
    ui->tableWidget_case->setItem(0, 1, new QTableWidgetItem(strName));
    ui->tableWidget_case->setItem(0, 2, new QTableWidgetItem(strSex));
    ui->tableWidget_case->setItem(0, 3, new QTableWidgetItem(strAge));

    //显示到结果输出界面
    ui->idEdit->setText(QString::number(searchRecordVec.at(0).userID));
    ui->idEdit->setEnabled(false);
    ui->nameEdit->setText(searchRecordVec.at(0).name);
    ui->nameEdit->setEnabled(false);
    ui->ageEdit->setText(QString::number(searchRecordVec.at(0).age));
    ui->ageEdit->setEnabled(false);
    ui->genderEdit->setText(searchRecordVec.at(0).bMale ? "男" : "女");
    ui->genderEdit->setEnabled(false);
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString timeStr = time.toString("yyyy-MM-dd"); //设置显示格式
    ui->dateLabel->setText(timeStr);
}

void Widget::slotUpDateCheck()
{
    if(NULL == m_pMtdDataBase) return;

    int rowIndex       = ui->tableWidget_diagnose->currentRow();//获取当前行
    if(-1 == rowIndex) return;
    int userId  = ui->tableWidget_diagnose->item(rowIndex, 1)->text().toInt();//获取当前行UserId

    //获取诊断
    QVector<MedCheckResult> resVector;
    resVector.clear();

    m_pMtdDataBase->selectResult(userId, resVector);

    if(true == resVector.empty()) return;


    //先删除columnIndex对应的列
    ui->tableWidget_diagnose->removeRow(rowIndex);
    ui->tableWidget_diagnose->insertRow(rowIndex);

    ui->tableWidget_diagnose->setItem(rowIndex, 0, new QTableWidgetItem(QString::number(resVector.at(rowIndex).id)));
    ui->tableWidget_diagnose->setItem(rowIndex, 1, new QTableWidgetItem(QString::number(resVector.at(rowIndex).userId)));
    ui->tableWidget_diagnose->setItem(rowIndex, 2, new QTableWidgetItem(resVector.at(rowIndex).checkDate.toString("yyyy-MM-dd hh:mm:ss")));
    ui->tableWidget_diagnose->setItem(rowIndex, 3, new QTableWidgetItem(resVector.at(rowIndex).checkSpot));
    ui->tableWidget_diagnose->setItem(rowIndex, 4, new QTableWidgetItem(QString::number(resVector.at(rowIndex).nDoctorID)));
    ui->tableWidget_diagnose->setItem(rowIndex, 5, new QTableWidgetItem(resVector.at(rowIndex).doctorName));
    ui->tableWidget_diagnose->setItem(rowIndex, 6, new QTableWidgetItem(resVector.at(rowIndex).decision));
}

/********************************************************************
* 函数名：slotUpDateRecordAndCheck
* 功能：  槽函数，点击修改病例或者诊断成功后，更新界面显示
* 参数：  isRecord true修改病例
*        isRecord false修改诊断
* 返回值：无
*
* 时间： 2017-8-11
* 作者：
*********************************************************************/
void Widget::slotUpDateRecord()
{
    if(NULL == m_pMtdDataBase) return;

    int rowIndex       = ui->tableWidget_case->currentRow();//获取当前行
    if(-1 == rowIndex) return;
    QString strUserId  = ui->tableWidget_case->item(rowIndex, 0)->text();//获取当前行UserId

    //获取病例
    QVector<MedRecord> medVector;
    medVector.clear();

    m_pMtdDataBase->searchRecord(strUserId, medVector); //搜索病历

    if(true == medVector.empty()) return;

    //先删除columnIndex对应的列
    ui->tableWidget_case->removeRow(rowIndex);
    ui->tableWidget_case->insertRow(rowIndex);

    //刷新病例
    ui->tableWidget_case->setItem(rowIndex, 0, new QTableWidgetItem(QString::number(medVector.at(0).userID)));
    ui->tableWidget_case->setItem(rowIndex, 1, new QTableWidgetItem(medVector.at(0).name));
    QString strSex = (true == medVector.at(0).bMale) ? "Male" : "Female";
    ui->tableWidget_case->setItem(rowIndex, 2, new QTableWidgetItem(strSex));
    ui->tableWidget_case->setItem(rowIndex, 3, new QTableWidgetItem(QString::number(medVector.at(0).age)));
}

/********************************************************************
* 函数名：on_radioButton_GrayScale_toggled
* 功能：  槽函数，视频处理，灰度图
* 参数：  checked 按钮是否check
* 返回值：无
*
* 时间： 2017-8-15
* 作者：
*********************************************************************/
void Widget::on_radioButton_GrayScale_toggled(bool checked)
{
    if(true == checked)
    {
        if(NULL == m_pCurrentImage) return;
        MTD::ImageParamer stValue;
        stValue = m_pCurrentImage->getParamer();
        stValue.gradation = MTD::Gray;
        m_pCurrentImage->setParamer(stValue);

        //更新调色盘
        ui->label_coloredTape->setPixmap(QPixmap::fromImage(m_pCurrentImage->getPalette()));
        ui->label_coloredTape->setScaledContents(true);
    }
}

/********************************************************************
* 函数名：on_radioButton_PseudoColor_toggled
* 功能：  槽函数，视频处理，伪彩色
* 参数：  checked 按钮是否check
* 返回值：无
*
* 时间： 2017-8-15
* 作者：
*********************************************************************/
void Widget::on_radioButton_PseudoColor_toggled(bool checked)
{
    if(true == checked)
    {
        if(NULL == m_pCurrentImage) return;
        MTD::ImageParamer stValue;
        stValue = m_pCurrentImage->getParamer();
        int index = ui->comboBox_PseudoColorSelector->currentIndex();
        switch(index)
        {
        case 0:
            stValue.gradation = MTD::Color20;
            break;
        case 1:
            stValue.gradation = MTD::Color40;
            break;
        case 2:
            stValue.gradation = MTD::Color80;
            break;
        case 3:
            stValue.gradation = MTD::Color160;
        default:
            break;
        }
        m_pCurrentImage->setParamer(stValue);
        //更新调色盘
        ui->label_coloredTape->setPixmap(QPixmap::fromImage(m_pCurrentImage->getPalette()));
        ui->label_coloredTape->setScaledContents(true);
    }
}

/********************************************************************
* 函数名：on_comboBox_PseudoColorSelector_currentIndexChanged
* 功能：  槽函数，获取伪彩色参数
* 参数：  index
* 返回值：无
*
* 时间： 2017-8-15
* 作者：
*********************************************************************/
void Widget::on_comboBox_PseudoColorSelector_currentIndexChanged(int index)
{
    on_radioButton_PseudoColor_toggled(true);
}

/********************************************************************
* 函数名：on_spinBox_MaxTmp_valueChanged
* 功能：  槽函数，获取温度上限
* 参数：  index
* 返回值：无
*
* 时间： 2017-8-15
* 作者：
*********************************************************************/
void Widget::on_spinBox_MaxTmp_valueChanged(int arg1)
{
    if(NULL == m_pCurrentImage) return;
    MTD::ImageParamer stValue;
    stValue = m_pCurrentImage->getParamer();
    stValue.temHigh = arg1;
    m_pCurrentImage->setParamer(stValue);

    //低温不能高于高温，高温不能低于低温
    int min = ui->spinBox_MinTmp->value();
    ui->spinBox_MinTmp->setRange(0, arg1);
    ui->spinBox_MaxTmp->setRange(min, 255);
}

/********************************************************************
* 函数名：on_spinBox_MaxTmp_valueChanged
* 功能：  槽函数，获取温度下限
* 参数：  index
* 返回值：无
*
* 时间： 2017-8-15
* 作者：
*********************************************************************/
void Widget::on_spinBox_MinTmp_valueChanged(int arg1)
{
    if(NULL == m_pCurrentImage) return;
    MTD::ImageParamer stValue;
    stValue = m_pCurrentImage->getParamer();
    stValue.temLow = arg1;
    m_pCurrentImage->setParamer(stValue);

    //低温不能高于高温，高温不能低于低温
    int max = ui->spinBox_MaxTmp->value();
    ui->spinBox_MaxTmp->setRange(arg1, 255);
    ui->spinBox_MinTmp->setRange(0, max);
}

/********************************************************************
* 函数名：on_comboBox_splitScreen_currentIndexChanged
* 功能：  槽函数，分屏
* 参数：  index
* 返回值：无
*
* 时间： 2017-8-15
* 作者：
*********************************************************************/
void Widget::on_comboBox_splitScreen_currentIndexChanged(int index)
{
    switch(index)
    {
    case 0:
        emit sendSplitScreenCount(1);
        break;
    case 1:
        emit sendSplitScreenCount(2);
        break;
    case 2:
        emit sendSplitScreenCount(4);
        break;
    default:
        break;
    }
}

/********************************************************************
* 函数名：on_printBtn_clicked
* 功能：  槽函数，打印诊断
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-15
* 作者：
*********************************************************************/
void Widget::on_printBtn_clicked()
{
    QPrinter printerPixmap;
    QPixmap pixmap = QPixmap::grabWidget(ui->scrollAreaWidgetContents, ui->scrollAreaWidgetContents->rect());  //获取界面的图片

    QPrintDialog print(&printerPixmap, this);
    if (print.exec())
    {
        QPainter painterPixmap;
        painterPixmap.begin(&printerPixmap);
        QRect rect = painterPixmap.viewport();
        int x = rect.width() / pixmap.width();
        int y = rect.height() / pixmap.height();
        painterPixmap.scale(x, y);
        painterPixmap.drawPixmap(0, 0, pixmap);
        painterPixmap.end();
    }
}

/********************************************************************
* 函数名：on_previewBtn_clicked
* 功能：  槽函数，预览诊断
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-15
* 作者：
*********************************************************************/
void Widget::on_previewBtn_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
    //自定义纸张大小
    printer.setPageSize(QPrinter::Custom);
    printer.setPaperSize(QSizeF(ui->scrollAreaWidgetContents->height(), ui->scrollAreaWidgetContents->width()), QPrinter::Point);
    QPrintPreviewDialog preview(&printer, this);
    preview.setMinimumSize(1000,600);
    connect(&preview, SIGNAL(paintRequested(QPrinter*)), SLOT(printPreviewSlot(QPrinter*)));
    preview.exec();
}

/********************************************************************
* 函数名：printPreviewSlot
* 功能：  槽函数，预览诊断
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-15
* 作者：
*********************************************************************/
void Widget::printPreviewSlot(QPrinter* printerPixmap)
{
    printerPixmap->setOrientation(QPrinter::Landscape);
    //获取界面的图片
    QPixmap pixmap = QPixmap::grabWidget(ui->scrollAreaWidgetContents, ui->scrollAreaWidgetContents->rect());
    QPainter painterPixmap(this);
    painterPixmap.begin(printerPixmap);
    QRect rect = painterPixmap.viewport();
    int x = rect.width() / pixmap.width();
    int y = rect.height() / pixmap.height();
    painterPixmap.scale(x, y);
    painterPixmap.drawPixmap(0, 0, pixmap);
    painterPixmap.end();
}

/********************************************************************
* 函数名：on_exportPdfBtn_clicked
* 功能：  槽函数，到处诊断pdf
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-15
* 作者：
*********************************************************************/
void Widget::on_exportPdfBtn_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("保存PDF文件"), QString(), "*.pdf");
    if (!fileName.isEmpty())
    {
        // 如果文件后缀为空，则默认使用.pdf
        if (QFileInfo(fileName).suffix().isEmpty())
        {
            fileName.append(".pdf");
        }
        QPrinter printerPixmap(QPrinter::HighResolution);
        //自定义纸张大小，这里要打印的内容都在scrollAreaWidgetContents上
        printerPixmap.setPageSize(QPrinter::Custom);
        printerPixmap.setPaperSize(QSizeF(ui->scrollAreaWidgetContents->height(), ui->scrollAreaWidgetContents->width()), QPrinter::Point);
        //设置纸张大小为A4，这里注释掉了，建议自定义纸张 ，否则保存的就会有很多空白
        //printerPixmap.setPageSize(QPrinter::A4);
        //横向打印
        printerPixmap.setOrientation(QPrinter::Landscape);
        //设置输出格式为pdf
        printerPixmap.setOutputFormat(QPrinter::PdfFormat);
        //设置输出路径
        printerPixmap.setOutputFileName(fileName);
        //获取界面的图片
        QPixmap pixmap = QPixmap::grabWidget(ui->scrollAreaWidgetContents, ui->scrollAreaWidgetContents->rect());

        QPainter painterPixmap;
        painterPixmap.begin(&printerPixmap);
        QRect rect = painterPixmap.viewport();
        int x = rect.width() / pixmap.width();
        int y = rect.height() / pixmap.height();
        //将图像(所有要画的东西)在pdf上按比例尺缩放
        painterPixmap.scale(x, y);
        //画图
        painterPixmap.drawPixmap(0, 0, pixmap);
        painterPixmap.end();

        QMessageBox::information(this, "生成PDF", "保存PDF文件成功", QMessageBox::Ok);
    }
}

/********************************************************************
* 函数名：on_outputBtn_clicked
* 功能：  槽函数，将图片分析内容导入到诊断报告中
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-15
* 作者：
*********************************************************************/
void Widget::on_outputBtn_clicked()
{
    QVector<QImage> imageList;
    imageList.clear();
    ui->label_analysisPicture->getImageList(imageList);
    qDebug() << imageList.size() << endl;
    if (imageList.size() == 0 || imageList.size() > 4)
    {
        QMessageBox::information(this, "error", "图片数量在 1-4 张", QMessageBox::Ok);
    }
    else
    {
        emit sendSplitScreenCount2(imageList.size());
        for(int i = 0; i < imageList.size(); i ++)
        {
            emit sendPicture2(QPixmap::fromImage(imageList[i]), i);
        }
    }
    //将图片分析区的测温tableWidget复制到诊断输出中
    int rowCount       = ui->tableWidget_pictureTemperatureMessure->rowCount();
    int columCount     = ui->tableWidget_pictureTemperatureMessure->columnCount();
    for(int rowLoop = 0; rowLoop < rowCount; rowLoop++)
    {
        ui->temDataTable->setRowCount(ui->temDataTable->rowCount() + 1);
        for(int columnLoop = 0; columnLoop < columCount; columnLoop++)
        {
            ui->temDataTable->setItem(rowLoop, columnLoop, new QTableWidgetItem(ui->tableWidget_pictureTemperatureMessure->item(rowLoop, columnLoop)->text()));
        }
    }

}

/********************************************************************
* 函数名：on_pushButton_ClearCaptureArea_clicked
* 功能：  槽函数，清除选取的区域(数据采集界面)
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-16
* 作者：wangzhiping
*********************************************************************/
void Widget::on_pushButton_ClearCaptureArea_clicked()
{
    ui->label_video->clearCaptureArea();
}

/********************************************************************
* 函数名：on_pushButton_clearArea_clicked
* 功能：  槽函数，清除选取的区域（图片分析界面）
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-17
* 作者：
*********************************************************************/
void Widget::on_pushButton_clearArea_clicked()
{
    ui->label_analysisPicture->clearCaptureArea();
}
