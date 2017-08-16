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

Q_SIGNALS:
    void signalCompleteCapture(QPixmap captureimage);

public:
    void setCaptureImage(const QPixmap &Image);
    void setCaptureShape(CapScr_Shape captureShape);
    void clearCaptureArea();

private:

    QVector<QPainterPath> m_SelectedArea;

    CCapureScreenHelper *m_pCapScrHelper;

};

#endif // CCAPTURESCREENLABEL_H
