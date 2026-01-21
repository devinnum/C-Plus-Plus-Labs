#include <iostream>
#include <vector>
#include "node.h"

using namespace std;

Node::Node() {
  puzzle = vector<int>(9);
  nextNeighbor = NULL;
  firstNeighbor = NULL;
  secondNeighbor = NULL;
  thirdNeighbor = NULL;
  fourthNeighbor = NULL;
  parent = NULL;
  count = 0
}
