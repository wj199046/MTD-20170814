#ifndef QPIXMAPITEMDELE_H
#define QPIXMAPITEMDELE_H

#include<QStyledItemDelegate>
#include<QPainter>

class PixmapItemdele : public QStyledItemDelegate
{
public:
    PixmapItemdele(QObject* parent = 0):QStyledItemDelegate(parent){ }
    //在委托类的paint中画图
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        if(index.data(Qt::DisplayRole).canConvert<QPixmap>())
        {
            QPixmap pix = index.data(Qt::DisplayRole).value<QPixmap>();
            painter->drawPixmap(option.rect,pix);
        }
        QStyledItemDelegate::paint(painter,option,index);
    }
};

#endif // QPIXMAPITEMDELE_H
