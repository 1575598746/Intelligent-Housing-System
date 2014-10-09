#include "sos_settings_dialog.h"
#include "ui_sos_settings_dialog.h"

SOS_settings_Dialog::SOS_settings_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SOS_settings_Dialog)
{
    ui->setupUi(this);

}

SOS_settings_Dialog::~SOS_settings_Dialog()
{
    delete ui;
}

void SOS_settings_Dialog::on_famNum_pushButton_clicked()
{
    family_Num = ui->familyNum_lineEdit->text();
    emit famNum_confirm_sig(1);
}

void SOS_settings_Dialog::on_friNum_pushButton_clicked()
{
    friends_Num = ui->friendsNum_lineEdit->text();
    emit friNum_confirm_sig(1);
}

void SOS_settings_Dialog::on_colNum_pushButton_clicked()
{
    colleagues_Num = ui->colleaguesNum_lineEdit->text();
    emit colNum_confirm_sig(1);
}
