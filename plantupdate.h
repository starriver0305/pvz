#ifndef PLANTUPDATE_H
#define PLANTUPDATE_H
#include"affix.h"
#include"peashooter.h"
#include"snowpea.h"
#include"gatlingpea.h"
#include"bare.h"
#include"repeater.h"
#include"gatlingpea.h"
class PlantUpdate:public Affix
{
public:
    PlantUpdate();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PLANTUPDATE_H
