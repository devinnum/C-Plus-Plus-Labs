#include <iostream>
#include <string>
using namespace std;

void sizeOfTest() {
  cout << "Size of int: " << sizeof(int) << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
  cout << "Size of float: " << sizeof(float) << endl;
  cout << "Size of double: " << sizeof(double) << endl;
  cout << "Size of char: " << sizeof(char) << endl;
  cout << "Size of bool: " << sizeof(bool) << endl;
  cout << "Size of int*: " << sizeof(int*) << endl;
  cout << "Size of char*: " << sizeof(char*) << endl;
  cout << "Size of double*: " << sizeof(double*) << endl;
}

void overflow() {
  cout << "4294967295 + 1 = " << (unsigned int) 4294967295 + 1 << endl;
}

void outputBinary(unsigned int x) {
  string s;
  for (int i = 0; i < 32; i++) {
    int r = x % 2;
    x = x / 2;
    s = to_string(r) + s;
    if ((i + 1) % 4 == 0 && i != 31) {
      s = " " + s;
    }
  }
  cout << s << endl;
}

int main() {
  unsigned int x;
  cin >> x;
  sizeOfTest();
  overflow();
  outputBinary(x);
  return 0;
}
