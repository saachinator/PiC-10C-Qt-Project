#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "foodstoragewidget.h"
#include "addedititemwidget.h"
#include "foodlistwidget.h"
#include "foodlistwidgetitem.h"
#include "Fridge.h"
#include "freezer.h"
#include "counter.h"
#include "recipecreator1.h"
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
  //  QPushButton * instructions_button = new QPushButton("Instructions"); //button to push for instructions

    // Play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/atlast.mp3"));
    music->play();

    // different fonts for different buttons of labels
    QFont Add_Item_Button("Arial", 20, QFont::Bold);
    QFont My_Pantry_Label("Decorative", 50, QFont::Bold);
 //   QFont Instruction_Button("Arial", 20, QFont::Bold);

    //code for the recipe widget
    //end of code for the recipe widget

    recipe_widget = new RecipeCreator1;
    recipe_widget->setFixedSize(250,300);
    QPalette pal = palette();

    // set black background
    pal.setColor(QPalette::Background, Qt::white);
    recipe_widget->setAutoFillBackground(true);
    recipe_widget->setPalette(pal);
    recipe_widget->show();

    //code for the instruction widget
    QWidget * instructions_page = new QWidget;
    QVBoxLayout * instructions_layout = new QVBoxLayout;
 //   QPushButton * close_instructions = new QPushButton ("Close Instructions");
    QLabel * instructions_label = new QLabel("Click the Add Item button to add an item to your pantry. "
                                             "Click on the fridge, the freezer, the counter, or the cabinets "
                                             "to see what you've added there! In the list, you can modify items "
                                             "by clicking the edit button next to them. You can also "
                                             "add items to a recipe by clicking the add button next to them. "
                                             "Once you have up to five items in your recipe list below, you can click on the "
                                             "recipe book to generate a query for recipes with those ingredients!");
    instructions_label->setWordWrap(true);
    QLabel * instructions_title = new QLabel("Instructions");
    instructions_title->setFont(Add_Item_Button);
    instructions_layout->addWidget(instructions_title,0, Qt::AlignCenter);
    instructions_layout->addWidget(instructions_label);
  //  instructions_layout->addWidget(close_instructions);
    instructions_page->setLayout(instructions_layout);
    instructions_page->setStyleSheet("color: rgb(25, 25, 100); background-color: rgb(250, 250, 250);");
    //end of code for instrucion widget

    //code for add_item_widget page
    add_item_widget = new AddEditItemWidget(true);
    edit_item_widget = new AddEditItemWidget(false);

    //end of code for add_item_widget page

    stackedWidget = new QStackedWidget;
  //  stackedWidget->addWidget(recipe_widget);
    stackedWidget->addWidget(instructions_page);
    stackedWidget->addWidget(add_item_widget);
    stackedWidget->addWidget(edit_item_widget);
    stackedWidget->setStyleSheet("background-color: rgb(240,240,250);");
    stackedWidget->setFixedSize(250, 275);

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
  //  instructions_button->setFont(Instruction_Button);
 //   instructions_button->setStyleSheet("color: rgb(25, 25, 100);");
    add_item_button->setFont(Add_Item_Button);
    add_item_button->setStyleSheet("color: rgb(25, 25, 100);");

    //background of the main window, bricks
    setStyleSheet("MainWindow {background-image: url(:/new/prefix1/hld186-oblong-granite-grey-tile-wallper-ea2.jpg);}");



    //adding all of the widgets and labels to the main window
    main_layout->addWidget(my_pantry, 0,0,1, 2, Qt::AlignCenter);
 //   main_layout->addWidget(instructions_button, 0,1, Qt::AlignRight);
    main_layout->addWidget(add_item_button, 1, 0);
    main_layout->addWidget(fridge, 3, 0);
    main_layout->addWidget(freezer, 2,0);
    main_layout->addWidget(counter, 3, 1, Qt::AlignBottom);
    main_layout->addWidget(cabinet, 1, 1, 1, 1, Qt::AlignTop);
    main_layout->addWidget(stackedWidget, 0,2,-1,1, Qt::AlignTop);
    main_layout->addWidget(recipe_widget, 0, 2, -1, 1, Qt::AlignBottom);

    fridge_list = new FoodListWidget (1);
    stackedWidget->addWidget(fridge_list);
    QObject::connect(fridge, SIGNAL(clicked()), this, SLOT(gotoFridgeListPage()));
    freezer_list = new FoodListWidget (2);
    stackedWidget->addWidget(freezer_list);
    QObject::connect(freezer, SIGNAL(clicked()), this, SLOT(gotoFreezerListPage()));
    cabinet_list = new FoodListWidget (3);
    stackedWidget->addWidget(cabinet_list);
    QObject::connect(cabinet, SIGNAL(clicked()), this, SLOT(gotoCabinetListPage()));
    counter_list = new FoodListWidget (4);
    stackedWidget->addWidget(counter_list);
    QObject::connect(counter, SIGNAL(clicked()), this, SLOT(gotoCounterListPage()));


    //CODE FOR ADDING BUTTON PAGES

    //opens the storage location
    QObject::connect(add_item_button, SIGNAL(clicked()), this, SLOT(gotoAddItemPage()));
    //showing the instructions_page when user clicks on instruction button
//    QObject::connect(instructions_button, SIGNAL(clicked()), this, SLOT(gotoInstructionPage()));
    //when close instructions button is clicked goes back to recipe main page
 //   QObject::connect(close_instructions, SIGNAL(clicked()), this, SLOT(gotoRecipePage()));
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
    stackedWidget->setCurrentIndex(0);
}
void MainWindow::gotoAddItemPage()
{
    stackedWidget->setCurrentIndex(1);
}

void MainWindow::gotoEditItemPage(FoodListWidgetItem * item)
{
    edit_item_widget->setTextDate(item->get_FoodItem());
    stackedWidget->setCurrentIndex(2);
}

void MainWindow::gotoFridgeListPage()
{
    stackedWidget->setCurrentIndex(3);
}

void MainWindow::gotoFreezerListPage()
{
    stackedWidget->setCurrentIndex(4);
}

void MainWindow::gotoCabinetListPage()
{
    stackedWidget->setCurrentIndex(5);
}

void MainWindow::gotoCounterListPage()
{
    stackedWidget->setCurrentIndex(6);
}

MainWindow::~MainWindow()
{
    delete ui;
}

