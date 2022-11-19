#ifndef GRASS_H
#define GRASS_H
#include<QPainter>
#include<QGraphicsItem>
#include<QDebug>
#include<QGraphicsSceneEvent>
class Grass: public QGraphicsItem
{
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
public:
    Grass(int _r, int _c);
    bool tag;
    int r,c;
};

#endif // GRASS_H
