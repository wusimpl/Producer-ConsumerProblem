#ifndef CONVEYOR_H
#define CONVEYOR_H
#include <QObject>
#include <QGraphicsItem>

class Conveyor : public QObject,public QGraphicsItem
{
    Q_OBJECT
private:
    QImage* conveyorImage;

    int startX;
    int startY;

public:
    Conveyor();
    ~Conveyor()override;


    // QGraphicsItem interface
public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // CONVEYOR_H
