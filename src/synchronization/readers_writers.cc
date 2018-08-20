#include <iostream>

#include "binary_semaphore.h"

BinarySemaphore *reader;
BinarySemaphore *writer;
int shared = 0;

void *foo(void *bar) {
    int *time = static_cast<int*>(bar);
}

void *bar(void *foo) {
    int *time = static_cast<int*>(foo);
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, foo, (void*) 1000);
    pthread_create(&t2, NULL, bar, (void*) 1000);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
