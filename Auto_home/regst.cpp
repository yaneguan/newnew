#include "regst.h"

Regst::Regst(QWidget *parent) : QWidget(parent)
{
    this->setAutoFillBackground(true);
    this->resize(600,400);
    this->setWindowTitle("注册");
    this->setWindowIcon(QIcon(":/fs_logo.png"));
     QPalette palette;
     palette.setBrush (QPalette::Background, QBrush(QPixmap(":/home_bh.png").scaled (this->size ())));
     this->setPalette(palette);

     name = new QLineEdit(this);
     name->setAutoFillBackground(true);
     name->resize(120,25);
     name->setGeometry(440,170,name->width(),name->height());

     notice = new QLabel(this);
     notice->resize(120,20);
     notice->setGeometry(440,267,notice->width(),notice->height());
     QPalette pe;
     pe.setColor(QPalette::WindowText,Qt::red);
     notice->setPalette(pe);
     notice->setText("(32个字母和整数组成)");

     passwd = new QLineEdit(this);
     passwd->resize(120,25);
     passwd->setGeometry(440,240,passwd->width(),passwd->height());

     passwd->setEchoMode(QLineEdit::Normal);

     tel = new QLineEdit(this);
//     tel->setAutoFillBackground(true);
     tel->resize(120,25);
     tel->setGeometry(440,300,name->width(),name->height());

     over = new QPushButton(this);
     over->resize(70,30);
     over->setGeometry(470,300,over->width(),over->height());
     over->setText("注册");
     socket = new QTcpSocket;

     //控制输入栏格式，账号仅允许大小写32个英文字母+数字组成
//     QRegExp px("^[a-zA-Z0-9]+$");
//     tor = new QRegExpValidator(px,this);
//     passwd->setValidator(tor);
//     //密码不允许出现空格
//     QRegExp xx("^[\\S]*$");
//     tur = new QRegExpValidator(xx,this);
//     passwd->setValidator(tur);
//     name->setValidator(tur);

//     QRegExp xy("^[0-9]*[1-9][0-9]*$");
//     tvr = new QRegExpValidator(xy,this);
//     name->setValidator(tvr);


    //将密码显示为隐藏
 //    passwd->setEchoMode(QLineEdit::Password);

    connect(over,SIGNAL(clicked(bool)),this,SLOT(exam_func()));
    connect(passwd,SIGNAL(returnPressed()),this,SLOT(exam_func()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(recv_info()));
//    connect(socket,SIGNAL(disconnected()),this,SLOT(connect_exam()));


}

void Regst::paintEvent(QPaintEvent *)
{
    QPainter pv(this);
          QPen pen;
          pv.setPen(pen);
          pv.drawImage(QRectF(380,150,60,60),QImage(":/manger.png"));
          pv.drawImage(QRectF(390,220,45,45),QImage(":/lock_ico.png"));

}




void Regst::exam_func()
{

    struct data_deliver data_info;
//    const char * a = n1->text().toStdString().data();
//    QString p = n1->text().trimmed();
//    char *a = p.toStdString();
//    data_info.data1 = n2->text().toStdString().data();
//    data_info.data2 = n3->text().toStdString().data();


    data_info.data_type = 10;
    data_info.func_num = DATA_TYPE;

    User_name = name->text().trimmed();
    User_pass = passwd->text().trimmed();
    Telphone = tel->text().trimmed();

    qDebug()<<"注册";
    qDebug()<<"用户名"<<User_name;
    qDebug()<<"密码"<<User_pass;
    us.insert("_username",User_name);
    us.insert("_phone",Telphone);
    us.insert("_password",User_pass);

    QJsonDocument send_doc;
    send_doc.setObject(us);
    QByteArray by = send_doc.toJson(QJsonDocument::Compact);

    data_info.data_length= User_name.size()+User_pass.size()+Telphone.size();
    //
    QByteArray block;
    QDataStream out(&block,QIODevice::ReadWrite);  //使用数据流写入数据

        out.setVersion(QDataStream::Qt_4_9);//设置版本号
        out.setByteOrder(QDataStream::LittleEndian);//设置大小端模式

        out<<uchar(0)<<uchar(0)<<ushort(0);//先用其他数占用前面四个位置

        out.device()->seek(0);//把位置符设置到起始位
        uchar type_id=uchar(0xaa);
        uchar fun_id=0x00;//设置好标志位表示登录还是注册等
        ushort mesg_len = by.size();//传过来的json字符串的长度

        out<<type_id<<fun_id<<mesg_len;//将开始占用的4个位置填充
       by.insert(0,block);//然后插入到json包的前面
//        qDebug() <<array.size() ;
//        qDebug() <<array ;

    socket->connectToHost("192.168.0.137",1111);
    qDebug()<<"连接状态:"<<socket->state();
    //发送账号密码给服务器
    if(socket->state() == QAbstractSocket::ConnectingState)
    {/*
//       socket->write(user_name,qstrlen(user_name));
//        socket->write(user_pass),qstrlen(user_pass);
        socket->write((char *)&data_info.data_type,4);
        qDebug()<<data_info.data_type;
        socket->write((char *)&data_info.func_num,4);
//        socket->write((char *)&data_info.hev,4);
        qDebug()<<data_info.func_num;
         socket->write((char *)&data_info.data_length,4);*/
        socket->write(by);


    }else if(this->close()){
        qDebug()<<"have close";
    }else{
        QMessageBox::warning(this,tr("警告"),tr("注册未连接，请重连"),QMessageBox::Yes);
    }

    if(name->text().trimmed() == ("1314520") && passwd->text() == tr("super7758"))
    {
            acceptDrops();
            this->close();

    }
    else{
        qDebug()<<"has close";
//        QMessageBox::warning(this,tr("警告"),tr("密码有误,请重新输入"),QMessageBox::Yes);
//        passwd->clear();
//        passwd->setFocus();
    }
}

void Regst::recv_info()
{
    QByteArray dav = socket->readAll();
    uchar state = dav[1];
//    qDebug()<<"data = "<<dav;
//    QJsonObject dat;
//    dat.insert("StateCode",0);
//    QJsonDocument tv;
//    tv.setObject(dat);
//    tv.toJson(QJsonDocument::Compact) = dav;
    if(state == 0)
    {
            QMessageBox::information(NULL,"注册","注册成功，请登录",QMessageBox::Yes);
            this->close();
            socket->close();
    }
    else
    {
        QMessageBox::information(NULL,"注册","注册有误，请重新输入",QMessageBox::Yes);
//          QMessageBox::warning(this,tr("完成"),tr("输入有误，请重新输入"),QMessageBox::Yes);
          name->clear();
          passwd->clear();
          tel->clear();
          name->setFocus();
    }
}


Regst::~Regst()
{
     delete line_name;
     delete line_passwd;
     delete re_passwd;
     delete name;
     delete passwd;
     delete over;
     delete tor;
     delete tur;
     delete socket;
     delete tvr;
     delete notice;

}
//void Regst::connect_exam()
//{
//    if(socket->state() == QAbstractSocket::ConnectingState)
//    {
//        qDebug()<<"连接状态:"<<socket->state();
//    }
//    else{
//        QMessageBox::information(NULL,"注意","连接失败哦，请重连",QMessageBox::Yes);
//        this->close();
//    }
//}
