#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
    length = 0;
}

int LinkedList::size() { 
    return length;
}

void LinkedList::append(int val) {
    length++;
}

int main() {
    LinkedList* list = new LinkedList();
    list->append(1);
    cout << list->size() << endl;
    return 0;
}

