#ifndef USERSPACE_H
#define USERSPACE_H

#include <QWidget>
#include <QPalette>
#include <QIcon>
#include <QDebug>
#include <QPushButton>
#include <QPainter>
#include <QPen>
#include <QSize>
#include <QLabel>
#include <QPixmap>
#include <QListWidget>
#include <QTime>
#include <QDateTime>
#include <QTimer>
#include <QMessageBox>
#include <QtWidgets/QMainWindow>
#include <QTcpsocket>
#include <QAbstractSocket>
#include <QByteArray>
#include "Option.h"
#include <QFont>
class Userspace : public QWidget
{
    Q_OBJECT
public:
    explicit Userspace(QWidget *parent = 0);


        ~Userspace();
signals:

public slots:
    void enter_option();
    void time_view();
    void send_email();
    void temper_view();
    void water_view();
    void sunshine_view();
    void connect_exam();
    void recv_server();

private:
    QLabel *lb1;
    QLabel *lb2;
    QLabel *lb3;
    QLabel *lb4;
    QLabel *lb5;
    QLabel *tim;
    QLabel *dat;
    QLabel *lb6;
    QLabel *lb7;
    QLabel *lb8;
    QLabel *lb9;
    QLabel *lb10;
    QLabel *temp;
    QLabel *water;
    QLabel *sunshine;
    QPushButton *temper;
    QPushButton *clock;
    QPushButton *sun;
    QPushButton *optv;
    QPushButton *camer;
    QPushButton *media;
    QPushButton *game;
    QPushButton *home;
    QPushButton *user;
    QPushButton *email;
    QPushButton *emails;
    bool tem;
    bool wat;
    bool su;
     QPalette pv;
     QFont seri;
    Option *op;
   QTcpSocket *socket;
};

#endif // USERSPACE_H
