#ifndef ZOMBIESPUTTER_H
#define ZOMBIESPUTTER_H
#include"basiczombie.h"
#include"affix.h"
#include"bare.h"
#include"grass.h"
class ZombieSputter:public Affix
{
public:
    ZombieSputter();
    void advance(int phase);
};

#endif // ZOMBIESPUTTER_H
