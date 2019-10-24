#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void Fridge::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(Qt::gray));
    painter.drawRect(0*scale, 0*scale, 60*scale, 40*scale);
    painter.drawRect(0*scale, 40*scale, 60*scale, 80*scale);
    painter.drawRect(50*scale, 10*scale, 3*scale, 20*scale);
    painter.drawRect(50*scale, 50*scale, 3*scale, 50*scale);
}

Fridge::Fridge(size_t s) : scale(s) {}

QSize Fridge::sizeHint() const
{
    return QSize(60*scale,120*scale);
}
QSize Fridge::minimumSizeHint() const
{
    return QSize(60*scale,120*scale);
}

Counter::Counter (size_t s) : scale(s) {}

void Counter::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(Qt::gray));
    painter.drawRect(0*scale, 0*scale, 120*scale, 60*scale);
    //drawing left drawers
    painter.drawRect(3*scale, 4*scale, 30*scale, 10*scale);
    painter.drawEllipse(3*scale, 4*scale, 10*scale, 2*scale);
    painter.drawRect(3*scale, 16*scale, 30*scale, 10*scale);
    painter.drawRect(3*scale, 28*scale, 30*scale, 10*scale);
    painter.drawRect(3*scale, 40*scale, 30*scale, 16*scale);

    //drawing middle drawers
    painter.drawRect(35*scale, 4*scale, 30*scale, 10*scale);
    painter.drawRect(35*scale, 16*scale, 30*scale, 40*scale);

    //drawing right drawers
    painter.drawRect(67*scale, 4*scale, 30*scale, 10*scale);
    painter.drawRect(67*scale, 16*scale, 30*scale, 40*scale);
}

QSize Counter::sizeHint() const
{
    return QSize(100*scale,100*scale);
}
QSize Counter::minimumSizeHint() const
{
    return QSize(100*scale,100*scale);
}
