// barrier.cc 
// -------------------------------------------------------------------------
// A C++ implementation of a barrier using binary semaphores 
//
// @author: Sam Prescott
//

#include "barrier.h"

void Barrier::wait() {
    mutex_.wait(); // grab the mutex
    value_++;

    if (value_ < size_) {
        mutex_.signal(); // release mutex, otherwise deadlock
        waitq_.wait();
        throttle_.signal();
        return;
    } else {
        for (int i = 0; i < (size_ - 1); i++) {
            waitq_.signal();
            throttle_.wait();
        }
        
        value_ = 0;
        mutex_.signal(); // release mutex
        return;
    }
}

