#ifndef CATTAIL_H
#define CATTAIL_H

#include"basicplant.h"
#include"basiczombie.h"
#include"cactus.h"
class Cattail:public BasicPlant
{
public:
    Cattail(int _x=0, int _y=0);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // CATTAIL_H
