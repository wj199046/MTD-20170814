#ifndef CCAPTURESCREENLABEL_H
#define CCAPTURESCREENLABEL_H

#include <QWidget>
#include<QPainter>
#include<QLabel>
#include <QPolygon>
#include<QVector>
#include<QMouseEvent>
#include<QPixmap>
#include<QBitmap>


enum CaptureState{
    InitCapture =0,
    BeginCaptureImage,
    FinishCaptureImage,
    BeginMoveCaptureArea,
    FinishMoveCaptureArea,
    BeginMoveStretchRect,
    FinishMoveStretchRect,
    OnCapturePolygon,
    FinishCapturePolygon,
    AdjustPolygon
};

enum StretchRectState{
    NotSelect = 0,
    TopLeftRect,
    TopRightRect,
    BottomLeftRect,
    BottomRightRect,
    LeftCenterRect,
    TopCenterRect,
    RightCenterRect,
    BottomCenterRect
};

enum MousePos{
    InSelectedArea = 0,
    OutSelectedArea,
    OnStretchRect,
};

enum CapScr_Shape{
    CapScr_Rectangle = 0,//矩形
    CapScr_Ellipse,      //椭圆
    CapScr_Polygon,      //多边形
};

class CCaptureScreenLabel : public QLabel
{
    Q_OBJECT
public:
    CCaptureScreenLabel(QWidget *parent = 0);
    ~CCaptureScreenLabel();

    void getPoint(QPoint &topLeftPoint, QPoint &bottomRightPoint);

Q_SIGNALS:
    void signalCompleteCapture(QPixmap captureimage);
    void signalMouseRelease();

public:
    void setCaptureImage(const QPixmap &Image);
    void setCaptureShape(CapScr_Shape captureShape);

private:

    void initStretchRect();

    QRect getRect(const QPoint &beginPoint,const QPoint &endPoint);
    QRect getMoveRect();
    QRect getStretchRect();

    bool isPressPointInSelectRect(QPoint mousePressPoint);
    QRect getSelectRect();
    QPoint getMovePoint();
    StretchRectState getStretchRectState(QPoint point);
    void setStretchCursorStyle(StretchRectState stretchRectState);

    void drawCaptureImage();
    void drawStretchRect();

    void mousePressEvent(QMouseEvent *event);
    QPoint keepPointInRange(QMouseEvent *event);
    void rectMousePressEvent(QMouseEvent *event);
    void polygonMousePressEvent(QMouseEvent *event);
    void mousePressCapturePolygon(QMouseEvent *event);
    void mousePressAdjustPolygon(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);
    void rectMouseMoveEvent(QMouseEvent *event);
    void polygonMouseMoveEvent(QMouseEvent *event);
    void mouseMoveAdjustAreaPos(QMouseEvent *event);
    void moveStretchRect(QPoint point);
    void mouseMoveAdjustStretchRect(QPoint point);

    void mouseDoubleClickEvent(QMouseEvent *event);
    void resetSelectedArea();
    void mouseReleaseEvent(QMouseEvent *event);
    void rectMouseReleaseEvent(QMouseEvent *event);
    void polygonMouseReleaseEvent(QMouseEvent *event);

    void keyPressEvent(QKeyEvent *event);

    void paintEvent(QPaintEvent *event);
    void rectPaintEvent(QPaintEvent *event);
    void polygonPaintEvent(QPaintEvent *event);

    void focusOutEvent(QFocusEvent *event);
    void getMousePos(QPoint);
    bool MouseOnStretchRect(QPoint);


private:
    QPixmap m_loadPixmap,m_capturePixmap;
    int m_screenWidth,m_screenHeight;
    QPoint m_beginPoint,m_endPoint,m_beginMovePoint,m_endMovePoint;
    QPainter m_painter;
    CaptureState m_currentCaptureState;
    QRect m_currentSelectRect;
    QRect m_topLeftRect,m_topRightRect,m_bottomLeftRect,m_bottomRightRect;
    QRect m_leftCenterRect,m_topCenterRect,m_rightCenterRect,m_bottomCenterRect,m_centerRect;

    StretchRectState m_stretchRectState;

    QPolygon *m_pPolygen;
    QVector<QRect> StretchRectVec;
    MousePos m_enMousePos;
    int m_adjustStretchRectIdx;
    CapScr_Shape m_enCaptureShape;
};

#endif // CCAPTURESCREENLABEL_H
