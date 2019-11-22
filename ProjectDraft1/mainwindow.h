#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QStackedWidget>
#include "foodlistwidget.h"
#include "foodlistwidgetitem.h"
#include "Fridge.h"
#include "freezer.h"
#include "cabinet.h"
#include "counter.h"
#include "addedititemwidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void gotoRecipePage();
    void gotoInstructionPage();
    void gotoAddItemPage();
    void gotoEditItemPage(FoodListWidgetItem *);

    void item_double_clicked(QListWidgetItem *);

private:
    Ui::MainWindow *ui;
    Fridge * fridge;
    Freezer * freezer;
    Cabinet * cabinet;
    Counter * counter;

    QPushButton * add_item_button;

    FoodListWidget * fridge_list;
    FoodListWidget * freezer_list;
    FoodListWidget * cabinet_list;
    FoodListWidget * counter_list;

    AddEditItemWidget * add_item_widget;
    AddEditItemWidget * edit_item_widget;

    QStackedWidget * stackedWidget;

friend class AddEditItemWidget;
};

#endif // MAINWINDOW_H
