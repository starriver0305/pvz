#ifndef PLANTSTRONGER_H
#define PLANTSTRONGER_H
#include"basicplant.h"
#include"affix.h"
#include"bare.h"
#include"grass.h"
class PlantStronger:public Affix
{
public:
    PlantStronger();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PLANTSTRONGER_H
