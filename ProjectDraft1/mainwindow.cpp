#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "foodstoragewidget.h"
#include "additemwindow.h"
#include "Fridge.h"
#include "freezer.h"
#include "counter.h"
#include "cabinet.h"
#include <QLabel>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QFont>
#include <QSound>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QListWidget>
#include "recipebook.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QLabel * my_pantry = new QLabel("My Pantry"); //title of application at top of window
    add_item_button = new QPushButton ("Add Item"); //button to add food items to different storage widgets
    QPushButton * instructions_button = new QPushButton("Instructions"); //button to push for instructions
    QWidget * recipe_widget = new QWidget; //widget where we will add ingredients to search a recipe

    // Play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/atlast.mp3"));
    music->play();

    // different fonts for different buttons of labels
    QFont Add_Item_Button("Arial", 20, QFont::Bold);
    QFont My_Pantry_Label("Decorative", 50, QFont::Bold);
    QFont Instruction_Button("Arial", 20, QFont::Bold);

    //code for the recipe widget
    QGridLayout * recipe_widget_layout = new QGridLayout;
    RecipeBook * recipe_book = new RecipeBook(1);
    QLabel * make_a_recipe = new QLabel("Make a Recipe!");
    make_a_recipe->setFont(Add_Item_Button);
    QLabel * number_1 = new QLabel ("1. ");
    QLabel * number_2 = new QLabel ("2. ");
    QLabel * number_3 = new QLabel ("3. ");
    QLabel * number_4 = new QLabel ("4. ");
    QLabel * number_5 = new QLabel ("5. ");
    recipe_widget_layout->addWidget(make_a_recipe, 0, 0, 1, -1, Qt::AlignCenter);
    recipe_widget_layout->addWidget(number_1, 1, 0);
    recipe_widget_layout->addWidget(number_2,2,0);
    recipe_widget_layout->addWidget(number_3,3,0);
    recipe_widget_layout->addWidget(number_4,4,0);
    recipe_widget_layout->addWidget(number_5,5,0);
    recipe_widget_layout->addWidget(recipe_book, 6,1, 1, -1, Qt::AlignRight);
    //background of adding ingredients to recipe widget
    recipe_widget->setStyleSheet("background-color: rgb(240,240,250);");
    QObject::connect(recipe_book, SIGNAL(clicked()), recipe_book, SLOT(is_clicked()));
    recipe_widget->setLayout(recipe_widget_layout);
    recipe_widget->setFixedSize(250,600);

    fridge = new Fridge(3);
    freezer = new Freezer(3);
    cabinet = new Cabinet(3);
    counter = new Counter(3);

    //central widget
    QWidget * window = new QWidget;
    //layout of central widget
    QGridLayout * fri = new QGridLayout;
    fri->setVerticalSpacing(0);

    //code for the instruction page
    QWidget * instructions_page = new QWidget;
    QVBoxLayout * instructions_layout = new QVBoxLayout;
    QLabel * instructions_label = new QLabel("Click the Add Item button to start adding items to your pantry. You will add "
                                             "the name, the expiration date, and how many units of the item you have. "
                                             "Click on the fridge, the freezer, the spice rack, or the cabinets "
                                             "to see a list of what you've added! From there you can modify and "
                                             "delete your current ingredients and use up to five to search for a recipe.");
    instructions_label->setWordWrap(true);
    QLabel * instructions_title = new QLabel("Instructions");
    instructions_title->setFont(Add_Item_Button);
    instructions_layout->addWidget(instructions_title,0, Qt::AlignCenter);
    instructions_layout->addWidget(instructions_label);
    instructions_page->setLayout(instructions_layout);
    instructions_page->setStyleSheet("color: rgb(25, 25, 100); background-color: rgb(250, 250, 250);");
    //end of code for instrucion page

    //setting the font and button colors
    my_pantry->setFont(My_Pantry_Label);
    my_pantry->setStyleSheet("color: rgb(25, 25, 100);");
    instructions_button->setFont(Instruction_Button);
    instructions_button->setStyleSheet("color: rgb(25, 25, 100);");
    add_item_button->setFont(Add_Item_Button);
    add_item_button->setStyleSheet("color: rgb(25, 25, 100);");

    //background of the main window, bricks
    setStyleSheet("MainWindow {background-image: url(:/new/prefix1/hld186-oblong-granite-grey-tile-wallper-ea2.jpg);}");

    //showing the instructions_page when user clicks on instruction button
    QObject::connect(instructions_button, SIGNAL(clicked()), instructions_page, SLOT(show()));

    //adding all of the widgets and labels to the main window
    fri->addWidget(my_pantry, 0,0,1, 2, Qt::AlignCenter);
    fri->addWidget(instructions_button, 0,1, Qt::AlignRight);
    fri->addWidget(add_item_button, 1, 0);
    fri->addWidget(fridge, 3, 0);
    fri->addWidget(freezer, 2,0);
    fri->addWidget(counter, 3, 1, Qt::AlignBottom);
    fri->addWidget(cabinet, 1, 1, 1, 1, Qt::AlignTop);
    fri->addWidget(recipe_widget, 0,2,-1,1);

    fridge_list = new FoodListWidget;
    QObject::connect(fridge, SIGNAL(clicked()), fridge_list, SLOT(show()));
    freezer_list = new FoodListWidget;
    QObject::connect(freezer, SIGNAL(clicked()), freezer_list, SLOT(show()));
    cabinet_list = new FoodListWidget;
    QObject::connect(cabinet, SIGNAL(clicked()), cabinet_list, SLOT(show()));
    counter_list = new FoodListWidget;
    QObject::connect(counter, SIGNAL(clicked()), counter_list, SLOT(show()));

    //CODE FOR ADDING BUTTON PAGES

    add_item_window = new AddItemWindow;
    //opens the storage location
    QObject::connect(add_item_button, SIGNAL(clicked()), add_item_window, SLOT(show()));
    //showing add_item_window and closing it at the same time the freezer button is clicked
    QObject::connect(add_item_window, SIGNAL(value_is_cut(FoodItem)), freezer_list, SLOT(line_item_add(FoodItem)));
    //showing add_item_window and closing it at the same time the fridge button is clicked
    QObject::connect(add_item_window, SIGNAL(value_is_cut(FoodItem)), fridge_list, SLOT(line_item_add(FoodItem)));
    //showing add_item_window and closing it at the same time the cabinet button is clicked
    QObject::connect(add_item_window, SIGNAL(value_is_cut(FoodItem)), cabinet_list, SLOT(line_item_add(FoodItem)));
    //showing add_item_window and closing it at the same time the counter button is clicked
    QObject::connect(add_item_window, SIGNAL(value_is_cut(FoodItem)), counter_list, SLOT(line_item_add(FoodItem)));

    //BACK TO ORIGINAL PAGE

    //setting layout and central widget of window
    window->setLayout(fri);
    this->setCentralWidget(window);
}

MainWindow::~MainWindow()
{
    delete ui;
}

