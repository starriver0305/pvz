#include "bare.h"

QRectF Bare::boundingRect() const
{
    return QRectF(-39,-52,78,104);
}

void Bare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QPixmap pixmap(":/new/prefix1/pictures/bare.png");
    painter->drawPixmap(QRect(-39,-52,78,104),pixmap);
}

Bare::Bare(int _r, int _c)
{
    ne=0;
    r=_r;
    c=_c;
}
