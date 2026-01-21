/*
Devinn Um
dau4eb
09/05/21
ListItr.cpp
*/
#include "ListItr.h"
#include <iostream>

using namespace std;

ListItr::ListItr() {
  current = NULL;
}

ListItr::ListItr(ListNode* theNode) {
  current = theNode;
}

bool ListItr::isPastEnd() const {
  if (current->next == NULL) {
    return 1;
  }
  return 0;
}

bool ListItr::isPastBeginning() const{
  if (current->previous == NULL) {
    return 1;
  }
  return 0;
}

void ListItr::moveForward() {
  if (!isPastEnd()) {
    current = current->next;
  }
}

void ListItr::moveBackward() {
  if (!isPastBeginning()) {
    current = current->previous;
  }
}

int ListItr::retrieve() const {
  return current->value;
}
