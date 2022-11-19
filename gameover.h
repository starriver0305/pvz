#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>
#include<QObject>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QMap>
#include<QPainter>
#include<QGraphicsSceneMouseEvent>
#include<QDebug>
#include<QPoint>
#include<queue>
#include"list.h"
#include"bare.h"
#include"grass.h"
class GameOver:public QGraphicsItem
{
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

public:
    GameOver();
signals:


public slots:

};

#endif // GAMAOVER_H
