#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "foodlistwidget.h"
#include "Fridge.h"
#include "freezer.h"
#include "cabinet.h"
#include "counter.h"
#include "additemwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


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

    AddItemWindow * add_item_window;
friend class AddItemWindow;
};

#endif // MAINWINDOW_H
