#ifndef PEASHOOTER_H
#define PEASHOOTER_H
#include"basicplant.h"
#include"pea.h"
class Peashooter:public BasicPlant
{
public:
    Peashooter(int _x, int _y);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // PEASHOOTER_H
