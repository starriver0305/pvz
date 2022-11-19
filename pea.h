#ifndef PEA_H
#define PEA_H
#include<QMovie>
#include<QPainter>
#include<QGraphicsItem>
#include<QTimer>
#include<QMouseEvent>
#include<QDebug>
#include<QGraphicsView>
#include"basiczombie.h"
#include"peaeffect.h"
class Pea:public QGraphicsItem
{
private:
    QMovie *movie;
    int state;
    int time1;
    int rotate;
    int cnt;
    int injury;
    int freeze;
    int stronger;
public:
    Pea(int idx=0,double _x=0, double _y=0, int _r=2, int _injury=0, int _freeze=0,double _stronger=1);
    ~Pea();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    double x,y;
};
#endif // PEA_H
