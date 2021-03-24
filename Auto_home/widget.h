#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QString>
#include <QSettings>
#include <QMessageBox>
#include <QtWidgets/QMainWindow>
#include <QTcpsocket>
#include <QAbstractSocket>
#include <QByteArray>
#include "userspace.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "regst.h"

#include <QDataStream>
#include <QIODevice>

#define port 8085


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:

    explicit Widget(QWidget *parent = 0);

    void paintEvent(QPaintEvent *);

    void Pushbutton();
        void writeinit(QString key,QString value);
        void readinit(QString key,QString &value);


    ~Widget();
signals:
    void returnPressed();

private slots:

    void gist_view();
    void exam_user();
    void recv_server();
    void do_show();
protected:


private:
    QLineEdit *user;
    QLineEdit *password;
    Ui::Widget *ui;
    QLabel *la1;
    QPushButton *login;
    QPushButton *regist;
    QCheckBox *check;
    Userspace *ser;
    Regst *gst;
    bool pwd;
    QString username;
    QString passwd;
    QString Remeberpasswd;
    QString readip;
    QString readport;
    QString exam;
    QString Usr_name;
    QString Usr_pass;
    QTcpSocket *socket;
    QJsonObject us;
//    QTcpSocket *socket;
};

#endif // WIDGET_H
