#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include <QGraphicsView>
#include<QTimer>
#include"list.h"
#include"peashooter.h"
#include"grass.h"
#include"bare.h"
#include"zombie.h"
#include"newspaperzombie.h"
#include"footballzombie.h"
#include"polevaultingzombie.h"
#include"bucktheadzombie.h"
#include"coneheadzombie.h"
#include"screendoorzombie.h"
#include"gameover.h"
#include"pea.h"
#include"plantupdate.h"
#include"plantrecovery.h"
#include"plantfaster.h"
#include"zombiefaster.h"
#include"planthurt.h"
#include"plantfreeze.h"
#include"plantup.h"
#include"zombiesputter.h"
#include"zombieendure.h"
#include"zombieup.h"
#include<iostream>
#include<fstream>
#include<QDebug>
#include<queue>
#include<QMouseEvent>
#include<QKeyEvent>
void up(BasicZombie*);
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;

private slots:

};

#endif // MAINWINDOW_H
