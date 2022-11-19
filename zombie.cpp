#include "zombie.h"
extern QGraphicsScene *se;
extern QGraphicsView *vw;
extern Bare* bare[5][9];
extern int row[5],col[9];
Zombie::Zombie(int _r, int _c):BasicZombie(_r, _c){
    state=2;
    flag1=flag2=0;
    setMovie(":/new/prefix1/pictures/Zombie/Zombie.gif");
    die1=":/new/prefix1/pictures/Zombie/ZombieDie.gif";
    die2=":/new/prefix1/pictures/Zombie/ZombieHead.gif";
    hp=thp=700;
}

QRectF Zombie::boundingRect() const{
    return QRectF(-45,-65,110,120);
}

void Zombie::advance(int phase){
    BasicZombie::advance(phase);
    if(state==1){
        if(flag1){
            update();
            return;
        }
        setMovie(":/new/prefix1/pictures/Zombie/ZombieAttack.gif");
        flag1=1;
        flag2=0;
        update();
        return;
    }
    else if(state==0){
        if(!flag2){
            setMovie(":/new/prefix1/pictures/Zombie/Zombie.gif");
            flag2=1;
            flag1=0;
        }
    }
    if(hp>0){
        move();
    }
}
