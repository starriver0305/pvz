#ifndef PLANTFASTER_H
#define PLANTFASTER_H
#include"basicplant.h"
#include"affix.h"
#include"bare.h"
#include"grass.h"
class PlantFaster:public Affix
{
public:
    PlantFaster();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};
#endif // PLANTFASTER_H
