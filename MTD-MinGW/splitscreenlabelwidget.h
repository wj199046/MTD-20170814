#ifndef SPLITSCREENLABELWIDGET_H
#define SPLITSCREENLABELWIDGET_H

#include <QApplication>
#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QLabel>
#include <QVector>
#include <QHBoxLayout>
#include<QGridLayout>
#include"ccapturescreenlabel.h"

class SplitScreenLabelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SplitScreenLabelWidget(QWidget *parent = 0);
    ~SplitScreenLabelWidget();

    void upDatePicture(QImage &image, int index);
    int  getCurrentColumn(int index);
    void clearLabelContent(int index);
    void setCaptureShape(int shape);

    void getImageList(QVector<QImage> &imageList);

protected:
    void dragEnterEvent(QDragEnterEvent *);
    void dragMoveEvent(QDragMoveEvent *);
    void dropEvent(QDropEvent *);

signals:
    void signalSendPrintScreen(QPixmap captureimage, QPoint top, QPoint bottom, QPoint labelPoint);
    void signalTempMeasCoordinate(QPoint top, QPoint bottom, QPoint);

private slots:
    void splitScreen(int count);
    void receivePicture(QPixmap pixmap, int columnIndex);
    void getColumn(int index);
    void slotCompleteCapture(QPixmap, QPoint, QPoint);
    void slotMouseRelease();

private:
    void resetScrollColumn();
    void clearAllLayoutContent(int layoutCount);

private:
    QGridLayout *m_pGLayout;

    CCaptureScreenLabel      *m_pLabelOne;
    CCaptureScreenLabel      *m_pLabelTwo;
    CCaptureScreenLabel      *m_pLabelThree;
    CCaptureScreenLabel      *m_pLabelFour;
    int                       m_scrollColumn[4]; //每个区域的图片对应图片展示区的列号
    int                       m_index;
};

#endif // SPLITSCREENLABELWIDGET_H
