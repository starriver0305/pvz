#ifndef SQUASH_H
#define SQUASH_H

#include"basicplant.h"
#include"basiczombie.h"
class Squash:public BasicPlant
{
private:
    int state;
public:
    Squash();
    QRectF boundingRect() const;
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SQUASH_H
