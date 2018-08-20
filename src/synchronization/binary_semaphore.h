#ifndef DATASTRUCTURES_SYNCHRONIZATION_BINARYSEMAPHORE_H
#define DATASTRUCTURES_SYNCHRONIZATION_BINARYSEMAPHORE_H

#include <pthread.h>

class BinarySemaphore {
    public:
    BinarySemaphore();
    void wait();
    void signal();

    private:
    pthread_mutex_t mutex_;
    pthread_cond_t cv_;
    int value_; // semaphore state (0 or 1)
};

#endif
