#ifndef RECIPECREATOR1_H
#define RECIPECREATOR1_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QRadioButton>
#include "recipebook.h"


class RecipeCreator1 : public QWidget
{
    Q_OBJECT
public:
    explicit RecipeCreator1(QWidget *parent = nullptr);
    QLineEdit& get_item1() const;
    QLineEdit& get_item2() const;
    QLineEdit& get_item3() const;
    QLineEdit& get_item4() const;
    QLineEdit& get_item5() const;

    ~RecipeCreator1();
public slots:
    void this_button_clicked();
    void clear_button_clicked();

private:
    QGridLayout * recipe_widget_layout;

    QRadioButton * vegan_button;
    QRadioButton * neither_button;
    QRadioButton * vegetarian_button;

    QPushButton * clear_fields_button;

    RecipeBook * book;
    QPushButton * button;
    QLineEdit * Item1;
    QLineEdit * Item2;
    QLineEdit * Item3;
    QLineEdit * Item4;
    QLineEdit * Item5;
    QLineEdit * allergies;

};

#endif // RECIPECREATOR1_H
