#ifndef ENTRANCEDIALOG_H
#define ENTRANCEDIALOG_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>

namespace Ui {
class entranceDialog;
}

class entranceDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit entranceDialog(QWidget *parent = 0);
    ~entranceDialog();
    
private slots:
    void on_insert_pushButton_clicked();

private:
    Ui::entranceDialog *ui;

    //member
    bool m_bOpen;
    QSqlDatabase m_database;
    QSqlQueryModel *m_pModel;
};

#endif // ENTRANCEDIALOG_H
