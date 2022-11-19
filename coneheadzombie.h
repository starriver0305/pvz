#ifndef CONEHEADZOMBIE_H
#define CONEHEADZOMBIE_H
#include"basiczombie.h"
class ConeheadZombie:public BasicZombie
{
private:
    int flag1,flag2,flag3;
public:
    ConeheadZombie(int _r=0, int _c=0);
    QRectF boundingRect() const;
    void advance(int phase);
};
#endif // CONEHEADZOMBIE_H
