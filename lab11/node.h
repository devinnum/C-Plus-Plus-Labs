#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

using namespace std;

class Node {

 public:
  Node();
  vector<int> puzzle;
  Node* firstNeighbor;
  Node* secondNeighbor;
  Node* thirdNeighbor;
  Node* fourthNeighbor;
  Node* nextNeighbor;
  Node* parent;
  int count;
};

#endif
  
