#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <semaphore.h>

class semaphore {
    public:
    semaphore();
    void wait();
    void signal();

    private:
    sem_t *bs;
    int count;
};

#endif
