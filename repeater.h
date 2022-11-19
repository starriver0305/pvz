#ifndef REPEATER_H
#define REPEATER_H

#include"basicplant.h"
#include"pea.h"
class Repeater:public BasicPlant
{
public:
    Repeater(int _x, int _y);
    QRectF boundingRect() const;
    void advance(int phase);
};
#endif // REPEATER_H
