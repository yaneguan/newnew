#ifndef REGST_H
#define REGST_H

#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QListWidget>
#include <QPainter>
#include <QDebug>
#include <QMessageBox>
#include <QTcpsocket>
#include <QAbstractSocket>
#include <QByteArray>
#include <QRegExp>
#include <QRegExpValidator>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDataStream>
#include <QIODevice>
class Regst : public QWidget
{
    Q_OBJECT
public:
    explicit Regst(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~Regst();

signals:
private:
    QLabel *line_name;
    QLabel *line_passwd;
    QLabel *re_passwd;
    QLineEdit *name;
    QLineEdit *passwd;
    QPushButton *over;
     QString User_name;
     QString User_pass;
     QString Telphone;
     QTcpSocket *socket;
     QValidator *tor;
     QValidator *tur;
     QValidator *tvr;
     QLabel *notice;
    QJsonObject us;
    QLineEdit *tel;


    struct data_deliver{
        uchar data_type;
        uchar func_num;
        ushort data_length;

    };

    enum{
            DATA_TYPE,
            FUNC_NUM,

    };

public slots:
     void exam_func();
     void recv_info();
//     void connect_exam();
};

#endif // REGST_H
