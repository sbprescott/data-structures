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
    pthread_t t1, t2;

    reader = new BinarySemaphore();
    writer = new BinarySemaphore();
    
    cout << "semaphores created" << endl;

    pthread_create(&t1, NULL, read, (void*) 3);
    pthread_create(&t2, NULL, write, (void*) 3);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
