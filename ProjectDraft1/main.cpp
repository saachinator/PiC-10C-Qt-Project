#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w; //this is the main window with the kitchen layout
    w.show();
    return a.exec();
}
