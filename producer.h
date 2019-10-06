#ifndef PRODUCER_H
#define PRODUCER_H
#include <QThread>
#include "shared.h"
#include <fishanimation.h>
#include <iostream>


class Producer
{
public:
    Producer();

    void produce();
private:
    static int count;

signals:
    void produced(FishAnimation* product);
};

#endif // PRODUCER_H
