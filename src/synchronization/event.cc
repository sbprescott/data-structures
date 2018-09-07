// event.cc
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

#include "event.h"

void Event::wait() {
    mutex_.wait(); // grab mutex
    value_++;
    mutex_.signal(); // signal mutex before placing thread on waitq_
    waitq_.wait();
    throttle_.signal(); // released thread signals throttle
    return;
}

void Event::signal() {
    mutex_.wait(); // grab mutex
    for (int i = 0; i < value_; i++) {
        waitq_.signal(); // wake up thread
        throttle_.wait(); // wait for handshake
    }
    // at this point all threads are released
    value_ = 0;
    mutex_.signal();
    return;
}

