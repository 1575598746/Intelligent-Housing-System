#include "entrancedialog.h"
#include "ui_entrancedialog.h"

entranceDialog::entranceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::entranceDialog)
{
    ui->setupUi(this);

    //
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("database.db");
    m_pModel = new QSqlQueryModel;
    m_bOpen = m_database.open();

    if(m_bOpen){
        QSqlQuery query(m_database);
        query.exec("create table student (id integer primary key,name varchar)");
        query.exec("");
        query.exec("");

        m_pModel->setQuery("select * from student");
        m_pModel->setHeaderData(0,Qt::Horizontal,tr("id"));
        m_pModel->setHeaderData(1,Qt::Horizontal,tr("name"));

        //ui->tableView->setModel(m_pModel);
        //ui->tableView->show();
    }
}

entranceDialog::~entranceDialog()
{
    delete ui;
}

void entranceDialog::on_insert_pushButton_clicked()
{
    QSqlQuery query;
    if(ui->id_lineEdit->text().isEmpty() || ui->name_lineEdit->text().isEmpty()){
//shu ru bu neng wei kong
    }

    QString name = ui->name_lineEdit->text();
    QString id = ui->id_lineEdit->text();

    QString sql ="";
    sql +="select * from student where name like '";
    sql +=name+"'";
}
