// binary-semaphore.cc
// -------------------------------------------------------------------------
// A C++ implementation of a binary semaphore using standard library 
// thread support mechanisms (mutex, condition_variable)
//
// Source: https://stackoverflow.com/a/4793662
//


#include "binary_semaphore.h"

void BinarySemaphore::wait() {
    std::unique_lock<std::mutex> lock(mutex_);// grab mutex
    
    while (value_ == 0) {
        cv_.wait(lock); // if bs is 0, threads wait on cv
    } 

    value_ = 0; // if thread is here, bs state was 1 but must now be set to 0
    
    // mutex is auto-released when lock goes out of scope here
}

void BinarySemaphore::signal() {
    std::unique_lock<std::mutex> lock(mutex_);  // grab the mutex

    cv_.notify_one(); // if threads are waiting on cv_, releases one thread

    value_ = 1; // reset semaphore state
    
    // mutex is auto-released when lock goes out of scope here
}
