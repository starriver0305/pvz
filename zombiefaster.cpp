#include "zombiefaster.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
extern Bare* bare[5][9];
extern Grass* grass[5][9];
ZombieFaster::ZombieFaster():Affix()
{
    movie=new QMovie(":/new/prefix1/pictures/ZombieFaster.png");
    movie->start();
}

void ZombieFaster::advance(int phase)
{
    Q_UNUSED(phase);
    Affix::advance(phase);
    if(time1>=1000){
        return;
    }
    QPoint point=this->scenePos().toPoint();
    rect=QRectF(point.x()-10,point.y()-10,20,20);
    QList<QGraphicsItem*>items=se->items(rect);
    foreach(QGraphicsItem* item,items){
        BasicZombie *zombie=dynamic_cast<BasicZombie*>(item);
        if(zombie && !zombie->fast){
            zombie->speed*=2;
            zombie->fast=1;
            delete this;
            return;
        }
    }
}
