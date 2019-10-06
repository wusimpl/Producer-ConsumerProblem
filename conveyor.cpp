#include "conveyor.h"
#include <QPainter>
#include <QDebug>


Conveyor::Conveyor()
{
    conveyorImage = new QImage(":/image/conveyor.png");

    startX = 600;
    startY = 300;


    height = conveyorImage->height();
    width = conveyorImage->width()*3-2;

    for (int i=0;i<ARRAYLENTH;i++) {
        itemsArray[i] = nullptr;
    }
}

Conveyor::~Conveyor(){
    delete conveyorImage;
    for (int i=0;i<ARRAYLENTH;i++) {
        if(itemsArray[i] != nullptr){
            delete itemsArray[i];
        }
    }
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

void Conveyor::addProduct(QGraphicsItem *item)
{
    //judge if *item is a FishAnimation object
    if(strcmp(typeid(FishAnimation()).name(),typeid(*item).name())){//considering if it is necessary
        childItems().append(item);

        FishAnimation *product = dynamic_cast<FishAnimation*>(item);
        itemsArray[count] = product;
        count = (count + 1) % ARRAYLENTH;

//        product->setStartX(startX);
//        product->setStartY(startY);

        product->setStartValue(startX);
        product->setEndValue(startX + width);
        product->setDuration(3000);
        product->start();
        product->setVisible(true);
    }
}
