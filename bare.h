#ifndef BARE_H
#define BARE_H
#include<QPainter>
#include<QGraphicsItem>
#include<QDebug>
#include<QMouseEvent>
using namespace std;
class Bare: public QGraphicsItem
{
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
public:
    int ne;
    Bare(int _r, int _c);
    int r,c;
};

#endif // BARE_H
