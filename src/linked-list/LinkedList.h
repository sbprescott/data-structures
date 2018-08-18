#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct ListNode {
    struct ListNode* prev;
    struct ListNode* next;
    int value;
};

class LinkedList {
    public:
    
    LinkedList();
    void append(int val);
    int size();
    
    private:
    
    struct ListNode* head;
    struct ListNode* tail;
    int length;  
       
};



#endif
