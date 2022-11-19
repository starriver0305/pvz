#ifndef PLANTFREEZE_H
#define PLANTFREEZE_H
#include"basicplant.h"
#include"affix.h"
#include"bare.h"
#include"grass.h"
class PlantFreeze:public Affix
{
public:
    PlantFreeze();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PLANTFREEZE_H
