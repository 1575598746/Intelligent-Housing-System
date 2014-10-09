#include "maingui.h"
#include "ui_maingui.h"

#include "dialoggui.h"
#include"qdebug.h"
#include <qtimer.h>
#include <QtCore>

#include <QCoreApplication>
#include <qdebug.h>
#include <QChar>
#include <QString>
#include "qzigbeethread.h"
#include "posix_qextserialport.h"

mainGUI::mainGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainGUI)
{
    ui->setupUi(this);

    //Zigbee SERIAL port
    SERIAL = "/dev/ttyS1";
    Posix_QextSerialPort * pSerial = NULL;

    pSerial = new Posix_QextSerialPort(SERIAL);

    //Message SERIAL port
    SERIAL_SMS = "/dev/ttySAC0";
    Posix_QextSerialPort * pSerial_sms = NULL;
    pSerial_sms = new Posix_QextSerialPort(SERIAL_SMS);


    //QZigbeeThread
    m_pZigbeeThread = new QZigbeeThread(pSerial);
    m_pZigbeeThread->start();

    //QMessageThread
    m_qMessageThread = new QMessageThread(pSerial_sms);
    m_qMessageThread->start();




    QTimer *timer = new QTimer(this);   //新建定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(xytimerUpDate()));//关联定时器计满信号和相应的槽函数
    timer->start(1000);

    connect(m_pZigbeeThread,SIGNAL(send_119_alert_sig(bool)),this,SLOT(call_119_now(bool)));

    //connect(smoke_alert_dialog,SIGNAL(send_119(bool)),this,SLOT(ok_call_119(bool)));

}

mainGUI::~mainGUI()
{
//    if(pSerial != NULL){

//        pSerial->close();
//        delete pSerial;
//        qDebug("close ttySAC1");
//    }

    delete ui;


}

//No.1  Zigbee information
void mainGUI::on_first_pushButton_clicked()
{
    dlg = new DialogGUI(m_pZigbeeThread->str);
    connect(dlg,SIGNAL(sendsignal(bool)),this,SLOT(getNewzigbeeinfo(bool)));

    connect(this,SIGNAL(signal(bool)),dlg,SLOT(refreshinfo(bool)));
    //dlg->getzigbeeinfo(str);
   dlg->exec();

    //delete dlg;
   qDebug("hello");
}


void mainGUI::xytimerUpDate()

{
    QDateTime time = QDateTime::currentDateTime();//get system time

    QString strTime = time.toString("yyyy-MM-dd /dddd /hh:mm:ss");//+" "+time.now.toString("dddd", new System.Globalization.CultureInfo("zh-cn"));//设置系统时间显示格式

    //ui->lcdNumber->display(strTime);

    ui->time_label->setText(strTime);
}


//void mainGUI::getzigbeeinfo()
//{

//    qDebug("hello");
//    dlg->zigbeeinfo = mainzigbeeinfo;
//    emit signal(0);
//}

void mainGUI::getNewzigbeeinfo(bool a)
{
    if(1 == a)
    {
      qDebug("hello2");
      mainzigbeeinfo = m_pZigbeeThread->getzigbee();
      dlg->zigbeeinfo = mainzigbeeinfo;
      emit signal(0);
    }

}





//No.2  entrance information
void mainGUI::on_entrance_pushButton_clicked()
{
    entrancedlg = new entranceDialog();
    entrancedlg->exec();
}

//No.3  remote information
void mainGUI::on_remote_pushButton_clicked()
{
    gprsdialog = new GPRSDialog(m_qMessageThread->number,m_qMessageThread->text);
    connect(gprsdialog,SIGNAL(send_sig_Call(bool)),this,SLOT(call(bool)));
    connect(gprsdialog,SIGNAL(send_sig_SMS(bool)),this,SLOT(sendsms(bool)));
    gprsdialog->exec();
}


void mainGUI::call(bool a){
    if(a == 1){
       m_qMessageThread->Call(gprsdialog->number);
    }
}

void mainGUI::sendsms(bool a){
    if(a == 1){
        m_qMessageThread->SendSMS(gprsdialog->number,gprsdialog->text);
    }
}

void mainGUI::on_SOS_pushButton_clicked()
{
    sosdialog = new SOSDialog();
    connect(sosdialog,SIGNAL(send_119_sig(bool)),m_qMessageThread,SLOT(call_119(bool)));
    connect(sosdialog,SIGNAL(send_120_sig(bool)),m_qMessageThread,SLOT(call_120(bool)));
    connect(sosdialog,SIGNAL(send_110_sig(bool)),m_qMessageThread,SLOT(call_110(bool)));
    connect(sosdialog,SIGNAL(send_family_sig(bool)),this,SLOT(family_call(bool)));
    connect(sosdialog,SIGNAL(send_friends_sig(bool)),this,SLOT(friends_call(bool)));
    connect(sosdialog,SIGNAL(send_colleagues_sig(bool)),this,SLOT(colleagues_call(bool)));
    sosdialog->exec();
}

void mainGUI::family_call(bool a){
    if(1 == a){
        m_qMessageThread->call_family(sosdialog->familyNum);
    }
}

void mainGUI::friends_call(bool a){
    if(1 == a){
        m_qMessageThread->call_friends(sosdialog->friendsNum);
    }
}

void mainGUI::colleagues_call(bool a){
    if(1 == a){
        m_qMessageThread->call_colleagues(sosdialog->colleaguesNum);
    }
}

void mainGUI::call_119_now(bool a){
    if(1 == a){
//        smoke_alert_dialog = new smoke_Alert_Dialog();
//        smoke_alert_dialog->exec();
        m_qMessageThread->call_119(1);
    }
}

void mainGUI::ok_call_119(bool a){
    if(1 == a){
        m_qMessageThread->call_119(1);
    }
}
