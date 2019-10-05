#ifndef FISHANIMATION_H
#define FISHANIMATION_H
#include <QGraphicsItem>
#include <QPropertyAnimation>

class FishAnimation:public QGraphicsItem,public QPropertyAnimation
{
public:
    FishAnimation();
};

#endif // FISHANIMATION_H
