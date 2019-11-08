#ifndef FOODLISTWIDGET_H
#define FOODLISTWIDGET_H

#include <QListWidget>
#include "fooditem.h"

class FoodListWidget : public QListWidget
{
    Q_OBJECT
public:
    FoodListWidget();
    void addItem(const QString &label, const FoodItem& f);
    virtual ~FoodListWidget() {}

signals:

public slots:
    void line_item_add(FoodItem f);

private:
    std::vector<FoodItem> contents;
friend class AddItemWindow;
};

#endif // FOODLISTWIDGET_H
