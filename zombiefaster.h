#ifndef ZOMBIEFASTER_H
#define ZOMBIEFASTER_H
#include"basiczombie.h"
#include"affix.h"
#include"bare.h"
#include"grass.h"
class ZombieFaster:public Affix
{
public:
    ZombieFaster();
    void advance(int phase);
};

#endif // ZOMBIEFASTER_H
