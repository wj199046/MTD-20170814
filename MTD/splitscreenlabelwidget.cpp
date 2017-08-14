#include"splitscreenlabelwidget.h"
#include<QDebug>
#include<QMimeData>

/********************************************************************
 * 函数名：SplitScreenLabelWidget
 * 功能：  构造函数
 * 参数：  QWidget
 * 返回值：无
 *
 * 时间： 2017-8-2
 * 作者：
 * *****************************************************************/
SplitScreenLabelWidget::SplitScreenLabelWidget(QWidget *parent)
    :  m_pGLayout(NULL), m_pLabelOne(NULL), m_pLabelTwo(NULL), m_pLabelThree(NULL), m_pLabelFour(NULL), QWidget(parent)
{
    m_pLabelOne = new CCaptureScreenLabel(this);
    m_pLabelOne->setFrameShape(QFrame::Box);    

    m_pLabelTwo = new CCaptureScreenLabel(this);
    m_pLabelTwo->setFrameShape(QFrame::Box);
    m_pLabelTwo->hide();

    m_pLabelThree = new CCaptureScreenLabel(this);
    m_pLabelThree->setFrameShape(QFrame::Box);
    m_pLabelThree->hide();

    m_pLabelFour = new CCaptureScreenLabel(this);
    m_pLabelFour->setFrameShape(QFrame::Box);
    m_pLabelFour->hide();

    connect(m_pLabelOne, SIGNAL(signalCompleteCapture(QPixmap)), this, SLOT(slotCompleteCapture(QPixmap)));
    connect(m_pLabelTwo, SIGNAL(signalCompleteCapture(QPixmap)), this, SLOT(slotCompleteCapture(QPixmap)));
    connect(m_pLabelThree, SIGNAL(signalCompleteCapture(QPixmap)), this, SLOT(slotCompleteCapture(QPixmap)));
    connect(m_pLabelFour, SIGNAL(signalCompleteCapture(QPixmap)), this, SLOT(slotCompleteCapture(QPixmap)));

    m_pGLayout = new QGridLayout;
    m_pGLayout->addWidget(m_pLabelOne);

    //设置间隔为0
    m_pGLayout->setSpacing(0);
    this->setLayout(m_pGLayout);
    setAcceptDrops(true);

    resetScrollColumn();
}

SplitScreenLabelWidget::~SplitScreenLabelWidget()
{
    if(NULL != m_pGLayout)
        delete m_pGLayout;
    if(NULL != m_pLabelOne)
        delete m_pLabelOne;
    if(NULL != m_pLabelTwo)
        delete m_pLabelTwo;
    if(NULL != m_pLabelThree)
        delete m_pLabelThree;
    if(NULL != m_pLabelFour)
        delete m_pLabelFour;
}

void SplitScreenLabelWidget::upDatePicture(QImage &image, int index)
{    
    switch(index)
    {
    case 1:
        m_pLabelOne->setPixmap(QPixmap::fromImage(image).scaled(278, 330));
        m_pLabelOne->setScaledContents(true);
        break;
    case 2:
        m_pLabelTwo->setPixmap(QPixmap::fromImage(image).scaled(278, 330));
        m_pLabelTwo->setScaledContents(true);
        break;
    case 3:
        m_pLabelThree->setPixmap(QPixmap::fromImage(image).scaled(278, 330));
        m_pLabelThree->setScaledContents(true);
        break;
    case 4:
        m_pLabelFour->setPixmap(QPixmap::fromImage(image).scaled(278, 330));
        m_pLabelFour->setScaledContents(true);
        break;
    default:
        break;
    }

}

int SplitScreenLabelWidget::getCurrentColumn(int index)
{
    return m_scrollColumn[index];
}

void SplitScreenLabelWidget::clearLabelContent(int index)
{
    switch(index)
    {
    case 1:
        m_pLabelOne->clear();
        break;
    case 2:
        m_pLabelTwo->clear();
        break;
    case 3:
        m_pLabelThree->clear();
        break;
    case 4:
        m_pLabelFour->clear();
        break;
    default:
        break;
    }
}
/********************************************************************
* 函数名：setCaptureShape
* 功能：  设置当前截图形状
* 参数：  count 分屏的个数
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*********************************************************************/
void SplitScreenLabelWidget::setCaptureShape(int shape)
{
    m_pLabelOne->setCaptureShape((CapScr_Shape)shape);
    m_pLabelTwo->setCaptureShape((CapScr_Shape)shape);
    m_pLabelThree->setCaptureShape((CapScr_Shape)shape);
    m_pLabelFour->setCaptureShape((CapScr_Shape)shape);
}

/********************************************************************
* 函数名：splitScreen
* 功能：  分屏
* 参数：  count 分屏的个数
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*********************************************************************/
void SplitScreenLabelWidget::splitScreen(int count)
{
    int itemCount = 0;
    itemCount = layout()->count();
    switch (count)
    {
    case 1:
        if(1 == itemCount) break;
        resetScrollColumn();
        clearAllLayoutContent(itemCount);
        for(int i = itemCount - 1; i > 0; --i)
        {
            QLayoutItem *item = this->layout()->takeAt(i);//取出布局中的item
            item->widget()->hide();
        }
        m_pGLayout->addWidget(m_pLabelOne);
        break;
    case 2:
        if(2 == itemCount) break;
        resetScrollColumn();
        clearAllLayoutContent(itemCount);
        if(itemCount < 2)
        {
            m_pLabelTwo->show();
        }
        else
        {
            for(int i = itemCount - 1; i > 1; --i)
            {
                QLayoutItem *item = this->layout()->takeAt(i);
                item->widget()->hide();
            }
        }
        m_pGLayout->addWidget(m_pLabelOne, 0, 0, 1, 1);
        m_pGLayout->addWidget(m_pLabelTwo, 0, 1, 1, 1);
        break;
    case 4:
        if(4 == itemCount) break;
        resetScrollColumn();
        clearAllLayoutContent(itemCount);
        if(itemCount < 4)
        {
            if(1 == itemCount) m_pLabelTwo->show();

            m_pLabelThree->show();
            m_pLabelFour->show();
        }
        m_pGLayout->addWidget(m_pLabelOne, 0, 0, 1, 1);
        m_pGLayout->addWidget(m_pLabelTwo, 0, 1, 1, 1);
        m_pGLayout->addWidget(m_pLabelThree, 1, 0, 1, 1);
        m_pGLayout->addWidget(m_pLabelFour, 1, 1, 1, 1);
        break;

    default:
        break;
    }
}

/********************************************************************
* 函数名：receivePicture
* 功能：  接受并且显示鼠标双击scrollimagewidget的图片，并且记录列号
* 参数：  pixmap 鼠标双击的图片
*        columnIndex 图片在scrollimagewidget区的列号
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*********************************************************************/
void SplitScreenLabelWidget::receivePicture(QPixmap &pixmap, int columnIndex)
{
    int itemCount = layout()->count();
    //如果one为空，先填one
    if(NULL == m_pLabelOne->pixmap() || 1 == itemCount)
    {
        m_pLabelOne->setCaptureImage(pixmap);
        m_scrollColumn[0] = columnIndex;//记录当前列号
        return;
    }
    if((itemCount > 1 && NULL == m_pLabelTwo->pixmap()) || 2 == itemCount)
    {
        m_pLabelTwo->setCaptureImage(pixmap);
        m_scrollColumn[1] = columnIndex;//记录当前列号
        return;
    }
    if(itemCount == 4 && NULL == m_pLabelThree->pixmap())
    {
        m_pLabelThree->setCaptureImage(pixmap);
        m_scrollColumn[2] = columnIndex;//记录当前列号
        return;
    }
    if(4 == itemCount)
    {
        m_pLabelFour->setCaptureImage(pixmap);
        m_scrollColumn[3] = columnIndex;//记录当前列号
        return;
    }
    return;
}

/********************************************************************
* 函数名：getColumn
* 功能：  槽函数，用于将scrollimagewidget中鼠标拖动的图片的列号记录下来
* 参数：  index 传递的列号
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*******************************************************************/
void SplitScreenLabelWidget::getColumn(int index)
{
    m_index = index;
}

/********************************************************************
* 函数名：slotCompleteCapture
* 功能：  槽函数，接收截图
* 参数：  captureimage 截取的图片
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*******************************************************************/
void SplitScreenLabelWidget::slotCompleteCapture(QPixmap captureimage)
{
    //将图片发送给主界面
    emit signalSendPrintScreen(captureimage);

}

/********************************************************************
* 函数名：resetScrollColumn
* 功能：  将记录scrollimagewidget中图片的列号的数组reset下
* 参数：  无
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*******************************************************************/
void SplitScreenLabelWidget::resetScrollColumn()
{
    m_scrollColumn[0] = -1;
    m_scrollColumn[1] = -1;
    m_scrollColumn[2] = -1;
    m_scrollColumn[3] = -1;
}

/********************************************************************
* 函数名：clearAllLayoutContent
* 功能：  清空布局中所有label的内容
* 参数：  layoutCount 布局中label个数
* 返回值：无
*
* 时间： 2017-8-9
* 作者：
*********************************************************************/
void SplitScreenLabelWidget::clearAllLayoutContent(int layoutCount)
{
    for(int i = 0; i < layoutCount; i++)
    {
        clearLabelContent(i + 1);
    }
}

void SplitScreenLabelWidget::dragEnterEvent(QDragEnterEvent *e)
{
    if (e->mimeData()->hasImage())
    {
        e->setDropAction(Qt::CopyAction);
        e->accept();
    }
}

void SplitScreenLabelWidget::dragMoveEvent(QDragMoveEvent *e)
{
    if (e->mimeData()->hasImage())
    {
        e->setDropAction(Qt::CopyAction);
        e->accept();
    }
}

void SplitScreenLabelWidget::dropEvent(QDropEvent *e)
{
    if (e->mimeData()->hasImage())
    {
        QImage image = qvariant_cast<QImage>(e->mimeData()->imageData());

        QPixmap pixmapToShow = QPixmap::fromImage(image.scaled(278, 330));

        QPoint eventPoint = e->pos();

        int itemCount = layout()->count();

        QRect labelOneRect(m_pLabelOne->frameGeometry().topLeft(), m_pLabelOne->frameGeometry().bottomRight());

        if(2 == itemCount)
        {
            QRect labelTwoRect(m_pLabelTwo->frameGeometry().topLeft(), m_pLabelTwo->frameGeometry().bottomRight());
            if(labelTwoRect.contains(eventPoint))
            {
                m_pLabelTwo->setCaptureImage(pixmapToShow);

                m_scrollColumn[1] = m_index;
            }
        }
        if(4 == itemCount)
        {
            QRect labelTwoRect(m_pLabelTwo->frameGeometry().topLeft(), m_pLabelTwo->frameGeometry().bottomRight());
            QRect labelThreeRect(m_pLabelThree->frameGeometry().topLeft(), m_pLabelThree->frameGeometry().bottomRight());
            QRect labelFourRect(m_pLabelFour->frameGeometry().topLeft(), m_pLabelFour->frameGeometry().bottomRight());
            if(labelTwoRect.contains(eventPoint))
            {
                m_pLabelTwo->setCaptureImage(pixmapToShow);
                m_scrollColumn[1] = m_index;
            }
            if(labelThreeRect.contains(eventPoint))
            {
                m_pLabelThree->setCaptureImage(pixmapToShow);
                m_scrollColumn[2] = m_index;
            }
            if(labelFourRect.contains(eventPoint))
            {
                m_pLabelFour->setCaptureImage(pixmapToShow);
                m_scrollColumn[3] = m_index;
            }
        }
        if(labelOneRect.contains(eventPoint))
        {
            m_pLabelOne->setCaptureImage(pixmapToShow);
            m_scrollColumn[0] = m_index;
        }
        e->setDropAction(Qt::CopyAction);
        e->accept();
    }
}
