#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
        this->setAutoFillBackground(true);
        this->resize(1000,700);
        this->setWindowTitle("my_game");
        this->setWindowIcon(QIcon(":/fs_logo.png"));
        //创建界面背景图
        QPalette palette = this->palette();
        palette.setBrush (QPalette::Background, QBrush(QPixmap(":/login_bj.jpg").scaled (this->size (),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
        this->setPalette(palette);

//        this->setStyleSheet("border-image:url(:/login_bj.jpg)");
        qDebug()<<"widget_over";
        user = new QLineEdit(this);
        //user->setAutoFillBackground(true);
        user->resize(120,25);

//        user->setSizeIncrement(QSize(user->width(),user->height()));
        user->setGeometry(710,315,user->width(),user->height());
      //  user->setStyleSheet("border-image:url(:/edittext_bj.png)");


        user->setFocus();
        password = new QLineEdit(this);
        password->resize(120,25);
        password->setGeometry(710,380,password->width(),password->height());

        password->setEchoMode(QLineEdit::Normal);


        login = new QPushButton(this);
        login->resize(50,30);
        login->setGeometry(780,420,login->width(),login->height());
        login->setText("登录");

        regist = new QPushButton(this);
        regist->resize(50,30);
        regist->setGeometry(715,420,regist->width(),regist->height());
        regist->setText("注册");

        la1 = new QLabel(this);
        //la1->clear();

        la1->resize(80,100);
        la1->setGeometry(650,390,la1->width(),la1->height());
        la1->setText("记住密码？");
        check = new QCheckBox(this);
        check->resize(20,20);
        check->setGeometry(630,430,check->width(),check->height());

        //将密码显示为隐藏
        password->setEchoMode(QLineEdit::Password);
        //回车进入

        connect(password,SIGNAL(returnPressed()),this,SLOT(exam_user()));
        //登录进入
        //connect(login,SIGNAL(clicked(bool)),this,SLOT(exam_user()));
        connect(login,SIGNAL(clicked(bool)),this,SLOT(do_show()));
//        QString us_ne = user->text().trimmed();
//        QString us_ps = password->text().trimmed();
         socket = new QTcpSocket;
        connect(socket,SIGNAL(readyRead()),this,SLOT(recv_server()));

        connect(regist,SIGNAL(clicked(bool)),this,SLOT(gist_view()));

//           readip = user->text();
//           readport = password->text();
           readinit("button",exam);
           qDebug()<<"exam "<<exam;
           if(exam == "true")
           {
           readinit("username",readip);
           readinit("passwd",readport);
           check->setChecked(true);
           user->setText(readip);
           password->setText(readport);
        }
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
          QPen pen;
          p.setPen(pen);
          p.drawImage(QRectF(30,50,450,80),QImage(":/fs_logo.png"));
          p.drawImage(QRectF(650,300,60,60),QImage(":/manger.png"));
          p.drawImage(QRectF(660,360,45,45),QImage(":/lock_ico.png"));

    qDebug()<<"paintEVent";

}

void Widget::Pushbutton()
{
    if(user->text() == "" || user->text() == "" )
        {
            QMessageBox::information(this,"Warning","IP and Port can not be empty!",QMessageBox::Ok);
            return;
        }
        writeinit("ip",user->text());
        writeinit("port",password->text());
        QString ip = user->text();
//         int port = password->text().toInt();
//         int meetNum = check->text().toInt();
}

void Widget::writeinit(QString key, QString value)
{
       QString path = "ip.ini";
       QSettings *conf = new QSettings(path,QSettings::IniFormat);
       conf->beginGroup("config");
       conf->setValue(key,value);
       conf->endGroup();
       delete conf;
}

void Widget::readinit(QString key, QString &value)
{
        value = QString ("");
        QString path = "ip.ini";
        QSettings *conf = new QSettings(path,QSettings::IniFormat);
        value = conf->value(QString ("config/")+key).toString();
        delete conf;
}






void Widget::gist_view()
{
    gst = new Regst();
    gst->show();
}

void Widget::exam_user()
{

    if(check->isChecked())
    {
        pwd = true;
        writeinit("username",user->text());
        writeinit("passwd",password->text());
        writeinit("button","true");
    }
    else{
//        user->clear();
//        password->clear();
        pwd = false;
    }



    Usr_name = user->text().trimmed();
    Usr_pass = password->text().trimmed();
    qDebug()<<"用户名"<<Usr_name;
    qDebug()<<"密码"<<Usr_pass;

    //将QString 类型的账号密码转为char *型；
//    QByteArray ba = Usr_name.toLatin1();
//    char *user_name = ba.data();

//    QByteArray bv = Usr_pass.toLatin1();
//    char *user_pass = bv.data();
      //

    us.insert("_username",Usr_name);
    us.insert("_password",Usr_pass);

    QJsonDocument send_doc;
    send_doc.setObject(us);
    QByteArray bx = send_doc.toJson(QJsonDocument::Compact);

//    data_info.data_length= User_name.size()+User_pass.size();
    //
    QByteArray block;
    QDataStream out(&block,QIODevice::ReadWrite);  //使用数据流写入数据

        out.setVersion(QDataStream::Qt_4_9);//设置版本号
        out.setByteOrder(QDataStream::LittleEndian);//设置大小端模式

        out<<uchar(0)<<uchar(0)<<ushort(0);//先用其他数占用前面四个位置

        out.device()->seek(0);//把位置符设置到起始位
        uchar type_id=uchar(0xaa);
        uchar fun_id=0x01;//设置好标志位表示登录还是注册等
        ushort mesg_len = bx.size();//传过来的json字符串的长度

        out<<type_id<<fun_id<<mesg_len;//将开始占用的4个位置填充
       bx.insert(0,block);//然后插入到json包的前面

          //

//    QJsonObject vs;
//    vs.insert("0xaa","0x01");
//    vs.insert("userName",Usr_name);
//    vs.insert("passWord",Usr_pass);

//    QJsonDocument send_doc;
//    send_doc.setObject(vs);
//    QByteArray bv = send_doc.toJson(QJsonDocument::Compact);

    socket->connectToHost("192.168.0.137",2222                                                          );
    qDebug()<<"连接状态:"<<socket->state();
    //发送账号密码给服务器
    if(socket->state() == QAbstractSocket::ConnectingState)
    {
//        socket->write(user_name,qstrlen(user_name));
//        socket->write(user_pass),qstrlen(user_pass);
        socket->write(bx);


    }else if(this->close()){}
    else{
        QMessageBox::warning(this,tr("警告"),tr("登录未连接，请重连"),QMessageBox::Yes);
    }

    if(user->text().trimmed() == ("1314520") && password->text() == tr("super7758"))
    {
            acceptDrops();
            ser = new Userspace();
            ser->show();
            this->close();
            socket->close();
    }
    else{
//        QMessageBox::warning(this,tr("警告"),tr("输入错误，请重新输入"),QMessageBox::Yes);
//        password->clear();
//        password->setFocus();
    }
}

void Widget::recv_server()
{
//    QByteArray dav = socket->readAll();
//    qDebug()<<"data = "<<dav;
//    if(dav == "OK")
//    {
//     QMessageBox::warning(this,tr("注册"),tr("注册成功,请登录"),QMessageBox::Yes);
//        QMessageBox::information(NULL,"","注册成功，请登录",QMessageBox::Yes);
//        this->close();
//       socket->close();
//

        QByteArray dav = socket->readAll();
        qDebug()<<"data = "<<dav;
//        qDebug()<<"状态："<<
        dav.remove(0,4);
        qDebug()<<"data2 = "<<dav;
        QJsonParseError json_error;
        QJsonDocument doc = QJsonDocument::fromJson(dav,&json_error);
        if(json_error.error == QJsonParseError::NoError)
        {
            qDebug()<<"error_inside";

             QJsonObject obj = doc.object();
             if(obj.contains("_username"))
             {
                      qDebug()<<"contains_insde";
                QJsonValue ve = obj.take("_username");
                if(ve.isDouble())
                {
                    int login_word = ve.toVariant().toInt();
                    qDebug()<<"_username:"<<login_word;
                }
             }
             else if(obj.contains("stateCode"))
                 {
                    QJsonValue ve = obj.take("stateCode");
                     int state = ve.toVariant().toInt();
                     if(state == 0)
                     {
                             QMessageBox::information(NULL,"登录","登录成功",QMessageBox::Yes);

                             socket->close();
                             ser = new Userspace();
                             ser->show();
                             this->close();
                     }
                 else
                 {
                     QMessageBox::information(NULL,"登录","输入有误，请重新输入",QMessageBox::Yes);
             //          QMessageBox::warning(this,tr("完成"),tr("输入有误，请重新输入"),QMessageBox::Yes);
                       user->clear();
                       password->clear();
                       user->setFocus();
                 }

                        }


        }
}

void Widget::do_show()
{
    ser = new Userspace();
    ser->show();
}

Widget::~Widget()
{
    delete ui;
    delete user;
    delete password;
    delete login;
    delete regist;
    delete check;
    delete ser;
    delete gst;
    delete la1;
    delete socket;

}
