#ifndef PLANTHURT_H
#define PLANTHURT_H
#include"basicplant.h"
#include"affix.h"
#include"bare.h"
#include"grass.h"
class PlantHurt:public Affix
{
public:
    PlantHurt();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PLANTHURT_H
