/*
Devinn Um
dau4eb
09/10/21
stack.h
*/
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"

class calcStack {
 public:

  calcStack();

  void push(int e);

  void pop();

  int top() const;

  bool empty() const;

  List* list;
};

#endif

  
