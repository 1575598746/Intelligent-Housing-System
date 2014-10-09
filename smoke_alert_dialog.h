#ifndef SMOKE_ALERT_DIALOG_H
#define SMOKE_ALERT_DIALOG_H

#include <QDialog>

namespace Ui {
class smoke_Alert_Dialog;
}

class smoke_Alert_Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit smoke_Alert_Dialog(QWidget *parent = 0);
    ~smoke_Alert_Dialog();

signals:
    void send_119(bool a);
    
private slots:
    void on_yes_pushButton_clicked();

    void on_no_pushButton_clicked();

private:
    Ui::smoke_Alert_Dialog *ui;
};

#endif // SMOKE_ALERT_DIALOG_H
