#include "widget.h"
#include <QApplication>
#include "deal.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    factory fy;
    deal *dl = fy.doperator(ML);
    int num = dl->dealIt(3,9);
    qDebug()<<"num = "<<num;
    return a.exec();
}
