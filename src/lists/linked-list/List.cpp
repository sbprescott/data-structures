/*
 *name: Sam Prescott
 *email id: sbp9as
 *date: 2017.01.29
 *filename: List.cpp
 */

#include "List.h"

using namespace std;

List::List() {
  head = new ListNode;
  tail = new ListNode;
  head->next = tail;
  head->previous = NULL;
  tail->previous=head;
  tail->next = NULL;
  count=0;
}

List::List(const List& source) {
  head=new ListNode;
  tail=new ListNode;
  head->next=tail;
  tail->previous=head;
  count=0;
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {       // deep copy of the list
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

List::~List() {
  makeEmpty();
  delete head;
  delete tail;
}

List& List::operator=(const List& source) {
  if (this == &source)
    return *this;
  else {
    makeEmpty();
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}

bool List::isEmpty() const {
  if (count == 0) return true;
  else return false;
}

void List::makeEmpty() {
  ListItr itr = first();
  while(!itr.isPastEnd()) {
    int x = itr.retrieve();
    itr.moveForward();
    remove(x);
  }
}

ListItr List::first() {
  return head->next;
}

ListItr List::last() {
  return tail->previous;
}

void List::insertAfter(int x, ListItr position) {
  if(position.isPastEnd()) {
      cout << "Cannot insert here. List is past end." << endl;
      return;
  }
  ListNode *NewNode = new ListNode();
  NewNode->value = x;
  NewNode->previous = position.current;
  NewNode->next = position.current->next;
  position.current->next = NewNode;
  NewNode->next->previous = NewNode;
  count++;
}

void List::insertBefore(int x, ListItr position) {
  if(position.isPastBeginning()) {
    cout << "Cannot insert here. List is past beginning." << endl;
    return;
  }
  ListNode *NewNode = new ListNode();
  NewNode->value = x;
  NewNode->next = position.current;
  NewNode->previous = position.current->previous;
  position.current->previous = NewNode;
  NewNode->previous->next = NewNode;
  count++;
}

void List::insertAtTail(int x) {
  insertBefore(x, tail);
}

void List::remove(int x) {
  ListItr itr = find(x);
  if(itr.current->next == NULL) {
    return;
  } else {
    itr.current->previous->next = itr.current->next;
    itr.current->next->previous = itr.current->previous;
    count--;
    delete itr.current;
  }
}

ListItr List::find(int x) {
  ListItr itr = first();
  while(!itr.isPastEnd()) {
    if(itr.retrieve() == x) {
      return itr;
    } else {
      itr.moveForward();
    }
  }
  return itr;
}

int List::size() const {
  return count;
}

