#include "mainwindow.h"
#include <QApplication>

Semaphore Conveyor::empty = ARRAYLENTH;
Semaphore Conveyor::full = 0;
Semaphore Conveyor::mutex = 1;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
