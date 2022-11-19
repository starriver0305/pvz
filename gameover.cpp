#include "gameover.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
//extern MainWindow w;
extern int a[5][9],vis[5][9];
extern Bare *bare[5][9];
extern int dx[3],dy[3];
int End=0;
using namespace std;
GameOver::GameOver()
{

}

QRectF GameOver::boundingRect() const
{
    return QRectF(-400,-300,800,600);
}

void GameOver::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QPixmap pixmap(":/new/prefix1/pictures/ZombiesWon.png");
    painter->drawPixmap(QRect(-400,-300,800,600),pixmap);
}

void GameOver::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    End=0;
    se->clear();
    for(int i=0;i<5;i++){
        for(int j=0;j<9;j++){
            vis[i][j]=0;
            if(a[i][j]){
                Grass *gra=new Grass(i,j);
                gra->setPos(255+j*78,130+i*104);
                se->addItem(gra);
            }
            else{
                Bare *b=new Bare(i,j);
                b->setPos(255+j*78,130+i*104);
                se->addItem(b);
                bare[i][j]=b;
            }
        }
    }
    queue<pair<int,int>>mq;
    for(int i=0;i<5;i++){
        if(!a[i][8]){
            mq.push({i,8});
        }
    }
    while(!mq.empty()){
        int x=mq.front().first;
        int y=mq.front().second;
        mq.pop();
        vis[x][y]=1;
        for(int i=0;i<3;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(x1<0 || y1<0 || x1>=5 || y1>=9 || a[x1][y1] || vis[x1][y1]){
                continue;
            }
            bare[x][y]->ne=i;
            mq.push({x1,y1});
        }
    }
    List *list=new List();
    list->setPos(410, 40);
    se->addItem(list);
}
