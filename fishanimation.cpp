#include "fishanimation.h"

#include <QPainter>
FishAnimation::FishAnimation(int startX,int startY)
{
    fishImage = new QImage(":/image/product.png");
    this->startX = startX;
    this->startY = startY;
    this->setVisible(false);
}

FishAnimation::~FishAnimation()
{
    delete fishImage;
}

int FishAnimation::getStartY() const
{
    return startY;
}

void FishAnimation::setStartY(int value)
{
    startY = value;
}

int FishAnimation::getStartX() const
{
    return startX;
}

void FishAnimation::setStartX(int value)
{
    startX = value;
}


QRectF FishAnimation::boundingRect() const
{
    return QRectF(QPoint(0,0),QSize(200,200));
}

void FishAnimation::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QRectF target(QPoint(startX,startY),QSize(fishImage->width(),fishImage->height()));
    QRectF source(QPoint(0,0),QSize(fishImage->width(),fishImage->height()));
    painter->drawImage(target,*fishImage,source);
}
