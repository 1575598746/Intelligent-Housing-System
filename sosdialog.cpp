#include "sosdialog.h"
#include "ui_sosdialog.h"

SOSDialog::SOSDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SOSDialog)
{
    ui->setupUi(this);
}

SOSDialog::~SOSDialog()
{
    delete ui;
}

void SOSDialog::on_call119_pushButton_clicked()
{
    emit send_119_sig(1);
}

void SOSDialog::on_call120_pushButton_clicked()
{
    emit send_120_sig(1);
}

void SOSDialog::on_call110_pushButton_clicked()
{
    emit send_110_sig(1);
}

void SOSDialog::on_family_pushButton_clicked()
{
    emit send_family_sig(1);
}

void SOSDialog::on_friends_pushButton_clicked()
{
    emit send_friends_sig(1);
}

void SOSDialog::on_colleagues_pushButton_clicked()
{
    emit send_colleagues_sig(1);
}


void SOSDialog::on_settings_pushButton_clicked()
{
    sosSettingsDlg = new SOS_settings_Dialog();
    connect(sosSettingsDlg,SIGNAL(famNum_confirm_sig(bool)),this,SLOT(famNum_confirm(bool)));
    connect(sosSettingsDlg,SIGNAL(friNum_confirm_sig(bool)),this,SLOT(friNum_confirm(bool)));
    connect(sosSettingsDlg,SIGNAL(colNum_confirm_sig(bool)),this,SLOT(colNum_confirm(bool)));
    sosSettingsDlg->exec();
}

void SOSDialog::famNum_confirm(bool a){
    if(1 == a){
         familyNum = sosSettingsDlg->family_Num;
     }
}

void SOSDialog::friNum_confirm(bool a){
    if(1 == a){
             friendsNum = sosSettingsDlg->friends_Num;
         }
}

void SOSDialog::colNum_confirm(bool a){
    if(1 == a){
             colleaguesNum = sosSettingsDlg->colleagues_Num;
         }
}


