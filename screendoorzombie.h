#ifndef SCREENDOORZOMBIE_H
#define SCREENDOORZOMBIE_H
#include"basiczombie.h"
class ScreenDoorZombie:public BasicZombie
{
private:
    int flag1,flag2,flag3;
public:
    ScreenDoorZombie(int _r=0, int _c=0);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // SCREENDOORZOMBIE_H
