#ifndef FISHANIMATION_H
#define FISHANIMATION_H
#include <QGraphicsItem>
#include <QPropertyAnimation>

class FishAnimation:public QGraphicsItem,public QPropertyAnimation
{
public:
    FishAnimation(int startX = 0,int startY = 0);
    ~FishAnimation()override;
private:
    QImage *fishImage;

    int startX;
    int startY;

    // QGraphicsItem interface
public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    int getStartX() const;
    void setStartX(int value);
    int getStartY() const;
    void setStartY(int value);
};

#endif // FISHANIMATION_H
