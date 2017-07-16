#ifndef TEBALL_H
#define TEBALL_H

#include <QGraphicsItem>

class TeBall : public QGraphicsItem
{

public:
    explicit TeBall(double x, double y, double w, double h, QGraphicsItem *parent = nullptr);
    double posX() const;
    void setPosX(double posX);
    double posY() const;
    void setPosY(double posY);
    double width() const;
    double height() const;
    void setWidth(double width);
    void setHeight(double height);

protected:

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override;

private:
    double m_posX, m_posY;
    double m_width, m_height;
};

#endif // TEBALL_H
