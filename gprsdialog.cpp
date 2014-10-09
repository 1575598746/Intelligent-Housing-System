#include "gprsdialog.h"
#include "ui_gprsdialog.h"

GPRSDialog::GPRSDialog(char *number, char *text, QWidget *parent):
    QDialog(parent),
    ui(new Ui::GPRSDialog)
{
    ui->setupUi(this);
    readNumber = number;
    readText = text;
}

GPRSDialog::~GPRSDialog()
{
    delete ui;
}

//void GPRSDialog::flag()
//{
//    if(Flag == 1){
//        ui->flag_label->setText("new message");
//    }
//}

void GPRSDialog::on_call_pushButton_clicked()
{
    number = ui->lineEdit->text();
    emit send_sig_Call(1);
}

void GPRSDialog::on_sendmes_pushButton_clicked()
{
    number = ui->lineEdit->text();
    text = ui->textEdit->toPlainText();
    emit send_sig_SMS(1);

}

void GPRSDialog::on_read_pushButton_clicked()
{
    ui->lineEdit->setText(readNumber);
    ui->textEdit->setText(readText);
}
