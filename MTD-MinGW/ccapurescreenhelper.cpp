#include "ccapurescreenhelper.h"


#define STRETCH_RECT_WIDTH 6
#define STRETCH_RECT_HEIGHT 6

CCapureScreenHelper::CCapureScreenHelper(QWidget *parent):
    QWidget(parent),
    m_currentCaptureState(InitCapture),
    m_enCaptureShape(CapScr_Rectangle),
    m_iCurrentSelectedAreaIdx(0),
    m_iNextSelectedAreaIdx(0)
{
    this->setMouseTracking(true);
    initStretchRect();
    m_pPolygen = new QPolygon();
    m_enMousePos = InOtherSelectedArea;
}

CCapureScreenHelper::~CCapureScreenHelper()
{
    delete m_pPolygen;
    qDebug("~CCapureScreenHelper：dddddddd");
}

void CCapureScreenHelper::setCaptureShape(CapScr_Shape captureShape)
{
    m_enCaptureShape = captureShape;
    m_currentCaptureState = CapScr_Polygon == m_enCaptureShape ? OnCapturePolygon : InitCapture;
}

void CCapureScreenHelper::init(const QPixmap & Image)
{
    m_loadPixmap = Image;
    m_screenHeight = m_loadPixmap.height();
    m_screenWidth = m_loadPixmap.width();
}

void CCapureScreenHelper::initStretchRect()
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


void CCapureScreenHelper::mousePressEvent(QMouseEvent *event)
{
    qDebug("mousePressEvent:m_currentCaptureState = %d",m_currentCaptureState);

    m_stretchRectState = getStretchRectState(event->pos());
    getMousePos(event->pos());

    if(Qt::RightButton == event->button())
    {
        resetSelectedArea();
        update();
        return;
    }



    if (m_astCapturedArea.isEmpty())
    {
        m_currentCaptureState = BeginCaptureImage;
        m_beginPoint = event->pos();
        return QWidget::mousePressEvent(event);
    }

    if (OutSelectedArea == m_enMousePos)
    {
        m_currentCaptureState = BeginCaptureImage;
        m_beginPoint = event->pos();
        return QWidget::mousePressEvent(event);
    }

    if (InCurSelectedArea == m_enMousePos)
    {
        //move captured area
        m_currentCaptureState = BeginMoveCaptureArea;
        m_beginMovePoint = event->pos();
        m_currentSelectRect = m_astCapturedArea[m_iCurrentSelectedAreaIdx].Area.boundingRect().toRect();
        m_originPath = m_astCapturedArea[m_iCurrentSelectedAreaIdx].Area;
        setCursor(Qt::SizeAllCursor);
    }

    if (InOtherSelectedArea == m_enMousePos)
    {
        m_currentCaptureState = ChangeCurSelectedArea;
    }

    if (OnStretchRect == m_enMousePos)
    {
        m_currentCaptureState = BeginMoveStretchRect;
        m_beginMovePoint = event->pos();
        m_originPath = m_astCapturedArea[m_iCurrentSelectedAreaIdx].Area;
    }

    return QWidget::mousePressEvent(event);
}


void CCapureScreenHelper::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug("mouseMoveEvent:event->pos() x=%d,y=%d",event->pos().x(),event->pos().y());

    //qDebug("mouseMoveEvent:m_currentCaptureState = %d",m_currentCaptureState);

    getMousePos(event->pos());
    setStretchCursorStyle(getStretchRectState(event->pos()));


    if (BeginCaptureImage == m_currentCaptureState)
    {
        m_currentCaptureState = InitCapture;
    }

    if (ChangeCurSelectedArea == m_currentCaptureState)
    {
        //m_currentCaptureState = InitCapture;
    }

    if (BeginMoveCaptureArea == m_currentCaptureState)
    {
        m_endMovePoint = event->pos();
        QPoint movePoint = getMovePoint();

        m_astCapturedArea[m_iCurrentSelectedAreaIdx].Area = m_originPath.translated(movePoint);
        updateStretchRectPos(m_astCapturedArea[m_iCurrentSelectedAreaIdx].Area.boundingRect().toRect());

        setCursor(Qt::SizeAllCursor);
        update();
    }

    if (BeginMoveStretchRect == m_currentCaptureState)
    {
        QPoint endPoint = keepPointInRange(event);
        m_endMovePoint = endPoint;

        QRect tmp = getStretchRect();
        stCapturedArea curArea;
        curArea.shape = m_enCaptureShape;
        curArea.Area.addRect(tmp);
        QFont textFont;
        textFont.setPointSize(14);
        curArea.Area.addText(tmp.x() + 10,tmp.y() + 20,textFont,QString::number(m_iCurrentSelectedAreaIdx,10));

        m_astCapturedArea.removeAt(m_iCurrentSelectedAreaIdx);
        m_astCapturedArea.insert(m_iCurrentSelectedAreaIdx,curArea);
        updateStretchRectPos(m_astCapturedArea[m_iCurrentSelectedAreaIdx].Area.boundingRect().toRect());

        update();
        setStretchCursorStyle(getStretchRectState(event->pos()));
    }

    return QWidget::mouseMoveEvent(event);
}

void CCapureScreenHelper::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug("mouseReleaseEvent:m_currentCaptureState = %d",m_currentCaptureState);

    if (BeginCaptureImage == m_currentCaptureState)
    {
        if (event->pos().x() + 100 > m_screenWidth || event->pos().y() + 100 > m_screenHeight)
        {
            m_currentCaptureState = FinishCaptureImage;
            return;
        }

        m_currentCaptureState = FinishCaptureImage;
        stCapturedArea curArea;
        curArea.shape = m_enCaptureShape;
        curArea.Area.addRect(QRect(m_beginPoint,QSize(100,100)));
        QFont textFont;
        textFont.setPointSize(14);
        curArea.Area.addText(m_beginPoint.x() + 10,m_beginPoint.y() + 20,textFont,QString::number(m_astCapturedArea.size(),10));
        m_astCapturedArea.append(curArea);
        m_iCurrentSelectedAreaIdx = m_astCapturedArea.size() -1;
        updateStretchRectPos(m_astCapturedArea[m_iCurrentSelectedAreaIdx].Area.boundingRect().toRect());

        update();
    }

    if (ChangeCurSelectedArea == m_currentCaptureState)
    {
        m_currentCaptureState = FinishCaptureImage;
        m_iCurrentSelectedAreaIdx = m_iNextSelectedAreaIdx;
        updateStretchRectPos(m_astCapturedArea[m_iCurrentSelectedAreaIdx].Area.boundingRect().toRect());
        update();
    }

    if (BeginMoveCaptureArea == m_currentCaptureState)
    {
        m_currentCaptureState = FinishMoveCaptureArea;
    }

    if (BeginMoveStretchRect == m_currentCaptureState)
    {
        m_currentCaptureState = FinishMoveStretchRect;
    }

    return QWidget::mouseReleaseEvent(event);
}

void CCapureScreenHelper::paintEvent(QPaintEvent *event)
{
    //qDebug("paintEvent:m_currentCaptureState = %d",m_currentCaptureState);

    if (FinishCaptureImage == m_currentCaptureState
            || BeginMoveCaptureArea == m_currentCaptureState
            || FinishMoveCaptureArea == m_currentCaptureState
            || BeginMoveStretchRect == m_currentCaptureState
            || FinishMoveStretchRect == m_currentCaptureState
            || ChangeCurSelectedArea == m_currentCaptureState)
//            || BeginCaptureImage == m_currentCaptureState)
    {
        m_painter.begin(this);
        m_painter.setPen(QPen(Qt::blue,1,Qt::SolidLine,Qt::FlatCap));

        for(int i = 0;i<m_astCapturedArea.size();i++)
        {
            m_painter.drawPath(m_astCapturedArea[i].Area);
        }
        drawStretchRect();
        m_painter.end();
    }

    return QWidget::paintEvent(event);
}


void CCapureScreenHelper::mouseDoubleClickEvent(QMouseEvent *event)
{

}

void CCapureScreenHelper::getMousePos(QPoint MousePos)
{
    if (NotSelect != m_stretchRectState)
    {
        m_enMousePos = OnStretchRect;
        return;
    }

    for(int i = 0;i<m_astCapturedArea.size();i++)
    {
        if (m_astCapturedArea[i].Area.contains(MousePos))
        {
            m_enMousePos = (i == m_iCurrentSelectedAreaIdx ? InCurSelectedArea : InOtherSelectedArea);
            m_iNextSelectedAreaIdx = i;
            return;
        }
    }

    m_enMousePos = OutSelectedArea;
    return;
}

void CCapureScreenHelper::updateStretchRectPos(QRect curSelectedArea)
{
    QPoint topLeft = curSelectedArea.topLeft();
    QPoint topRight = curSelectedArea.topRight();
    QPoint bottomLeft = curSelectedArea.bottomLeft();
    QPoint bottomRight = curSelectedArea.bottomRight();

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
}



/********************************************************************
* 函数名：keepPointInRange
* 功能：  限制节选框不会超出控件范围
* 参数：  QMouseEvent *event
* 返回值：QPoint
* 时间： 2017-8-11
* 作者： wangzhiping
*********************************************************************/
QPoint CCapureScreenHelper::keepPointInRange(QMouseEvent *event)
{
    QPoint adjustedMousePos = event->pos();

    if (event->pos().x() < 0)
    {
        adjustedMousePos.setX(0);
    }

    if (event->pos().x() > m_screenWidth)
    {
        adjustedMousePos.setX(m_screenWidth);
    }

    if (event->pos().y() < 0)
    {
        adjustedMousePos.setY(0);
    }

    if (event->pos().y() > m_screenHeight)
    {
        adjustedMousePos.setY(m_screenHeight);
    }

    return adjustedMousePos;
}





void CCapureScreenHelper::resetSelectedArea()
{
    initStretchRect();
    m_astCapturedArea.clear();
    m_iCurrentSelectedAreaIdx = 0;
    m_iNextSelectedAreaIdx = 0;
    m_currentSelectRect = QRect(0,0,0,0);

    m_currentCaptureState = FinishCapturePolygon == m_currentCaptureState ? OnCapturePolygon : InitCapture;

    m_pPolygen->clear();
    StretchRectVec.clear();
}














QRect CCapureScreenHelper::getSelectRect()
{
    if(BeginCaptureImage == m_currentCaptureState|| FinishCaptureImage == m_currentCaptureState)
    {
        return getRect(m_beginPoint,m_endPoint);
    }
    else if(BeginMoveCaptureArea == m_currentCaptureState || FinishMoveCaptureArea == m_currentCaptureState)
    {
        return getMoveRect();
    }
    else if(BeginMoveStretchRect == m_currentCaptureState|| FinishMoveStretchRect == m_currentCaptureState)
    {
        return getStretchRect();
    }

    return QRect(0,0,0,0);
}

void CCapureScreenHelper::drawCaptureImage()
{
    //rectangle screenshot
    if(CapScr_Rectangle == m_enCaptureShape)
    {
        //qDebug(" drawCaptureImage select area x=%d,y=%d",m_currentSelectRect.x(),m_currentSelectRect.y());
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

void CCapureScreenHelper::drawStretchRect()
{
    QColor color = QColor(0,174,255);

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

void CCapureScreenHelper::keyPressEvent(QKeyEvent *event)
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

QRect CCapureScreenHelper::getRect(const QPoint &beginPoint,const QPoint &endPoint)
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

QRect CCapureScreenHelper::getMoveRect()
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

QPoint CCapureScreenHelper::getMovePoint()
{
    //qDebug("getMovePoint:::end point x=%d,y=%d,begin point x=%d,y=%d",m_endMovePoint.x(),m_endMovePoint.y(),m_beginMovePoint.x(),m_beginMovePoint.y());
    QPoint movePoint = m_endMovePoint - m_beginMovePoint;
    //QRect currentRect = getRect(m_beginPoint,m_endPoint);
    QRect currentRect = m_currentSelectRect;

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

StretchRectState CCapureScreenHelper::getStretchRectState(QPoint point)
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

void CCapureScreenHelper::setStretchCursorStyle(StretchRectState stretchRectState)
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

QRect CCapureScreenHelper::getStretchRect()
{
    QRect stretchRect;
    //QRect currentRect = getRect(m_beginPoint,m_endPoint);
    QRect currentRect = m_originPath.boundingRect().toRect();
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






























