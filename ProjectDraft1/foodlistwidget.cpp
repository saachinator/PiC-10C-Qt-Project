#include "foodlistwidget.h"

FoodListWidget::FoodListWidget()
{
}

void FoodListWidget::addItem(const QString &label, const FoodItem& f)
{
    QListWidget::addItem(label);
    contents.push_back(f);
}

void FoodListWidget::line_item_add(FoodItem f)
{
    FoodListWidget::addItem(f.get_name(), f);
}
