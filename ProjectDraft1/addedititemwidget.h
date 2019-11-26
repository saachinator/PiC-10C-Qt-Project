#ifndef ADDEDITITEMWINDOW_H
#define ADDEDITITEMWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QStackedWidget>
#include <QRadioButton>
#include <QDateEdit>
#include "fooditem.h"

class AddEditItemWidget : public QWidget
{
    Q_OBJECT
public:
    //explicit AddItemWidget(QWidget *parent = nullptr);
    explicit AddEditItemWidget(bool is_add = true, QWidget *parent = nullptr);
    QLineEdit& get_name() const;
    QDateEdit& get_expiration() const;
    QLineEdit& get_size() const;

    void setTextDate(const FoodItem& f);

    ~AddEditItemWidget();

signals:
    void value_is_cut(FoodItem f, int i);

public slots:
    void button_clicked();
    void clearFields();
    void close_widget();

private:
    bool is_add;

    QPushButton * addchange_item_button;
    QPushButton * clear_fields_button;
    QPushButton * cancel_add_item;
    QPushButton * delete_item_button = nullptr;

    QRadioButton * fridge_button;
    QRadioButton * freezer_button;
    QRadioButton * cabinet_button;
    QRadioButton * counter_button;

    QLineEdit * add_name;
    QDateEdit * add_expiration;
    QLineEdit * add_size;

friend class MainWindow;
friend class FoodStorageWidget;
};

#endif // ADDITEMWINDOW_H
