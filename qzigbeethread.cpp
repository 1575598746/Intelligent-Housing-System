#include "qzigbeethread.h"
#include <QDebug>
#include <stdlib.h>

QZigbeeThread::QZigbeeThread(Posix_QextSerialPort *pCom, QObject *parent) :
    m_com(pCom),QThread(parent)
{
    //m_pOwner = pCom;

    //she zhi chuan kou bo te lv
//    m_com.setBaudRate(BAUD115200);
//    //she zhi shu ju wei
//    m_com.setDataBits(DATA_8);
//    //she zhi ting zhi wei
//    m_com.setStopBits(STOP_1);
//    //
//    m_com.setParity(PAR_NONE);
//    //da kai chuan kou
//    m_com.open(QIODevice::ReadWrite);

    m_com->setBaudRate(BAUD115200);
    m_com->setDataBits(DATA_8);
    m_com->setStopBits(STOP_1);
    m_com->setParity(PAR_NONE);

    m_com->setFlowControl(FLOW_OFF);
    m_com->setTimeout(10);

    if(m_com->open(QIODevice::ReadWrite)){
        qDebug("open ttySAC1");
    }



}

void QZigbeeThread::run(){
    char buffer[26] = {0};
    //init 0
    //memset(buffer, 0, sizeof(buffer));
    //int size = -1;
    while(1){
        //qDebug("get into while");
        int size = m_com->read(buffer, 1);//read one byte and judge
        usleep(30);

        //qDebug("start to read");
        sleep(2);
        //qDebug("size = %d buffer[%d] = 0x%02x ",size,0, (char)buffer[0]);
        if(size > 0 && buffer[0] == (qint8)0xEE){//0xEEruo bu jin xing zhuan huan shi yi ge 32 wei shu
//            qDebug("get into if");
            size = m_com->read(buffer + 1, 25);



//            if(size > 0 && buffer[1] == (unsigned char)0xCC && buffer[25] == (unsigned char)0xFF){
//                qDebug("get into buffer");
//                //compute temp & hum
//                //if(size > 0 && buffer[14] == 0x)
                for(int i = 0; i < 26; ++i){
                    qDebug("buffer[%d] = %02x", i, (qint8)buffer[i]);
                }
                switch(buffer[14]){
                case (qint8)0x0A:{
                    qDebug("get into case");
                    double hum = ((qint8)buffer[19]*256 + (qint8)buffer[20]) / 10.0;
                    double temp = ((qint8)buffer[21]*256 + (qint8)buffer[22]) / 10.0;
                    QString humstr = QString::number(hum,'lf',2);
                    QString tempstr = QString::number(temp,'lf',2);
                    str = "";
                    str += "the humidity is ";
                    str += humstr;
                    str += "\n\nthe temperature is ";
                    str += tempstr;

                    qDebug("the humidity is %.2lf %\nthe temperature is %.2lf C", (double)hum, (double)temp);
                    qDebug(str.toStdString().c_str());
                }break;

                case (qint8)0x0B:{
                    if((qint8)buffer[22] == 0x01){
                        emit send_119_alert_sig(1);
                        qDebug("get smoke");
                    }
                }break;
                default:
                    break;

                }
//            }
        }
        //qDebug("about to leave while");
    }

    //m_com->close();
}



QString QZigbeeThread::getzigbee(){
    //emit sendsignal(1);
   return str;
}

//QString str = QString::number(num,10);
