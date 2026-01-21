#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include "node.h"

using namespace std;

//heap code taken from lecture slides

class heap {
public:

  heap();

  heap(vector<Node*> vec);

  ~heap();

  void insert(Node* x);

  Node* deleteMin();

  int findMin();

  Node* findMinNode();

  unsigned int size();

  void makeEmpty();

  bool isEmpty();

  void print();

private:

  void percolateDown(int hole);

  void percolateUp(int hole);

  vector<Node*> huffheap;

  unsigned int heap_size;
};

#endif
