#include "basicplant.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
extern int row[5],col[9];
BasicPlant::BasicPlant(int _x, int _y)
{
    x=_x;
    y=_y;
    time1=time2=time3=0;
    injury=0;
    freeze=0;
    isset=1;
    stronger=1;
}

BasicPlant::~BasicPlant()
{
    if(movie){
        delete movie;
    }
}

QRectF BasicPlant::boundingRect() const
{
    return QRectF(-40,-40,80,80);
}

void BasicPlant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
        painter->drawRect(-30,-35,60*rate,7);
    }
}

void BasicPlant::advance(int phase)
{
    Q_UNUSED(phase);
    update();
}
