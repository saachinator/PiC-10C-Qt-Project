#include "foodlistwidget.h"
#include "foodlistwidgetitem.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QListWidgetItem>

void FoodListWidget::addItem (FoodItem& f)
{
    FoodListWidgetItem * item = new FoodListWidgetItem (f);
    QListWidget::addItem(item);
}

void FoodListWidget::line_item_add(FoodItem f, int l)
{
    if (location==l)
    addItem(f);
}

void FoodListWidget::doubleClickedRebroadcast (QListWidgetItem * item)
{
    emit foodItemDoubleClicked(dynamic_cast<FoodListWidgetItem*>(item));
}

