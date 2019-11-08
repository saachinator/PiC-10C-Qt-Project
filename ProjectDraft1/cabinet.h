#ifndef CABINET_H
#define CABINET_H

#include "foodstoragewidget.h"

class Cabinet : public FoodStorageWidget
{
public:
    Cabinet (const double& s): scale(s) {}
    void mousePressEvent ( QMouseEvent * event ) override;
    void paintEvent(QPaintEvent *event) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
private:
    double scale;
};

#endif // CABINET_H
