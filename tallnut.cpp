#include "tallnut.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
TallNut::TallNut()
{
    hp=thp=2000;
    movie=new QMovie(":/new/prefix1/pictures/TallNut/TallNut.gif");
    movie->start();
}

QRectF TallNut::boundingRect() const
{
    return QRectF(-35,-45,70,90);
}

void TallNut::advance(int phase)
{
    Q_UNUSED(phase)
    if(!isset){
        return;
    }
    if(598<=hp && hp<=602){
        delete movie;
        movie=new QMovie(":/new/prefix1/pictures/TallNut/TallnutCracked1.gif");
        movie->start();
    }
    if(198<=hp && hp<=202){
        delete movie;
        movie=new QMovie(":/new/prefix1/pictures/TallNut/TallnutCracked2.gif");
        movie->start();
    }
    QPoint point=this->scenePos().toPoint();
    QRectF rec(point.x()-100,point.y()-100,200,200);
    QList<QGraphicsItem*>items=se->items(rec);
    foreach (QGraphicsItem* item, items) {
        QPoint p=item->scenePos().toPoint();
        if(fabs(point.x()-p.x())<=10 && fabs(point.y()-p.y())<=3){
            BasicZombie *zombie=dynamic_cast<BasicZombie*>(item);
            if(zombie){
                if(zombie->hp>0){
                    hp-=1;
                    zombie->state=1;
                    if(!zombie->freeze){
                        zombie->freeze=freeze;
                    }
                }
            }
        }
    }
    update();
    if(hp<=0){
        foreach (QGraphicsItem* item, items) {
            QPoint p=item->scenePos().toPoint();
            if(fabs(point.x()-p.x())<=10 && fabs(point.y()-p.y())<=3){
                BasicZombie *zombie=dynamic_cast<BasicZombie*>(item);
                if(zombie){
                    zombie->state=0;
                }
            }
        }
        delete this;
    }
}

