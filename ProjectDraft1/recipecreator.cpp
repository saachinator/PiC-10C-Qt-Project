#include "recipecreator.h"
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QFont>
#include <QDesktopServices>
#include <QUrl>

recipecreator::recipecreator(QWidget *parent) : QWidget(parent)
{
    QGridLayout * recipe_widget_layout = new QGridLayout;
  //  RecipeBook * recipe_book = new RecipeBook(1);
    QLabel * make_a_recipe = new QLabel("Make a Recipe!");
    QFont Add_Item_Button("Arial", 20, QFont::Bold);
    make_a_recipe->setFont(Add_Item_Button);
    button = new QPushButton("Search Recipes!");


    QLabel * number_1 = new QLabel ("1. ");
    QLabel * number_2 = new QLabel ("2. ");
    QLabel * number_3 = new QLabel ("3. ");
    QLabel * number_4 = new QLabel ("4. ");
    QLabel * number_5 = new QLabel ("5. ");

    QLineEdit * Item1 = new QLineEdit;
    Item1->setPlaceholderText("Item 1 (required)");
    QLineEdit * Item2 = new QLineEdit;
    Item2->setPlaceholderText("Item 2");
    QLineEdit * Item3 = new QLineEdit;
    Item3->setPlaceholderText("Item 3");
    QLineEdit * Item4 = new QLineEdit;
    Item4->setPlaceholderText("Item 4");
    QLineEdit * Item5 = new QLineEdit;
    Item5->setPlaceholderText("Item 5");

    recipe_widget_layout->addWidget(make_a_recipe, 0, 0, 1, -1, Qt::AlignCenter);
    recipe_widget_layout->addWidget(number_1, 1, 0);
    recipe_widget_layout->addWidget(Item1, 1, 1);
    recipe_widget_layout->addWidget(number_2,2,0);
    recipe_widget_layout->addWidget(Item2, 2, 1);
    recipe_widget_layout->addWidget(number_3,3,0);
    recipe_widget_layout->addWidget(Item3, 3, 1);
    recipe_widget_layout->addWidget(number_4,4,0);
    recipe_widget_layout->addWidget(Item4, 4, 1);
    recipe_widget_layout->addWidget(number_5,5,0);
    recipe_widget_layout->addWidget(Item5, 5, 1);
    recipe_widget_layout->addWidget(button, 6, 1, 1, -1, Qt::AlignRight);
 //   recipe_widget_layout->addWidget(recipe_book, 6,1, 1, -1, Qt::AlignRight);


    QString item_1 = Item1->text();
    QString item_2 = Item2->text();
    QString item_3 = Item3->text();
    QString item_4 = Item4->text();
    QString item_5 = Item5->text();
    QObject::connect(button, SIGNAL(clicked()), this, SLOT(this_button_clicked()));
    this->setStyleSheet("background-color: rgb(240,240,250);");
    this->setLayout(recipe_widget_layout);
}

QLineEdit& recipecreator::get_item1() const
{
    return *Item1;
}

QLineEdit& recipecreator::get_item2() const
{
    return *Item2;
}

QLineEdit& recipecreator::get_item3() const
{
    return *Item3;
}
QLineEdit& recipecreator::get_item4() const
{
    return *Item4;
}
QLineEdit& recipecreator::get_item5() const
{
    return *Item5;
}

void recipecreator::this_button_clicked(){
    QString item_1 = Item1->text();
    QString item_2 = Item2->text();
    QString item_3 = Item3->text();
    QString item_4 = Item4->text();
    QString item_5 = Item5->text();
    QString query = "https://www.google.com/search?q=recipe";

    if (item_1 != ""){
        query += "+";
        query += item_1;
    }
    if (item_2 != ""){
        query += "+";
        query += item_2;
    }
    if (item_3 != ""){
        query += "+";
        query += item_3;
    }
    if (item_4 != ""){
        query += "+";
        query += item_4;
    }
    if (item_5 != ""){
        query += "+";
        query += item_5;
    }

    QDesktopServices::openUrl(QUrl(query));
}

recipecreator::~recipecreator()
{
    delete button;
    delete Item1;
    delete Item2;
    delete Item3;
    delete Item4;
    delete Item5;
}
