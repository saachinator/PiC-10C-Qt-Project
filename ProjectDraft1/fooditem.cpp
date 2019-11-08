#include "fooditem.h"

bool FoodItem::operator < (const FoodItem& f)
{
    if (this->name<f.name)
        return true;
    else
        return false;
}
bool FoodItem::operator > (const FoodItem& f)
{
    if (this->name>f.name)
        return true;
    else
        return false;
}
bool FoodItem::operator == (const FoodItem& f)
{
    if (this->name==f.name)
        return true;
    else
        return false;
}

QString FoodItem::get_name() const
{
    return name;
}
QString FoodItem::get_expiration() const
{
    return expiration;
}
int FoodItem::get_size() const
{
    return size;
}
