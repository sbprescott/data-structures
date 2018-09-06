// binary-semaphore.h
// -------------------------------------------------------------------------
// A C++ implementation of a binary semaphore using standard library 
// thread support mechanisms (mutex, condition_variable)
//
// Source: https://stackoverflow.com/a/4793662
//


#ifndef BINARYSEMAPHORE_H
#define BINARYSEMAPHORE_H 

#include <mutex>
#include <condition_variable> 

class BinarySemaphore {
    public:
        BinarySemaphore(int value) : cv_(), mutex_(), value_(value) {}
        ~BinarySemaphore() {}
        void wait();
        void signal();

    private:
        std::condition_variable cv_;
        std::mutex mutex_;
        int value_; // semaphore state (0 or 1)
};

#endif
