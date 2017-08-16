#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"userinfowidgets.h"
#include<QTableWidgetItem>
#include"pixlabelwidget.h"
#include"MTDMed/mtdmed.h"
#include"savepicturewidgets.h"
#include"include/camera/mtd_camera_core.h"
#include"include/camera/mtd_image.h"
#include"recordupdatewidgets.h"
#include"resultupdatewidgets.h"
#include <QPrinter>
#include<QPrintDialog>
#include<QPrintPreviewDialog>
#include<QFileDialog>

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
    void ReceiveUserInfo(Common::stUserSigninInfo stInfo);
    void on_pushButton_capture_clicked();
    void doubleClickedShowPicture(QTableWidgetItem *pItem);
    void changeCurrentTab(PixLabel*);
    void showUserInfo(UserLabel *);
    void clickedShowDiagnosePicture(QTableWidgetItem *pItem);    
    void doubleClickedShowRecord(QTableWidgetItem*);
    void clickedShowDiagnose(QTableWidgetItem *pItem);
    void doubleClickedShowResult(QTableWidgetItem*);

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

    void on_pushButton_modifyDiagnose_clicked();

    void slotSendPrintScreen(QPixmap captureimage, QPoint top, QPoint bottom, QPoint labelPoint);
    void slotTempMeasCoordinate(QPoint top, QPoint bottom, QPoint labelPoint);

    void on_comboBox_printScreenForm_currentIndexChanged(int index);
    void slotLogInUserId(QString strId);

    void slotUpDateRecord();
    void slotUpDateCheck();

    void on_radioButton_GrayScale_toggled(bool checked);
    void on_radioButton_PseudoColor_toggled(bool checked);
    void on_comboBox_PseudoColorSelector_currentIndexChanged(int index);
    void on_spinBox_MaxTmp_valueChanged(int arg1);
    void on_spinBox_MinTmp_valueChanged(int arg1);

    void on_radioButton_GrayScale_2_toggled(bool checked);
    void on_radioButton_PseudoColor_2_toggled(bool checked);
    void on_comboBox_PseudoColorSelector_2_currentIndexChanged(int index);
    void on_checkBox_polarityReversal_toggled(bool checked);
    void on_checkBox_filtration_toggled(bool checked);
    void on_checkBox_histogram_toggled(bool checked);
    void on_horizontalSlider_edgeDetection_valueChanged(int value);
    void on_SpinBox_lowerTemperature_valueChanged(int arg1);
    void on_SpinBox_upperTemperature_valueChanged(int arg1);

    void on_comboBox_splitScreen_currentIndexChanged(int index);

    void on_printBtn_clicked();

    void on_previewBtn_clicked();

    void on_exportPdfBtn_clicked();

    void printPreviewSlot(QPrinter* printerPixmap);

    void on_outputBtn_clicked();

    void on_pushButton_ClearCaptureArea_clicked();

signals:
    void sendSplitScreenCount(int count);
    void sendPicture(QPixmap , int);

    void sendSplitScreenCount2(int count);
    void sendPicture2(QPixmap, int);

private:
    Ui::Widget *ui;
    userInfoWidgets     *m_userInfo;
    MTDCameraCore       *m_pVideo;
    MTDImage            *m_pCurrentImage;
    MtdMed              *m_pMtdDataBase;
    savePictureWidgets  *m_pSaveDiagnose;
    RecordUpdateWidgets *m_recordUpdate, *m_recordShow;
    ResultUpdateWidgets *m_resultUpdate, *m_resultShow;

    QVector<MTDImage *>  m_MtdImageVec;

    bool                 m_bUpDownStop;
    bool                 m_bFocusStop;

    QPixmap              m_resizedVideoFrame;

    QPoint               m_topLeftPoint;
    QPoint               m_bottomRightPoint;

    enum enMainWidgetsTab
    {
        EN_OPERATE_TAB  = 0,
        EN_ANALYSIS_TAB = 1,
        EN_DATABASE_TAB = 2,
        EN_REPORT_TAB   = 3,
    };
};

#endif // WIDGET_H
