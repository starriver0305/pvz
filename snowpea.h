#ifndef SNOWPEA_H
#define SNOWPEA_H

#include"basicplant.h"
#include"pea.h"
class SnowPea:public BasicPlant
{
public:
    SnowPea(int _x=0, int _y=0);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // SNOWPEA_H
