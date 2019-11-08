#include "Fridge.h"
#include <QPainter>

void Fridge::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(Qt::gray));
    //fridge's body
    painter.drawRect(0*scale, 0*scale, 60*scale, 80*scale);

    //fridge's handle
    painter.setBrush(QBrush(QColor(180,180,180)));
    painter.drawRect(50*scale, 5*scale, 3*scale, 45*scale);

}
void Fridge::mousePressEvent ( QMouseEvent * event )
{
    emit clicked();
}
QSize Fridge::sizeHint() const
{
    return QSize(60*scale,80*scale);
}
QSize Fridge::minimumSizeHint() const
{
    return QSize(60*scale,80*scale);
}
