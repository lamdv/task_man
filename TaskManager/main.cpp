#include "taskmanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    TaskManager w;
    w.show();

    return a.exec();
}
