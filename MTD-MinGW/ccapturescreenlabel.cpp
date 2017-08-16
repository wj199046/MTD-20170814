#include "ccapturescreenlabel.h"

#define STRETCH_RECT_WIDTH 6
#define STRETCH_RECT_HEIGHT 6

CCaptureScreenLabel::CCaptureScreenLabel(QWidget *parent):QLabel(parent)
{
    this->setMouseTracking(true);
    m_pCapScrHelper = new CCapureScreenHelper(this);
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

    m_pCapScrHelper->resize(this->size());
    m_pCapScrHelper->init(Image);
    m_pCapScrHelper->show();
    //qDebug("CCaptureScreenLabel w=%d,h=%d,m_pCapScrHelper w=%d,h=%d",this->width(),this->height(),m_pCapScrHelper->width(),m_pCapScrHelper->height());
}































