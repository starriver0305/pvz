#ifndef POLEVAULTINGZOMBIE_H
#define POLEVAULTINGZOMBIE_H
#include"basiczombie.h"
class PoleVaultingZombie:public BasicZombie
{
private:
    int flag1,flag2;
public:
    PoleVaultingZombie(int _r=0, int _c=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
};

#endif // POLEVAULTINGZOMBIE_H
