#ifndef CHOMPER_H
#define CHOMPER_H
#include"basicplant.h"
#include"basiczombie.h"
class Chomper:public BasicPlant
{
private:
    int state;
public:
    Chomper();
    QRectF boundingRect() const;
    void advance(int phase);
};
#endif // CHOMPER_H
