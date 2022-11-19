#ifndef AFFIX_H
#define AFFIX_H
#include<QMovie>
#include<QPainter>
#include<QGraphicsItem>
#include<QTimer>
#include<QGraphicsSceneMouseEvent>
#include<QGraphicsView>
#include<QDebug>
class Affix:public QGraphicsItem
{
protected:
    QMovie *movie;
    int time1;
    QPoint prev,cur;
    QRectF rect;
public:
    Affix();
    ~Affix();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // AFFIX_H
