#include "affix.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
Affix::Affix()
{
    time1=0;
}

Affix::~Affix()
{
    if(movie){
        delete movie;
    }
}

QRectF Affix::boundingRect() const
{
    return QRectF(-20,-20,40,40);
}

void Affix::advance(int phase)
{
    Q_UNUSED(phase);
    if(time1==1000){
        delete this;
        return;
    }
    time1++;
    update();
}

void Affix::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    prev=QCursor::pos();
}

void Affix::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    cur=QCursor::pos();
    QPoint point=this->scenePos().toPoint();
    int x=point.x()+cur.x()-prev.x();
    int y=point.y()+cur.y()-prev.y();
    rect=QRectF(x-20,y-20,40,40);
}

void Affix::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QImage image=movie->currentImage();
    painter->drawImage(boundingRect(),image);
}
