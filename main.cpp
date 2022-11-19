#include "mainwindow.h"
#include "peashooter.h"
#include <QApplication>
QGraphicsScene *se;
QGraphicsView *vw;
int row[5],col[9];
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
