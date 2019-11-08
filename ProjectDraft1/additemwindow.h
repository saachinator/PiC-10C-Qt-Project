#ifndef ADDITEMWINDOW_H
#define ADDITEMWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QStackedWidget>
#include "fooditem.h"

class AddItemWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit AddItemWindow(QWidget *parent = nullptr);
    QLineEdit& get_name() const;
    QLineEdit& get_expiration() const;
    QLineEdit& get_size() const;

signals:
    void value_is_cut(FoodItem f);

public slots:
    void button_clicked();
    void gotoSecondWindow();

private:
    QStackedWidget * AddItem_StackedWidget;
    QPushButton * add_item_button;
    QLineEdit * add_name;
    QLineEdit * add_expiration;
    QLineEdit * add_size;
friend class MainWindow;
friend class FoodStorageWidget;
};

#endif // ADDITEMWINDOW_H
