#include "bucktheadzombie.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
extern Bare* bare[5][9];
extern int row[5],col[9];
BucktheadZombie::BucktheadZombie(int _r, int _c):BasicZombie(_r, _c){
    state=2;
    flag1=flag2=flag3=0;
    setMovie(":/new/prefix1/pictures/BucketheadZombie/BucketheadZombie.gif");
    die1=":/new/prefix1/pictures/Zombie/ZombieDie.gif";
    die2=":/new/prefix1/pictures/Zombie/ZombieHead.gif";
    hp=thp=1500;
}

QRectF BucktheadZombie::boundingRect() const{
    return QRectF(-40,-65,110,120);
}

void BucktheadZombie::advance(int phase){
    BasicZombie::advance(phase);
    if(hp<=500 && hp>0){
        if(state==1){
            if(flag1 && flag3){
                update();
                return;
            }
            setMovie(":/new/prefix1/pictures/Zombie/ZombieAttack.gif");
            flag1=1;
            flag3=1;
            flag2=0;
            update();
            return;
        }
        else{
            if(!flag2 || !flag3){
                setMovie(":/new/prefix1/pictures/Zombie/Zombie.gif");
                flag2=1;
                flag3=1;
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
            setMovie(":/new/prefix1/pictures/BucketheadZombie/BucketheadZombieAttack.gif");
            flag1=1;
            flag2=0;
            update();
            return;
        }
        else{
            if(!flag2){
                setMovie(":/new/prefix1/pictures/BucketheadZombie/BucketheadZombie.gif");
                flag2=1;
                flag1=0;
            }
        }
    }
    if(hp>0){
        move();
    }
}
