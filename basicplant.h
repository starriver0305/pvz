#ifndef BASICPLANT_H
#define BASICPLANT_H
#include<QMovie>
#include<QPainter>
#include<QGraphicsItem>
#include<QTimer>
#include<QMouseEvent>
#include<QDebug>
#include<QGraphicsView>
class Spikerock;
class Allplants;
class BasicPlant:public QGraphicsItem
{
protected:
    QMovie *movie;
public:
    BasicPlant(int _x=0, int _y=0);
    ~BasicPlant();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    int speed;
    int hp;
    int thp;
    int x,y;
    int time1,time2,time3;
    int injury;
    int freeze;
    int isset;
    double stronger;
    friend class Allplants;
};

#endif // BASICPLANT_H
