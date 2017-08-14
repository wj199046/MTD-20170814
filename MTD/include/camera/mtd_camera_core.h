#ifndef MTD_CAMERA_CORE_H
#define MTD_CAMERA_CORE_H

#include "mtdcameracore_global.h"
#include <QObject>
#include<QTimer>
#include<QList>
#include<qwindowdefs_win.h>
#include"mtd_camera_ste.h"
typedef unsigned char       UCHAR;
typedef unsigned short      USHORT;
typedef _W64 unsigned int UINT_PTR, *PUINT_PTR;
#include "include/IRSysDll.h"
#define WM_COMM_RXCHAR	WM_USER+7
#include "include/opencv2/core.hpp"
#include"mtd_image.h"
class MTDCAMERACORESHARED_EXPORT MTDCameraCore :public QObject
{
     Q_OBJECT
public:
    MTDCameraCore(HWND hwnd);
    ~MTDCameraCore();
signals:
    void capture();
public:
    void cameraControl(MTD::CameraControl control);//相机控制
    MTDImage *getImage() const;//获取缓存的图像
private slots:
    void bufferData();
    void getBuffer();
private:
    bool isBuffer;
    int count=0;
    IRSysDll*	m_pIRController;
    cv::Mat* buffer;
    MTDImage *image;
    QTimer* timer_buffer;
    QTimer* timer_get_buffer;
    QList<cv::Mat*> list;
};
#endif // MTD_CAMERA_CORE_H
