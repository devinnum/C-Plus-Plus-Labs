#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main() {

  cout << "int" << INT_MAX << endl;
  cout << "unsigned int" << UINT_MAX << endl;
  cout << "float" << INT_MAX << endl;
  cout << "double" << INT_MAX << endl;
  cout << "char" << CHAR_MAX << endl;

  unsigned int y;
  float j;
  double i;
  i=NULL;
  char z;
  z=NULL;
  bool k;
  char* u = &z;
  double* f = &i;

  y = 1;
  j = 1.0;
  i = 1.00;
  z = '1';
  k = true;

  cout << z << endl;

  string boob = "ABCD";
  int grey = 0;
  cout << boob.length();
  for (grey; grey < boob.length(); grey++) {
    cout << "check" << grey << endl;

    if(5+2*-2){
      cout << "yup its true" << endl;
    }
  }
  
}
