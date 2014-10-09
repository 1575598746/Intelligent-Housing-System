#ifndef MAINGUI_H
#define MAINGUI_H

#include <QMainWindow>
#include "dialoggui.h"
#include "qzigbeethread.h"
#include "entrancedialog.h"
#include "qmessagethread.h"
#include "gprsdialog.h"
#include "sosdialog.h"
#include "smoke_alert_dialog.h"

namespace Ui {
class mainGUI;
}

class DialogGUI;

class mainGUI : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit mainGUI(QWidget *parent = 0);
    ~mainGUI();
    //friend void on_refresh_pushButton_clicked(mainGUI &maingui);
    QZigbeeThread *m_pZigbeeThread;
    QMessageThread *m_qMessageThread;

    friend class DialogGUI;

    QString mainzigbeeinfo;

    QString SERIAL;

    QString SERIAL_SMS;



    //void getzigbeeinfo();

signals:
    void signal(bool a);


private slots:
    void on_first_pushButton_clicked();

    void xytimerUpDate();

    void getNewzigbeeinfo(bool a);

    void on_entrance_pushButton_clicked();

    void on_remote_pushButton_clicked();

    void call(bool a);

    void sendsms(bool a);

    void on_SOS_pushButton_clicked();

    void family_call(bool a);

    void friends_call(bool a);

    void colleagues_call(bool a);

    void call_119_now(bool a);

    void ok_call_119(bool a);

private:
    Ui::mainGUI *ui;

    DialogGUI *dlg;

    entranceDialog *entrancedlg;

    GPRSDialog *gprsdialog;

    SOSDialog *sosdialog;

    smoke_Alert_Dialog *smoke_alert_dialog;
};

#endif // MAINGUI_H





