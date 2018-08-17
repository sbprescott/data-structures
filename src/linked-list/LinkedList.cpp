//#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

int LinkedList::size() { 
    return length;
}

void LinkedList::append(int val) {
    if (head == nullptr && tail == nullptr) {
        ListNode* node = new ListNode();
        node.value = val;
        node.next = nullptr;
        head = node;
        tail = node;
       
    }    
    size++;

}

int main() {
    LinkedList* list = new LinkedList();
    list.append(1);
    // cout << "hi" << endl;
    return 0;
}

