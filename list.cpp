#include "list.h"

QRectF List::boundingRect() const
{
    return QRectF(-260, -40, 520, 80);
}

void List::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QPixmap pixmap(":/new/prefix1/pictures/Shop.png");
    painter->drawPixmap(QRect(-260,-40,760,80),pixmap);
    QFont font;
    font.setBold(true);
    font.setPointSize(18);
    painter->setFont(font);
    painter->drawText(QRectF(-223,14,60,25),Qt::AlignCenter,"INF");
}

void List::advance(int phase)
{
    Q_UNUSED(phase)
    update();
}

List::List()
{
    for(int i=0;i<12;i++){
        Allplants *p=new Allplants(i);
        p->setParentItem(this);
        p->setPos(-115+53*i,0);
    }
}

