/*
Devinn Um
dau4eb
09/10/21
postfixCalculator.cpp
*/
#include "postfixCalculator.h"
#include "stack.h"
#include <iostream>

using namespace std;

postfixCalculator::postfixCalculator() {
}

void postfixCalculator::addition() {
  int i;
  int j;
  i = stack.top();
  stack.pop();
  j = stack.top();
  stack.pop();
  stack.push(i + j);
}

void postfixCalculator::subtraction() {
  int i;
  int j;
  i = stack.top();
  stack.pop();
  j = stack.top();
  stack.pop();
  stack.push(j - i);
  
}

void postfixCalculator::multiplication() {
  int i;
  int j;
  i = stack.top();
  stack.pop();
  j = stack.top();
  stack.pop();
  stack.push(i * j);
  
}

void postfixCalculator::division() {
  int i;
  int j;
  i = stack.top();
  stack.pop();
  j = stack.top();
  stack.pop();
  stack.push(j / i);
  
}

void postfixCalculator::negation() {
  int i;
  i = stack.top();
  stack.pop();
  stack.push(0 - i);
}
