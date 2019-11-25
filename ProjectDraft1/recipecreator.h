#ifndef RECIPECREATOR_H
#define RECIPECREATOR_H

#include "recipebook.h"
#include <QLineEdit>
#include <QWidget>
#include <QPushButton>

class recipecreator : public QWidget
{

public:
    explicit recipecreator(QWidget *parent = nullptr);
    QLineEdit& get_item1() const;
    QLineEdit& get_item2() const;
    QLineEdit& get_item3() const;
    QLineEdit& get_item4() const;
    QLineEdit& get_item5() const;

    ~recipecreator();
public slots:
    void this_button_clicked();

private:
    QPushButton * button;
    QLineEdit * Item1;
    QLineEdit * Item2;
    QLineEdit * Item3;
    QLineEdit * Item4;
    QLineEdit * Item5;

 friend class RecipeBook;
};

#endif // RECIPECREATOR_H
