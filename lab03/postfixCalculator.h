/*
Devinn Um
dau4eb
09/10/21
postfixCalculator.h
*/
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "stack.h"

using namespace std;

class postfixCalculator {
public:
  postfixCalculator();
  
  void addition();

  void subtraction();

  void multiplication();

  void division();

  void negation();

  calcStack stack;

};

#endif
