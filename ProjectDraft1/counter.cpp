#include "counter.h"
#include <QPainter>

void Counter::mousePressEvent ( QMouseEvent * event )
{
    emit clicked();
}
void Counter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //SPICE_RACK

    //oregano
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(QColor(90,107,47)));
    painter.drawRect(69*scale, 0*scale, 5*scale, 10*scale);
    //black cap
    painter.setBrush(QBrush(Qt::black));
    painter.drawRect(69*scale, 0*scale, 5*scale, 2*scale);

    //paprika
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(QColor(150,60,40)));
    painter.drawRect(62*scale, 0*scale, 5*scale, 10*scale);
    //black cap
    painter.setBrush(QBrush(Qt::black));
    painter.drawRect(62*scale, 0*scale, 5*scale, 2*scale);

    //garlic powder
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(QColor(245,220,160)));
    painter.drawRect(76*scale, 0*scale, 5*scale, 10*scale);
    //black cap
    painter.setBrush(QBrush(Qt::black));
    painter.drawRect(76*scale, 0*scale, 5*scale, 2*scale);

    //cumin powder
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(QColor(170,110,0)));
    painter.drawRect(83*scale, 0*scale, 5*scale, 10*scale);
    //black cap
    painter.setBrush(QBrush(Qt::black));
    painter.drawRect(83*scale, 0*scale, 5*scale, 2*scale);

    //bars to hold spices
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(Qt::white));
    painter.drawRect(60*scale, 5*scale, 30*scale, 2*scale);
    painter.drawRect(60*scale, 10*scale, 30*scale, 2*scale);

    //COUNTER

    //back counter
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(QColor(115,75,45)));
    painter.drawRect(0*scale, 12*scale, 100*scale, 60*scale);

    //drawing left drawers
    painter.setBrush(QBrush(QColor(100,60,30)));
    painter.drawRect(3*scale, 16*scale, 30*scale, 10*scale);
    painter.drawRect(3*scale, 28*scale, 30*scale, 10*scale);
    painter.drawRect(3*scale, 40*scale, 30*scale, 10*scale);
    painter.drawRect(3*scale, 52*scale, 30*scale, 16*scale);

    //handles for the left drawers
    painter.setBrush(QBrush(QColor(212,175,55)));
    painter.drawEllipse(16*scale, 20*scale, 3*scale, 3*scale);
    painter.drawEllipse(16*scale, 32*scale, 3*scale, 3*scale);
    painter.drawEllipse(16*scale, 44*scale, 3*scale, 3*scale);
    painter.drawEllipse(16*scale, 56*scale, 3*scale, 3*scale);

    //drawing middle drawers
    painter.setBrush(QBrush(QColor(100,60,30)));
    painter.drawRect(35*scale, 16*scale, 30*scale, 10*scale);
    painter.drawRect(35*scale, 28*scale, 30*scale, 40*scale);

    //handle for top middle drawer
    painter.setBrush(QBrush(QColor(212,175,55)));
    painter.drawEllipse(48*scale, 20*scale, 3*scale, 3*scale);
    //handle for bottom middle drawer
    painter.drawEllipse(58*scale, 32*scale, 3*scale, 3*scale);

    //drawing right drawers
    painter.setBrush(QBrush(QColor(100,60,30)));
    painter.drawRect(67*scale, 16*scale, 30*scale, 10*scale);
    painter.drawRect(67*scale, 28*scale, 30*scale, 40*scale);

    //handle for top right drawer
    painter.setBrush(QBrush(QColor(212,175,55)));
    painter.drawEllipse(80*scale, 20*scale, 3*scale, 3*scale);
    //handle for bottom right drawer
    painter.drawEllipse(71*scale, 32*scale, 3*scale, 3*scale);

    //OVEN

    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(Qt::gray));
    //back oven
    painter.drawRect(100*scale, 12*scale, 60*scale, 42*scale);
    painter.drawRect(100*scale, 54*scale, 60*scale, 18*scale);
    //window to inside
    painter.setBrush(QBrush(Qt::black));
    painter.drawRect(108*scale, 27*scale, 44*scale, 20*scale);
    //oven handle
    painter.setBrush(QBrush(QColor(180,180,180)));
    painter.drawEllipse(110*scale, 19*scale, 40*scale, 2*scale);
    //bottom warmer handle
    painter.setBrush(QBrush(QColor(180,180,180)));
    painter.drawEllipse(110*scale, 60*scale, 40*scale, 2*scale);
}
QSize Counter::sizeHint() const
{
    return QSize(160*scale,72*scale);
}
QSize Counter::minimumSizeHint() const
{
    return QSize(160*scale,72*scale);
}
