#include "planthurt.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
extern Bare* bare[5][9];
extern Grass* grass[5][9];
PlantHurt::PlantHurt()
{
    movie=new QMovie(":/new/prefix1/pictures/PlantHurt.png");
    movie->start();
}

void PlantHurt::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    Affix::mouseReleaseEvent(event);
    QList<QGraphicsItem*>items=se->items(rect);
    foreach(QGraphicsItem* item,items){
        BasicPlant *plant=dynamic_cast<BasicPlant*>(item);
        if(plant){
            plant->injury=1;
            delete this;
            return;
        }
    }
}

