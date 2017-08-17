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
#include "ccapurescreenhelper.h"

class CCaptureScreenLabel : public QLabel
{
    Q_OBJECT
public:
    CCaptureScreenLabel(QWidget *parent = 0);
    ~CCaptureScreenLabel();

signals:
    void signalCompleteCapture(QPixmap,QPoint,QPoint);

public:
    void setCaptureImage(const QPixmap &Image);
    void setCaptureShape(CapScr_Shape captureShape);
    void clearCaptureArea();
    void clear();

private:

    QVector<QPainterPath> m_SelectedArea;

    CCapureScreenHelper *m_pCapScrHelper;

};

#endif // CCAPTURESCREENLABEL_H
