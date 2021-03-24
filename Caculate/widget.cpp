#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->N0->installEventFilter(this);
    ui->N1->installEventFilter(this);
    ui->N2->installEventFilter(this);
    ui->N3->installEventFilter(this);
    ui->N4->installEventFilter(this);
    ui->N5->installEventFilter(this);
    ui->N6->installEventFilter(this);
    ui->N7->installEventFilter(this);
    ui->N8->installEventFilter(this);
    ui->N9->installEventFilter(this);
    ui->plus->installEventFilter(this);
    ui->decr->installEventFilter(this);
    ui->multi->installEventFilter(this);
    ui->devison->installEventFilter(this);

}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    QString tmp;
    if(watched == ui->N1 && event->type() == QEvent::MouseButtonPress)
    {
        ui->lineEdit->text() = ui->N1->text().toInt();
        qDebug()<<" "<<ui->lineEdit->text();
    }
    else if(watched == ui->N2 && event->type() == QEvent::MouseButtonPress)
    {
        ui->lineEdit->text() = ui->N2->text();
    }
    else if(watched == ui->N3 && event->type() == QEvent::MouseButtonPress)
    {
        ui->lineEdit->text() = ui->N3->text();
    }
    else if(watched == ui->N4 && event->type() == QEvent::MouseButtonPress)
    {
        tmp = ui->N4->text();
    }
    else if(watched == ui->N5 && event->type() == QEvent::MouseButtonPress)
    {
        tmp = ui->N5->text();
    }
    else if(watched == ui->N6 && event->type() == QEvent::MouseButtonPress)
    {
        tmp = ui->N6->text();
    }
    else if(watched == ui->N7 && event->type() == QEvent::MouseButtonPress)
    {
        tmp = ui->N7->text();
    }
    else if(watched == ui->N8 && event->type() == QEvent::MouseButtonPress)
    {
        tmp = ui->N8->text();
    }
    else if(watched == ui->N9 && event->type() == QEvent::MouseButtonPress)
    {
        tmp = ui->N9->text();
    }
    else if(watched == ui->N0 && event->type() == QEvent::MouseButtonPress)
    {
        tmp = ui->N0->text();
    }
    else if(watched == ui->plus && event->type() == QEvent::MouseButtonPress)
    {
        tmp = ui->plus->text();
    }
    else if(watched == ui->decr && event->type() == QEvent::MouseButtonPress)
    {
        tmp = ui->decr->text();
    }
    else if(watched == ui->multi && event->type() == QEvent::MouseButtonPress)
    {
        tmp = ui->multi->text();
    }
    else if(watched == ui->devison && event->type() == QEvent::MouseButtonPress)
    {
        tmp = ui->devison->text();
    }
   // qDebug()<<"输入了 "<<tmp;
   // ui->lineEdit->text() = tmp;
    str= tmp;
    tmp.clear();
}

void Widget::setlineText()
{

}
