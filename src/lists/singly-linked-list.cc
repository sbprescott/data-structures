#include <iostream>
#include "singly-linked-list.h"

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
    length = 0;
}

Iterator LinkedList::begin() {
    Iterator itr;
    itr.current = head;
    return itr;
}

int LinkedList::size() { 
    return length;
}

void LinkedList::push_back(int val) {
    ListNode *node = new ListNode();
    node->value = val;    

    if (head == nullptr) {
        head = node;
        head->next = nullptr;
    } else if (head != nullptr && head->next == nullptr) {
        head->next = node;
    }


    length++;
}

int main() {
    LinkedList* list = new LinkedList();
    list->push_back(1);
    list->push_back(3);
    Iterator itr = list->begin();
    cout << itr.current->value << endl;
    cout << (itr.current + 2)->value << endl;
    return 0;
}

