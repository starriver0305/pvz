#include "footballzombie.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
extern Bare* bare[5][9];
extern int row[5],col[9];
FootBallZombie::FootBallZombie(int _r, int _c):BasicZombie(_r, _c){
    state=2;
    flag1=flag2=flag3=0;
    setMovie(":/new/prefix1/pictures/ConeheadZombie/ConeheadZombie.gif");
    die1=":/new/prefix1/pictures/FootBallZombie/橄榄僵尸死.gif";
    die2=":/new/prefix1/pictures/Zombie/ZombieHead.gif";
    hp=thp=3000;
}

QRectF FootBallZombie::boundingRect() const{
    return QRectF(-35,-65,110,120);
}

void FootBallZombie::advance(int phase){
    BasicZombie::advance(phase);
    if(hp<=1500 && hp>0){
        if(state==1){
            if(flag1 && flag3){
                update();
                return;
            }
            setMovie(":/new/prefix1/pictures/FootBallZombie/橄榄僵尸失去帽子攻击.gif");
            flag1=1;
            flag3=1;
            flag2=0;
            update();
            return;
        }
        else{
            if(!flag2 || !flag3){
                setMovie(":/new/prefix1/pictures/FootBallZombie/橄榄僵尸失去帽子.gif");
                flag2=1;
                flag3=1;
                flag1=0;
            }
        }
    }
    else if(hp>1000){
        if(state==1){
            if(flag1){
                update();
                return;
            }
            setMovie(":/new/prefix1/pictures/FootBallZombie/橄榄僵尸攻击.gif");
            flag1=1;
            flag2=0;
            update();
            return;
        }
        else{
            if(!flag2){
                setMovie(":/new/prefix1/pictures/FootBallZombie/橄榄僵尸.gif");
                flag2=1;
                flag1=0;
            }
        }
    }
    if(hp>0){
        move();
    }
}
