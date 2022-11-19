#ifndef FOOTBALLZOMBIE_H
#define FOOTBALLZOMBIE_H
#include"basiczombie.h"
class FootBallZombie:public BasicZombie
{
private:
    int flag1,flag2,flag3;
public:
    FootBallZombie(int _r=0, int _c=0);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // FOOTBALLZOMBIE_H
