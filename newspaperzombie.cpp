#include "newspaperzombie.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
extern Bare* bare[5][9];
extern int row[5],col[9];
NewspaperZombie::NewspaperZombie(int _r, int _c):BasicZombie(_r, _c){
    state=2;
    flag1=flag2=0;
    setMovie(":/new/prefix1/pictures/NewspaperZombie/HeadWalk1.gif");
    die1=":/new/prefix1/pictures/NewspaperZombie/Die.gif";
    die2=":/new/prefix1/pictures/NewspaperZombie/Head.gif";
    hp=thp=1500;
}

QRectF NewspaperZombie::boundingRect() const{
    return QRectF(-35,-85,120,145);
}

void NewspaperZombie::advance(int phase){
    BasicZombie::advance(phase);
    if(hp<=500 && hp>0){
        faster=1;
        if(time1==0){
            setFaster(6);
            setMovie(":/new/prefix1/pictures/NewspaperZombie/LostNewspaper.gif");
        }
        if(time1==200){
            setMovie(":/new/prefix1/pictures/NewspaperZombie/HeadWalk0.gif");
            flag1=flag2=0;
        }
        time1+=2;
        if(time1<200){
            update();
            return;
        }
        if(state==1){
            if(flag1){
                update();
                return;
            }
            setMovie(":/new/prefix1/pictures/NewspaperZombie/HeadAttack0.gif");
            setSpeed();
            flag1=1;
            flag2=0;
            update();
            return;
        }
        else if(state==0){
            if(!flag2){
                setMovie(":/new/prefix1/pictures/NewspaperZombie/HeadWalk0.gif");
                flag2=1;
                flag1=0;
            }
        }
    }
    else if(hp>500){
        if(state==1){
            if(flag1){
                update();
                return;
            }
            setMovie(":/new/prefix1/pictures/NewspaperZombie/HeadAttack1.gif");
            flag1=1;
            flag2=0;
            update();
            return;
        }
        else{
            if(!flag2){
                setMovie(":/new/prefix1/pictures/NewspaperZombie/HeadWalk1.gif");
                flag2=1;
                flag1=0;
            }
        }
    }
    if(hp>0){
        move();
    }
}
