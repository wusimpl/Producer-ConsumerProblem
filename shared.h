//WARNING the header file has been deprecated. It's already refactored in Conveyor class and main.cpp file
/*
 * UNUSED ANYMORE. WARNING
 * UNUSED ANYMORE. WARNING
 * UNUSED ANYMORE. WARNING
 * UNUSED ANYMORE. WARNING*
 */
#ifndef FORCE_SHARED
    #define FORECE_SHARED 0
    #if FORECE_SHARED
    #else
        #ifndef SHARED_H
        #define SHARED_H
        #include <cstring>
        #include <QDebug>

        #define N 20 //the size of the buffer
        typedef int Semaphore; //use int type to present Semaphore
        typedef int Item;//use int type to present Item type
        struct Shared{
            Item buffer[N];//buffer pool
            Semaphore mutex;//
            Semaphore full;
            Semaphore empty;

            Shared(){
                 std::memset(buffer,0,N);
                 mutex = 1;
                 full = 0;
                 empty = N;
                 qDebug()<<"shared Constructor called";
            }
        };

        extern Shared s;
    #endif // SHARED_H
    #endif
#endif
