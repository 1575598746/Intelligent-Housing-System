#include "dialoggui.h"
#include "ui_dialoggui.h"
#include "qzigbeethread.h"
#include "maingui.h"
#include <QDebug>

DialogGUI::DialogGUI(QString str, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogGUI)
{
    ui->setupUi(this);
    ui->zigbee_label->setText(str);
    ui->zigbee_label->adjustSize();

    //connect(ui->refresh_pushButton,SIGNAL(clicked()),this,SLOT(refresh_pushButton_clicked()));

    connect(ui->refresh_pushButton,SIGNAL(clicked()),this,SLOT(refresh_pushButton_clicked()));

    connect(ui->zig_close_pushButton,SIGNAL(clicked()),this,SLOT(zig_close_pushButton_click()));

    //connect(mainGUI,SIGNAL(signal(bool)),this,SLOT(refreshinfo(bool)));

    //m_pZigbeeThread_1 = new



//    ui->zigbee_label->setGeometry(QRect(328, 240, 329, 27*4));  //四倍行距

//    ui->zigbee_label->setWordWrap(true);
//    ui->zigbee_label->setAlignment(Qt::AlignTop);

}


DialogGUI::~DialogGUI()
{
    delete ui;
}

void DialogGUI::zig_close_pushButton_click()
{
    qDebug("hello");
    this->close();
}


void DialogGUI::refreshinfo(bool a){
    if(0 == a){
        qDebug("hello3");
    ui->zigbee_label->setText(zigbeeinfo);
    }
}




//refresh information of temp&tum
void DialogGUI::refresh_pushButton_clicked()
{
    qDebug("hello1");
    emit sendsignal(1);
    //ui->zigbee_label->setText(zigbeeinfo);
    //ui->zigbee_label->setText(maingui.m_pZigbeeThread->str);
}

//void DialogGUI::receivesig(bool a, mainGUI &maingui)
//{
//    if(a == 1)
//    {
//       ui->zigbee_label->setText(maingui.m_pZigbeeThread->str);
//    }

//}

//void DialogGUI::refresh(bool a, QZigbeeThread& zigbeethread)
//{

//    if(1 == a){
//
//       QString str = zigbeethread.getzigbee();
//       ui->zigbee_label->setText(str);
//    }
//}
