#ifndef PEAEFFECT_H
#define PEAEFFECT_H
#include<QMovie>
#include<QPainter>
#include<QGraphicsItem>
#include<QTimer>
#include<QMouseEvent>
#include<QDebug>
#include<QGraphicsView>
class PeaEffect:public QGraphicsItem
{
public:
    PeaEffect();
    ~PeaEffect();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    QMovie *movie;
    int time1;
};

#endif // PEAEFFECT_H
