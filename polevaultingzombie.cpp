#include "polevaultingzombie.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
extern Bare* bare[5][9];
extern int row[5],col[9];
PoleVaultingZombie::PoleVaultingZombie(int _r, int _c):BasicZombie(_r,_c)
{
    hp=thp=1000;
    state=2;
    flag1=flag2=0;
    setMovie(":/new/prefix1/pictures/PoleVaultingZombie/PoleVaultingZombie.gif");
    speed=0.65;
}
void PoleVaultingZombie::advance(int phase){
    Q_UNUSED(phase)
    if(eaten){
        row[r]--,col[c]--;
        delete this;
        return;
    }
    if(hp<=0){
        if(time1==0){
            row[r]--,col[c]--;
            if(movie){
                delete movie;
            }
            if(die){
                delete die;
            }
            if(!fire){
                movie=new QMovie(":/new/prefix1/pictures/PoleVaultingZombie/PoleVaultingZombieDie.gif");
                die=new QMovie(":/new/prefix1/pictures/PoleVaultingZombie/PoleVaultingZombieHead.gif");
                movie->start();
                die->start();
            }
            else{
                this->setScale(this->scale()*0.65);
                movie=new QMovie(":/new/prefix1/pictures/Zombie/BoomDie.gif");
                movie->start();
            }
        }
        time1+=2;
        if(time1==300 && !fire){
            delete this;
            return;
        }
        if(time1==500 && fire){
            delete this;
            return;
        }
        update();
        return;
    }
    if(x<0 || y<0){
        GameOver *gameover=new GameOver();
        gameover->setPos(600,350);
        se->addItem(gameover);
        return;
    }
    if(sputter){
        int _x=this->scenePos().x();
        int _y=this->scenePos().y();
        QList<QGraphicsItem*>items=se->items(QRectF(_x-60,_y-75,120,150));
        foreach(QGraphicsItem* item,items){
            BasicPlant *plant=dynamic_cast<BasicPlant*>(item);
            if(plant && plant->hp>0){
                plant->hp-=2;
            }
        }
    }
    if(state==1){
        if(flag1){
            update();
            return;
        }
        if(movie){
            delete movie;
        }
        movie=new QMovie(":/new/prefix1/pictures/PoleVaultingZombie/PoleVaultingZombieAttack.gif");
        movie->start();
        flag1=1;
        flag2=0;
        update();
        return;
    }
    else if(state==0){
        if(!flag2){
            if(movie){
                delete movie;
            }
            movie=new QMovie(":/new/prefix1/pictures/PoleVaultingZombie/PoleVaultingZombieWalk.gif");
            movie->start();
            flag2=1;
            flag1=0;
        }
    }
    if(hp>0){
        move();
    }
}
QRectF PoleVaultingZombie::boundingRect() const{
    return QRectF(-45,-75,140,130);
}
void PoleVaultingZombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option)
    Q_UNUSED(widget)
    if(freeze){
        freeze++;
    }
    qDebug()<<freeze;
    if(freeze==150){
        freeze=0;
    }
    QImage image=movie->currentImage();
    if(freeze && !fire){
        for(int i=0;i<image.height();i++){
            QRgb* line=(QRgb*)image.scanLine(i);
            for(int j=0;j<image.width();j++){
                if(line[j]==0){
                    continue;
                }
                image.setPixel(j,i,qRgb(qRed(line[j]),qGreen(line[j]),200));
            }
        }
    }
    painter->drawImage(QRectF(-100,-115,180,180),image);
    if(die){
        image=die->currentImage();
        if(freeze && !fire){
            for(int i=0;i<image.height();i++){
                QRgb* line=(QRgb*)image.scanLine(i);
                for(int j=0;j<image.width();j++){
                    if(line[j]==0){
                        continue;
                    }
                    image.setPixel(j,i,qRgb(qRed(line[j]),qGreen(line[j]),200));
                }
            }
        }
        painter->drawImage(QRectF(-100,-115,180,180),image);
    }
    if(hp>0){
        QBrush brush(Qt::red);
        painter->setBrush(brush);
        double rate = (double)hp/thp;
        painter->drawRect(-10,-60,60*rate,7);
    }
}

