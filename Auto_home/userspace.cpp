#include "userspace.h"

Userspace::Userspace(QWidget *parent) : QWidget(parent),wat(false),su(false),seri("Times", 18, QFont::Bold),tem(false)
{
    this->setAutoFillBackground(true);
        this->resize(1000,700);
        this->setWindowTitle("my_game");
        this->setWindowIcon(QIcon(":/fs_logo.png"));
        //创建界面背景图
        QPalette palette;
        palette.setBrush (QPalette::Background, QBrush(QPixmap(":/home_bh.png").scaled (this->size ())));
        this->setPalette(palette);

        lb1 = new QLabel(this);
        lb1->setGeometry(QRect(10,10,220,60));
        //lb1->setAutoFillBackground(true);
        lb1->setPixmap(QPixmap(QString::fromUtf8(":/fs_logo.png")));
        lb1->setScaledContents(true);


        lb2 = new QLabel(this);
        lb2->setGeometry(QRect(60,200,250,250));
       // lb2->setAutoFillBackground(true);
        lb2->setPixmap(QPixmap(QString::fromUtf8(":/pellet_ico.png")));
        lb2->setScaledContents(true);

        lb3 = new QLabel(this);
        lb3->setGeometry(QRect(430,180,60,70));
        lb3->setText("温度");
        QFont serif("Times", 18, QFont::Bold);
        lb3->setFont(serif);
        QPalette pe;
        pe.setColor(QPalette::WindowText,Qt::white);
        lb3->setPalette(pe);

        lb4 = new QLabel(this);
        lb4->setGeometry(QRect(435,300,80,80));
        lb4->setText("湿度");
        lb4->setFont(serif);
        pe.setColor(QPalette::WindowText,Qt::white);
        lb4->setPalette(pe);

        lb5= new QLabel(this);
        lb5->setGeometry(QRect(435,410,80,80));
        lb5->setText("光照");
        lb5->setFont(serif);
        pe.setColor(QPalette::WindowText,Qt::white);
        lb5->setPalette(pe);

        lb6= new QLabel(this);
        lb6->setGeometry(QRect(240,15,150,60));
        lb6->setText("武汉中心");
        lb6->setFont(serif);
        pe.setColor(QPalette::WindowText,Qt::white);
        lb6->setPalette(pe);
            //隐藏背景图片，显示部件功能；
//        lb5->setStyleSheet("QTaWidget:pane{border-top:0px solid #e8f3f9;background: transparent;}");
//        lb5->setFrameShape(QListWidget::NoFrame);
        lb7= new QLabel(this);
        lb7->setGeometry(QRect(175,645,100,40));
        lb7->setText("视频监控");
        lb7->setFont(serif);
        pe.setColor(QPalette::WindowText,Qt::white);
        lb7->setPalette(pe);

        lb8= new QLabel(this);
        lb8->setGeometry(QRect(360,645,100,40));
        lb8->setText("多媒体播放");
        lb8->setFont(serif);
        pe.setColor(QPalette::WindowText,Qt::white);
        lb8->setPalette(pe);

        lb9= new QLabel(this);
        lb9->setGeometry(QRect(530,645,100,40));
        lb9->setText("设备管理");
        lb9->setFont(serif);
        pe.setColor(QPalette::WindowText,Qt::white);
        lb9->setPalette(pe);

        lb10= new QLabel(this);
        lb10->setGeometry(QRect(700,645,100,40));
        lb10->setText("娱乐休闲");
        lb10->setFont(serif);
        pe.setColor(QPalette::WindowText,Qt::white);
        lb10->setPalette(pe);

        temp = new QLabel(this);
        water = new QLabel(this);
        sunshine = new QLabel(this);

        temper = new QPushButton(this);
        temper->setIcon(QIcon(":/temperature_button_ico.png"));
        temper->setIconSize(QSize(100,180));
        temper->setGeometry(QRect(350,180,70,100));
        temper->setFlat(true);
        connect(temper,SIGNAL(clicked(bool)),this,SLOT(temper_view()));
        clock = new QPushButton(this);
        clock->setIcon(QIcon(":/humidity_button_ico.png"));
        clock->setIconSize(QSize(100,180));
        clock->setGeometry(QRect(350,300,80,80));
        clock->setFlat(true);
        connect(clock,SIGNAL(clicked(bool)),this,SLOT(water_view()));
        sun = new QPushButton(this);
        sun->setIcon(QIcon(":/illumination_button_ico.png"));
        sun->setIconSize(QSize(100,180));
        sun->setGeometry(QRect(350,410,80,80));
        sun->setFlat(true);
        connect(sun,SIGNAL(clicked(bool)),this,SLOT(sunshine_view()));
        qDebug()<<"QPushbtn start";
        optv = new QPushButton(this);
       // optv->setAutoFillBackground(true);

        optv->setIcon(QIcon(":/dev_button_ico.png"));
        QSize si(100,150);
        optv->setIconSize(si);
        optv->setGeometry(QRect(530,530,80,100));
        optv->setFlat(true);
         qDebug()<<"QPushbtn over";
        connect(optv,SIGNAL(clicked(bool)),this,SLOT(enter_option()));
//        palette.setColor(QPalette::Background,QColor(0x00,0xff,0x00,0x00));
//        setPalette(palette);


        camer = new QPushButton(this);
       // camer->setAutoFillBackground(true);
        camer->setIcon(QIcon(":/video_button_ico.png"));
        camer->setIconSize(QSize(100,180));
        camer->setGeometry(QRect(180,540,85,100));
        camer->setFlat(true);

        media = new QPushButton(this);
       //media->setAutoFillBackground(true);
        media->setIcon(QIcon(":/meadioplayer_button_ico.png"));
        media->setIconSize(QSize(100,180));
        media->setGeometry(QRect(360,530,85,100));
        media->setFlat(true);

        game = new QPushButton(this);
       // game->setAutoFillBackground(true);
        game->setIcon(QIcon(":/yule_button_ico.png"));
        game->setIconSize(QSize(100,180));
        game->setGeometry(QRect(700,530,85,100));
        game->setFlat(true);

        home = new QPushButton(this);
        //home->setAutoFillBackground(true);
        home->setIcon(QIcon(":/home_ico.png"));
        home->setIconSize(QSize(80,80));
        home->setGeometry(QRect(920,5,50,50));
        home->setFlat(true);

        user = new QPushButton(this);
       // user->setAutoFillBackground(true);
        user->setIcon(QIcon(":/manger.png"));
        user->setIconSize(QSize(80,80));
        user->setGeometry(QRect(850,5,50,50));
        user->setFlat(true);

        email = new QPushButton(this);
       // email->setAutoFillBackground(true);
        email->setIcon(QIcon(":/email_no_ico.png"));
        email->setIconSize(QSize(80,80));
        email->setGeometry(QRect(780,5,50,50));
        email->setFlat(true);


        emails = new QPushButton(this);
        emails->setIcon(QIcon(":/email_yes_ico.png"));
        emails->setIconSize(QSize(80,80));
        emails->setGeometry(QRect(780,5,50,50));
        emails->setFlat(true);
        emails->hide();

        connect(email,SIGNAL(clicked(bool)),this,SLOT(send_email()));

        dat = new QLabel(this);

        //dat->resize(350,180);
        dat->setGeometry(QRect(600,260,300,120));


        tim = new QLabel(this);

        //tim->resize(250,150);
        tim->setGeometry(QRect(600,310,250,150));

        //获取系统时间字符串
//        QDateTime dt;
//        QTime time;
//        QDate date;
//        dt.setTime(time.currentTime());
//        dt.setDate(date.currentDate());
//        QString currentdate = dt.toString("20yy年:MM月:hh时:mm分:ss秒");
//        qDebug()<<"时间 = "<<currentdate;
//        tim->setText(currentdate);
        //实时获取系统时间
        QTimer *timer = new QTimer(this);
        timer->start(500);
        connect(timer,SIGNAL(timeout()),this,SLOT(time_view()));
        socket = new QTcpSocket;
       connect(socket,SIGNAL(readyRead()),this,SLOT(recv_server()));
       //只要有类文件的连接状态断开，则会响应该函数；
//       connect(socket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(connect_exam()));
       connect(socket,SIGNAL(disconnected()),this,SLOT(connect_exam()));
        socket->connectToHost("192.168.215.1",8087);
}



void Userspace::temper_view()
{

    temp->setGeometry(QRect(500,165,70,100));
    temp->setFont(seri);
    pv.setColor(QPalette::WindowText,Qt::red);
    temp->setPalette(pv);
    tem = true;
    qDebug()<<"temper is runing";
}

void Userspace::water_view()
{
    water->setGeometry(QRect(500,290,70,100));
    water->setFont(seri);
    pv.setColor(QPalette::WindowText,Qt::red);
    water->setPalette(pv);
    wat = true;
    qDebug()<<"water is runing";
}

void Userspace::sunshine_view()
{
    sunshine->setGeometry(QRect(500,400,70,100));
    sunshine->setFont(seri);
    pv.setColor(QPalette::WindowText,Qt::red);
    sunshine->setPalette(pv);
   su = true;
   qDebug()<<"sunshine is runing";
}
//无视多文件类不同，只要一个类文件的连接状态断开，则会调用该函数；
void Userspace::connect_exam()
{
    if(socket->state() == QAbstractSocket::ConnectingState)
    {
        qDebug()<<"连接状态:"<<socket->state();
    }
    else if(this->close()){
    }else{
        QMessageBox::information(NULL,"注意","断网啦，请重连",QMessageBox::Yes);
        this->close();

    }
}

//QJsonObject vs;
//vs.insert("0xaa","0x01");
//vs.insert("userName",Usr_name);
//vs.insert("passWord",Usr_pass);

//QJsonDocument send_doc;
//send_doc.setObject(vs);
//QByteArray bv = send_doc.toJson(QJsonDocument::Compact);
void Userspace::recv_server()
{
    QString dax = socket->readAll();
//    QString str;
//    str.toLatin1() = dax;
//    QByteArray ba = User_name.toLatin1();
//    //    char *user_name = ba.data();
//    //    QByteArray bv = User_pass.toL
    if(tem)
    {
    temp->setText(dax);
     qDebug()<<"temp_recv";
     tem = false;
    }
    else if(wat)
    {
        water->setText(dax);
        qDebug()<<"water_recv";
        wat = false;
    }
    else if(su)
    {
        sunshine->setText(dax);
        qDebug()<<"sunshine_recv";
        su = false;
    }
}

Userspace::~Userspace()
{
    delete lb1;
    delete lb2;
    delete lb3;
    delete lb4;
    delete lb5;
    delete lb6;
    delete lb7;
    delete lb8;
    delete lb9;
    delete lb10;
    delete tim;
    delete dat;
    delete temper;
    delete clock;
    delete sun;
    delete optv;
    delete camer;
    delete media;
    delete game;
    delete home;
    delete user;
    delete email;
    delete emails;
    delete op;
    delete socket;

}

void Userspace::enter_option()
{
    op = new Option();
    op->show();
}

void Userspace::time_view()
{
     QTime time = QTime::currentTime();
     QString txtTime = time.toString("hh时 mm分 ss秒");
     QDate date = QDate::currentDate();
     QString txtDate = date.toString("yy年 MM月 dd日");
     txtDate = "20" + txtDate;
     tim->setText(txtTime);
     dat->setText(txtDate);
     QFont serifFont("Times", 24, QFont::Normal);
     tim->setFont(serifFont);
     dat->setFont(serifFont);

}

void Userspace::send_email()
{
    emails->show();
    emails->setIcon(QIcon(":/email_yes_ico.png"));
    emails->setIconSize(QSize(80,80));
    emails->setGeometry(QRect(780,5,50,50));
    email->hide();
}


