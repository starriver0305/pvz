#include "plantfreeze.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
extern Bare* bare[5][9];
extern Grass* grass[5][9];
PlantFreeze::PlantFreeze()
{
    movie=new QMovie(":/new/prefix1/pictures/PlantStronger.png");
    movie->start();
}

void PlantFreeze::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    Affix::mouseReleaseEvent(event);
    QList<QGraphicsItem*>items=se->items(rect);
    foreach(QGraphicsItem* item,items){
        BasicPlant *plant=dynamic_cast<BasicPlant*>(item);
        if(plant){
            plant->freeze=1;
            delete this;
            return;
        }
    }
}
