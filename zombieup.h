#ifndef ZOMBIEUP_H
#define ZOMBIEUP_H
#include"basiczombie.h"
#include"affix.h"
#include"bare.h"
#include"grass.h"
class ZombieUp:public Affix
{
public:
    ZombieUp(int _state);
    void advance(int phase);
    int state;
};

#endif // ZOMBIEUP_H
