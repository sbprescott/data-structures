#include "binary_semaphore.h"

using namespace std;

BinarySemaphore::BinarySemaphore() {
    pthread_mutex_init(&mutex_, NULL);
    pthread_cond_init(&cv_, NULL);
    value_ = 1; // initialize bs to 1
}

void BinarySemaphore::signal() {
    pthread_mutex_lock(&mutex_); // grab mutex
    
    while (value_ == 0) {
        pthread_cond_wait(&cv_, &mutex_); // if bs is 0, threads wait on cv
    } 

    value_ = 0; // if thread is here, bs state was 1 but must now be set to 0
    pthread_mutex_unlock(&mutex_); // release mutex
}

void BinarySemaphore::wait() {
    pthread_mutex_lock(&mutex_); // grab the mutex

    pthread_cond_signal(&cv_); // if threads are waiting on cv_, releases one thread

    value_ = 1; // reset semaphore state

    pthread_mutex_unlock(&mutex_); // release the mutex
}
