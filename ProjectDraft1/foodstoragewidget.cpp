#include "foodstoragewidget.h"
#include "additemwindow.h"
#include "mainwindow.h"

void FoodStorageWidget::add_item (const FoodItem& f)
{
    contents.push_back(f);
}
void FoodStorageWidget::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}

FoodItem FoodStorageWidget::get_item(const QString &search_name)
{
    for (size_t i=0; i<contents.size(); i++)
    {
        if (search_name==contents[i].get_name())
        {
            return contents[i];
        }
    }
}
