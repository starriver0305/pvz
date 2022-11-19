#include "cherrybomb.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
CherryBomb::CherryBomb()
{
    movie=new QMovie(":/new/prefix1/pictures/CherryBomb/CherryBomb.gif");
    movie->start();
}

QRectF CherryBomb::boundingRect() const
{
    return QRectF(-70,-70,140,140);
}

void CherryBomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QImage image=movie->currentImage();
    painter->drawImage(QRectF(-35,-35,70,70),image);
}

void CherryBomb::advance(int phase)
{
    Q_UNUSED(phase)
    if(!isset){
        return;
    }
    QPoint point=this->scenePos().toPoint();
    QRectF rec(point.x()-100,point.y()-100,200,200);
    QList<QGraphicsItem*>items=se->items(rec);
    if(time1==35){
        foreach (QGraphicsItem* item, items) {
            QPoint p=item->scenePos().toPoint();
            if(fabs(point.x()-p.x())<=150 && fabs(point.y()-p.y())<=150){
                BasicZombie *zombie=dynamic_cast<BasicZombie*>(item);
                if(zombie){
                    if(zombie->hp>0){
                        zombie->hp-=2000;
                    }
                    if(zombie->hp<=0){
                        zombie->fire=1;
                    }
                }
            }
        }
        delete movie;
        this->setScale(this->scale()*1.5);
        movie=new QMovie(":/new/prefix1/pictures/CherryBomb/Boom.gif");
        movie->start();
    }
    if(time1==100){
        delete this;
        return;
    }
    time1+=1;
    update();
}
