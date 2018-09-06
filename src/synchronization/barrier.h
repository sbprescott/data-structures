// barrier.h 
// -------------------------------------------------------------------------
// A C++ implementation of a barrier using binary semaphores 
//
// @author: Sam Prescott
//

#ifndef BARRIER_H
#define BARRIER_H

#include "binary_semaphore.h"

class Barrier {
    public:
        Barrier(int size) : mutex_(1), throttle_(0), waitq_(0), size_(size), value_(0) {}
        ~Barrier() {}
        void wait();

    private:
        BinarySemaphore mutex_;
        BinarySemaphore throttle_;
        BinarySemaphore waitq_;
        int size_;
        int value_;
};

#endif


