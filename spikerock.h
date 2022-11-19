#ifndef SPIKEROCK_H
#define SPIKEROCK_H

#include"basicplant.h"
#include"basiczombie.h"
class Spikerock:public BasicPlant
{
public:
    Spikerock();
    QRectF boundingRect() const;
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SPIKEROCK_H
