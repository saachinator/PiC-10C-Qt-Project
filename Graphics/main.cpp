#include "mainwindow.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget * window = new QWidget;
    QHBoxLayout * fri = new QHBoxLayout;
    QWidget * Fridge_1 = new Fridge(5);
    QWidget * Counter_1 = new Counter(5);
    fri->addWidget(Counter_1);
    fri->addWidget(Fridge_1);

    window->setLayout(fri);
    window->show();

    return a.exec();
}
