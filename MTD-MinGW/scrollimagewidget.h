#ifndef SCROLLIMAGEWIDGET_H
#define SCROLLIMAGEWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QtGui>
#include<QImage>

class scrollImageWidget : public QTableWidget
{
    Q_OBJECT

public:
    explicit scrollImageWidget(QWidget *parent = 0);

public:
    void addImage(const QPixmap pix, const QString& imgText);
    void setCurrentId(int id);
    int  getCurrentId();
    void replacePicture(int columnIndex, QImage image);
    void init(int count, bool isRowCount);

signals:
    void signal_currentColumn(int);

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

private:
    QPoint startPos;
    int    m_currentId;
    bool   m_bIsRowCount;//固定行数或者列数    
};

#endif // SCROLLIMAGEWIDGET_H
