#include "widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    qDebug()<<"helloworld!  ";
}

Widget::~Widget()
{

}
