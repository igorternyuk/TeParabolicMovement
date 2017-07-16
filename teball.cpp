#include "teball.h"
#include <QPainter>

TeBall::TeBall(double x, double y, double w, double h, QGraphicsItem *parent) :
    QGraphicsItem(parent), m_posX(x), m_posY(y), m_width(w), m_height(h)
{

}

double TeBall::posX() const
{
    return m_posX;
}

void TeBall::setPosX(double posX)
{
    m_posX = posX;
}

double TeBall::posY() const
{
    return m_posY;
}

void TeBall::setPosY(double posY)
{
    m_posY = posY;
}

double TeBall::width() const
{
    return m_width;
}

double TeBall::height() const
{
    return m_height;
}

void TeBall::setWidth(double width)
{
    m_width = width;
}

void TeBall::setHeight(double height)
{
    m_height = height;
}

QRectF TeBall::boundingRect() const
{
    return QRectF(m_posX - m_width, m_posY - m_height, 2 * m_width, 2 * m_height);
}

void TeBall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    (void) option;
    (void) widget;
    painter->setBrush(Qt::blue);
    painter->drawEllipse(QPointF(m_posX, m_posY), m_width, m_height);
    painter->setBrush(Qt::NoBrush);
    //painter->setPen(Qt::red);
    //painter->drawRect(this->boundingRect());
}
