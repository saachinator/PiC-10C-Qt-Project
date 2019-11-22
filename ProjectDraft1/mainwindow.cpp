#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "foodstoragewidget.h"
#include "addedititemwidget.h"
#include "foodlistwidget.h"
#include "foodlistwidgetitem.h"
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
#include <QStackedWidget>
#include "recipebook.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QLabel * my_pantry = new QLabel("My Pantry"); //title of application at top of window
    add_item_button = new QPushButton ("Add Item"); //button to add food items to different storage widgets
    QPushButton * instructions_button = new QPushButton("Instructions"); //button to push for instructions

    // Play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/atlast.mp3"));
    music->play();

    // different fonts for different buttons of labels
    QFont Add_Item_Button("Arial", 20, QFont::Bold);
    QFont My_Pantry_Label("Decorative", 50, QFont::Bold);
    QFont Instruction_Button("Arial", 20, QFont::Bold);

    //code for the recipe widget
    QWidget * recipe_widget = new QWidget; //widget where we will add ingredients to search a recipe
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
    //end of code for the recipe widget

    //code for the instruction widget
    QWidget * instructions_page = new QWidget;
    QVBoxLayout * instructions_layout = new QVBoxLayout;
    QPushButton * close_instructions = new QPushButton ("Close Instructions");
    QLabel * instructions_label = new QLabel("Click the Add Item button to start adding items to your pantry. You will add "
                                             "the name, the expiration date, and how many units of the item you have. "
                                             "Click on the fridge, the freezer, the counter, or the cabinets "
                                             "to see a list of what you've added! From there you can modify your items"
                                             "by double clicking on an item in one of the lists. You can also "
                                             "delete your current items or use up to five to search for a recipe.");
    instructions_label->setWordWrap(true);
    QLabel * instructions_title = new QLabel("Instructions");
    instructions_title->setFont(Add_Item_Button);
    instructions_layout->addWidget(instructions_title,0, Qt::AlignCenter);
    instructions_layout->addWidget(instructions_label);
    instructions_layout->addWidget(close_instructions);
    instructions_page->setLayout(instructions_layout);
    instructions_page->setStyleSheet("color: rgb(25, 25, 100); background-color: rgb(250, 250, 250);");
    instructions_page->setFixedSize(250,600);
    //end of code for instrucion widget

    //code for add_item_widget page
    add_item_widget = new AddEditItemWidget(true);
    edit_item_widget = new AddEditItemWidget(false);

    add_item_widget->setFixedSize(250,600);
    //end of code for add_item_widget page

    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(recipe_widget);
    stackedWidget->addWidget(instructions_page);
    stackedWidget->addWidget(add_item_widget);
    stackedWidget->addWidget(edit_item_widget);
    stackedWidget->setStyleSheet("background-color: rgb(240,240,250);");

    fridge = new Fridge(3);
    freezer = new Freezer(3);
    cabinet = new Cabinet(3);
    counter = new Counter(3);

    //central widget
    QWidget * window = new QWidget;
    //layout of central widget
    QGridLayout * main_layout = new QGridLayout;
    main_layout->setVerticalSpacing(0);
    main_layout->setContentsMargins(11, 11, 11, 0);


    //setting the font and button colors
    my_pantry->setFont(My_Pantry_Label);
    my_pantry->setStyleSheet("color: rgb(25, 25, 100);");
    instructions_button->setFont(Instruction_Button);
    instructions_button->setStyleSheet("color: rgb(25, 25, 100);");
    add_item_button->setFont(Add_Item_Button);
    add_item_button->setStyleSheet("color: rgb(25, 25, 100);");

    //background of the main window, bricks
    setStyleSheet("MainWindow {background-image: url(:/new/prefix1/hld186-oblong-granite-grey-tile-wallper-ea2.jpg);}");



    //adding all of the widgets and labels to the main window
    main_layout->addWidget(my_pantry, 0,0,1, 2, Qt::AlignCenter);
    main_layout->addWidget(instructions_button, 0,1, Qt::AlignRight);
    main_layout->addWidget(add_item_button, 1, 0);
    main_layout->addWidget(fridge, 3, 0);
    main_layout->addWidget(freezer, 2,0);
    main_layout->addWidget(counter, 3, 1, Qt::AlignBottom);
    main_layout->addWidget(cabinet, 1, 1, 1, 1, Qt::AlignTop);
    main_layout->addWidget(stackedWidget, 0,2,-1,1);

    fridge_list = new FoodListWidget (1);
    QObject::connect(fridge, SIGNAL(clicked()), fridge_list, SLOT(show()));
    freezer_list = new FoodListWidget (2);
    QObject::connect(freezer, SIGNAL(clicked()), freezer_list, SLOT(show()));
    cabinet_list = new FoodListWidget (3);
    QObject::connect(cabinet, SIGNAL(clicked()), cabinet_list, SLOT(show()));
    counter_list = new FoodListWidget (4);
    QObject::connect(counter, SIGNAL(clicked()), counter_list, SLOT(show()));

    //CODE FOR ADDING BUTTON PAGES

    //opens the storage location
    QObject::connect(add_item_button, SIGNAL(clicked()), this, SLOT(gotoAddItemPage()));
    //showing the instructions_page when user clicks on instruction button
    QObject::connect(instructions_button, SIGNAL(clicked()), this, SLOT(gotoInstructionPage()));
    //when close instructions button is clicked goes back to recipe main page
    QObject::connect(close_instructions, SIGNAL(clicked()), this, SLOT(gotoRecipePage()));
    //when cancel is pressed on add_item_page then it goes back to recipe main page
    QObject::connect(add_item_widget->cancel_add_item, SIGNAL(clicked()), this, SLOT(gotoRecipePage()));
    QObject::connect(add_item_widget->addchange_item_button, SIGNAL(clicked()), this, SLOT(gotoRecipePage()));
    QObject::connect(edit_item_widget->cancel_add_item, SIGNAL(clicked()), this, SLOT(gotoRecipePage()));
    QObject::connect(edit_item_widget->addchange_item_button, SIGNAL(clicked()), this, SLOT(gotoRecipePage()));
    QObject::connect(edit_item_widget->delete_item_button, SIGNAL(clicked()), this, SLOT(gotoRecipePage()));


    //showing add_item_widget and closing it at the same time the freezer button is clicked
    QObject::connect(add_item_widget, SIGNAL(value_is_cut(FoodItem, int)), freezer_list, SLOT(line_item_add(FoodItem, int)));
    //showing add_item_widget and closing it at the same time the fridge button is clicked
    QObject::connect(add_item_widget, SIGNAL(value_is_cut(FoodItem, int)), fridge_list, SLOT(line_item_add(FoodItem, int)));
    //showing add_item_widget and closing it at the same time the cabinet button is clicked
    QObject::connect(add_item_widget, SIGNAL(value_is_cut(FoodItem, int)), cabinet_list, SLOT(line_item_add(FoodItem, int)));
    //showing add_item_widget and closing it at the same time the counter button is clicked
    QObject::connect(add_item_widget, SIGNAL(value_is_cut(FoodItem, int)), counter_list, SLOT(line_item_add(FoodItem, int)));


    QObject::connect(fridge_list, SIGNAL(itemDoubleClicked(QListWidgetItem*)), fridge_list, SLOT(doubleClickedRebroadcast (QListWidgetItem *)));
    QObject::connect(fridge_list, SIGNAL(foodItemDoubleClicked(FoodListWidgetItem *)), this, SLOT(gotoEditItemPage(FoodListWidgetItem*)));
    QObject::connect(freezer_list, SIGNAL(itemDoubleClicked(QListWidgetItem*)), freezer_list, SLOT(doubleClickedRebroadcast (QListWidgetItem *)));
    QObject::connect(freezer_list, SIGNAL(foodItemDoubleClicked(FoodListWidgetItem *)), this, SLOT(gotoEditItemPage(FoodListWidgetItem*)));
    QObject::connect(counter_list, SIGNAL(itemDoubleClicked(QListWidgetItem*)), counter_list, SLOT(doubleClickedRebroadcast (QListWidgetItem *)));
    QObject::connect(counter_list, SIGNAL(foodItemDoubleClicked(FoodListWidgetItem *)), this, SLOT(gotoEditItemPage(FoodListWidgetItem*)));
    QObject::connect(cabinet_list, SIGNAL(itemDoubleClicked(QListWidgetItem*)), cabinet_list, SLOT(doubleClickedRebroadcast (QListWidgetItem *)));
    QObject::connect(cabinet_list, SIGNAL(foodItemDoubleClicked(FoodListWidgetItem *)), this, SLOT(gotoEditItemPage(FoodListWidgetItem*)));



    //BACK TO ORIGINAL PAGE

    //setting layout and central widget of window
    window->setLayout(main_layout);
    this->setCentralWidget(window);
}
void MainWindow::item_double_clicked(QListWidgetItem* item)
{
    std::cout << item->text().toStdString() << std::endl;
}
void MainWindow::gotoRecipePage()
{
    stackedWidget->setCurrentIndex(0);
}
void MainWindow::gotoInstructionPage()
{
    stackedWidget->setCurrentIndex(1);
}
void MainWindow::gotoAddItemPage()
{
    stackedWidget->setCurrentIndex(2);
}

void MainWindow::gotoEditItemPage(FoodListWidgetItem * item)
{
    edit_item_widget->setTextDate(item->get_FoodItem());
    stackedWidget->setCurrentIndex(3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

