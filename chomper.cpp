#include "chomper.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
Chomper::Chomper()
{
    hp=thp=500;
    state=0;
    speed=50;
    movie=new QMovie(":/new/prefix1/pictures/Chomper/Chomper.gif");
    movie->start();
}

QRectF Chomper::boundingRect() const
{
    return QRectF(-35,-60,80,110);
}

void Chomper::advance(int phase)
{
    Q_UNUSED(phase)
    if(!isset){
        return;
    }
    QPoint point=this->scenePos().toPoint();
    QRectF rec(point.x()-100,point.y()-100,200,200);
    QList<QGraphicsItem*>items=se->items(rec);
    if(state==1){
        time3=0;
        if(time1==0){
            delete movie;
            movie=new QMovie(":/new/prefix1/pictures/Chomper/ChomperAttack.gif");
            movie->start();
            if(speed!=50){
                movie->setSpeed(130);
            }
        }
        time1+=1;
        bool tag=0;
        foreach (QGraphicsItem* item, items) {
            QPoint p=item->scenePos().toPoint();
            if(fabs(point.x()-p.x())<=100 && fabs(point.y()-p.y())<=20){
                BasicZombie *zombie=dynamic_cast<BasicZombie*>(item);
                if(zombie){
                    hp--;
                    if(time1==speed && (!tag || injury)){
                        zombie->hp-=180*stronger;
                        if(!zombie->freeze){
                            zombie->freeze=freeze;
                        }
                    }
                    if(zombie->hp<=0){
                        zombie->eaten=1;
                        state=2;
                    }
                    if(fabs(point.x()-p.x())<=10 && fabs(point.y()-p.y())<=3){
                        zombie->state=1;
                    }
                    tag=1;
                }
            }
        }
        if(time1==speed){
            time1=0;
        }
        if(state!=2){
            state=tag;
        }
    }
    else if(state==0){
        if(time3==0){
            delete movie;
            movie=new QMovie(":/new/prefix1/pictures/Chomper/Chomper.gif");
            movie->start();
        }
        time3+=1;
        foreach (QGraphicsItem* item, items) {
            QPoint p=item->scenePos().toPoint();
            if(fabs(point.x()-p.x())<=100 && fabs(point.y()-p.y())<=20){
                BasicZombie *zombie=dynamic_cast<BasicZombie*>(item);
                if(zombie){
                    if(fabs(point.x()-p.x())<=10 && fabs(point.y()-p.y())<=3){
                        zombie->state=1;
                    }
                    state=1;
                }
            }
        }
    }
    else if(state==2){
        if(time2==0){
            delete movie;
            movie=new QMovie(":/new/prefix1/pictures/Chomper/ChomperDigest.gif");
            movie->start();
        }
        time2+=1;
        if(time2==1000){
            time2=0;
            state=0;
        }
        foreach (QGraphicsItem* item, items) {
            QPoint p=item->scenePos().toPoint();
            if(fabs(point.x()-p.x())<=10 && fabs(point.y()-p.y())<=3){
                BasicZombie *zombie=dynamic_cast<BasicZombie*>(item);
                if(zombie){
                    hp--;
                    zombie->state=1;
                }
            }
        }
    }
    update();
    if(hp<=0){
        foreach (QGraphicsItem* item, items) {
            QPoint p=item->scenePos().toPoint();
            if(fabs(point.x()-p.x())<=100 && fabs(point.y()-p.y())<=20){
                BasicZombie *zombie=dynamic_cast<BasicZombie*>(item);
                if(zombie){
                    zombie->state=0;
                }
            }
        }
        delete this;
    }
}

