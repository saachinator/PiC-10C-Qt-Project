#include "addedititemwidget.h"
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QFont>
#include <QMessageBox>
#include "mainwindow.h"

AddEditItemWidget::AddEditItemWidget(bool is_add, QWidget *parent) : QWidget(parent)
{
    QGridLayout * layout_add_item = new QGridLayout;
    QLabel *location_page_title = nullptr;

    if (is_add==true)
    {
         location_page_title = new QLabel("Add Item");
    }
    else if (is_add==false)
    {
        location_page_title = new QLabel("Change Item");
    }

    QFont location_title_font ("Arial", 20, QFont::Bold);
    location_page_title->setFont(location_title_font);
    location_page_title->setAlignment(Qt::AlignTop);
    location_page_title->setWordWrap(true);

    QLabel * locationquestion = new QLabel ("Where would you like to store it?");
    fridge_button = new QRadioButton("Fridge");
    freezer_button = new QRadioButton("Freezer");
    cabinet_button = new QRadioButton("Cabinet");
    counter_button = new QRadioButton("Counter");

    layout_add_item->addWidget(location_page_title, 0,0, 1,-1, Qt::AlignCenter);
    layout_add_item->addWidget(locationquestion, 1, 0, 1, -1, Qt::AlignTop);
    layout_add_item->addWidget(fridge_button,2,0);
    layout_add_item->addWidget(freezer_button, 2,1);
    layout_add_item->addWidget(cabinet_button,3,0);
    layout_add_item->addWidget(counter_button,3,1);

    add_name = new QLineEdit;
    add_name->setPlaceholderText("What is the name of your item?");
    QLabel * expiration_label = new QLabel ("What's the expiration date?");
    add_expiration = new QDateEdit;
    add_expiration->setMinimumDate(QDate::currentDate());
    add_size = new QLineEdit;
    add_size->setPlaceholderText("How many units of your item?");

    if (is_add==true)
    {
        addchange_item_button = new QPushButton("Add Item!");
    }
    else if (is_add==false)
    {
        addchange_item_button = new QPushButton("Change Item!");
        delete_item_button = new QPushButton ("Delete Item");
    }

    cancel_add_item = new QPushButton("Cancel");

    layout_add_item->addWidget(add_name, 4, 0, 1, -1);
    layout_add_item->addWidget(expiration_label, 5, 0, 1, -1);
    layout_add_item->addWidget(add_expiration, 6, 0, 1, -1);
    layout_add_item->addWidget(add_size, 7, 0, 1, -1);
    layout_add_item->addWidget(addchange_item_button, 9, 0);
    if (is_add==false)
    {
        layout_add_item->addWidget(delete_item_button, 9,1);
        layout_add_item->addWidget(cancel_add_item, 10, 0, 1, -1);
    }
    else if (is_add==true)
    {
        layout_add_item->addWidget(cancel_add_item, 9,1);
    }

    layout_add_item->setRowStretch(0,2);
    layout_add_item->setRowStretch(7,1);

    QObject::connect(addchange_item_button, SIGNAL(clicked()), this, SLOT(button_clicked()));
    QObject::connect(addchange_item_button, SIGNAL(clicked()), this, SLOT(close_widget()));

    this->setLayout(layout_add_item);
}

QLineEdit& AddEditItemWidget::get_name() const
{
    return *add_name;
}
QDateEdit& AddEditItemWidget::get_expiration() const
{
    return *add_expiration;
}
QLineEdit& AddEditItemWidget::get_size() const
{
    return *add_size;
}
void AddEditItemWidget::button_clicked()
{
    QString name = add_name->text();
    QDate expiration = add_expiration->date();
    QString string_unit = add_size->text();
    int unit = string_unit.toInt();

    if (is_add==true)
    {
        //if the user does not input a name or unit amount or if the expiration is before the current date
        if (name==""||expiration<QDate::currentDate()||string_unit==""||unit<=0)
        {
            QMessageBox w(QMessageBox::NoIcon, "Input Error", "Something went wrong. Please change your input.");
            w.exec();
            return;
        }
        if (!fridge_button->isChecked()&&!freezer_button->isChecked()&&!cabinet_button->isChecked()&&!counter_button->isChecked())
        {
            QMessageBox w(QMessageBox::NoIcon, "Location Button Error", "Please choose a location for your item");
            w.exec();
            return;
        }
    }

    if (fridge_button->isChecked())
    {
        emit value_is_cut(FoodItem (name, expiration, unit), 1);
    }
    if (freezer_button->isChecked())
    {
        emit value_is_cut(FoodItem (name, expiration, unit), 2);
    }
    if (cabinet_button->isChecked())
    {
        emit value_is_cut(FoodItem (name, expiration, unit), 3);
    }
    if (counter_button->isChecked())
    {
        emit value_is_cut(FoodItem (name, expiration, unit), 4);
    }
}



void AddEditItemWidget::close_widget()
{
    add_name->clear();
    add_expiration->clear();
    add_size->clear();

    fridge_button->setAutoExclusive(false);
    freezer_button->setAutoExclusive(false);
    cabinet_button->setAutoExclusive(false);
    counter_button->setAutoExclusive(false);

    fridge_button->setChecked(false);
    freezer_button->setChecked(false);
    cabinet_button->setChecked(false);
    counter_button->setChecked(false);

    fridge_button->setAutoExclusive(true);
    freezer_button->setAutoExclusive(true);
    cabinet_button->setAutoExclusive(true);
    counter_button->setAutoExclusive(true);

    this->close();
}
void AddEditItemWidget::setTextDate(const FoodItem& f)
{
    add_name->setText(f.get_name());
    add_size->setText(QString::number(f.get_size()));
    add_expiration->setDate(f.get_expiration());
    fridge_button->setEnabled(false);
    cabinet_button->setEnabled(false);
    freezer_button->setEnabled(false);
    counter_button->setEnabled(false);
}
AddEditItemWidget::~AddEditItemWidget()
{
    delete addchange_item_button;
    delete add_name;
    delete add_expiration;
    delete add_size;
    delete delete_item_button;
}


