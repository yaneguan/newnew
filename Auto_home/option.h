#ifndef OPTION_H
#define OPTION_H

#include <QWidget>
#include <QPalette>
#include <QIcon>
#include <QDebug>
#include <QPushButton>
#include <QPainter>
#include <QPen>
#include <QSize>
#include <QLabel>
#include <QEvent>
#include <QMessageBox>
#include <QtWidgets/QMainWindow>
#include <QTcpsocket>
#include <QAbstractSocket>
#include <QByteArray>

class Option : public QWidget
{
    Q_OBJECT
public:
    explicit Option(QWidget *parent = 0);
         void led1_light();
         void led2_light();
         void wind_light();
         void door_light();
         void led1_over();
         void led2_over();
         void wind_over();
         void door_over();

        ~Option();

signals:
private:
           QPushButton *on_1;
           QPushButton *on_2;
           QPushButton *on_3;
           QPushButton *on_4;
           QPushButton *off_1;
           QPushButton *off_2;
           QPushButton *off_3;
           QPushButton *off_4;
           QLabel *led1;
           QLabel *led11;
           QLabel *led2;
           QLabel *led22;
           QLabel *wind;
           QLabel *wind1;
           QLabel *door;
           QLabel *door1;
           QTcpSocket *socket;



public slots:

                  void led1_on();

                  void led1_off();

                  void led2_on();
                  void led2_off();
                  void wind_on();
                  void wind_off();
                  void door_on();
                  void door_off();
                  void recv_server();
};

#endif // OPTION_H
