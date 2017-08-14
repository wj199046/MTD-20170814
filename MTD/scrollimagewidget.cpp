#include "scrollimagewidget.h"
#include<QApplication>
#include<QDebug>
#include"pixmapitemdele.h"
#include<QHeaderView>

#define W_ICONSIZE 196
#define H_ICONSIZE 196

scrollImageWidget::scrollImageWidget(QWidget *parent) :
    QTableWidget(parent), m_currentId(0)
{
    this->setItemDelegate(new PixmapItemdele());//设置委托

    //setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//去掉水平滚动条
    this->horizontalHeader()->setVisible(false);
    this->verticalHeader()->setVisible(false);
    this->setSelectionMode(this->NoSelection);
    this->setShowGrid(true);
    this->setFrameShape(QFrame::Box);
    this->setEditTriggers(this->SelectedClicked);
}

void scrollImageWidget::init(int count, bool isRowCount)
{
    m_bIsRowCount = isRowCount;

    if(true == isRowCount)
    {
        this->setRowCount(count);
        this->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应高度
    }
    else
    {
        this->setColumnCount(count);
        this->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应宽度
        this->horizontalHeader()->setHidden(true);//隐藏列号
    }
}


void scrollImageWidget::addImage(QPixmap &pix, const QString& strImgText)
{
    this->horizontalHeader()->setVisible(false);
    this->verticalHeader()->setVisible(false);

    this->setColumnCount(this->columnCount() + 1);
    this->setColumnWidth(columnCount() - 1, 100);
    this->setRowHeight(0, 100);
    QTableWidgetItem *item = new QTableWidgetItem();
    this->setItem(0, columnCount() - 1, item);
    item->setData(Qt::DisplayRole, QVariant::fromValue(QPixmap(pix).scaled(278, 330)));
}

void scrollImageWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        startPos = event->pos();
    QTableWidget::mousePressEvent(event);

    //发送信号，记录当前列号
    emit signal_currentColumn(this->currentColumn());
}

void scrollImageWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        int distance = (event->pos() - startPos).manhattanLength();
        if (distance >= QApplication::startDragDistance())
        {
            QTableWidgetItem *item = currentItem();
            if (item)
            {
                QMimeData *mimeData = new QMimeData;
                //mimeData->setText(item->text());
                //mimeData->setImageData(item->icon().pixmap(278, 330));
                mimeData->setImageData(item->data(Qt::DisplayRole));

                QDrag *drag = new QDrag(this);
                drag->setMimeData(mimeData);
                //QPixmap pix = item->data(Qt::DisplayRole).value<QPixmap>();
                //鼠标移动时的图片
                QImage image = qvariant_cast<QImage>(mimeData->imageData());
                drag->setPixmap(QPixmap::fromImage(image.scaled(100, 100)));

                if (drag->exec(Qt::CopyAction) == Qt::CopyAction)
                {
                    show();
                }
            }
        }
    }
    QTableWidget::mouseMoveEvent(event);
}

void scrollImageWidget::setCurrentId(int id)
{
    this->m_currentId = id;
}

int scrollImageWidget::getCurrentId()
{
    return this->m_currentId;
}

void scrollImageWidget::replacePicture(int columnIndex, QImage image)
{
    //先删除columnIndex对应的列
    this->removeColumn(columnIndex);
    this->insertColumn(columnIndex);
    QTableWidgetItem *item = new QTableWidgetItem();
    this->setItem(0, columnIndex, item);
    QPixmap pix = QPixmap::fromImage(image);
    item->setData(Qt::DisplayRole, QVariant::fromValue(QPixmap(pix).scaled(278, 330)));
}

