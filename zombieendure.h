#ifndef ZOMBIEENDURE_H
#define ZOMBIEENDURE_H
#include"basiczombie.h"
#include"affix.h"
#include"bare.h"
#include"grass.h"
class ZombieEndure:public Affix
{
public:
    ZombieEndure();
    void advance(int phase);
};
#endif // ZOMBIEENDURE_H
