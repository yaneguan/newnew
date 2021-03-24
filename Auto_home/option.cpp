#include "option.h"

Option::Option(QWidget *parent) : QWidget(parent)
{
    this->setAutoFillBackground(true);
        this->resize(1000,700);
         this->setWindowTitle("my_game");
        this->setWindowIcon(QIcon(":/fs_logo.png"));

        QPalette palette;
            palette.setBrush (QPalette::Background, QBrush(QPixmap(":/login_bj.jpg").scaled (this->size ())));
            this->setPalette(palette);

            on_1 = new QPushButton(this);
            on_1->setIcon(QIcon(":/ON.png"));
            QSize si(160,200);
            on_1->setIconSize(si);
            on_1->setGeometry(QRect(766,140,60,40));
            on_1->setFlat(true);
            on_1->hide();

            off_1 = new QPushButton(this);
            off_1->setIcon(QIcon(":/OFF.png"));
            off_1->setIconSize(si);
            off_1->setGeometry(QRect(766,140,60,40));
            off_1->setFlat(true);


            on_2= new QPushButton(this);
            on_2->setIcon(QIcon(":/ON.png"));
            on_2->setIconSize(si);
            on_2->setGeometry(QRect(766,270,60,40));
            on_2->setFlat(true);
            on_2->hide();

            off_2= new QPushButton(this);
            off_2->setIcon(QIcon(":/OFF.png"));
            off_2->setIconSize(si);
            off_2->setGeometry(QRect(766,270,60,40));
            off_2->setFlat(true);


            on_3= new QPushButton(this);
            on_3->setIcon(QIcon(":/ON.png"));
            on_3->setIconSize(si);
            on_3->setGeometry(QRect(766,430,60,40));
            on_3->setFlat(true);
            on_3->hide();

            off_3= new QPushButton(this);
            off_3->setIcon(QIcon(":/OFF.png"));
            off_3->setIconSize(si);
            off_3->setGeometry(QRect(766,430,60,40));
            off_3->setFlat(true);


            on_4= new QPushButton(this);
            on_4->setIcon(QIcon(":/ON.png"));
            on_4->setIconSize(si);
            on_4->setGeometry(QRect(766,580,60,40));
            on_4->setFlat(true);
            on_4->hide();

            off_4= new QPushButton(this);
            off_4->setIcon(QIcon(":/OFF.png"));
            off_4->setIconSize(si);
            off_4->setGeometry(QRect(766,580,60,40));
            off_4->setFlat(true);

            led1 = new QLabel(this);
            led1->setGeometry(QRect(766,50,60,85));
            led1->setPixmap(QPixmap(QString::fromUtf8(":/openled_ico.png")));
            led1->setScaledContents(true);
            led1->hide();

            led11 = new QLabel(this);
            led11->setGeometry(QRect(766,50,60,85));
            led11->setPixmap(QPixmap(QString::fromUtf8(":/closeled_ico.png")));
            led11->setScaledContents(true);


            led2 = new QLabel(this);
            led2->setGeometry(QRect(766,180,60,85));
            led2->setPixmap(QPixmap(QString::fromUtf8(":/openled_ico.png")));
            led2->setScaledContents(true);
            led2->hide();

            led22 = new QLabel(this);
            led22->setGeometry(QRect(766,180,60,85));
            led22->setPixmap(QPixmap(QString::fromUtf8(":/closeled_ico.png")));
            led22->setScaledContents(true);



            wind = new QLabel(this);
            wind->setGeometry(QRect(755,320,85,100));
            wind->setPixmap(QPixmap(QString::fromUtf8(":/openfan_ico.png")));
            wind->setScaledContents(true);
            wind->hide();

            wind1 = new QLabel(this);
            wind1->setGeometry(QRect(755,320,85,100));
            wind1->setPixmap(QPixmap(QString::fromUtf8(":/closefan_ico.png")));
            wind1->setScaledContents(true);


            door = new QLabel(this);
            door->setGeometry(QRect(755,480,85,100));
            door->setPixmap(QPixmap(QString::fromUtf8(":/opendoor_ico.png")));
            door->setScaledContents(true);
            door->hide();

            door1 = new QLabel(this);
            door1->setGeometry(QRect(755,480,85,100));
            door1->setPixmap(QPixmap(QString::fromUtf8(":/closedoor_ico.png")));
            door1->setScaledContents(true);


                    socket = new QTcpSocket;
                    connect(socket,SIGNAL(readyRead()),this,SLOT(recv_server()));
                    connect(on_1,SIGNAL(clicked(bool)),this,SLOT(led1_on()));
                    connect(off_1,SIGNAL(clicked(bool)),this,SLOT(led1_off()));
                    connect(on_2,SIGNAL(clicked(bool)),this,SLOT(led2_on()));
                    connect(off_2,SIGNAL(clicked(bool)),this,SLOT(led2_off()));
                    connect(on_3,SIGNAL(clicked(bool)),this,SLOT(wind_on()));
                    connect(off_3,SIGNAL(clicked(bool)),this,SLOT(wind_off()));
                    connect(on_4,SIGNAL(clicked(bool)),this,SLOT(door_on()));
                    connect(off_4,SIGNAL(clicked(bool)),this,SLOT(door_off()));



                    socket->connectToHost("192.168.215.1",8087);

                    //发送账号密码给服务器
                    if(socket->state() == QAbstractSocket::ConnectingState)
                    {

                        qDebug()<<"连接状态:"<<socket->state();
                    }
                    else if(this->close()){}
                    else{
                        QMessageBox::information(NULL,"注意","连接失败，请重连",QMessageBox::Yes);
                        this->close();
                    }

}

void Option::led1_light()
{
    led1->show();
   led1->setPixmap(QPixmap(QString::fromUtf8(":/openled_ico.png")));
   led11->hide();
}

void Option::led2_light()
{
    led2->show();
   led2->setPixmap(QPixmap(QString::fromUtf8(":/openled_ico.png")));
   led22->hide();
}

void Option::wind_light()
{
   wind->show();
   wind->setPixmap(QPixmap(QString::fromUtf8(":/openfan_ico.png")));
   wind1->hide();
}

void Option::door_light()
{
    door->show();
    door->setPixmap(QPixmap(QString::fromUtf8(":/opendoor_ico.png")));
    door1->hide();
}

void Option::led1_over()
{
    led11->show();

     led11->setPixmap(QPixmap(QString::fromUtf8(":/closeled_ico.png")));
     led1->hide();
}

void Option::led2_over()
{
    led22->show();

     led22->setPixmap(QPixmap(QString::fromUtf8(":/closeled_ico.png")));
     led2->hide();
}

void Option::wind_over()
{
    wind1->show();

     wind1->setPixmap(QPixmap(QString::fromUtf8(":/closefan_ico.png")));
     wind->hide();
}

void Option::door_over()
{
    door1->show();

     door1->setPixmap(QPixmap(QString::fromUtf8(":/closedoor_ico.png")));
     door->hide();
}


Option::~Option()
{
    delete on_1;
    delete on_2;
    delete on_3;
    delete on_4;
    delete off_1;
    delete off_2;
    delete off_3;
    delete off_4;
    delete led1;
     delete led11;
     delete led2;
     delete led22;
     delete wind;
     delete wind1;
     delete door;
     delete door1;
}

void Option::led1_on()
{
    off_1->show();
    off_1->setIcon(QIcon(":/OFF.png"));
    off_1->setIconSize(QSize(160,200));
    off_1->setGeometry(QRect(760,140,60,40));
    off_1->setFlat(true);
    on_1->hide();

    //led11->setAutoFillBackground(true);

    socket->write("led1_on");
}

void Option::led1_off()
{
    on_1->show();
    on_1->setIcon(QIcon(":/ON.png"));
    on_1->setIconSize(QSize(160,200));
    on_1->setGeometry(QRect(766,140,60,40));
    on_1->setFlat(true);
    off_1->hide();

   // led1->setAutoFillBackground(true);

    socket->write("led1_off");
}

void Option::led2_on()
{
    off_2->show();
    off_2->setIcon(QIcon(":/OFF.png"));
    off_2->setIconSize(QSize(160,200));
    off_2->setGeometry(QRect(766,270,60,40));
    off_2->setFlat(true);
    on_2->hide();

   socket->write("led2_on");

}

void Option::led2_off()
{
    on_2->show();
    on_2->setIcon(QIcon(":/ON.png"));
    on_2->setIconSize(QSize(160,200));
    on_2->setGeometry(QRect(766,270,60,40));
    on_2->setFlat(true);
    off_2->hide();
     socket->write("led2_off");
}

void Option::wind_on()
{
    off_3->show();
    off_3->setIcon(QIcon(":/OFF.png"));
    off_3->setIconSize(QSize(160,200));
    off_3->setGeometry(QRect(765,430,60,40));
    off_3->setFlat(true);
    on_3->hide();
    socket->write("wind_on");
}

void Option::wind_off()
{
    on_3->show();
    on_3->setIcon(QIcon(":/ON.png"));
    on_3->setIconSize(QSize(160,200));
    on_3->setGeometry(QRect(765,430,60,40));
    on_3->setFlat(true);
    off_3->hide();

    socket->write("wind_off");
}

void Option::door_on()
{
    off_4->show();
    off_4->setIcon(QIcon(":/OFF.png"));
    off_4->setIconSize(QSize(160,200));
    off_4->setGeometry(QRect(760,580,60,40));
    off_4->setFlat(true);
    on_4->hide();
     socket->write("door_on");
}

void Option::door_off()
{
    on_4->show();
    on_4->setIcon(QIcon(":/ON.png"));
    on_4->setIconSize(QSize(160,200));
    on_4->setGeometry(QRect(760,580,60,40));
    on_4->setFlat(true);
    off_4->hide();
    socket->write("door_off");
}

void Option::recv_server()
{
    QByteArray dav = socket->readAll();
    qDebug()<<"data = "<<dav;
    if(dav == "led1on")
    {
        led1_light();
    }
    else if(dav == "led1off")
    {
        led1_over();
    }
    else if(dav == "led2on")
    {
        led2_light();
    }
    else if(dav == "led2off")
    {
        led2_over();
    }
    else if(dav == "windon")
    {
        wind_light();
    }
    else if(dav == "windoff")
    {
        wind_over();
    }
    else if(dav == "dooron")
    {
        door_light();
    }
    else if(dav == "dooroff")
    {
        door_over();
    }
}
