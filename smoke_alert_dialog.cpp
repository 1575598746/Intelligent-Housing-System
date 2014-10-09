#include "smoke_alert_dialog.h"
#include "ui_smoke_alert_dialog.h"

smoke_Alert_Dialog::smoke_Alert_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::smoke_Alert_Dialog)
{
    ui->setupUi(this);
    ui->label_2->setText("smoke detected! call 119?");
    ui->label_2->adjustSize();
}

smoke_Alert_Dialog::~smoke_Alert_Dialog()
{
    delete ui;
}

void smoke_Alert_Dialog::on_yes_pushButton_clicked()
{
    emit send_119(1);
}

void smoke_Alert_Dialog::on_no_pushButton_clicked()
{
    this->close();
}
