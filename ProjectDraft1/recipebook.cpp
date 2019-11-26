#include "recipebook.h"

#include <QPainter>
#include <QDesktopServices>
#include <QUrl>
#include <QString>

void RecipeBook::mousePressEvent ( QMouseEvent * event )
{
    emit clicked();
}
void RecipeBook::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QBrush(QColor(90,107,47)));
    QPointF points_left[4] = {QPointF(0.0*scale/2,0.0*scale/2),QPointF(35*scale/2,20.0*scale/2),QPointF(35.0*scale/2,60.0*scale/2),QPointF(0*scale/2,45.0*scale/2)};
    QPointF points_right[4] = {QPointF(35.0*scale/2,20.0*scale/2),QPointF(70.0*scale/2,0.0*scale/2),QPointF(70.0*scale/2,45.0*scale/2),QPointF(35.0*scale/2,60.0*scale/2)};
    painter.drawPolygon(points_left, 4);
    painter.drawPolygon(points_right, 4);
}
QSize RecipeBook::sizeHint() const
{
    return QSize(71*scale/2,61*scale/2);
}
QSize RecipeBook::minimumSizeHint() const
{
    return QSize(71*scale/2,61*scale/2);
}

