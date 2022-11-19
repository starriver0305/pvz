#ifndef GATLINGPEA_H
#define GATLINGPEA_H

#include"basicplant.h"
#include"pea.h"
class GatlingPea:public BasicPlant
{
public:
    GatlingPea(int _x=0, int _y=0);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // GATLINGPEA_H
