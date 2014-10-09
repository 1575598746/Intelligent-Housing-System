#ifndef QMESSAGETHREAD_H
#define QMESSAGETHREAD_H

#include "posix_qextserialport.h"
#include "gprsdialog.h"
#include <QThread>

class QMessageThread : public QThread
{
    Q_OBJECT
public:
    explicit QMessageThread(Posix_QextSerialPort *pCom, QObject *parent = 0);

    void run();

    //GPRSDialog *m_Qgprsdialog;

    //char *readString;

    //int Flag;

    //QString readAllStr;

    char *number;
    char *text;

    QString callnumber;
    QString smstext;
    
signals:
    
public slots:
    void Call(QString number);
    void SendSMS(QString number, QString text);

    void call_119(bool a);
    void call_120(bool a);
    void call_110(bool a);
    void call_family(QString number);
    void call_friends(QString number);
    void call_colleagues(QString number);

private:
    Posix_QextSerialPort *m_com;
    
};

#endif // QMESSAGETHREAD_H
