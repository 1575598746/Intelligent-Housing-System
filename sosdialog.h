#ifndef SOSDIALOG_H
#define SOSDIALOG_H

#include <QDialog>
#include "sos_settings_dialog.h"

namespace Ui {
class SOSDialog;
}

class SOSDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SOSDialog(QWidget *parent = 0);
    ~SOSDialog();

    QString familyNum;
    QString friendsNum;
    QString colleaguesNum;
    
private slots:
    void on_call119_pushButton_clicked();

    void on_call120_pushButton_clicked();

    void on_call110_pushButton_clicked();

    void on_family_pushButton_clicked();

    void on_friends_pushButton_clicked();

    void on_colleagues_pushButton_clicked();

    void on_settings_pushButton_clicked();

    void famNum_confirm(bool a);

    void friNum_confirm(bool a);

    void colNum_confirm(bool a);


signals:
    void send_119_sig(bool a);

    void send_120_sig(bool a);

    void send_110_sig(bool a);

    void send_family_sig(bool a);

    void send_friends_sig(bool a);

    void send_colleagues_sig(bool a);

private:
    Ui::SOSDialog *ui;

    SOS_settings_Dialog *sosSettingsDlg;
};

#endif // SOSDIALOG_H
