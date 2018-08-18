#include <iostream>
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
    ListNode* node = new ListNode;
    node->value = val;    

    if (head == nullptr && tail == nullptr) {
        node->next = nullptr;
        node->prev = nullptr;
        head = node;
        tail = node; 
    } else if (head->next == nullptr) {
        node->next = nullptr;
        node->prev = tail;
        
    }
    length++;
}

int main() {
    LinkedList* list = new LinkedList();
    list->append(1);
    cout << "hi" << endl;
    return 0;
}

