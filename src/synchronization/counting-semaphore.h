// event.h
// ------------------------------------------------
//
// C++ implementation of counting semaphore using custom
// binary semaphore. 
//
// 
// @ author: Sam Prescott
//

#ifndef COUNTING_SEMAPHORE_H
#define COUNTING_SEMAPHORE_H

#include "binary_semaphore.h"

class CS {
    public:
        CS(int value): mutex_(1), throttle_(0), waitq_(0), value_(value) {}
        ~CS() {}
        void wait();
        void signal();

    private:
        BinarySemaphore mutex_;
        BinarySemaphore throttle_;
        BinarySemaphore waitq_;
        int value_;
};

#endif

