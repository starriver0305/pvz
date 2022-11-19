#ifndef ZOMBIE_H
#define ZOMBIE_H
#include"basiczombie.h"
#include"footballzombie.h"
#include"coneheadzombie.h"
#include"bucktheadzombie.h"
class Zombie:public BasicZombie
{
private:
    int flag1,flag2;
public:
    Zombie(int _r=0, int _c=0);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // ZOMBIE_H
