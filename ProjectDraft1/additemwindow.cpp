#include "additemwindow.h"
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include "mainwindow.h"

AddItemWindow::AddItemWindow(QWidget *parent) : QMainWindow(parent)
{
    //first page
    QWidget * storage_location_page = new QWidget;
    QGridLayout * layout_location_page = new QGridLayout;

    QLabel *location_page_title = new QLabel("Where would you like to add your item?");
    QPushButton * freezer_location = new QPushButton("Freezer");
    QPushButton * fridge_location = new QPushButton("Fridge");
    QPushButton * cabinet_location = new QPushButton("Cabinet");
    QPushButton * counter_location = new QPushButton("Counter");

    layout_location_page->addWidget(location_page_title, 0,0, 1,-1, Qt::AlignCenter);
    layout_location_page->addWidget(freezer_location,1,0);
    layout_location_page->addWidget(fridge_location, 2,0);
    layout_location_page->addWidget(cabinet_location,3,0);
    layout_location_page->addWidget(counter_location,4,0);
    storage_location_page->setLayout(layout_location_page);

    //second page
    QWidget * add_item_page = new QWidget;
    QVBoxLayout * layout = new QVBoxLayout;

    add_name = new QLineEdit;
    add_name->setPlaceholderText("What is the name of your item?");
    add_expiration = new QLineEdit;
    add_expiration->setPlaceholderText("What's the expiration of your item (format: mm/dd/yy)?");
    add_size = new QLineEdit;
    add_size->setPlaceholderText("How many units of your item?");
    QLabel * title = new QLabel ("New Item");

    add_item_button = new QPushButton("Add Item!");

    layout->addWidget(title, 0, Qt::AlignCenter);
    layout->addWidget(add_name);
    layout->addWidget(add_expiration);
    layout->addWidget(add_size);
    layout->addWidget(add_item_button, 0, Qt::AlignCenter);
    add_item_page->setLayout(layout);


    AddItem_StackedWidget = new QStackedWidget;
    AddItem_StackedWidget->addWidget(storage_location_page);
    AddItem_StackedWidget->addWidget(add_item_page);

    this->setCentralWidget(AddItem_StackedWidget);

    QObject::connect(freezer_location, SIGNAL(clicked()), this, SLOT(gotoSecondWindow()));
    QObject::connect(fridge_location, SIGNAL(clicked()), this, SLOT(gotoSecondWindow()));
    QObject::connect(cabinet_location, SIGNAL(clicked()), this, SLOT(gotoSecondWindow()));
    QObject::connect(counter_location, SIGNAL(clicked()), this, SLOT(gotoSecondWindow()));
    QObject::connect(add_item_button, SIGNAL(clicked()), this, SLOT(button_clicked()));
    QObject::connect(add_item_button, SIGNAL(clicked()), this, SLOT(close()));

    this->setFixedSize(400,200);
}

QLineEdit& AddItemWindow::get_name() const
{
    return *add_name;
}
QLineEdit& AddItemWindow::get_expiration() const
{
    return *add_expiration;
}
QLineEdit& AddItemWindow::get_size() const
{
    return *add_size;
}
void AddItemWindow::button_clicked()
{
    QString name = add_name->text();
    QString expiration = add_expiration->text();
    QString string_unit = add_size->text();
    int unit = string_unit.toInt();
    emit value_is_cut(FoodItem (name, expiration, unit));
}

/*void AddItemWindow::add_item()
{
    //make QValidator derived class to check if the input is correct in the textlines
}*/

void AddItemWindow::gotoSecondWindow()
{
    AddItem_StackedWidget->setCurrentIndex(1);
}


