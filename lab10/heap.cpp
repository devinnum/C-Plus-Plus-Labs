#include "heap.h"
#include "node.h"
#include <iostream>
#include <vector>

using namespace std;

//heap code taken from lecture slides

heap::heap() : heap_size(0) {
  Node* node = new Node();
  node->value = 'z';
  huffheap.push_back(node);
}

heap::~heap() {
}

void heap::insert(Node* x) {
  huffheap.push_back(x);
  percolateUp(++heap_size);
}

int heap::findMin() {
  if (heap_size == 0) {
    throw "finMin() called on empty heap";
  }
  return huffheap[1]->count;
}

Node* heap::findMinNode() {
  if (heap_size == 0) {
    throw "finMin() called on empty heap";
  }
  return huffheap[1];
}
   
unsigned int heap::size() {
  return heap_size;
}

void heap::makeEmpty() {
  heap_size = 0;
  huffheap.resize(1);
}

bool heap::isEmpty() {
  return heap_size == 0;
}

void heap::print() {
  cout << "(buffer)";
  for (int i = 1; i <= heap_size; i++) {
    cout << huffheap[i]->value << " ";
    bool isPow2 = (((i+1) & ~(i)) == (i+1))? i+1 : 0;
    if (isPow2) {
      cout << endl << "\t";
    }
  }
  cout << endl;
}

Node* heap::deleteMin() {
  if (heap_size == 0) {
    throw "deleteMin() called on empty heap";
  }
  Node* ret = huffheap[1];
  huffheap[1] = huffheap[heap_size--];
  huffheap.pop_back();
  if (!isEmpty()) {
    percolateDown(1);
  }
  return ret;
}
  
void heap::percolateUp(int hole) {
  Node* x = huffheap[hole];
  for (; (hole > 1) && (x->count < huffheap[hole/2]->count); hole /= 2) {
    huffheap[hole] = huffheap[hole/2];
  }
  huffheap[hole] = x;
}

void heap::percolateDown(int hole) {
  Node* x = huffheap[hole];
  while (hole * 2 <= heap_size) {
    int child = hole * 2;
    if ((child + 1 <= heap_size) && (huffheap[child + 1]->count < huffheap[child]->count)) {
      child++;
    }
    if (x->count > huffheap[child]->count) {
      huffheap[hole] = huffheap[child];
      hole = child;
    }
    else {
      break;
    }
  }
  huffheap[hole] = x;
}
  

