#ifndef SOS_SETTINGS_DIALOG_H
#define SOS_SETTINGS_DIALOG_H

#include <QDialog>

namespace Ui {
class SOS_settings_Dialog;
}

class SOS_settings_Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SOS_settings_Dialog(QWidget *parent = 0);
    ~SOS_settings_Dialog();

    QString family_Num;
    QString friends_Num;
    QString colleagues_Num;
    
private slots:
    void on_famNum_pushButton_clicked();

    void on_friNum_pushButton_clicked();

    void on_colNum_pushButton_clicked();

signals:
    void famNum_confirm_sig(bool a);
    void friNum_confirm_sig(bool a);
    void colNum_confirm_sig(bool a);

private:
    Ui::SOS_settings_Dialog *ui;
};

#endif // SOS_SETTINGS_DIALOG_H
