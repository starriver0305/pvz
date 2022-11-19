#include "peaeffect.h"

PeaEffect::PeaEffect()
{
    time1=0;
}

PeaEffect::~PeaEffect()
{
    if(movie){
        delete movie;
    }
}

QRectF PeaEffect::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void PeaEffect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QImage image=movie->currentImage();
    painter->drawImage(QRectF(-10,-10,20,20),image);
}

void PeaEffect::advance(int phase)
{
    Q_UNUSED(phase);
    time1++;
    if(time1==15){
        delete this;
    }
    update();
}
