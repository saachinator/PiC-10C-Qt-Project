#include "recipebook.h"

#include <QPainter>
#include <QDesktopServices>
#include <QUrl>

void RecipeBook::mousePressEvent ( QMouseEvent * event )
{
    emit clicked();
}
void RecipeBook::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::white));
    QPointF points_left[4] = {QPointF(0.0*scale,0.0*scale),QPointF(35*scale,20.0*scale),QPointF(35.0*scale,60.0*scale),QPointF(0*scale,45.0*scale)};
    QPointF points_right[4] = {QPointF(35.0*scale,20.0*scale),QPointF(70.0*scale,0.0*scale),QPointF(70.0*scale,45.0*scale),QPointF(35.0*scale,60.0*scale)};
    painter.drawPolygon(points_left, 4);
    painter.drawPolygon(points_right, 4);
}
QSize RecipeBook::sizeHint() const
{
    return QSize(71*scale,61*scale);
}
QSize RecipeBook::minimumSizeHint() const
{
    return QSize(71*scale,61*scale);
}

void RecipeBook::is_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.google.com/?client=safari"));
}