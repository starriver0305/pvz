#ifndef ALLPLANTS_H
#define ALLPLANTS_H

#include <QWidget>
#include<QObject>
#include<QGraphicsItem>
#include<QMap>
#include<QPainter>
#include<QGraphicsSceneMouseEvent>
#include<QDebug>
#include<QPoint>
#include<QTimer>
#include<cmath>
#include"basicplant.h"
#include"cattail.h"
#include"peashooter.h"
#include"snowpea.h"
#include"cherrybomb.h"
#include"chomper.h"
#include"gatlingpea.h"
#include"gloomshroom.h"
#include"cattail.h"
#include"potatomine.h"
#include"repeater.h"
#include"spikerock.h"
#include"squash.h"
#include"tallnut.h"
#include "grass.h"
struct Card{
    QString name;
    int cost;
    int cooling;
    int id;
    Card(QString n="", int co=0, int cool=0, int i=0){
        name=n;
        cost=co;
        cooling=cool;
        id=i;
    }
};
class Allplants:public QGraphicsItem
{
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void advance(int phase);
    bool tag;
    BasicPlant *plant;
    Spikerock *rock;
public:
    Allplants(int idx);
    QMap<int,Card>mp;
    Card card;
    QPoint pointer;
    QPoint pos;
    int time;
};

#endif // ALLPLANTS_H
