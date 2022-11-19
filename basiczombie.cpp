#include "basiczombie.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
extern int row[5],col[9];
extern Bare* bare[5][9];
extern int End;
void up(BasicZombie*);
BasicZombie::BasicZombie(int _x, int _y)
{
    r=_x,c=_y;
    time1=time2=0;
    attack=1;
    speed=0.5;
    eaten=0;
    tag1=tag2=0;
    fire=0;
    faster=0;
    movie=NULL;
    die=NULL;
    change=0;
    freeze=0;
    fast=0;
    flash=0;
    sputter=0;
    up1=up2=up3=0;
}

BasicZombie::~BasicZombie()
{
    if(movie){
        delete movie;
    }
    if(die){
        delete die;
    }
}

QRectF BasicZombie::boundingRect() const
{
    return QRectF(-45,-85,120,145);
}

void BasicZombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    if(freeze){
        freeze++;
    }
    if(freeze==150){
        freeze=0;
    }
    if(freeze){
        movie->setSpeed(60);
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
    painter->drawImage(boundingRect(),image);
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
        painter->drawImage(boundingRect(),image);
    }
    if(hp>0){
        QBrush brush(Qt::red);
        painter->setBrush(brush);
        double rate = (double)hp/thp;
        painter->drawRect(-10,-60,60*rate,7);
    }
}

void BasicZombie::advance(int phase)
{
    Q_UNUSED(phase)
    if(End){
        return;
    }
    if(x<0 || y<0){
        End=1;
        GameOver *gameover=new GameOver();
        gameover->setPos(600,350);
        se->addItem(gameover);
        return;
    }
    if(eaten && (!up1 && !up2 && !up3)){
        row[r]--;
        col[c]--;
        se->removeItem(this);
        delete this;
        return;
    }
    if(hp<=0){
        bool tag=up1 || up2 || up3;
        if(tag){
            up(this);
        }
        if(movie && freeze && !fire){
            movie->setSpeed(40);
        }
        if(die && freeze && !fire){
            die->setSpeed(60);
        }
        if(time2==0){
            row[r]--;
            col[c]--;
            if(!fire){
                setMovie(die1);
                setDie(die2);
            }
            else{
                movie=new QMovie(":/new/prefix1/pictures/Zombie/BoomDie.gif");
                movie->start();
            }
        }
        time2+=2;
        if(time2==300 && !fire){
            se->removeItem(this);
            delete this;
            return;
        }
        if(time2==500 && fire){
            se->removeItem(this);
            delete this;
            return;
        }
        if(!tag){
            update();
        }
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
}

void BasicZombie::setMovie(QString str)
{
    if(movie){
        delete movie;
    }
    movie=new QMovie(str);
    movie->start();
}

void BasicZombie::setDie(QString str)
{
    if(die){
        delete die;
    }
    die=new QMovie(str);
    die->start();
}

void BasicZombie::setSpeed()
{
    movie->setSpeed(300);
}

void BasicZombie::setFaster(int val)
{
    speed*=val;
}

void BasicZombie::move()
{
    if(End){
        return;
    }
    row[r]--;
    col[c]--;
    Bare *b=bare[x][y];
    QPoint pointer=this->pos().toPoint();
    QPoint p=b->pos().toPoint();
    if(fabs(p.x()-pointer.x())<=3 && fabs(p.y()-pointer.y())<=3){
        if(change==0){
            change=1;
            direction=b->ne;
        }
        r=x,c=y;
        switch(b->ne){
        case 0:y--;break;
        case 1:x--;break;
        case 2:x++;break;
        }
    }
    else{
        change=0;
    }
    if(freeze){
        speed/=2;
    }
    switch(direction){
    case 0:tag1+=speed;break;
    case 1:tag2-=speed;break;
    case 2:tag2+=speed;break;
    }
    if(freeze){
        speed*=2;
    }
    row[r]++;
    col[c]++;
    this->setPos(src1-tag1,src2+tag2);
}
