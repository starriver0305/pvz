#include "pea.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
static int dx[8]={0,5,7,5,0,-5,-7,-5},dy[8]={7,5,0,-5,-7,-5,0,5};
Pea::Pea(int idx,double _x, double _y, int _r, int _injury, int _freeze,double _stronger)
{
    state=idx;
    x=_x;
    y=_y;
    rotate=_r;
    cnt=0;
    time1=0;
    injury=_injury;
    freeze=_freeze;
    stronger=_stronger;
    if(idx==0){
        movie=new QMovie(":/new/prefix1/pictures/绿豆.png");
        this->setScale(this->scale()*1.2);
    }
    else if(idx==1){
        movie=new QMovie(":/new/prefix1/pictures/冰豆.png");
        this->setScale(this->scale()*1.2);
    }
    else if(idx==2){
        movie=new QMovie(":/new/prefix1/pictures/火豆.gif");
        this->setScale(this->scale()*1.5);
    }
    else if(idx==3){
        movie=new QMovie(":/new/prefix1/pictures/ShroomBullet.gif");
        this->setScale(this->scale()*1.5);
    }
    movie->start();
}

Pea::~Pea()
{
    if(movie){
        delete movie;
    }
}

QRectF Pea::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void Pea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    if(state==3){
        painter->translate(0,0);
        painter->rotate(22.5*rotate);
        painter->translate(0,0);
    }
    QImage image;
    if(movie){
        image=movie->currentImage();
        painter->drawImage(QRectF(-10,-10,20,20),image);
    }
}

void Pea::advance(int phase)
{
    Q_UNUSED(phase)
    if(state==3){
        if(cnt==15){
            delete this;
            return;
        }
    }
    cnt++;
    if(!time1 || injury){
        x+=dx[rotate];
        y+=dy[rotate];
    }
    this->setPos(x,y);
    if(x>=1000){
        delete this;
        return;
    }
    QPoint point=this->scenePos().toPoint();
    QRectF rec(point.x()-100,point.y()-100,200,200);
    QList<QGraphicsItem*>items=se->items(rec);
    foreach (QGraphicsItem* item, items) {
        QPoint p=item->scenePos().toPoint();
        if(fabs(point.x()-p.x())<=10 && fabs(point.y()-p.y())<=70){
            BasicZombie *zombie=dynamic_cast<BasicZombie*>(item);
            if(zombie && zombie->hp>=0){
                if(!time1 || injury){
                    if(state==0){
                        zombie->hp-=50;
                        if(!zombie->freeze){
                            zombie->freeze=freeze;
                        }
                    }
                    else if(state==1){
                        zombie->hp-=50*stronger;
                        zombie->freeze=1;
                    }
                    else if(state==2){
                        zombie->hp-=100*stronger;
                        if(!zombie->freeze){
                            zombie->freeze=freeze;
                        }
                    }
                    time1=1;
                }
            }
        }
    }
    if(time1){
        if(state==1 && !injury){
            delete this;
            return;
        }
        if(time1==1){
            x+=30;
            if(state==0){
                PeaEffect *effect=new PeaEffect();
                effect->movie=new QMovie(":/new/prefix1/pictures/PeaBulletHit.gif");
                effect->movie->start();
                effect->setPos(this->scenePos());
                se->addItem(effect);
            }
            else if(state==2){
                PeaEffect *effect=new PeaEffect();
                effect->movie=new QMovie(":/new/prefix1/pictures/SputteringFire.gif");
                effect->movie->start();
                effect->setPos(this->scenePos());
                se->addItem(effect);
            }
            else if(state==3){
                PeaEffect *effect=new PeaEffect();
                effect->movie=new QMovie(":/new/prefix1/pictures/ShroomBulletHit.gif");
                effect->movie->start();
                effect->setPos(this->scenePos());
                se->addItem(effect);
            }
            if(!injury){
                delete this;
                return;
            }
        }
        time1++;
        if(time1==15){
            return;
        }
    }
    update();
}

