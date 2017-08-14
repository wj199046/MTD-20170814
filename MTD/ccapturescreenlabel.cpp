#include "ccapturescreenlabel.h"



#define STRETCH_RECT_WIDTH 6
#define STRETCH_RECT_HEIGHT 6

CCaptureScreenLabel::CCaptureScreenLabel(QWidget *parent):QLabel(parent),m_currentCaptureState(InitCapture),m_enCaptureShape(CapScr_Rectangle)
{
    this->setMouseTracking(true);
    //this->setAttribute(Qt::WA_DeleteOnClose);
    initStretchRect();
    m_pPolygen = new QPolygon();
}

CCaptureScreenLabel::~CCaptureScreenLabel()
{
    delete m_pPolygen;
    qDebug("~CCaptureScreenLabel：dddddddd");
}

void CCaptureScreenLabel::setCaptureShape(CapScr_Shape captureShape)
{
    m_enCaptureShape = captureShape;
    if(CapScr_Polygon == m_enCaptureShape)
    {
        m_currentCaptureState = OnCapturePolygon;
    }
}

void CCaptureScreenLabel::initStretchRect()
{
    m_stretchRectState = NotSelect;

    m_topLeftRect = QRect(0 , 0 , 0 , 0);
    m_topRightRect = QRect(0, 0, 0, 0);
    m_bottomLeftRect = QRect(0, 0, 0, 0);
    m_bottomRightRect = QRect(0, 0, 0, 0);

    m_leftCenterRect = QRect(0, 0, 0, 0);
    m_topCenterRect = QRect(0, 0, 0, 0);
    m_rightCenterRect = QRect(0, 0, 0, 0);
    m_bottomCenterRect = QRect(0, 0, 0, 0);

    m_centerRect = QRect(0,0,0,0);
}

void CCaptureScreenLabel::setCaptureImage(const QPixmap & Image)
{
//    if(!ImageLabel)
//    {
//       return;
//    }

//    //setParent(ImageLabel);
//    resize(ImageLabel->size());
//    move(ImageLabel->x(),ImageLabel->y());

//    m_loadPixmap = *ImageLabel->pixmap();
//    m_screenHeight = ImageLabel->height();
//    m_screenWidth = ImageLabel->width();
//    qDebug("loadImage,height=%d,width=%d",m_screenHeight,m_screenWidth);

    setPixmap(Image.scaled(this->size()));
    //setScaledContents(true);
    m_loadPixmap = *this->pixmap();
    m_screenHeight = height();
    m_screenWidth = width();
}

void CCaptureScreenLabel::mousePressEvent(QMouseEvent *event)
{
    qDebug("mousePressEvent");

    if(Qt::RightButton == event->button())
    {
        m_currentCaptureState = InitCapture;
        //close();
    }

    if(CapScr_Polygon == m_enCaptureShape)
    {
        return polygonMousePressEvent(event);
    }
    else
    {
        return rectMousePressEvent(event);
    }
}

void CCaptureScreenLabel::rectMousePressEvent(QMouseEvent *event)
{
    m_stretchRectState = getStretchRectState(event->pos());

    if(m_currentCaptureState == InitCapture)
    {
        m_currentCaptureState = BeginCaptureImage;
        m_beginPoint = event->pos();
    }
    else if(m_stretchRectState != NotSelect)
    {
        m_currentCaptureState = BeginMoveStretchRect;
        setStretchCursorStyle(m_stretchRectState);
        m_beginMovePoint = event->pos();
    }
    else if(isPressPointInSelectRect(event->pos()))
    {
        qDebug("rectMousePressEvent is in");
        m_currentCaptureState = BeginMoveCaptureArea;
        m_beginMovePoint = event->pos();
    }

    return QWidget::mousePressEvent(event);
}

void CCaptureScreenLabel::polygonMousePressEvent(QMouseEvent *event)
{
    switch(m_currentCaptureState)
    {
    case OnCapturePolygon:mousePressCapturePolygon(event);break;
    case FinishCapturePolygon:m_currentCaptureState = AdjustPolygon;
    case AdjustPolygon:mousePressAdjustPolygon(event); break;
    default:break;
    }

    return QWidget::mousePressEvent(event);
}

void CCaptureScreenLabel::mousePressCapturePolygon(QMouseEvent *event)
{
    //上一个点在vector中存了两遍，移除一个重复的
    if (!m_pPolygen->isEmpty())
    {
        m_pPolygen->removeLast();
    }
    //多存一个点，这个点用来保存mouseMoveEvent事件中鼠标的位置
    m_pPolygen->append(event->pos());
    m_pPolygen->append(event->pos());
    update();

    //生成每个点上小矩形并存入StretchRectVec
    QRect stretchRect(event->pos().x() - STRETCH_RECT_HEIGHT / 2,event->pos().y() - STRETCH_RECT_WIDTH / 2,STRETCH_RECT_WIDTH,STRETCH_RECT_HEIGHT);
    StretchRectVec.push_back(stretchRect);

}

//调整多边形大小形状和位置
void CCaptureScreenLabel::mousePressAdjustPolygon(QMouseEvent *event)
{
    getMousePos(event->pos());
    if(m_enMousePos == InSelectedArea)
    {
        m_beginMovePoint = event->pos();
        m_endMovePoint = event->pos();
        qDebug("mousePressAdjustPolygon: m_beginMovePoint,x=%d,y=%d",m_beginMovePoint.x(),m_beginMovePoint.y());
    }
}

void CCaptureScreenLabel::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug("move x=%d,y=%d,size=%d",event->pos().x(),event->y(),m_pPolygen->size());
    //qDebug("mouseMoveEvent m_currentCaptureState=%d",m_currentCaptureState);

    if(CapScr_Polygon == m_enCaptureShape)
    {
        return polygonMouseMoveEvent(event);
    }
    else
    {
        return rectMouseMoveEvent(event);
    }
}

void CCaptureScreenLabel::rectMouseMoveEvent(QMouseEvent *event)
{
    if(m_currentCaptureState == BeginCaptureImage)
    {
        m_endPoint = event->pos();
        update();
    }
    else if(m_currentCaptureState == BeginMoveCaptureArea)
    {
        m_endMovePoint = event->pos();
        update();
    }
    else if(m_currentCaptureState == BeginMoveStretchRect)
    {
        m_endMovePoint = event->pos();
        update();

        return QLabel::mouseMoveEvent(event);
    }

    StretchRectState stretchRectState = getStretchRectState(event->pos());

    if(stretchRectState != NotSelect)
    {
        setStretchCursorStyle(stretchRectState);
    }
    else if(isPressPointInSelectRect(event->pos()))
    {
        setCursor(Qt::SizeAllCursor);
    }
    else if(!isPressPointInSelectRect(event->pos()) && m_currentCaptureState != BeginMoveCaptureArea)
    {
        setCursor(Qt::ArrowCursor);
    }

    return QLabel::mouseMoveEvent(event);
}

void CCaptureScreenLabel::polygonMouseMoveEvent(QMouseEvent *event)
{
    if(m_currentCaptureState == OnCapturePolygon)
    {
        if(!m_pPolygen->isEmpty())
        {
            //qDebug("in if");
            m_pPolygen->setPoint(m_pPolygen->size()-1,event->pos());
            update();
        }
    }

    if(m_currentCaptureState == AdjustPolygon)
    {
        qDebug("polygonMouseMoveEvent if pos is=%d",m_enMousePos);
        switch(m_enMousePos)
        {
        case InSelectedArea:mouseMoveAdjustAreaPos(event);break;
        case OutSelectedArea:break;
        case OnStretchRect:mouseMoveAdjustStretchRect(event->pos());break;
        default:break;
        }
    }

    return QLabel::mouseMoveEvent(event);
}

void CCaptureScreenLabel::mouseMoveAdjustAreaPos(QMouseEvent *event)
{
    qDebug("mouseMoveAdjustAreaPos");
    m_endMovePoint = event->pos();
    QPoint movePoint = m_endMovePoint - m_beginMovePoint;

    m_pPolygen->translate(movePoint);
    moveStretchRect(movePoint);

    repaint();

    m_pPolygen->translate(-movePoint);
    moveStretchRect(-movePoint);

}

void CCaptureScreenLabel::moveStretchRect(QPoint point)
{
    for(int i = 0;i < StretchRectVec.size();i++)
    {
        StretchRectVec[i].translate(point);
    }
}

void CCaptureScreenLabel::mouseMoveAdjustStretchRect(QPoint point)
{
    qDebug("mouseMoveAdjustStretchRect ");
    m_pPolygen->setPoint(m_adjustStretchRectIdx,point);
    QRect stretchRect(point.x() - STRETCH_RECT_HEIGHT / 2,point.y() - STRETCH_RECT_WIDTH / 2,STRETCH_RECT_WIDTH,STRETCH_RECT_HEIGHT);
    StretchRectVec[m_adjustStretchRectIdx] = stretchRect;
    update();
}

void CCaptureScreenLabel::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(m_enCaptureShape != CapScr_Rectangle) return;
    //finish polygon and draw stretch rect
    qDebug("double click");

    if (event->button() != Qt::LeftButton)
    {
        return;
    }

    if (m_enCaptureShape == CapScr_Polygon)
    {
        if (m_currentCaptureState == FinishCapturePolygon)
        {
            signalCompleteCapture(m_capturePixmap);
            resetSelectedArea();
        }
        else
        {
            m_pPolygen->removeLast();
            qDebug("size=%d",m_pPolygen->size());
            m_currentCaptureState = FinishCapturePolygon;
        }
    }
    else
    {
        signalCompleteCapture(m_capturePixmap);
        resetSelectedArea();
    }
    update();

}

void CCaptureScreenLabel::resetSelectedArea()
{
    initStretchRect();
    m_currentSelectRect = QRect(0,0,0,0);
    m_currentCaptureState = InitCapture;
    m_pPolygen->clear();
    StretchRectVec.clear();
}

void CCaptureScreenLabel::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug("mouseReleaseEvent m_currentCaptureState=%d",m_currentCaptureState);
    if(CapScr_Polygon == m_enCaptureShape)
    {
        return polygonMouseReleaseEvent(event);
    }
    else
    {
        return rectMouseReleaseEvent(event);
    }
}

void CCaptureScreenLabel::rectMouseReleaseEvent(QMouseEvent *event)
{
    if(m_currentCaptureState == BeginCaptureImage)
    {
        m_currentCaptureState = FinishCaptureImage;
        m_endPoint = event->pos();
        update();
    }
    else if(m_currentCaptureState == BeginMoveCaptureArea)
    {
        qDebug("rectMouseReleaseEvent,end point x=%d,y=%d",event->pos().x(),event->pos().y());
        qDebug("rectMouseReleaseEvent select area x=%d,y=%d",m_currentSelectRect.x(),m_currentSelectRect.y());
        m_currentCaptureState = FinishMoveCaptureArea;
        m_endMovePoint = event->pos();
        repaint();
        qDebug("rectMouseReleaseEvent select area x=%d,y=%d",m_currentSelectRect.x(),m_currentSelectRect.y());
    }
    else if(m_currentCaptureState == BeginMoveStretchRect)
    {
        m_currentCaptureState = FinishMoveStretchRect;
        m_endMovePoint = event->pos();
        update();
    }

    return QLabel::mouseReleaseEvent(event);
}

void CCaptureScreenLabel::polygonMouseReleaseEvent(QMouseEvent *event)
{
    if(m_currentCaptureState == AdjustPolygon)
    {
        qDebug("polygonMouseReleaseEvent");
        if(m_enMousePos == OnStretchRect)
        {
            m_pPolygen->setPoint(m_adjustStretchRectIdx,event->pos());
            update();
        }
        if(m_enMousePos == InSelectedArea)
        {
            QPoint movePoint = m_endMovePoint - m_beginMovePoint;
            m_pPolygen->translate(movePoint);
            moveStretchRect(movePoint);
            update();
        }
        m_currentCaptureState = FinishCapturePolygon;
    }


    return QLabel::mouseReleaseEvent(event);
}

bool CCaptureScreenLabel::isPressPointInSelectRect(QPoint mousePressPoint)
{
    QRect selectRect = getRect(m_beginPoint,m_endPoint);
    if(selectRect.contains(mousePressPoint))
    {
        return true;
    }
    return false;
}

void CCaptureScreenLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);

    //qDebug("paintEvent m_enCaptureShape = %d",m_enCaptureShape);
    m_painter.begin(this);
    m_painter.setPen(QPen(Qt::blue,1,Qt::SolidLine,Qt::FlatCap));
    //m_painter.drawPixmap(0,0,m_loadPixmap);

    if(CapScr_Polygon == m_enCaptureShape)
    {
        polygonPaintEvent(event);
    }
    else
    {
        rectPaintEvent(event);
    }

    m_painter.end();

}

void CCaptureScreenLabel::rectPaintEvent(QPaintEvent *event)
{
    //qDebug("loadpixmap height=%d.width=%d",m_loadPixmap.height(),m_loadPixmap.width());
    switch(m_currentCaptureState)
    {
    case InitCapture:break;
    case BeginCaptureImage:
    case FinishCaptureImage:
    case BeginMoveCaptureArea:
    case FinishMoveCaptureArea:
    case BeginMoveStretchRect:
    case FinishMoveStretchRect:
        m_currentSelectRect = getSelectRect();
        drawCaptureImage();
    default:
        break;
    }
}

void CCaptureScreenLabel::polygonPaintEvent(QPaintEvent *event)
{
    if (!m_pPolygen->isEmpty())
    {
        QPainterPath polygenPainterPath(m_pPolygen->at(0));
        for(int i = 1;i < m_pPolygen->size();i++)
        {
            polygenPainterPath.lineTo(m_pPolygen->at(i));
        }

        if (m_currentCaptureState == FinishCapturePolygon || m_currentCaptureState == AdjustPolygon)
        {
            //qDebug("rects = %d",StretchRectVec.size());
            m_painter.drawPolygon(*m_pPolygen);
            m_painter.drawRects(StretchRectVec);
            drawCaptureImage();
        }
        else if (m_currentCaptureState == OnCapturePolygon)
        {
            qDebug("OnCapturePolygon");
            m_painter.drawPath(polygenPainterPath);
        }
    }
}

void CCaptureScreenLabel::focusOutEvent(QFocusEvent *event)
{
    QWidget::focusOutEvent(event);
    close();
}

void CCaptureScreenLabel::getMousePos(QPoint point)
{
    if(MouseOnStretchRect(point))
    {
        m_enMousePos = OnStretchRect;
        return;
    }
    if(m_pPolygen->containsPoint(point,Qt::OddEvenFill))
    {
        qDebug("CCaptureScreenLabel::getMousePos InSelectedArea");
        m_enMousePos = InSelectedArea;
    }
    else
    {
        qDebug("CCaptureScreenLabel::getMousePos OutSelectedArea");
        m_enMousePos = OutSelectedArea;
    }
}

bool CCaptureScreenLabel::MouseOnStretchRect(QPoint point)
{
    for(int i = 0;i < StretchRectVec.size();i++)
    {
        if(StretchRectVec[i].contains(point))
        {
            qDebug("StretchRectVec[i].contains(point) i=%d",i);
            m_beginMovePoint = point;
            m_adjustStretchRectIdx = i;
            return true;
        }
    }
    return false;
}

QRect CCaptureScreenLabel::getSelectRect()
{
    if(m_currentCaptureState == BeginCaptureImage || m_currentCaptureState == FinishCaptureImage)
    {
        return getRect(m_beginPoint,m_endPoint);
    }
    else if(m_currentCaptureState == BeginMoveCaptureArea || m_currentCaptureState == FinishMoveCaptureArea)
    {
        return getMoveRect();
    }
    else if(m_currentCaptureState == BeginMoveStretchRect || m_currentCaptureState == FinishMoveStretchRect)
    {
        return getStretchRect();
    }

    return QRect(0,0,0,0);
}

void CCaptureScreenLabel::drawCaptureImage()
{
    //rectangle screenshot
    if(CapScr_Rectangle == m_enCaptureShape)
    {
        qDebug(" drawCaptureImage select area x=%d,y=%d",m_currentSelectRect.x(),m_currentSelectRect.y());
        m_capturePixmap = m_loadPixmap.copy(m_currentSelectRect);
        m_painter.drawPixmap(m_currentSelectRect.topLeft(),m_capturePixmap);
        m_painter.drawRect(m_currentSelectRect);
        drawStretchRect();
    }
    else if(CapScr_Ellipse == m_enCaptureShape)
    {
        //round screenshot
        m_painter.drawEllipse(m_currentSelectRect);

        QBitmap mask(m_currentSelectRect.size());
        QPainter maskPainter(&mask);

        maskPainter.setRenderHint(QPainter::Antialiasing);
        maskPainter.setRenderHint(QPainter::SmoothPixmapTransform);

        maskPainter.fillRect(0,0,m_currentSelectRect.width(),m_currentSelectRect.height(), Qt::white);
        maskPainter.setBrush(QColor(0, 0, 0));
        maskPainter.drawEllipse(0,0,m_currentSelectRect.width(),m_currentSelectRect.height());

        m_capturePixmap = m_loadPixmap.copy(m_currentSelectRect);
        m_capturePixmap.setMask(mask);
        drawStretchRect();
    }
    else
    {
        //polygon screenshot
        m_currentSelectRect = m_pPolygen->boundingRect();

        QBitmap mask(m_currentSelectRect.size());
        QPainter maskPainter(&mask);

        maskPainter.setRenderHint(QPainter::Antialiasing);
        maskPainter.setRenderHint(QPainter::SmoothPixmapTransform);

        maskPainter.fillRect(0,0,m_currentSelectRect.width(),m_currentSelectRect.height(), Qt::white);
        maskPainter.setBrush(QColor(0,0,0));
        //mask和m_pPolygen坐标系不同，需要对m_pPolygen进行坐标变换才可以在mask上绘制m_pPolygen，mask上的（0,0）其实是原图坐标的m_currentSelectRect.topLeft()
        maskPainter.drawPolygon(m_pPolygen->translated(-m_currentSelectRect.topLeft()));

        m_capturePixmap = m_loadPixmap.copy(m_currentSelectRect);
        m_capturePixmap.setMask(mask);
    }

}

void CCaptureScreenLabel::drawStretchRect()
{
    QColor color = QColor(0,174,255);

    QPoint topLeft = m_currentSelectRect.topLeft();
    QPoint topRight = m_currentSelectRect.topRight();
    QPoint bottomLeft = m_currentSelectRect.bottomLeft();
    QPoint bottomRight = m_currentSelectRect.bottomRight();

    QPoint leftCenter = QPoint(topLeft.x(),(topLeft.y() + bottomLeft.y())/2);
    QPoint topCenter = QPoint((topLeft.x() + topRight.x())/2,topLeft.y());
    QPoint rightCenter = QPoint(topRight.x(),leftCenter.y());
    QPoint bottomCenter = QPoint(topCenter.x(),bottomLeft.y());

    m_topLeftRect = QRect(topLeft.x() - STRETCH_RECT_WIDTH / 2,topLeft.y() - STRETCH_RECT_HEIGHT / 2,STRETCH_RECT_WIDTH,STRETCH_RECT_HEIGHT);
    m_topRightRect = QRect(topRight.x() - STRETCH_RECT_WIDTH / 2,topRight.y() - STRETCH_RECT_HEIGHT / 2,STRETCH_RECT_WIDTH,STRETCH_RECT_HEIGHT);
    m_bottomLeftRect = QRect(bottomLeft.x() - STRETCH_RECT_WIDTH / 2,bottomLeft.y() - STRETCH_RECT_HEIGHT / 2,STRETCH_RECT_WIDTH,STRETCH_RECT_HEIGHT);
    m_bottomRightRect = QRect(bottomRight.x() - STRETCH_RECT_WIDTH / 2, bottomRight.y() - STRETCH_RECT_HEIGHT / 2, STRETCH_RECT_WIDTH, STRETCH_RECT_HEIGHT);

    m_leftCenterRect = QRect(leftCenter.x() - STRETCH_RECT_WIDTH / 2, leftCenter.y() - STRETCH_RECT_HEIGHT / 2, STRETCH_RECT_WIDTH, STRETCH_RECT_HEIGHT);
    m_topCenterRect = QRect(topCenter.x() - STRETCH_RECT_WIDTH / 2, topCenter.y() - STRETCH_RECT_HEIGHT / 2, STRETCH_RECT_WIDTH, STRETCH_RECT_HEIGHT);
    m_rightCenterRect = QRect(rightCenter.x() - STRETCH_RECT_WIDTH / 2, rightCenter.y() - STRETCH_RECT_HEIGHT / 2, STRETCH_RECT_WIDTH, STRETCH_RECT_HEIGHT);
    m_bottomCenterRect = QRect(bottomCenter.x() - STRETCH_RECT_WIDTH / 2, bottomCenter.y() - STRETCH_RECT_HEIGHT / 2, STRETCH_RECT_WIDTH, STRETCH_RECT_HEIGHT);

    m_centerRect = QRect(topCenter.x() - STRETCH_RECT_WIDTH / 2,leftCenter.y() - STRETCH_RECT_HEIGHT / 2,STRETCH_RECT_WIDTH,STRETCH_RECT_HEIGHT);

    m_painter.fillRect(m_topLeftRect, color);
    m_painter.fillRect(m_topRightRect, color);
    m_painter.fillRect(m_bottomLeftRect, color);
    m_painter.fillRect(m_bottomRightRect, color);
    m_painter.fillRect(m_leftCenterRect, color);
    m_painter.fillRect(m_topCenterRect, color);
    m_painter.fillRect(m_rightCenterRect, color);
    m_painter.fillRect(m_bottomCenterRect, color);
    m_painter.fillRect(m_centerRect, color);
}

void CCaptureScreenLabel::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        //qDebug("esc quit");
        m_currentCaptureState = InitCapture;
        close();
    }

    if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
    {
        signalCompleteCapture(m_capturePixmap);
        close();
    }
}

QRect CCaptureScreenLabel::getRect(const QPoint &beginPoint,const QPoint &endPoint)
{
    int x,y,width,height;
    width = qAbs(beginPoint.x()-endPoint.x());
    height = qAbs(beginPoint.y()-endPoint.y());
    x = beginPoint.x() < endPoint.x() ? beginPoint.x() : endPoint.x();
    y = beginPoint.y() < endPoint.y() ? beginPoint.y() : endPoint.y();

    QRect selectedRect = QRect(x,y,width,height);

    if(selectedRect.width() == 0)
    {
        selectedRect.setWidth(1);
    }
    if(selectedRect.height() == 0)
    {
        selectedRect.setHeight(1);
    }

    return selectedRect;
}

QRect CCaptureScreenLabel::getMoveRect()
{
    QPoint movePoint = getMovePoint();
    qDebug("getMoveRect x=%d,y=%d",movePoint.x(),movePoint.y());
    QPoint beginPoint = m_beginPoint + movePoint;
    QPoint endPoint = m_endPoint + movePoint;

    if(m_currentCaptureState == FinishMoveCaptureArea)
    {
        m_beginPoint = beginPoint;
        m_endPoint = endPoint;
        m_beginMovePoint = QPoint(0,0);
        m_endMovePoint = QPoint(0,0);
    }

    return getRect(beginPoint,endPoint);
}

QPoint CCaptureScreenLabel::getMovePoint()
{
    qDebug("getMovePoint:::end point x=%d,y=%d,begin point x=%d,y=%d",m_endMovePoint.x(),m_endMovePoint.y(),m_beginMovePoint.x(),m_beginMovePoint.y());
    QPoint movePoint = m_endMovePoint - m_beginMovePoint;
    QRect currentRect = getRect(m_beginPoint,m_endPoint);

    if(currentRect.topLeft().x() + movePoint.x() < 0)
    {
        movePoint.setX(0 - currentRect.topLeft().x());
    }
    if(currentRect.topLeft().y() + movePoint.y() < 0)
    {
        movePoint.setY(0 - currentRect.topLeft().y());
    }
    if(currentRect.bottomRight().x() + movePoint.x() > m_screenWidth)
    {
        movePoint.setX(m_screenWidth - currentRect.bottomRight().x());
    }
    if(currentRect.bottomRight().y() + movePoint.y() > m_screenHeight)
    {
        movePoint.setY(m_screenHeight - currentRect.bottomRight().y());
    }

    return movePoint;
}

StretchRectState CCaptureScreenLabel::getStretchRectState(QPoint point)
{
    StretchRectState stretchRectState = NotSelect;
    if(m_topLeftRect.contains(point))
    {
        stretchRectState = TopLeftRect;
    }
    else if(m_topCenterRect.contains(point))
    {
        stretchRectState = TopCenterRect;
    }
    else if(m_topRightRect.contains(point))
    {
        stretchRectState = TopRightRect;
    }
    else if(m_rightCenterRect.contains(point))
    {
        stretchRectState = RightCenterRect;
    }
    else if(m_bottomCenterRect.contains(point))
    {
        stretchRectState = BottomCenterRect;
    }
    else if(m_bottomLeftRect.contains(point))
    {
        stretchRectState = BottomLeftRect;
    }
    else if(m_bottomRightRect.contains(point))
    {
        stretchRectState = BottomRightRect;
    }else if(m_leftCenterRect.contains(point))
    {
        stretchRectState = LeftCenterRect;
    }

    return stretchRectState;
}

void CCaptureScreenLabel::setStretchCursorStyle(StretchRectState stretchRectState)
{
    switch(stretchRectState)
    {
    case NotSelect:setCursor(Qt::ArrowCursor);break;
    case TopLeftRect:
    case BottomRightRect:setCursor(Qt::SizeFDiagCursor);break;
    case TopRightRect:
    case BottomLeftRect:setCursor(Qt::SizeBDiagCursor);break;
    case LeftCenterRect:
    case RightCenterRect:setCursor(Qt::SizeHorCursor);break;
    case TopCenterRect:
    case BottomCenterRect:setCursor(Qt::SizeVerCursor);break;
    default:break;
    }
}

QRect CCaptureScreenLabel::getStretchRect()
{
    QRect stretchRect;
    QRect currentRect = getRect(m_beginPoint,m_endPoint);
    switch(m_stretchRectState)
    {
    case NotSelect:
        stretchRect = getRect(m_beginPoint,m_endPoint);
        break;
    case TopLeftRect:
    {
        stretchRect = getRect(currentRect.bottomRight(),m_endMovePoint);
    }
        break;
    case TopRightRect:
    {
        QPoint beginPoint = QPoint(currentRect.topLeft().x(),m_endMovePoint.y());
        QPoint endPoint = QPoint(m_endMovePoint.x(),currentRect.bottomRight().y());
        stretchRect = getRect(beginPoint,endPoint);
    }
        break;
    case BottomLeftRect:
    {
        QPoint beginPoint = QPoint(m_endMovePoint.x(),currentRect.topLeft().y());
        QPoint endPoint = QPoint(currentRect.bottomRight().x(),m_endMovePoint.y());
        stretchRect = getRect(beginPoint,endPoint);
    }
        break;
    case BottomRightRect:
    {
        stretchRect = getRect(currentRect.topLeft(),m_endMovePoint);
    }
        break;
    case LeftCenterRect:
    {
        QPoint beginPoint = QPoint(m_endMovePoint.x(),currentRect.topLeft().y());
        stretchRect = getRect(beginPoint,currentRect.bottomRight());
    }
        break;
    case TopCenterRect:
    {
        QPoint beginPoint = QPoint(currentRect.topLeft().x(),m_endMovePoint.y());
        stretchRect = getRect(beginPoint,currentRect.bottomRight());
    }
        break;
    case RightCenterRect:
    {
        QPoint endPoint = QPoint(m_endMovePoint.x(),currentRect.bottomRight().y());
        stretchRect = getRect(currentRect.topLeft(),endPoint);
    }
        break;
    case BottomCenterRect:
    {
        QPoint endPoint = QPoint(currentRect.bottomRight().x(),m_endMovePoint.y());
        stretchRect = getRect(currentRect.topLeft(),endPoint);
    }
        break;
    default:
    {
        stretchRect = getRect(m_beginPoint,m_endPoint);
    }
        break;
    }

    if(m_currentCaptureState == FinishMoveStretchRect)
    {
        m_beginPoint = stretchRect.topLeft();
        m_endPoint = stretchRect.bottomRight();
    }

    return stretchRect;
}






























