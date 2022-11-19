#ifndef BASICZOMBIE_H
#define BASICZOMBIE_H

#include<QMovie>
#include<QPainter>
#include<QGraphicsItem>
#include<QTimer>
#include<QMouseEvent>
#include<QDebug>
#include<QGraphicsView>
#include"bare.h"
#include"gameover.h"
class BasicZombie:public QGraphicsItem
{
protected:
    QMovie *movie;
    QMovie *die;
    int change;
public:
    BasicZombie(int x, int y);
    ~BasicZombie();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    void setMovie(QString str);
    void setDie(QString str);
    void setSpeed();
    void setFaster(int val);
    void move();
    int state;
    int hp;
    int thp;
    int x,y;
    double tag1,tag2;
    int r,c;
    int time1,time2;
    int eaten;
    int fire;
    int direction;
    double attack;
    double speed;
    int fast;
    int faster;
    int freeze;
    int flash;
    int sputter;
    int up1,up2,up3;
    double src1,src2;
    QString die1,die2;
};

#endif // BASICZOMBIE_H
