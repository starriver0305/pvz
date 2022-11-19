#include "plantfaster.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
extern Bare* bare[5][9];
extern Grass* grass[5][9];
PlantFaster::PlantFaster()
{
    movie=new QMovie(":/new/prefix1/pictures/PlantFaster.png");
    movie->start();
}

void PlantFaster::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    Affix::mouseReleaseEvent(event);
    QList<QGraphicsItem*>items=se->items(rect);
    foreach(QGraphicsItem* item,items){
        BasicPlant *plant=dynamic_cast<BasicPlant*>(item);
        if(plant){
            plant->speed*=0.7;
            delete this;
            return;
        }
    }
}
