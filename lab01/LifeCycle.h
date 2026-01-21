/*
Devinn Um
dau4eb
08/30/21
LifeCycle.h
*/
#ifndef LIFECYCLE_H
#define LIFECYCLE_H
#include <iostream>
#include <string>
using namespace std;

class MyObject {
 public:
  static int numObjs;

  MyObject();
  MyObject(string n);
  MyObject(const MyObject& rhs);
  ~MyObject();

  string getName() const;
  void setName(const string& newName);

  friend ostream& operator<<(ostream& output, const MyObject& obj);
 private:
  string name;
  int id;

  
  
};

  // Prototypes for non-member functions we define later on
  // These are *non-member* functions because we didn't declare them as part of the MyObject class
  MyObject getMaxMyObj(const MyObject o1, const MyObject o2);
  int cmpMyObj(const MyObject o1, const MyObject o2);
  void swapMyObj(MyObject& o1, MyObject& o2);

  // Static variables
 


#endif
