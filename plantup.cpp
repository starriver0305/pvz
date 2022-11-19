#include "plantup.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
extern Bare* bare[5][9];
extern Grass* grass[5][9];
PlantUp::PlantUp()
{
    movie=new QMovie(":/new/prefix1/pictures/PlantUp.gif");
    movie->start();
}

void PlantUp::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    Affix::mouseReleaseEvent(event);
    QList<QGraphicsItem*>items=se->items(rect);
    foreach(QGraphicsItem* item,items){
        BasicPlant *plant=dynamic_cast<BasicPlant*>(item);
        if(plant){
            plant->thp*=2;
            plant->hp=plant->thp;
            plant->freeze=1;
            plant->injury=1;
            plant->speed*=0.7;
            delete this;
            return;
        }
    }
}
