#include "producer.h"
#include "conveyor.h"


Producer::Producer()
{

}

void Producer::produce()
{
    while (true) {
        while(Conveyor::empty <= 0){QThread::msleep(10);};
        s.empty--;
        while(s.mutex <= 0){QThread::msleep(10);};
        s.mutex--;


        FishAnimation *product = new FishAnimation();//produce
        emit produced(product);

        /*the codes below has been refactored to be the implemented in Conveyor class
        s.buffer[count] = 1;
        count = (count + 1)%N;
        */

        s.mutex++;
        s.full++;
        QThread::msleep(900);
    }

}
