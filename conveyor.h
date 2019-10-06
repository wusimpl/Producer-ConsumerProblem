#ifndef CONVEYOR_H
#define CONVEYOR_H
#include <QObject>
#include <fishanimation.h>

#define ARRAYLENTH 10
typedef int Semaphore;

class Conveyor : public QObject,public QGraphicsItem
{
    Q_OBJECT

private:
    QImage* conveyorImage;

    int startX;
    int startY;

    int width;
    int height;

    FishAnimation* itemsArray[ARRAYLENTH];

public:
    Conveyor();
    ~Conveyor()override;

     // QGraphicsItem interface
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

public:
    static Semaphore empty;
    static Semaphore full;
    static Semaphore mutex;

    int count;


public slots:
    void addProduct(QGraphicsItem* item);
};

#endif // CONVEYOR_H
