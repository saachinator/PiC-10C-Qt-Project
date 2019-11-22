#ifndef FOODLISTWIDGET_H
#define FOODLISTWIDGET_H

#include <QListWidget>
#include "fooditem.h"
#include "foodlistwidgetitem.h"

class FoodListWidget : public QListWidget
{
    Q_OBJECT
public:
    FoodListWidget(int l): location(l){}
    void addItem(FoodItem& f);
    virtual ~FoodListWidget() {}

signals:
    void foodItemDoubleClicked(FoodListWidgetItem * item);
public slots:
    void line_item_add(FoodItem f, int l);
    void doubleClickedRebroadcast (QListWidgetItem * item);

protected:
    int location;

friend class AddItemWindow;
};

#endif // FOODLISTWIDGET_H
