/*
Devinn Um
dau4eb
09/10/21
testPostfixCalc.cpp
*/
#include <iostream>
#include <string>
using namespace std;

#include "postfixCalculator.h"

int main () {
  postfixCalculator i;
  string token;
  while (cin >> token) {
    if (token == "+") {
      i.addition();
    }
    else if (token == "-") {
      i.subtraction();
    }
    else if (token == "*") {
      i.multiplication();
    }
    else if (token == "/") {
      i.division();
    }
    else if (token == "~") {
      i.negation();
    }
    else {
      i.stack.push(stoi(token));
    }
  }
  cout << i.stack.top() << endl;
}
