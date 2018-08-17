#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct ListNode {
    ListNode* prev;
    ListNode* next;
    int value;
};

class LinkedList {
    public:
    
    LinkedList();
    void append(int val);
    int size();
    
    private:
    
    ListNode* head, tail;
    int length;  
       
};



#endif
