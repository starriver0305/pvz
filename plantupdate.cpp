#include "plantupdate.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
extern Bare* bare[5][9];
extern Grass* grass[5][9];
PlantUpdate::PlantUpdate():Affix()
{
    movie=new QMovie(":/new/prefix1/pictures/PlantUpdate.png");
    movie->start();
}

void PlantUpdate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    Affix::mouseReleaseEvent(event);
    QList<QGraphicsItem*>items=se->items(rect);
    foreach(QGraphicsItem* item,items){
        Peashooter *peashooter=dynamic_cast<Peashooter*>(item);
        if(peashooter){
            int x=peashooter->x;
            int y=peashooter->y;
            delete peashooter;
            Grass *g=grass[x][y];
            GatlingPea *gatlingpea=new GatlingPea(x,y);
            se->addItem(gatlingpea);
            gatlingpea->setParentItem(g);
            delete this;
            return;
        }
        SnowPea *snowpea=dynamic_cast<SnowPea*>(item);
        if(snowpea){
            int x=snowpea->x;
            int y=snowpea->y;
            delete snowpea;
            Grass *g=grass[x][y];
            GatlingPea *gatlingpea=new GatlingPea(x,y);
            se->addItem(gatlingpea);
            gatlingpea->setParentItem(g);
            delete this;
            return;
        }
        Repeater *repeater=dynamic_cast<Repeater*>(item);
        if(repeater){
            int x=repeater->x;
            int y=repeater->y;
            delete repeater;
            Grass *g=grass[x][y];
            GatlingPea *gatlingpea=new GatlingPea(x,y);
            se->addItem(gatlingpea);
            gatlingpea->setParentItem(g);
            delete this;
            return;
        }
        GatlingPea *gatlingpea=dynamic_cast<GatlingPea*>(item);
        if(gatlingpea){
            gatlingpea->hp=2200;
            delete this;
            return;
        }
    }
}
