#ifndef CACTUS_H
#define CACTUS_H

#include<QMovie>
#include<QPainter>
#include<QGraphicsItem>
#include<QTimer>
#include<QMouseEvent>
#include<QDebug>
#include<QGraphicsView>
#include"basiczombie.h"
class Zombie;
class Cactus:public QGraphicsItem
{
private:
    QImage image;
    int state;
    int injury;
    int freeze;
    double stronger;
public:
    Cactus(int idx=0,double _x=0, double _y=0, int _injury=0, int _freeze=0, double _stronger=1);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    double x,y;
};

#endif // CACTUS_H
