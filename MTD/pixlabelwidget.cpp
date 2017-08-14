#include "pixlabelwidget.h"

PixLabel::PixLabel(QWidget *parent)
    : QWidget(parent)
{
    initVariable();
    initSetupUi();
}

PixLabel::~PixLabel()
{
    delete m_pLabelIcon;
    delete m_pLabelText;
    delete m_pHLayout;
}

void PixLabel::setPixmap(const QPixmap &pixmap)
{
    m_pLabelIcon->setPixmap(pixmap.scaled(QSize(40, 40), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void PixLabel::setText(const QString &text)
{
    m_pLabelText->setText(text);
}

void PixLabel::setMouseEnterFlag(bool flag)
{
    m_mouseEnterFlag = flag;
    this->update();
}

void PixLabel::setMousePressFlag(bool flag)
{
    m_mousePressFlag = flag;
    this->update();
}

void PixLabel::setTab(int indexTab)
{
    m_indexTab = indexTab;
}

int PixLabel::getTab()
{
    return m_indexTab;
}

//鼠标进入事件
void PixLabel::enterEvent(QEvent *)
{
    if(!getMousePressFlag())
    {
        setMouseEnterFlag(true);
    }
    this->setCursor(Qt::PointingHandCursor);
}

void PixLabel::leaveEvent(QEvent *)
{
    setMouseEnterFlag(false);
}

void PixLabel::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        setMousePressFlag(true);
        emit signalLabelPress(this);
    }
}

void PixLabel::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    if(getMouseEnterFlag())
    {
        paintWidget(50, &painter);
    }
    else if(getMousePressFlag())
    {
        paintWidget(80, &painter);
    }
    QWidget::paintEvent(e);
}

void PixLabel::initVariable()
{
    setMouseEnterFlag(false);
    setMousePressFlag(false);
}

void PixLabel::initSetupUi()
{
    createFrame();
    createWidget();
    createLayout();
}

void PixLabel::createFrame()
{
    this->setStyleSheet("QWidget{background:transparent; border:0px; color:black; font-weight:bold; font-size:16px;}");
}

void PixLabel::createWidget()
{
    m_pLabelIcon = new QLabel(this);
    m_pLabelText = new QLabel(this);
}

void PixLabel::createLayout()
{
    m_pHLayout = new QHBoxLayout;
    m_pHLayout->setSpacing(10);
    m_pHLayout->setContentsMargins(QMargins(55, 0, 5, 0));
    m_pHLayout->addWidget(m_pLabelIcon);
    m_pHLayout->addWidget(m_pLabelText);
    m_pHLayout->addStretch();

    this->setLayout(m_pHLayout);
}

void PixLabel::paintWidget(int transparency, QPainter *device)
{
    QPen pen(Qt::NoBrush, 1);
    device->setPen(pen);
    QLinearGradient linear(this->rect().topLeft(), this->rect().bottomLeft());
    //linear.setColorAt(0, QColor(255, 255, 255, transparency));
    linear.setColorAt(0, QColor(255, 0, 0, transparency));

    QBrush brush(linear);
    device->setBrush(brush);
    //device->drawRoundedRect(this->rect(), 2, 2);
    device->drawRoundedRect(this->rect(), 4, 4);
}

inline bool PixLabel::getMouseEnterFlag()
{
    return m_mouseEnterFlag;
}

inline bool PixLabel::getMousePressFlag()
{
    return m_mousePressFlag;
}
