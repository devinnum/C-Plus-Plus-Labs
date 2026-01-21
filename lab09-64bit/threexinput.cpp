#include <iostream>
#include <cstring>
#include "timer.h"
using namespace std;

extern "C" int threexplusone(int x);

int main(){

  int x, n;
  cout << "Enter a number: ";
  cin >> x;
  cout << "Enter iterations of subroutine: ";
  cin >> n;
  
  int out = threexplusone(x);
  cout << "Steps: " << out << endl;

  timer t;
  t.start();
  for (int i = 0; i < n; i++) {
    threexplusone(x);
  }
  t.stop();
  
  return 0;

}
