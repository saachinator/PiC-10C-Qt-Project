#include "cabinet.h"
#include <QPainter>

void Cabinet::mousePressEvent ( QMouseEvent * event )
{
    emit clicked();
}
void Cabinet::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(QColor(115,75,45)));
    //back cabinet
    painter.drawRect(0*scale, 0*scale, 132*scale, 60*scale);

    //drawing left cabinet
    painter.setBrush(QBrush(QColor(100,60,30)));
    painter.drawRect(3*scale, 4*scale, 30*scale, 52*scale);

    //handles for the left cabinet
    painter.setBrush(QBrush(QColor(212,175,55)));
    painter.drawEllipse(25*scale, 48*scale, 3*scale, 3*scale);

    //drawing middle left cabinet
    painter.setBrush(QBrush(QColor(100,60,30)));
    painter.drawRect(35*scale, 4*scale, 30*scale, 52*scale);
    //handle for middle left cabinet
    painter.setBrush(QBrush(QColor(212,175,55)));
    painter.drawEllipse(40*scale, 48*scale, 3*scale, 3*scale);

    //drawing middle right cabinet
    painter.setBrush(QBrush(QColor(100,60,30)));
    painter.drawRect(67*scale, 4*scale, 30*scale, 52*scale);
    //handle for middle right cabinet
    painter.setBrush(QBrush(QColor(212,175,55)));
    painter.drawEllipse(89*scale, 48*scale, 3*scale, 3*scale);

    //drawing far right cabinet
    painter.setBrush(QBrush(QColor(100,60,30)));
    painter.drawRect(99*scale, 4*scale, 30*scale, 52*scale);
    //handle for right cabinet
    painter.setBrush(QBrush(QColor(212,175,55)));
    painter.drawEllipse(104*scale, 48*scale, 3*scale, 3*scale);
}

QSize Cabinet::sizeHint() const
{
    return QSize(132*scale,60*scale);
}
QSize Cabinet::minimumSizeHint() const
{
    return QSize(132*scale,60*scale);
}
