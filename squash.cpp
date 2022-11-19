#include "squash.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
Squash::Squash()
{
    movie=new QMovie(":/new/prefix1/pictures/Squash/Squash.gif");
    movie->start();
    state=0;
    hp=thp=1000;
}

QRectF Squash::boundingRect() const
{
    return QRectF(-35,-150,70,200);
}

void Squash::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QImage image=movie->currentImage();
    QRectF rect=boundingRect();
    painter->drawImage(QRectF(rect.x(),rect.y()+10,rect.width(),rect.height()-10),image);
    if(isset){
        QBrush brush(Qt::red);
        painter->setBrush(brush);
        double rate = (double)hp/thp;
        painter->drawRect(-30,-30,60*rate,7);
    }
}

void Squash::advance(int phase)
{
    Q_UNUSED(phase)
    if(!isset){
        return;
    }
    QPoint point=this->scenePos().toPoint();
    QRectF rec(point.x()-100,point.y()-100,200,200);
    QList<QGraphicsItem*>items=se->items(rec);
    if(state==0){
        foreach (QGraphicsItem* item, items) {
            QPoint p=item->scenePos().toPoint();
            if(fabs(point.x()-p.x())<=100 && fabs(point.y()-p.y())<=30){
                int tag=0;
                if(point.x()>p.x() && point.x()<=p.x()+90){
                    tag=1;
                }
                else if(point.x()<=p.x() && point.x()>=p.x()-20){
                    tag=2;
                }
                BasicZombie *zombie=dynamic_cast<BasicZombie*>(item);
                if(zombie && !state){
                    state=tag;
                }
            }
        }
    }
    else{
        if(time1==0){
            if(state==1){
                delete movie;
                movie=new QMovie(":/new/prefix1/pictures/Squash/SquashPreL.png");
                movie->start();
            }
            else{
                delete movie;
                movie=new QMovie(":/new/prefix1/pictures/Squash/SquashPreR.png");
                movie->start();
            }
        }
        if(time1==60){
            delete movie;
            movie=new QMovie(":/new/prefix1/pictures/Squash/SquashAttack.gif");
            movie->start();
        }
        if(time1==90){
            foreach (QGraphicsItem* item, items) {
                QPoint p=item->scenePos().toPoint();
                int x=point.x()-p.x();
                if(((x>=0 && x<=110) || (x<=0 && x>=-20)) && fabs(point.y()-p.y())<=50){
                    BasicZombie *zombie=dynamic_cast<BasicZombie*>(item);
                    if(zombie){
                        zombie->hp-=1200*stronger;
                    }
                }
            }
        }
        if(time1==140){
            delete this;
            return;
        }
        time1++;
    }
    update();
}

