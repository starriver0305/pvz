#ifndef PLANTUP_H
#define PLANTUP_H
#include"basicplant.h"
#include"affix.h"
#include"bare.h"
#include"grass.h"
class PlantUp:public Affix
{
public:
    PlantUp();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PLANTUP_H
