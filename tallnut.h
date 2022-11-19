#ifndef TALLNUT_H
#define TALLNUT_H

#include"basicplant.h"
#include"basiczombie.h"
class TallNut:public BasicPlant
{
public:
    TallNut();
    QRectF boundingRect() const;
    void advance(int phase);
};
#endif // TALLNUT_H
