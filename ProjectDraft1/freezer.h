#ifndef FREEZER_H
#define FREEZER_H

#include "foodstoragewidget.h"

class Freezer : public FoodStorageWidget
{
public:
    Freezer (const double& s): scale(s) {}
    void mousePressEvent ( QMouseEvent * event ) override;
    void paintEvent(QPaintEvent *event) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
private:
    double scale;
};

#endif // FREEZER_H
