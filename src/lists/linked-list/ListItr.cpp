/*
 *name: Sam Prescott
 *email id: sbp9as
 *date: 2017.01.29
 *filename: List.cpp
 */

#include "ListItr.h"

using namespace std;

ListItr::ListItr() {
  current = NULL;
}

ListItr::ListItr(ListNode* theNode) {
  current = theNode;
}

bool ListItr::isPastEnd() const {
  if (current->next == NULL) return true;
  else return false;
}

bool ListItr::isPastBeginning() const {
  if (current->previous == NULL) return true;
  else return false;
}

void ListItr::moveForward() {
  if(isPastEnd()) return;
  current = current->next;
}

void ListItr::moveBackward() {
  if (isPastBeginning()) return;
  current = current->previous;
}

int ListItr::retrieve() const {
  return current->value;
}

void printList(List& theList, bool forward) {
  if (forward) {
    ListItr itr = theList.first();
    while(!itr.isPastEnd()) {
      cout << itr.retrieve() << endl;
      itr.moveForward();
    }
  } else {
    ListItr itr = theList.last();
    while(!itr.isPastBeginning()) {
      cout << itr.retrieve() << endl;
      itr.moveBackward();
    }
  }
}



