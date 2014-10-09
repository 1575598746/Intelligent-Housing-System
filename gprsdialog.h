#ifndef GPRSDIALOG_H
#define GPRSDIALOG_H

#include <QDialog>

namespace Ui {
class GPRSDialog;
}

class GPRSDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit GPRSDialog(char *number, char *text, QWidget *parent = 0);
    ~GPRSDialog();
    //QString readInfo;

    QString readNumber;
    QString readText;

    QString number;
    QString text;

signals:
    void send_sig_Call(bool a);
    void send_sig_SMS(bool a);

    
private slots:
    void on_call_pushButton_clicked();

    void on_sendmes_pushButton_clicked();

    void on_read_pushButton_clicked();

private:
    Ui::GPRSDialog *ui;
};

#endif // GPRSDIALOG_H
