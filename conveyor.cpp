#include "conveyor.h"
#include <QPainter>
#include <QDebug>

Conveyor::Conveyor()
{
    conveyorImage = new QImage(":/image/conveyor.png");
    startX = 600;
    startY = 300;
}

Conveyor::~Conveyor(){
    delete conveyorImage;
}

QRectF Conveyor::boundingRect() const
{
    return QRectF(0,0,1920,200);
}

void Conveyor::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QRect source(QPoint(0,0),QSize(conveyorImage->width()-2,conveyorImage->height()));
    QRect target(QPoint(startX,startY),QSize(conveyorImage->width()-1,conveyorImage->height()));
    painter->drawImage(target,*conveyorImage,source);
    target.setX(target.x() + conveyorImage->width());
    painter->drawImage(target,*conveyorImage,source);
    target.setX(target.x() + conveyorImage->width());
    painter->drawImage(target,*conveyorImage,source);
}
