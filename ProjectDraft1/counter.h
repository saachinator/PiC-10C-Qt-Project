#ifndef COUNTER_H
#define COUNTER_H

#include "foodstoragewidget.h"

class Counter : public FoodStorageWidget
{
public:
    Counter (const double& s): scale(s) {}
    void mousePressEvent ( QMouseEvent * event ) override;
    void paintEvent(QPaintEvent *event) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
private:
    double scale;
};

#endif // COUNTER_H
