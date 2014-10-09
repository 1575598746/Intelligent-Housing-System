#ifndef DIALOGGUI_H
#define DIALOGGUI_H

#include <QDialog>
#include "maingui.h"
#include "qzigbeethread.h"

namespace Ui {
class DialogGUI;
}

class mainGUI;

class DialogGUI : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogGUI(QString str,QWidget *parent = 0);
    ~DialogGUI();
    friend class mainGUI;

    QString zigbeeinfo;

    //void getzigbeeinfo(QString str);



signals:
    void sendsignal(bool a);

private slots:

    void zig_close_pushButton_click();

    void refresh_pushButton_clicked();

    void refreshinfo(bool a);

    //void receivesig(bool a, mainGUI &maingui);

    //void refresh(bool a, QZigbeeThread &zigbeethread);

private:
    Ui::DialogGUI *ui;



};

#endif // DIALOGGUI_H
