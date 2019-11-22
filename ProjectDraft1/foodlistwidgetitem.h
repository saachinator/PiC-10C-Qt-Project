#ifndef FOODLISTWIDGETITEM_H
#define FOODLISTWIDGETITEM_H

#include <QListWidgetItem>
#include <fooditem.h>

class FoodListWidgetItem : public QListWidgetItem
{
public:
    FoodListWidgetItem(FoodItem& new_f);
    FoodItem get_FoodItem() const;


protected:
    FoodItem f;

friend class FoodListWidget;
};

#endif // FOODLISTWIDGETITEM_H
