#include "mainwindow.h"
#include "ui_mainwindow.h"
int id;
QTimer *timer;
extern QGraphicsScene *se;
extern QGraphicsView *vw;
int dx[3]={0,-1,1},dy[3]={-1,0,0};
Bare* bare[5][9];
Grass* grass[5][9];
int a[5][9],vis[5][9];
extern int row[5],col[9];
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    se=new QGraphicsScene(this);
    vw = new QGraphicsView(se, this);
    se->setSceneRect(150,0, 800, 600);
    se->setItemIndexMethod(QGraphicsScene::NoIndex);
    vw->resize(805, 605);
    vw->setRenderHint(QPainter::Antialiasing);
    QImage image(":/new/prefix1/pictures/backgroud.png");
    image = image.scaled(1000,620);
    vw->setBackgroundBrush(image);
    ifstream i_file("C:\\Users\\13564\\Desktop\\test.txt",ios::in);
    for(int i=0;i<5;i++){
        for(int j=0;j<9;j++){
            i_file>>a[i][j];
            if(a[i][j]){
                Grass *g=new Grass(i,j);
                g->setPos(255+j*78,130+i*104);
                se->addItem(g);
                grass[i][j]=g;
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
    timer=new QTimer();
    connect(timer,SIGNAL(timeout()), se,SLOT(advance()));
    timer->start(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
        case(0x31):{
            Zombie *zombie=new Zombie(4,8);
            zombie->setPos(879,546);
            zombie->x=4;
            zombie->y=8;
            zombie->src1=879;
            zombie->src2=546;
            row[4]++,col[8]++;
            zombie->direction=0;
            se->addItem(zombie);
            break;
        }
        case(0x32):{
            NewspaperZombie *newspaperzombie=new NewspaperZombie(4,8);
            newspaperzombie->setPos(879,546);
            newspaperzombie->x=4;
            newspaperzombie->y=8;
            newspaperzombie->src1=879;
            newspaperzombie->src2=546;
            row[4]++,col[8]++;
            newspaperzombie->direction=0;
            se->addItem(newspaperzombie);
            break;
        }
        case(0x33):{
            FootBallZombie *footballzombie=new FootBallZombie(4,8);
            footballzombie->setPos(879,546);
            footballzombie->x=4;
            footballzombie->y=8;
            footballzombie->src1=879;
            footballzombie->src2=546;
            row[4]++,col[8]++;
            footballzombie->direction=0;
            se->addItem(footballzombie);
            break;
        }
        case(0x34):{
            PoleVaultingZombie *polevaultingzombie=new PoleVaultingZombie(4,8);
            polevaultingzombie->setPos(879,546);
            polevaultingzombie->x=4;
            polevaultingzombie->y=8;
            polevaultingzombie->src1=879;
            polevaultingzombie->src2=546;
            row[4]++,col[8]++;
            polevaultingzombie->direction=0;
            se->addItem(polevaultingzombie);
            break;
        }
        case(0x35):{
            BucktheadZombie *bucktheadzombie=new BucktheadZombie(4,8);
            bucktheadzombie->setPos(879,546);
            bucktheadzombie->x=4;
            bucktheadzombie->y=8;
            bucktheadzombie->src1=879;
            bucktheadzombie->src2=546;
            row[4]++,col[8]++;
            bucktheadzombie->direction=0;
            se->addItem(bucktheadzombie);
            break;
        }
        case(0x36):{
            ConeheadZombie *coneheadzombie=new ConeheadZombie(4,8);
            coneheadzombie->setPos(879,546);
            coneheadzombie->x=4;
            coneheadzombie->y=8;
            coneheadzombie->src1=879;
            coneheadzombie->src2=546;
            row[4]++,col[8]++;
            coneheadzombie->direction=0;
            se->addItem(coneheadzombie);
            break;
        }
        case(0x37):{
            ScreenDoorZombie *screendoorzombie=new ScreenDoorZombie(4,8);
            screendoorzombie->setPos(879,546);
            screendoorzombie->x=4;
            screendoorzombie->y=8;
            screendoorzombie->src1=879;
            screendoorzombie->src2=546;
            row[4]++,col[8]++;
            screendoorzombie->direction=0;
            se->addItem(screendoorzombie);
            break;
        }
        case(0x38):{
            ZombieUp *plantrecovery=new ZombieUp(1);
            plantrecovery->setPos(820,450);
            se->addItem(plantrecovery);
            break;
        }
        case(0x39):{
            ZombieUp *plantrecovery=new ZombieUp(2);
            plantrecovery->setPos(820,450);
            se->addItem(plantrecovery);
            break;
        }
        case(0x30):{
            ZombieUp *plantrecovery=new ZombieUp(3);
            plantrecovery->setPos(820,450);
            se->addItem(plantrecovery);
            break;
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    if(event->button()==Qt::RightButton){
        QPoint point=QCursor::pos();
        point=QPoint(point.x()-80,point.y()-90);
        QList<QGraphicsItem*>items=se->items(QRectF(point.x()-10,point.y()-10,20,20));
        foreach(QGraphicsItem* item,items){
            Zombie *zombie=dynamic_cast<Zombie*>(item);
            if(zombie){
                row[zombie->x]--;
                col[zombie->y]--;
                delete zombie;
                return;
            }
            PoleVaultingZombie *polevaultingzombie=dynamic_cast<PoleVaultingZombie*>(item);
            if(polevaultingzombie){
                row[polevaultingzombie->x]--;
                col[polevaultingzombie->y]--;
                delete polevaultingzombie;
                return;
            }
            NewspaperZombie *newspaperzombie=dynamic_cast<NewspaperZombie*>(item);
            if(newspaperzombie){
                row[newspaperzombie->x]--;
                col[newspaperzombie->y]--;
                delete newspaperzombie;
                return;
            }
            FootBallZombie *footballzombie=dynamic_cast<FootBallZombie*>(item);
            if(footballzombie){
                row[footballzombie->x]--;
                col[footballzombie->y]--;
                delete footballzombie;
                return;
            }
            ConeheadZombie *coneheadzombie=dynamic_cast<ConeheadZombie*>(item);
            if(coneheadzombie){
                row[coneheadzombie->x]--;
                col[coneheadzombie->y]--;
                delete coneheadzombie;
                return;
            }
            BucktheadZombie *bucktheadzombie=dynamic_cast<BucktheadZombie*>(item);
            if(bucktheadzombie){
                row[bucktheadzombie->x]--;
                col[bucktheadzombie->y]--;
                delete bucktheadzombie;
                return;
            }
            ScreenDoorZombie *screendoorzombie=dynamic_cast<ScreenDoorZombie*>(item);
            if(screendoorzombie){
                row[screendoorzombie->x]--;
                col[screendoorzombie->y]--;
                delete screendoorzombie;
                return;
            }
            Peashooter *peashooter=dynamic_cast<Peashooter*>(item);
            if(peashooter){
                delete peashooter;
                return;
            }
            TallNut *tallnut=dynamic_cast<TallNut*>(item);
            if(tallnut){
                delete tallnut;
                return;
            }
            Squash *squash=dynamic_cast<Squash*>(item);
            if(squash){
                delete squash;
                return;
            }
            Spikerock *spikerock=dynamic_cast<Spikerock*>(item);
            if(spikerock){
                delete spikerock;
                return;
            }
            SnowPea *snowpea=dynamic_cast<SnowPea*>(item);
            if(snowpea){
                delete snowpea;
                return;
            }
            Repeater *repeater=dynamic_cast<Repeater*>(item);
            if(repeater){
                delete repeater;
                return;
            }
            PotatoMine *potatomine=dynamic_cast<PotatoMine*>(item);
            if(potatomine){
                delete potatomine;
                return;
            }
            Cattail *cattail=dynamic_cast<Cattail*>(item);
            if(cattail){
                delete cattail;
                return;
            }
            GloomShroom *gloomshroom=dynamic_cast<GloomShroom*>(item);
            if(gloomshroom){
                delete gloomshroom;
                return;
            }
            GatlingPea *gatlingpea=dynamic_cast<GatlingPea*>(item);
            if(gatlingpea){
                delete gatlingpea;
                return;
            }
            Chomper *chomper=dynamic_cast<Chomper*>(item);
            if(chomper){
                delete chomper;
                return;
            }
        }
    }
}

void up(BasicZombie* bzombie)
{
    if(bzombie->hp<=0){
        BasicZombie *zombie;
        if(bzombie->up1){
            zombie=new BucktheadZombie(bzombie->r,bzombie->c);
            bzombie->up1--;
        }
        else if(bzombie->up2){
            zombie=new ScreenDoorZombie(bzombie->r,bzombie->c);
            bzombie->up2--;
        }
        else if(bzombie->up3){
            zombie=new FootBallZombie(bzombie->r,bzombie->c);
            bzombie->up3--;
        }
        zombie->freeze=bzombie->freeze;
        zombie->sputter=bzombie->sputter;
        zombie->fire=bzombie->fire;
        zombie->x=bzombie->x;
        zombie->y=bzombie->y;
        zombie->up1=bzombie->up1;
        zombie->up2=bzombie->up2;
        zombie->up3=bzombie->up3;
        row[bzombie->x]++;
        col[bzombie->y]++;
        zombie->direction=bzombie->direction;
        zombie->src1=bzombie->scenePos().x();
        zombie->src2=bzombie->scenePos().y();
        zombie->setPos(bzombie->scenePos());
        se->addItem(zombie);
        delete bzombie;
    }
}
