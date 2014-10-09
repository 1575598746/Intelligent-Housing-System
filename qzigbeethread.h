#ifndef QZIGBEETHREAD_H
#define QZIGBEETHREAD_H

#include <QThread>
#include <QMainWindow>
#include "posix_qextserialport.h"
#include <QDebug>

class QZigbeeThread : public QThread
{
    Q_OBJECT
public:
    explicit QZigbeeThread(Posix_QextSerialPort * pCom,QObject *parent = 0);

    QString str;

    friend class dialogGUI;


    QString getzigbee();
    
signals:
//    void sendsignal(bool a);
    void send_119_alert_sig(bool a);
public slots:

public:
    void run();

private:
    //QMainWindow *m_pOwner;//MainWindow pointer
    Posix_QextSerialPort *m_com;


    
};

#endif // QZIGBEETHREAD_H
