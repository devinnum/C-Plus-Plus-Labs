/*
Devinn Um
dau4eb
09/10/21
stack.cpp
*/
#include "stack.h"
#include <iostream>
#include <cstdlib>

using namespace std;

calcStack::calcStack() {
  list = new List();
}

void calcStack::push(int e) {
  list->insertBefore(e, list->first());
}

void calcStack::pop() {
  if (!list->isEmpty()) {
    list->remove(list->first().retrieve());
  }
  else {
    cout << "pop() performed on empty stack" << endl;
    exit(-1);
  }
}

int calcStack::top() const {
  if (!list->isEmpty()) {
    return list->first().retrieve();
  }
  else {
    cout << "top() performed on empty stack" << endl;
    exit(-1);
  }
}

bool calcStack::empty() const {
  return list->isEmpty();
}
