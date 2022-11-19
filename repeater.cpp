#include "repeater.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
extern int row[5],col[9];
Repeater::Repeater(int _x, int _y):BasicPlant(_x,_y)
{
    movie=new QMovie(":/new/prefix1/pictures/Repeater/Repeater.gif");
    movie->start();
    hp=thp=2200;
    speed=100;
}

QRectF Repeater::boundingRect() const
{
    return QRectF(-35,-35,70,70);
}

void Repeater::advance(int phase)
{
    Q_UNUSED(phase)
    if(!isset){
        return;
    }
    hp--;
    if(row[x]){
        time1+=1;
        if(time1==10){
            if(freeze){
                Pea* pea=new Pea(2,this->scenePos().x()+20,this->scenePos().y()-13,2,injury,freeze,stronger);
                se->addItem(pea);
            }
            else{
                Pea* pea=new Pea(0,this->scenePos().x()+20,this->scenePos().y()-13,2,injury,freeze,stronger);
                se->addItem(pea);
            }
        }
        if(time1==20){
            if(freeze){
                Pea* pea=new Pea(2,this->scenePos().x()+20,this->scenePos().y()-13,2,injury,freeze,stronger);
                se->addItem(pea);
            }
            else{
                Pea* pea=new Pea(0,this->scenePos().x()+20,this->scenePos().y()-13,2,injury,freeze,stronger);
                se->addItem(pea);
            }
        }
        if(time1==speed){
            time1=0;
        }
    }
    else{
        time1=0;
    }
    update();
    if(hp<=0){
        delete this;
    }
}

