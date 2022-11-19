#include "allplants.h"
#include "mainwindow.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
extern QTimer *timer;
Allplants::Allplants(int idx)
{
    mp[0]={"Peashooter",100,500,0};
    mp[1]={"SnowPea",175,775,1};
    mp[2]={"Repeater",200,500,2};
    mp[3]={"GatlingPea",225,1000,3};
    mp[4]={"TallNut",175,1000,4};
    mp[5]={"PotatoMine",25,1000,5};
    mp[6]={"CherryBomb",125,1000,6};
    mp[7]={"Chomper",150,1000,7};
    mp[8]={"Squash",50,1000,8};
    mp[9]={"Spikerock",200,1000,9};
    mp[10]={"GloomShroom",225,1000,10};
    mp[11]={"Cattail",175,1000,11};
    card=mp[idx];
    time=0;
}

QRectF Allplants::boundingRect() const{
    return QRectF(-30,-50,60,100);
}

void Allplants::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QImage image;
    if(card.id==0){
        image=QImage(":/new/prefix1/pictures/card/peashooter.png");
    }
    else if(card.id==1){
        image=QImage(":/new/prefix1/pictures/card/snowpea.png");
    }
    else if(card.id==2){
        image=QImage(":/new/prefix1/pictures/card/repeater.png");
    }
    else if(card.id==3){
        image=QImage(":/new/prefix1/pictures/card/gatlingpea.png");
    }
    else if(card.id==4){
        image=QImage(":/new/prefix1/pictures/card/tallnut.png");
    }
    else if(card.id==5){
        image=QImage(":/new/prefix1/pictures/card/potatomine.png");
    }
    else if(card.id==6){
        image=QImage(":/new/prefix1/pictures/card/cherrybomb.png");
    }
    else if(card.id==7){
        image=QImage(":/new/prefix1/pictures/card/chomper.png");
    }
    else if(card.id==8){
        image=QImage(":/new/prefix1/pictures/card/squash.png");
    }
    else if(card.id==9){
        image=QImage(":/new/prefix1/pictures/card/spilerock.png");
    }
    else if(card.id==10){
        image=QImage(":/new/prefix1/pictures/card/gloomshroom.png");
    }
    else if(card.id==11){
        image=QImage(":/new/prefix1/pictures/card/cattail.png");
    }
    double rate=(double)time/card.cooling;
    for(int i=0;i<image.height()*rate;i++){
        QRgb* line=(QRgb*)image.scanLine(i);
        for(int j=0;j<image.width();j++){
            int average=(qRed(line[j])+qBlue(line[j])+qGreen(line[j]))/15;
            image.setPixel(j,i,qRgba(average,average,average,200));
        }
    }
    painter->drawImage(QRect(-27,-34,54,68),image);
}

void Allplants::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    if(time!=0){
        return;
    }
    pointer=QCursor::pos();
    if(card.id==0){
        plant=new Peashooter(0,0);
    }
    if(card.id==1){
        plant=new SnowPea(0,0);
    }
    if(card.id==2){
        plant=new Repeater(0,0);
    }
    if(card.id==3){
        plant=new GatlingPea(0,0);
    }
    if(card.id==4){
        plant=new TallNut();
    }
    if(card.id==5){
        plant=new PotatoMine();
    }
    if(card.id==6){
        plant=new CherryBomb();
    }
    if(card.id==7){
        plant=new Chomper();
    }
    if(card.id==8){
        plant=new Squash();
    }
    if(card.id==9){
        plant=new Spikerock();
    }
    if(card.id==10){
        plant=new GloomShroom();
    }
    if(card.id==11){
        plant=new Cattail(0,0);
    }
    QString str=":/new/prefix1/pictures/"+card.name+"/"+card.name+".gif";
    plant->isset=0;
    plant->movie=new QMovie(str);
    plant->movie->start();
    plant->movie->stop();
    se->addItem(plant);
}

void Allplants::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    if(time!=0){
        return;
    }
    QPoint point=QCursor::pos();
    int x=this->scenePos().x()+point.x()-pointer.x();
    int y=this->scenePos().y()+point.y()-pointer.y();
    plant->setPos(x,y);
}

void Allplants::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    if(time!=0){
        return;
    }
    QPoint point=QCursor::pos();
    int x=this->scenePos().x()+point.x()-pointer.x();
    int y=this->scenePos().y()+point.y()-pointer.y();
    QList<QGraphicsItem*>items=se->items(QRectF(x-10,y-10,20,20));
    int tag=0;
    foreach (QGraphicsItem* item, items) {
        Grass *g=dynamic_cast<Grass*>(item);
        Bare *b=dynamic_cast<Bare*>(item);
        if(g||b){
            if(!tag){
                if(card.id==0){
                    if(!g){
                        delete plant;
                        return;
                    }
                    Peashooter *shooter=new Peashooter(g->r,g->c);
                    shooter->setParentItem(g);
                    tag=1;
                }
                if(card.id==1){
                    if(!g){
                        delete plant;
                        return;
                    }
                    SnowPea *snowpea=new SnowPea(g->r,g->c);
                    snowpea->setParentItem(g);
                    tag=1;
                }
                if(card.id==2){
                    if(!g){
                        delete plant;
                        return;
                    }
                    Repeater *repeater=new Repeater(g->r,g->c);
                    repeater->setParentItem(g);
                    tag=1;
                }
                if(card.id==3){
                    if(!g){
                        delete plant;
                        return;
                    }
                    GatlingPea *gatlingpea=new GatlingPea(g->r,g->c);
                    gatlingpea->setParentItem(g);
                    tag=1;
                }
                if(card.id==4){
                    if(!b){
                        delete plant;
                        return;
                    }
                    TallNut *tallnut=new TallNut();
                    tallnut->setParentItem(b);
                    tag=1;
                }
                if(card.id==5){
                    if(!b){
                        delete plant;
                        return;
                    }
                    PotatoMine *potatomine=new PotatoMine();
                    potatomine->setParentItem(b);
                    tag=1;
                }
                if(card.id==6){
                    if(!b){
                        delete plant;
                        return;
                    }
                    CherryBomb *cherrybomb=new CherryBomb();
                    cherrybomb->setParentItem(b);
                    tag=1;
                }
                if(card.id==7){
                    if(!b){
                        delete plant;
                        return;
                    }
                    Chomper *chomper=new Chomper();
                    chomper->setParentItem(b);
                    tag=1;
                }
                if(card.id==8){
                    if(!b){
                        delete plant;
                        return;
                    }
                    Squash *squash=new Squash();
                    squash->setParentItem(b);
                    tag=1;
                }
                if(card.id==9){
                    if(!b){
                        delete plant;
                        return;
                    }
                    Spikerock *spikerock=new Spikerock();
                    spikerock->setParentItem(b);
                    tag=1;
                }
                if(card.id==10){
                    if(!g){
                        delete plant;
                        return;
                    }
                    GloomShroom *gloomshroom=new GloomShroom();
                    gloomshroom->setParentItem(g);
                    tag=1;
                }
                if(card.id==11){
                    if(!g){
                        delete plant;
                        return;
                    }
                    Cattail *cattail=new Cattail(g->r,g->c);
                    cattail->setParentItem(g);
                    tag=1;
                }
            }
        }
    }
    if(tag){
        this->time=this->card.cooling;
    }
    delete plant;
}

void Allplants::advance(int phase)
{
    Q_UNUSED(phase);
    QList<QGraphicsItem*>count=se->items(QRectF(-1000,-1000,2000,2000));
    timer->start(20);
    qDebug()<<count.size();
    if(time>0){
        time--;
    }
    update();
}

