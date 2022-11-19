#ifndef LIST_H
#define LIST_H

#include<QGraphicsItem>
#include<QPainter>
#include<QDebug>
#include"allplants.h"
class List :public QGraphicsItem
{
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
public:
    List();
};



#endif // LISTS_H
