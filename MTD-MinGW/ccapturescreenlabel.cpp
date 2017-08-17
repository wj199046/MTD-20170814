#include "ccapturescreenlabel.h"
#include<QDebug>

#define STRETCH_RECT_WIDTH 6
#define STRETCH_RECT_HEIGHT 6

CCaptureScreenLabel::CCaptureScreenLabel(QWidget *parent):QLabel(parent)
{
    this->setMouseTracking(true);
    m_pCapScrHelper = new CCapureScreenHelper(this);
    connect(m_pCapScrHelper,SIGNAL(captureComplete(QPixmap,QPoint,QPoint)),this,SIGNAL(signalCompleteCapture(QPixmap,QPoint,QPoint)));
    connect(m_pCapScrHelper,SIGNAL(captureAreaChanged(QPoint,QPoint)),this,SIGNAL(signalMouseRelease(QPoint,QPoint)));

}

CCaptureScreenLabel::~CCaptureScreenLabel()
{
    qDebug("~CCaptureScreenLabel：dddddddd");
}

void CCaptureScreenLabel::setCaptureShape(CapScr_Shape captureShape)
{
    m_pCapScrHelper->setCaptureShape(captureShape);
}


void CCaptureScreenLabel::setCaptureImage(const QPixmap & Image)
{
    setPixmap(Image);
    qDebug() << Image.width() <<"," << Image.height()<<"11111111111111111111111111111111"<<endl;
    m_pCapScrHelper->resize(Image.size());
    m_pCapScrHelper->init(Image);
    m_pCapScrHelper->show();
}

void CCaptureScreenLabel::clearCaptureArea()
{
    m_pCapScrHelper->resetSelectedArea();
    m_pCapScrHelper->update();
}

void CCaptureScreenLabel::clear()
{
    QLabel::clear();
    clearCaptureArea();
}































