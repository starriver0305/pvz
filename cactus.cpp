#include "cactus.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
Cactus::Cactus(int idx,double _x, double _y, int _injury, int _freeze, double _stronger)
{
    state=idx;
    x=_x;
    y=_y;
    injury=_injury;
    freeze=_freeze;
    stronger=_stronger;
    image=QImage(":/new/prefix1/pictures/猫扑子弹.png");
}
QRectF Cactus::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void Cactus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->translate(0,0);
    painter->rotate(45+90*state);
    painter->translate(0,0);
    painter->drawImage(QRectF(-10,-10,20,20),image);
}

void Cactus::advance(int phase)
{
    Q_UNUSED(phase)
    switch(state){
    case 0:x+=2.5,y+=2.5;break;
    case 1:x-=2.5,y+=2.5;break;
    case 2:x-=2.5;y-=2.5;break;
    case 3:x+=2.5,y-=2.5;break;
    }
    this->setPos(x,y);
    if(x>=1000 || x<=0 || y>=1000 || y<=0){
        delete this;
    }
    QPoint point=this->scenePos().toPoint();
    QRectF rec(point.x()-100,point.y()-100,200,200);
    QList<QGraphicsItem*>items=se->items(rec);
    foreach (QGraphicsItem* item, items) {
        QPoint p=item->scenePos().toPoint();
        if(fabs(point.x()-p.x())<=10 && fabs(point.y()-p.y())<=70){
            BasicZombie *zombie=dynamic_cast<BasicZombie*>(item);
            if(zombie){
                if(zombie->hp>0){
                    zombie->hp-=70*stronger;
                    if(!zombie->freeze){
                        zombie->freeze=freeze;
                    }
                    if(!injury){
                        delete this;
                        return;
                    }
                }
            }
        }
    }
}
