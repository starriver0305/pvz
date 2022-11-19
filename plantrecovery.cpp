#include "plantrecovery.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
extern Bare* bare[5][9];
extern Grass* grass[5][9];
PlantRecovery::PlantRecovery()
{
    movie=new QMovie(":/new/prefix1/pictures/PlantRecovery.png");
    movie->start();
}

void PlantRecovery::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    Affix::mouseReleaseEvent(event);
    QList<QGraphicsItem*>items=se->items(rect);
    foreach(QGraphicsItem* item,items){
        BasicPlant *plant=dynamic_cast<BasicPlant*>(item);
        if(plant){
            plant->hp=plant->thp;
            delete this;
            return;
        }
    }
}
