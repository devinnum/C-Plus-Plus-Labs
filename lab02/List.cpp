/*
Devinn Um
dau4eb
09/05/21
List.cpp
*/
#include "List.h"
#include <iostream>

using namespace std;

List::List() {
  head = new ListNode();
  tail = new ListNode();
  head->next = tail;
  tail->previous = head;
  count = 0;
}

List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
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
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const {
  if (size() == 0) {
    return 1;
  }
  return 0;
}

void List::makeEmpty() {
  while (head->next != tail) {
    ListNode* temp = head->next;
    head->next = head->next->next;
    delete temp;
  }
  head->next = tail;
  tail->previous = head;
  count = 0;
}

ListItr List::first() {
  return ListItr(head->next);
}

ListItr List::last() {
  return ListItr(tail->previous);
}

void List::insertAfter(int x, ListItr position) {
  if (position.current == tail) {
    insertBefore(x, position);
  }
  else {
    ListNode* node = new ListNode();
    node->value = x;
    node->next = position.current->next;
    node->previous = position.current;
    position.current->next = node;
    node->next->previous = node;
    count++;
  }
  
}

void List::insertBefore(int x, ListItr position) {
  if (position.current == head) {
    insertAfter(x, position);
  }
  else {
    ListNode* node = new ListNode();
    node->value = x;
    node->next = position.current;
    node->previous = position.current->previous;
    position.current->previous = node;
    node->previous->next = node;
    count++;
  }
}

void List::insertAtTail(int x) {
  ListNode* node = new ListNode();
  node->value = x;
  node->previous = tail->previous;
  node->next = tail;
  tail->previous = node;
  node->previous->next = node;
  count++;
}

ListItr List::find(int x) {
  ListItr i = first();
  while (i.current->next != NULL) {
    if (i.current->value == x) {
      return i;
    }
    i.moveForward();
  }
  return i;
}

void List::remove(int x) {
  if (find(x).current != tail) {
    ListNode* i = find(x).current;
    i->previous->next = i->next;
    i->next->previous = i->previous;
    delete i;
    count--;
  }
}

int List::size() const {
  return count;
}

void printList(List& source, bool forward) {
  if (forward) {
    ListItr i = source.first();
    while (!i.isPastEnd()) {
      cout << i.retrieve() << " ";
      i.moveForward();
    }
    cout << endl;
  }
  else {
    ListItr i = source.last();
    while (!i.isPastBeginning()) {
      cout << i.retrieve() << " ";
      i.moveBackward();
    }
    cout << endl;
  }
}
  
