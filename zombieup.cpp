#include "zombieup.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
extern Bare* bare[5][9];
extern Grass* grass[5][9];
ZombieUp::ZombieUp(int _state)
{
    state=_state;
    if(state==2){
        movie=new QMovie(":/new/prefix1/pictures/ZombieUp1.png");
    }
    else if(state==1){
        movie=new QMovie(":/new/prefix1/pictures/ZombieUp2.png");
    }
    else if(state==3){
        movie=new QMovie(":/new/prefix1/pictures/ZombieUp3.png");
    }
    movie->start();
}

void ZombieUp::advance(int phase)
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
        switch(state){
        case 1:
            if(zombie && zombie->hp>0 && !zombie->up1){
                zombie->up1++;
                delete this;
                return;
            }
        case 2:
            if(zombie && zombie->hp>0 && !zombie->up2){
                zombie->up2++;
                delete this;
                return;
            }
        case 3:
            if(zombie && zombie->hp>0 && !zombie->up3){
                zombie->up3++;
                delete this;
                return;
            }
        }
    }
}
