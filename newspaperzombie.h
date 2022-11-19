#ifndef NEWSPAPERZOMBIE_H
#define NEWSPAPERZOMBIE_H
#include"basiczombie.h"
class NewspaperZombie:public BasicZombie
{
private:
    int flag1,flag2;
public:
    NewspaperZombie(int _r=0, int _c=0);
    QRectF boundingRect() const;
    void advance(int phase);
};

#endif // NEWSPAPERZOMBIE_H
