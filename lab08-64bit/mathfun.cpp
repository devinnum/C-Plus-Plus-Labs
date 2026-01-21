#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" long product (long, long);
extern "C" long power (long, long);

int main() {
  long x, y;
  cout << "Enter integer 1: ";
  cin >> x;
  cout << "Enter integer 2: ";
  cin >> y;
  cout << "Product: " << product(x, y) << endl;
  cout << "Power: " << power(x,y) << endl;
  return 0;
}
