#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

struct ListNode {
    struct ListNode* next;
    int value;
};

struct Iterator {
    struct ListNode* current;
};

class LinkedList {
    public:
    LinkedList();
    void push_back(int val);
    int size();
    Iterator begin();
    
    private:
    struct ListNode* head;
    int length;  
       
};



#endif
