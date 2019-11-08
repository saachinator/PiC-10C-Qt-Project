#ifndef FRIDGE_H
#define FRIDGE_H

#include "foodstoragewidget.h"

class Fridge : public FoodStorageWidget
{
public:
    Fridge (const double &s): scale(s){}
    void mousePressEvent ( QMouseEvent * event ) override;
    void paintEvent(QPaintEvent *event) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
private:
    double scale;
};

#endif // FRIDGE_H
