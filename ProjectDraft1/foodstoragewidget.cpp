#include "foodstoragewidget.h"
#include "addedititemwidget.h"
#include "mainwindow.h"

void FoodStorageWidget::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}


