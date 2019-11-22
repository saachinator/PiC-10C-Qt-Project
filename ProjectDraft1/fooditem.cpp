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

bool FoodItem::expired()
{
    return expiration<QDate::currentDate();
}


QString FoodItem::get_name() const
{
    return name;
}
QDate FoodItem::get_expiration() const
{
    return expiration;
}
int FoodItem::get_size() const
{
    return size;
}

void FoodItem::set_name(const QString& new_name)
{
    name=new_name;
}
void FoodItem::set_expiration(const QDate& new_expiration)
{
    expiration=new_expiration;
}
void FoodItem::set_size(const double& new_size)
{
    size=new_size;
}
