#include "mainwindowm.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowM w;

    w.show();

    return a.exec();
}
