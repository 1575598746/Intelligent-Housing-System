#include "maingui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainGUI w;
    w.show();

    //connect(QZigbeeThread,SIGNAL(getzigbee()),DialogGUI,SLOT(getzigbeeinfo()));
    
    return a.exec();
}
