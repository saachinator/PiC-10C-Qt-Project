#include "freezer.h"
#include <QPainter>

void Freezer::mousePressEvent ( QMouseEvent * event )
{
    emit clicked();
}
void Freezer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(Qt::gray));
    //freezer's body
    painter.drawRect(0*scale, 0*scale, 60*scale, 45*scale);
    //freezer's handle
    painter.setBrush(QBrush(QColor(180,180,180)));
    painter.drawRect(50*scale, 10*scale, 3*scale, 20*scale);
}
QSize Freezer::sizeHint() const
{
    return QSize(60*scale,45*scale);
}
QSize Freezer::minimumSizeHint() const
{
    return QSize(60*scale,45*scale);
}
