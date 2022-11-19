#ifndef BUCKTHEADZOMBIE_H
#define BUCKTHEADZOMBIE_H
#include"basiczombie.h"
class BucktheadZombie:public BasicZombie
{
private:
    int flag1,flag2,flag3;
public:
    BucktheadZombie(int _r=0, int _c=0);
    QRectF boundingRect() const;
    void advance(int phase);
};
#endif // BUCKTHEADZOMBIE_H
