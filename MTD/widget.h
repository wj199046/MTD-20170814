#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"userinfowidgets.h"
#include"analysiswidgets.h"
#include<QTableWidgetItem>
#include"pixlabelwidget.h"
#include"MTDMed/mtdmed.h"
#include"savepicturewidgets.h"
#include"include/camera/mtd_camera_core.h"
#include"include/camera/mtd_image.h"
#include"recordupdatewidgets.h"
#include"resultupdatewidgets.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_maniTool_clicked();
    void ReceiveUserInfo(QString strName, QString strAge, QString strSex);
    void on_pushButton_capture_clicked();
    void doubleClickedShowPicture(QTableWidgetItem *pItem);
    void changeCurrentTab(PixLabel*);
    void showUserInfo(UserLabel *);
    void clickedShowDiagnosePicture(QTableWidgetItem *pItem);
    void clickedShowDiagnose(QTableWidgetItem *pItem);

    void on_pushButton_splitScreen_1_clicked();
    void on_pushButton_splitScreen_2_clicked();
    void on_pushButton_splitScreen_4_clicked();

    void controlCameraUp();
    void controlCameraDown();
    void controlCameraFocusPlus();
    void controlCameraFocusMinus();
    void controlCameraStop();

    void on_pushButton_search_clicked();
    void on_pushButton_deleteCase_clicked();
    void on_pushButton_modifyCase_clicked();
    void on_pushButton_PictureToDataBase_clicked();

    void receiveDiagnoseInfo(Common::stDiagnoseRst stRst);

    void on_pushButton_deleteDiagnose_clicked();
    void on_pushButton_deleteScrollImage_clicked();

    void playVideo();

    void imageAnalysis_BlackAndWhite(bool checked);
    void imageAnalysis_160(bool checked);
    void imageAnalysis_80(bool checked);
    void imageAnalysis_40(bool checked);
    void imageAnalysis_20(bool checked);
    void imageAnalysis_polarityReversal(bool checked);
    void imageAnalysis_filtration(bool checked);
    void imageAnalysis_histogram(bool checked);
    void imageAnalysis_edgeDetection(int value);
    void imageAnalysis_lowerTemperature(int value);
    void imageAnalysis_upperTemperature(int value);

    void on_pushButton_modifyDiagnose_clicked();

    void slotSendPrintScreen(QPixmap captureimage);

    void on_comboBox_printScreenForm_currentIndexChanged(int index);
    void slotLogInUserId(QString strId);

    void slotUpDateRecord();
    void slotUpDateCheck();

    void on_radioButton_GrayScale_toggled(bool checked);

    void on_radioButton_PseudoColor_toggled(bool checked);

    void on_comboBox_PseudoColorSelector_currentIndexChanged(int index);

signals:
    void sendSplitScreenCount(int count);
    void sendPicture(QPixmap &, int);

private:
    Ui::Widget *ui;
    userInfoWidgets     *m_userInfo;
    analysisWidgets     *m_analysisTool;
    MTDCameraCore       *m_pVideo;
    MTDImage            *m_pCurrentImage;
    MtdMed              *m_pMtdDataBase;
    savePictureWidgets  *m_pSaveDiagnose;
    RecordUpdateWidgets *m_recordUpdate;
    ResultUpdateWidgets *m_resultUpdate;

    QVector<MTDImage *>  m_MtdImageVec;

    bool                 m_bUpDownStop;
    bool                 m_bFocusStop;

    QPixmap             m_resizedVideoFrame;

    enum enMainWidgetsTab
    {
        EN_OPERATE_TAB  = 0,
        EN_ANALYSIS_TAB = 1,
        EN_DATABASE_TAB = 2,
        EN_REPORT_TAB   = 3,
    };
};

#endif // WIDGET_H
