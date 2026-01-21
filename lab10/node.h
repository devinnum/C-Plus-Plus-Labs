#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node {
public:
    Node();        


    char value;
    int count;
    Node* left;     
    Node* right; 
};

#endif
