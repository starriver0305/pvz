#ifndef POTATOMINE_H
#define POTATOMINE_H

#include"basicplant.h"
#include"basiczombie.h"
class PotatoMine:public BasicPlant
{
private:
    QMovie *die;
    int state;
    int growth;
public:
    PotatoMine();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
};

#endif // POTATOMINE_H
