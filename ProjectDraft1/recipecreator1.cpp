#include "recipecreator1.h"
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QPainter>
#include <QFont>
#include <QDesktopServices>
#include <QUrl>

RecipeCreator1::RecipeCreator1(QWidget *parent) : QWidget(parent)
{
    recipe_widget_layout = new QGridLayout;
  //  RecipeBook * recipe_book = new RecipeBook(1);
    QLabel * make_a_recipe = new QLabel("Search for a Recipe!");
    QFont Add_Item_Button("Arial", 20, QFont::Bold);
    make_a_recipe->setFont(Add_Item_Button);
    book = new RecipeBook(1);

    clear_fields_button = new QPushButton ("Clear Fields");
    QPalette pal = clear_fields_button->palette();
 //   pal.setColor(QPalette::Button, QColor(90,107,47));
  //  clear_fields_button()->setAutoFillBackground(true);
 //   clear_fields_button()->setPalette(pal);
    clear_fields_button->setStyleSheet("background-color: rgb(245,220,160);");

    QLabel * number_1 = new QLabel ("1. ");
    QLabel * number_2 = new QLabel ("2. ");
    QLabel * number_3 = new QLabel ("3. ");
    QLabel * number_4 = new QLabel ("4. ");
    QLabel * number_5 = new QLabel ("5. ");

    Item1 = new QLineEdit;
    Item1->setPlaceholderText("Item 1 (Required)");
    Item2 = new QLineEdit;
    Item2->setPlaceholderText("Item 2");
    Item3 = new QLineEdit;
    Item3->setPlaceholderText("Item 3");
    Item4 = new QLineEdit;
    Item4->setPlaceholderText("Item 4");
    Item5 = new QLineEdit;
    Item5->setPlaceholderText("Item 5");

    allergies = new QLineEdit;
    allergies->setPlaceholderText("Allergy Name");


    vegan_button = new QRadioButton("Vegan");
    vegetarian_button = new QRadioButton("Vegetarian");
    neither_button = new QRadioButton("N/A");
    neither_button->setChecked(true);

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
    recipe_widget_layout->addWidget(vegan_button, 6, 1, Qt::AlignRight);
    recipe_widget_layout->addWidget(vegetarian_button, 6, 1, Qt::AlignLeft);
    recipe_widget_layout->addWidget(allergies, 7, 1, Qt::AlignLeft);
    recipe_widget_layout->addWidget(neither_button, 7, 1, Qt::AlignRight);
    recipe_widget_layout->addWidget(clear_fields_button, 8, 1, 1, -1, Qt::AlignLeft);
    recipe_widget_layout->addWidget(book, 8, 1, 1, -1, Qt::AlignRight);

    QObject::connect(book, SIGNAL(clicked()), this, SLOT(this_button_clicked()));
    QObject::connect(clear_fields_button, SIGNAL(clicked()), this, SLOT(clear_button_clicked()));
    this->setLayout(recipe_widget_layout);
}



QLineEdit& RecipeCreator1::get_item1() const
{
    return *Item1;
}

QLineEdit& RecipeCreator1::get_item2() const
{
    return *Item2;
}

QLineEdit& RecipeCreator1::get_item3() const
{
    return *Item3;
}
QLineEdit& RecipeCreator1::get_item4() const
{
    return *Item4;
}
QLineEdit& RecipeCreator1::get_item5() const
{
    return *Item5;
}

void RecipeCreator1::this_button_clicked(){
    QString item_1 = Item1->text();
    QString item_2 = Item2->text();
    QString item_3 = Item3->text();
    QString item_4 = Item4->text();
    QString item_5 = Item5->text();
    QString allergy = allergies->text();
    QString query = "https://www.google.com/search?q=recipe";
    if (item_1 == ""){
        clear_button_clicked();
    } else {
        if (vegan_button->isChecked()){
            query += "+vegan";
        }
        if (vegetarian_button->isChecked()){
            query += "+vegetarian";
        }
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
        if (allergy != ""){
            query += "+no+";
            query += allergy;
        }
        QDesktopServices::openUrl(QUrl(query));
        clear_button_clicked();
    }

}

void RecipeCreator1::clear_button_clicked(){
    Item1->clear();
    Item2->clear();
    Item3->clear();
    Item4->clear();
    Item5->clear();
    allergies->clear();
    neither_button->setChecked(true);
    vegan_button->setChecked(false);
    vegetarian_button->setChecked(false);
}

RecipeCreator1::~RecipeCreator1()
{
    delete button;
    delete Item1;
    delete Item2;
    delete Item3;
    delete Item4;
    delete Item5;
}
