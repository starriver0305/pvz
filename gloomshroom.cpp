#include "gloomshroom.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
using namespace std;
GloomShroom::GloomShroom()
{
    movie=new QMovie(":/new/prefix1/pictures/GloomShroom/GloomShroom.gif");
    movie->start();
    time1=-1;
    hp=thp=2200;
    speed=70;
}

QRectF GloomShroom::boundingRect() const
{
    return QRectF(-40,-40,80,80);
}

void GloomShroom::advance(int phase)
{
    Q_UNUSED(phase)
    if(!isset){
        return;
    }
    hp--;
    QPoint point=this->scenePos().toPoint();
    QRectF rec(point.x()-60,point.y()-100,120,200);
    QList<QGraphicsItem*>items=se->items(rec);
    bool tag=0;
    foreach (QGraphicsItem* item, items) {
        BasicZombie *zombie=dynamic_cast<BasicZombie*>(item);
        if(zombie){
            if(zombie->hp>0 && (!tag ||injury)){
                if(speed==70){
                    zombie->hp-=2*stronger;
                }
                else{
                    zombie->hp-=3*stronger;
                }
                if(!zombie->freeze){
                    zombie->freeze=freeze;
                }
                tag=1;
            }
        }
    }
    if(tag){
        if(time1<=0){
            delete movie;
            movie=new QMovie(":/new/prefix1/pictures/GloomShroom/GloomShroomAttack.gif");
            movie->start();
        }
        if(time1==10){
            for(int i=0;i<8;i++){
                Pea *bullet=new Pea(3,this->scenePos().x(),this->scenePos().y(),i);
                se->addItem(bullet);
            }
        }
        if(time1==20){
            for(int i=0;i<8;i++){
                Pea *bullet=new Pea(3,this->scenePos().x(),this->scenePos().y(),i);
                se->addItem(bullet);
            }
        }
        if(time1==30){
            for(int i=0;i<8;i++){
                Pea *bullet=new Pea(3,this->scenePos().x(),this->scenePos().y(),i);
                se->addItem(bullet);
            }
        }
        time1++;
        if(time1==speed){
            time1=0;
        }
    }
    else{
        if(time1!=-1){
            time1=-1;
            delete movie;
            movie=new QMovie(":/new/prefix1/pictures/GloomShroom/GloomShroom.gif");
            movie->start();
        }
    }
    update();
    if(hp<=0){
        delete this;
    }
}

