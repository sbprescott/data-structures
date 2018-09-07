// event.h
// ------------------------------------------------
//
// C++ implementation of event thread synchronization
// mechanism using binary semaphore.  
//
// Threads are added to waitq_ until signal is called,
// at which point all threads are released.
// 
// @ author: Sam Prescott
//

#ifndef EVENT_H
#define EVENT_H

#include "binary_semaphore.h"

class Event {
    public:
        Event() : mutex_(1), throttle_(0), waitq_(0), value_(0) {}
        ~Event() {}
        void wait();
        void signal();

    private:
        BinarySemaphore mutex_;
        BinarySemaphore throttle_;
        BinarySemaphore waitq_;
        int value_;
};

#endif
