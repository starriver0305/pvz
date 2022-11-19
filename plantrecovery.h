#ifndef PLANTRECOVERY_H
#define PLANTRECOVERY_H
#include"basicplant.h"
#include"affix.h"
#include"bare.h"
#include"grass.h"
class PlantRecovery:public Affix
{
public:
    PlantRecovery();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PLANTRECOVERY_H
