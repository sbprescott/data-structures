/*
 * readers_writers.cc
 * --------------------------------------------
 * A C++ implementation of the readers/writers synchronization
 * problem to serve as a test of BinarySemaphore class.
 *
 */

#include <iostream>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

#include "binary_semaphore.h"

using namespace std;

BinarySemaphore *reader;
BinarySemaphore *writer;
int shared = 0;


void *read(void *foo) {
    
    int *time = static_cast<int*>(foo);
    
    while (1) {
        sleep(3);

        reader->wait();
        cout << "thread_id:" << syscall(SYS_gettid) << " reading value of shared: " << shared << endl;
        reader->signal();
    }
}


void *write(void *foo) {
    int *time = static_cast<int*>(foo);
   
    while (1) { 
        sleep(3);
        
        writer->wait();
        shared += 2;
        cout << "thread_id:" << syscall(SYS_gettid) << " updating value of shared: " << shared << endl;
        writer->signal();
    }
}


int main() {
    pthread_t r1, r2;
    pthread_t w1;

    reader = new BinarySemaphore();
    writer = new BinarySemaphore();
    
    int waittime = 3;

    pthread_create(&r1, NULL, read, (void*) waittime);
    pthread_create(&r2, NULL, read, (void*) waittime);
    pthread_create(&w1, NULL, write, (void*) waittime);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);

    return 0;
}
