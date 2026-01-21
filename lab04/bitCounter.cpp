/*
Devinn Um
dau4eb
09/21/21
bitCounter.cpp
*/
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int oddCount = 0;

int binaryBitCounter(int n) {
  if (n == 0) {
    return 0;
  }
  else if (n == 1) {
    oddCount++;
    return oddCount;
  }
  else if (n % 2 == 0) {
    binaryBitCounter(n / 2);
  }
  else {
    oddCount++;
    binaryBitCounter(n / 2);
  }
  return oddCount;
}

string baseConverter(string n, int startBase, int endBase) {
  int converted;
  int sum = 0;
  char digit;
  string output;
  string outputback;
  for (int i = 0; i < n.length(); i++) {
    if (n[i] == '0' || n[i] == '1' || n[i] == '2' || n[i] == '3' || n[i] == '4' || n[i] == '5' || n[i] == '6' || n[i] == '7' || n[i] == '8' || n[i] == '9') {
      converted = n[i] - '0';
    }
    else {
      converted = n[i] - 55;
    }
    sum += converted * pow(startBase, (n.length() - (i +1)));
  }
  
  while (sum != 0){
    if (to_string(sum % endBase) == "0" || to_string(sum % endBase) == "1" || to_string(sum % endBase) == "2" || to_string(sum % endBase) == "3" || to_string(sum % endBase) == "4" || to_string(sum % endBase) == "5" || to_string(sum % endBase) == "6" || to_string(sum % endBase) == "7" || to_string(sum % endBase) == "8" || to_string(sum % endBase) == "9") {
      digit = (sum % endBase) + '0';
    }
    else {
      digit = (sum % endBase) + 55;
    }
    output += digit;
    sum = sum / endBase;
  }

  for (int i = output.length() - 1; i > -1; i--) {
    outputback += output[i];
  }

  return outputback;
}

int main(int argc, char **argv) {
  if (argc == 1) {
    cout << "No command line arguments were given." << endl;
    exit(-1);
  }
  cout << argv[1] << " has " << binaryBitCounter(stoi(argv[1])) << " bit(s)" << endl;
  cout << argv[2] << " (base " << argv[3] << ") = " << baseConverter(argv[2], stoi(argv[3]), stoi(argv[4])) << " (base " << argv[4] << ")" << endl;
}
