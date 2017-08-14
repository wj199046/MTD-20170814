#ifndef PIXLABELWIDGET_H
#define PIXLABELWIDGET_H

#include <QApplication>
#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QLabel>
#include <QVector>
#include <QHBoxLayout>
#include <QDebug>

class PixLabel : public QWidget
{
    Q_OBJECT
public:
    explicit PixLabel(QWidget *parent = 0);
    ~PixLabel();

    void setPixmap(const QPixmap &);
    void setText(const QString &);
    void setMouseEnterFlag(bool);
    void setMousePressFlag(bool);
    void setTab(int);
    int  getTab();

protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);

signals:
    void signalLabelPress(PixLabel *);

private:
    void initVariable();
    void initSetupUi();
    void createFrame();
    void createWidget();
    void createLayout();
    void paintWidget(int, QPainter *);
    bool getMouseEnterFlag();
    bool getMousePressFlag();

    bool m_mouseEnterFlag;
    bool m_mousePressFlag;

    QHBoxLayout *m_pHLayout;
    QLabel      *m_pLabelIcon;
    QLabel      *m_pLabelText;

    int          m_indexTab;
};

class UserLabel : public QLabel
{
    Q_OBJECT
public:
    UserLabel(QWidget *parent = 0) : QLabel(parent){}
    ~UserLabel(){}

protected:
    void mousePressEvent(QMouseEvent *e)
    {
        if(e->button() == Qt::LeftButton)
        {
            emit signalLabelPress(this);
        }
    }
signals:
    void signalLabelPress(UserLabel *);

};

#endif // PIXLABELWIDGET_H
