#ifndef CCAPURESCREENHELPER_H
#define CCAPURESCREENHELPER_H

#include <QWidget>
#include<QPainter>
#include<QLabel>
#include <QPolygon>
#include<QVector>
#include<QMouseEvent>
#include<QPixmap>
#include<QBitmap>
#include<QRect>


enum CaptureState{
    InitCapture =0,
    BeginCaptureImage,
    FinishCaptureImage,
    ChangeCurSelectedArea,


    BeginMoveCaptureArea,
    FinishMoveCaptureArea,
    BeginMoveStretchRect,
    FinishMoveStretchRect,
    OnCapturePolygon,
    FinishCapturePolygon,
    AdjustPolygon,

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
    InCurSelectedArea = 0,
    InOtherSelectedArea,
    OutSelectedArea,
    OnStretchRect,
};

enum CapScr_Shape{
    CapScr_Rectangle = 0,//矩形
    CapScr_Ellipse,      //椭圆
    CapScr_Polygon,      //多边形
};

struct stCapturedArea
{
    QPainterPath    Area;
    CapScr_Shape    shape;
};

class CCapureScreenHelper : public QWidget
{
    Q_OBJECT
public:
    explicit CCapureScreenHelper(QWidget *parent = nullptr);
    ~CCapureScreenHelper();

signals:
    captureComplete(QPixmap,QPoint,QPoint);

public:

    void setCaptureShape(CapScr_Shape captureShape);
    void init(const QPixmap & Image);
    void resetSelectedArea();

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

    void mouseMoveEvent(QMouseEvent *event);


    void mouseDoubleClickEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

    void keyPressEvent(QKeyEvent *event);

    void paintEvent(QPaintEvent *event);
    void rectPaintEvent(QPaintEvent *event);
    void polygonPaintEvent(QPaintEvent *event);

    void getMousePos(QPoint);
    bool MouseOnStretchRect(QPoint);
    void updateStretchRectPos(QRect curSelectedArea);


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

    QVector<stCapturedArea> m_astCapturedArea;
    int m_iCurrentSelectedAreaIdx;
    int m_iNextSelectedAreaIdx;

    QPainterPath m_originPath;
};




#endif // CCAPURESCREENHELPER_H
