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
        Barrier(int size) : size_(size), mutex_(1), throttle_(0), waitq_(0) {}
        ~Barrier() {}
        void wait();

    private:
        int size_;
        int value_;
        BinarySemaphore mutex_;
        BinarySemaphore throttle_;
        BinarySemaphore waitq_;

};

#endif


