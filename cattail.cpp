#include "cattail.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
extern int row[5],col[9];
static int dx[8]={-1,1,-1,1,1,-1,0,0},dy[8]={-1,-1,1,1,0,0,1,-1};
Cattail::Cattail(int _x, int _y):BasicPlant(_x,_y)
{
    movie=new QMovie(":/new/prefix1/pictures/Cattail/Cattail.gif");
    movie->start();
    time1=0;
    hp=thp=2200;
    speed=100;
}

QRectF Cattail::boundingRect() const
{
    return QRectF(-45,-45,90,90);
}

void Cattail::advance(int phase)
{
    Q_UNUSED(phase)
    if(!isset){
        return;
    }
    hp--;
    bool tag=0;
    for(int k=0;k<8;k++){
        for(int i=0;i<=9;i++){
            int x1=x+i*dx[k];
            int y1=y+i*dy[k];
            if(x1<0 || y1<0 || x1>=5 || y1>=9){
                continue;
            }
            if(row[x1] && col[y1]){
                tag=1;
            }
        }
    }
    if(tag){
        time1+=1;
        if(time1==10){
            Cactus *cactus1=new Cactus(0,this->scenePos().x()-30,this->scenePos().y()-20,injury,freeze,stronger);
            Cactus *cactus2=new Cactus(1,this->scenePos().x()-30,this->scenePos().y()-20,injury,freeze,stronger);
            Cactus *cactus3=new Cactus(2,this->scenePos().x()-30,this->scenePos().y()-20,injury,freeze,stronger);
            Cactus *cactus4=new Cactus(3,this->scenePos().x()-30,this->scenePos().y()-20,injury,freeze,stronger);
            se->addItem(cactus1);
            se->addItem(cactus2);
            se->addItem(cactus3);
            se->addItem(cactus4);
        }
        if(time1==20){
            Cactus *cactus1=new Cactus(0,this->scenePos().x()-30,this->scenePos().y()-20,injury,freeze,stronger);
            Cactus *cactus2=new Cactus(1,this->scenePos().x()-30,this->scenePos().y()-20,injury,freeze,stronger);
            Cactus *cactus3=new Cactus(2,this->scenePos().x()-30,this->scenePos().y()-20,injury,freeze,stronger);
            Cactus *cactus4=new Cactus(3,this->scenePos().x()-30,this->scenePos().y()-20,injury,freeze,stronger);
            se->addItem(cactus1);
            se->addItem(cactus2);
            se->addItem(cactus3);
            se->addItem(cactus4);
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

