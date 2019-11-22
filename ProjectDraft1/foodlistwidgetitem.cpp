#include "foodlistwidgetitem.h"

FoodListWidgetItem::FoodListWidgetItem(FoodItem & new_f): QListWidgetItem(new_f.get_name())
{

    f=new_f;
}

FoodItem FoodListWidgetItem::get_FoodItem() const
{
    return f;
}
