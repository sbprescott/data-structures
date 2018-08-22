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
    ListNode *tmp = head;
    node->value = val;    

    if (head == nullptr) {
        head = node;
        head->next = nullptr;
    } else { 
        while (tmp->next != nullptr) tmp = tmp->next;
        tmp->next = node;
    }

    length++;
}

int LinkedList::get(int index) {
    // bounds checking 
    if (index >= length) {
        cout << "Index out of bounds" << endl;
        return 0;
    }
   
    ListNode* tmp = head;
    for (int i = 0; i < index; i++) tmp = tmp->next;  
    return tmp->value;
}

int main() {
    LinkedList* list = new LinkedList();
    list->push_back(1);
    list->push_back(3);
    list->push_back(56);
    Iterator itr = list->begin();
    cout << list->get(0) << endl;
    cout << list->get(1) << endl;
    cout << list->get(2) << endl;
    cout << list->get(3) << endl;
    return 0;
}

