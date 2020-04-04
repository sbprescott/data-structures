// counting_semaphore.cc
// ------------------------------------------------
//
// C++ implementation of counting semaphore using custom
// binary semaphore. 
//
// 
// @ author: Sam Prescott
//

#include "counting_semaphore.h"

void CS::wait() {
    mutex_.wait();  //grab the mutex
    value_--;
    
    if (value_ >= 0) {  // if value_ >= 0, don't go on to waitq_, return
        mutex_.signal();
        return;
    }
    
    mutex_.signal();  // release mutex before adding thread to waitq_
    waitq_.wait();
    throttle_.signal();  // released thread signals handshake

}

void CS::signal() {
    mutex_.wait();  // grab mutex
    value_++;
    
    if (value_ > 0) {  // if current value > 0, no threads released
        mutex_.signal();  // release mutex
        return;
    }
    
    waitq_.signal();
    throttle_.wait();
    mutex_.signal();

}

