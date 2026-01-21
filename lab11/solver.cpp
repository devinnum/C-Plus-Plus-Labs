#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include "node.h"

using namespace std;

Node* root = new Node();
unordered_set<string> myset;
int currentNeighbor = 1;
vector<Node*> nodes;

void generateNeighbors(Node* start) {
  
  string full = "";
  int zeroindex;
  for (int i = 0; i < start->puzzle.size(); i++) {
    if (start->puzzle[i] == 0) {
      zeroindex = i;
    }
  }

  if (zeroindex == 0) {
    Node* neighbor1 = new Node();
    Node* neighbor2 = new Node();
    neighbor1->puzzle = start->puzzle;
    neighbor1->parent = start;
    neighbor1->puzzle[0] = neighbor1->puzzle[1];
    neighbor1->puzzle[1] = 0;
    neighbor2->puzzle = start->puzzle;
    neighbor2->parent = start;
    neighbor2->puzzle[0] = neighbor2->puzzle[3];
    neighbor2->puzzle[3] = 0;
    full = "";
    for (int i = 0; i < neighbor1->puzzle.size(); i++) {
      full += neighbor1->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      start->nextNeighbor = neighbor1;
      myset.insert(full);
      start->firstNeighbor = neighbor1;
      neighbor1->count = start->count + 1;
      nodes.push_back(neighbor1);
    }
    full = "";
    for (int i = 0; i < neighbor2->puzzle.size(); i++) {
      full += neighbor2->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      if (start->firstNeighbor == NULL) {
	start->nextNeighbor = neighbor2;
      }
      myset.insert(full);
      start->secondNeighbor = neighbor2;
      neighbor2->count = start->count + 1;
      nodes.push_back(neighbor2);
    }
  }

  else if (zeroindex == 2) {
    Node* neighbor1 = new Node();
    Node* neighbor2 = new Node();
    neighbor1->puzzle = start->puzzle;
    neighbor1->puzzle[2] = neighbor1->puzzle[1];
    neighbor1->puzzle[1] = 0;
    neighbor2->puzzle = start->puzzle;
    neighbor2->puzzle[2] = neighbor2->puzzle[5];
    neighbor2->puzzle[5] = 0;
    full = "";
    for (int i = 0; i < neighbor1->puzzle.size(); i++) {
      full += neighbor1->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      start->nextNeighbor = neighbor1;
      myset.insert(full);
      start->firstNeighbor = neighbor1;
      neighbor1->count = start->count + 1;
      nodes.push_back(neighbor1);
    }
    full = "";
    for (int i = 0; i < neighbor2->puzzle.size(); i++) {
      full += neighbor2->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      if (start->firstNeighbor == NULL) {
	start->nextNeighbor = neighbor2;
      }
      myset.insert(full);
      start->secondNeighbor = neighbor2;
      neighbor2->count = start->count + 1;
      nodes.push_back(neighbor2);
    }
  }

  else if (zeroindex == 6) {
    Node* neighbor1 = new Node();
    Node* neighbor2 = new Node();
    neighbor1->puzzle = start->puzzle;
    neighbor1->puzzle[6] = neighbor1->puzzle[3];
    neighbor1->puzzle[3] = 0;
    neighbor2->puzzle = start->puzzle;
    neighbor2->puzzle[6] = neighbor2->puzzle[7];
    neighbor2->puzzle[7] = 0;
    full = "";
    for (int i = 0; i < neighbor1->puzzle.size(); i++) {
      full += neighbor1->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      start->nextNeighbor = neighbor1;
      myset.insert(full);
      start->firstNeighbor = neighbor1;
      neighbor1->count = start->count + 1;
      nodes.push_back(neighbor1);
    }
    full = "";
    for (int i = 0; i < neighbor2->puzzle.size(); i++) {
      full += neighbor2->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      if (start->firstNeighbor == NULL) {
	start->nextNeighbor = neighbor2;
      }
      myset.insert(full);
      start->secondNeighbor = neighbor2;
      neighbor2->count = start->count + 1;
      nodes.push_back(neighbor2);
    }
  }

  else if (zeroindex == 8) {
    Node* neighbor1 = new Node();
    Node* neighbor2 = new Node();
    neighbor1->puzzle = start->puzzle;
    neighbor1->puzzle[8] = neighbor1->puzzle[5];
    neighbor1->puzzle[5] = 0;
    neighbor2->puzzle = start->puzzle;
    neighbor2->puzzle[8] = neighbor2->puzzle[7];
    neighbor2->puzzle[7] = 0;
    full = "";
    for (int i = 0; i < neighbor1->puzzle.size(); i++) {
      full += neighbor1->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      start->nextNeighbor = neighbor1;
      myset.insert(full);
      start->firstNeighbor = neighbor1;
      neighbor1->count = start->count + 1;
      nodes.push_back(neighbor1);
    }
    full = "";
    for (int i = 0; i < neighbor2->puzzle.size(); i++) {
      full += neighbor2->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      if (start->firstNeighbor == NULL) {
	start->nextNeighbor = neighbor2;
      }
      myset.insert(full);
      start->secondNeighbor = neighbor2;
      neighbor2->count = start->count + 1;
      nodes.push_back(neighbor2);
    }
  }

  else if (zeroindex == 4) {
    Node* neighbor1 = new Node();
    Node* neighbor2 = new Node();
    Node* neighbor3 = new Node();
    Node* neighbor4 = new Node();
    neighbor1->puzzle = start->puzzle;
    neighbor1->puzzle[4] = neighbor1->puzzle[1];
    neighbor1->puzzle[1] = 0;
    neighbor2->puzzle = start->puzzle;
    neighbor2->puzzle[4] = neighbor2->puzzle[5];
    neighbor2->puzzle[5] = 0;
    neighbor3->puzzle = start->puzzle;
    neighbor3->puzzle[4] = neighbor1->puzzle[7];
    neighbor3->puzzle[7] = 0;
    neighbor4->puzzle = start->puzzle;
    neighbor4->puzzle[4] = neighbor2->puzzle[3];
    neighbor4->puzzle[3] = 0;
    full = "";
    for (int i = 0; i < neighbor1->puzzle.size(); i++) {
      full += neighbor1->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      start->nextNeighbor = neighbor1;
      myset.insert(full);
      start->firstNeighbor = neighbor1;
      neighbor1->count = start->count + 1;
      nodes.push_back(neighbor1);
      cout << "added" << endl;
    }
    full = "";
    for (int i = 0; i < neighbor2->puzzle.size(); i++) {
      full += neighbor2->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      if (start->firstNeighbor == NULL) {
	start->nextNeighbor = neighbor2;
      }
      myset.insert(full);
      start->secondNeighbor = neighbor2;
      neighbor2->count = start->count + 1;
      nodes.push_back(neighbor2);
      cout << "added" << endl;
    }
    full = "";
    for (int i = 0; i < neighbor3->puzzle.size(); i++) {
      full += neighbor3->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      if (start->firstNeighbor == NULL && start->secondNeighbor == NULL) {
	start->nextNeighbor = neighbor3;
      }
      myset.insert(full);
      start->thirdNeighbor = neighbor3;
      neighbor3->count = start->count + 1;
      nodes.push_back(neighbor3);
      cout << "added" << endl;
    }
    full = "";
    for (int i = 0; i < neighbor4->puzzle.size(); i++) {
      full += neighbor4->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      if (start->firstNeighbor == NULL && start->secondNeighbor == NULL && start->thirdNeighbor == NULL) {
	start->nextNeighbor = neighbor4;
      }
      myset.insert(full);
      start->fourthNeighbor = neighbor4;
      neighbor4->count = start->count + 1;
      nodes.push_back(neighbor4);
      cout << "added" << endl;
    }
  }

  else if (zeroindex == 1) {
    Node* neighbor1 = new Node();
    Node* neighbor2 = new Node();
    Node* neighbor3 = new Node();
    neighbor1->puzzle = start->puzzle;
    neighbor1->puzzle[1] = neighbor1->puzzle[0];
    neighbor1->puzzle[0] = 0;
    neighbor2->puzzle = start->puzzle;
    neighbor2->puzzle[1] = neighbor2->puzzle[2];
    neighbor2->puzzle[2] = 0;
    neighbor3->puzzle = start->puzzle;
    neighbor3->puzzle[1] = neighbor2->puzzle[4];
    neighbor3->puzzle[4] = 0;
    full = "";
    for (int i = 0; i < neighbor1->puzzle.size(); i++) {
      full += neighbor1->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      start->nextNeighbor = neighbor1;
      myset.insert(full);
      start->firstNeighbor = neighbor1;
      neighbor1->count = start->count + 1;
      nodes.push_back(neighbor1);
    }
    full = "";
    for (int i = 0; i < neighbor2->puzzle.size(); i++) {
      full += neighbor2->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      if (start->firstNeighbor == NULL) {
	start->nextNeighbor = neighbor2;
      }
      myset.insert(full);
      start->secondNeighbor = neighbor2;
      neighbor2->count = start->count + 1;
      nodes.push_back(neighbor2);
    }
    full = "";
    for (int i = 0; i < neighbor3->puzzle.size(); i++) {
      full += neighbor3->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      if (start->firstNeighbor == NULL && start->secondNeighbor == NULL) {
	start->nextNeighbor = neighbor3;
      }
      myset.insert(full);
      start->thirdNeighbor = neighbor3;
      neighbor3->count = start->count + 1;
      nodes.push_back(neighbor3);
    }
  }

  else if (zeroindex == 3) {
    Node* neighbor1 = new Node();
    Node* neighbor2 = new Node();
    Node* neighbor3 = new Node();
    neighbor1->puzzle = start->puzzle;
    neighbor1->puzzle[3] = neighbor1->puzzle[0];
    neighbor1->puzzle[0] = 0;
    neighbor2->puzzle = start->puzzle;
    neighbor2->puzzle[3] = neighbor2->puzzle[4];
    neighbor2->puzzle[4] = 0;
    neighbor3->puzzle = start->puzzle;
    neighbor3->puzzle[3] = neighbor2->puzzle[6];
    neighbor3->puzzle[6] = 0;
    full = "";
    for (int i = 0; i < neighbor1->puzzle.size(); i++) {
      full += neighbor1->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      start->nextNeighbor = neighbor1;
      myset.insert(full);
      start->firstNeighbor = neighbor1;
      neighbor1->count = start->count + 1;
      nodes.push_back(neighbor1);
    }
    full = "";
    for (int i = 0; i < neighbor2->puzzle.size(); i++) {
      full += neighbor2->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      if (start->firstNeighbor == NULL) {
	start->nextNeighbor = neighbor2;
      }
      myset.insert(full);
      start->secondNeighbor = neighbor2;
      neighbor2->count = start->count + 1;
      nodes.push_back(neighbor2);
    }
    full = "";
    for (int i = 0; i < neighbor3->puzzle.size(); i++) {
      full += neighbor3->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      if (start->firstNeighbor == NULL && start->secondNeighbor == NULL) {
	start->nextNeighbor = neighbor3;
      }
      myset.insert(full);
      start->thirdNeighbor = neighbor3;
      neighbor3->count = start->count + 1;
      nodes.push_back(neighbor3);
    }
  }

  else if (zeroindex == 5) {
    Node* neighbor1 = new Node();
    Node* neighbor2 = new Node();
    Node* neighbor3 = new Node();
    neighbor1->puzzle = start->puzzle;
    neighbor1->puzzle[5] = neighbor1->puzzle[2];
    neighbor1->puzzle[2] = 0;
    neighbor2->puzzle = start->puzzle;
    neighbor2->puzzle[5] = neighbor2->puzzle[4];
    neighbor2->puzzle[4] = 0;
    neighbor3->puzzle = start->puzzle;
    neighbor3->puzzle[5] = neighbor2->puzzle[8];
    neighbor3->puzzle[8] = 0;
    full = "";
    for (int i = 0; i < neighbor1->puzzle.size(); i++) {
      full += neighbor1->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      start->nextNeighbor = neighbor1;
      myset.insert(full);
      start->firstNeighbor = neighbor1;
      neighbor1->count = start->count + 1;
      nodes.push_back(neighbor1);
    }
    full = "";
    for (int i = 0; i < neighbor2->puzzle.size(); i++) {
      full += neighbor2->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      if (start->firstNeighbor == NULL) {
	start->nextNeighbor = neighbor2;
      }
      myset.insert(full);
      start->secondNeighbor = neighbor2;
      neighbor2->count = start->count + 1;
      nodes.push_back(neighbor2);
    }
    full = "";
    for (int i = 0; i < neighbor3->puzzle.size(); i++) {
      full += neighbor3->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      if (start->firstNeighbor == NULL && start->secondNeighbor == NULL) {
	start->nextNeighbor = neighbor3;
      }
      myset.insert(full);
      start->thirdNeighbor = neighbor3;
      neighbor3->count = start->count + 1;
      nodes.push_back(neighbor3);
    }
  }

  else if (zeroindex == 7) {
    Node* neighbor1 = new Node();
    Node* neighbor2 = new Node();
    Node* neighbor3 = new Node();
    neighbor1->puzzle = start->puzzle;
    neighbor1->puzzle[3] = neighbor1->puzzle[6];
    neighbor1->puzzle[6] = 0;
    neighbor2->puzzle = start->puzzle;
    neighbor2->puzzle[3] = neighbor2->puzzle[4];
    neighbor2->puzzle[4] = 0;
    neighbor3->puzzle = start->puzzle;
    neighbor3->puzzle[3] = neighbor2->puzzle[8];
    neighbor3->puzzle[8] = 0;
    full = "";
    for (int i = 0; i < neighbor1->puzzle.size(); i++) {
      full += neighbor1->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      start->nextNeighbor = neighbor1;
      myset.insert(full);
      start->firstNeighbor = neighbor1;
      neighbor1->count = start->count + 1;
      nodes.push_back(neighbor1);
    }
    full = "";
    for (int i = 0; i < neighbor2->puzzle.size(); i++) {
      full += neighbor2->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      if (start->firstNeighbor == NULL) {
	start->nextNeighbor = neighbor2;
      }
      myset.insert(full);
      start->secondNeighbor = neighbor2;
      neighbor2->count = start->count + 1;
      nodes.push_back(neighbor2);
    }
    full = "";
    for (int i = 0; i < neighbor3->puzzle.size(); i++) {
      full += neighbor3->puzzle[i];
    }
    if (myset.find(full) != myset.end()) {
      if (start->firstNeighbor == NULL && start->secondNeighbor == NULL) {
	start->nextNeighbor = neighbor3;
      }
      myset.insert(full);
      start->thirdNeighbor = neighbor3;
      neighbor3->count = start->count + 1;
      nodes.push_back(neighbor3);
    }
  }


  /*if (start->nextNeighbor == NULL) {
    if (start->parent->secondNeighbor != NULL) {
      start->parent->nextNeighbor = secondNeighbor;
    }

    else if (start->parent->thirdNeighbor != NULL) {
      start->parent->nextNeighbor = thirdNeighbor;
    }
    
    else if (start->parent->fourthNeighbor != NULL) {
      start->parent->nextNeighbor = fourthNeighbor;
    }
    else {
      start->parent->nextNeighbor = NULL;
    }

    if (start->parent->nextNeighbor != NULL) {
      generateNeighbors(start->parent->nextNeighbor);
    }

    else {
    }
  }
  
  if (currentNeighbor == 1) {
    currentNeighbor++;
    generateNeighbors(start->nextNeighbor);
    
  }

  else if (currentNeighbor == 2) {
    currentNeighbor++;
    generateNeighbors(start->parent->parent->nextNeighbor);





  

  

  else if (currentNeighbor == 1) {
    currentNeighbor++;
    generateNeighbors(start->secondNeighbor);
    
  }

  else if (currentNeighbor == 1 && start->thirdNeighbor != NULL) {
    currentNeighbor++;
    generateNeighbors(start->thirdNeighbor);
    
  }

  else if (currentNeighbor == 1 && start->fourthNeighbor != NULL) {
    currentNeighbor++;
    generateNeighbors(start->fourthNeighbor);
    
  }

  else if (currentNeighbor == 1 ) {
    currentNeighbor++;
    generateNeighbors(start->parent->secondNeighbor);
    
  }

  else if (currentNeighbor == 2 ) {
    currentNeighbor++;
    generateNeighbors(start->parent->secondNeighbor);
  }

  else if (currentNeighbor == 3) {
    if (start->parent->thirdNeighbor == NULL && start->parent->fourthNeighbor == NULL) {
      currentNeighbor = 1;
      generateNeighbors(start->parent->firstNeighbor->firstNeighbor);
    }

    else {
      currentNeighbor++;
      generateNeighbors(start->parent->thirdNeighbor);
    }
  }

  else if (currentNeighbor == 4) {
    if (start->parent->fourthNeighbor == NULL) {
      currentNeighbor = 1;
      generateNeighbors(start->parent->firstNeighbor->firstNeighbor);
    }

    else {
      currentNeighbor = 1;
      generateNeighbors(start->parent->fourthNeighbor);
    }
    }*/
  
}

int main() {

  int x;
  int y;
  int z;
  int a;
  int b;
  int c;
  int j;
  int k;
  int l;
  cout << "Enter puzzle" << endl;

  cin >> x;
  root->puzzle.push_back(x);
  cin >> y;
  root->puzzle.push_back(y);
  cin >> z;
  root->puzzle.push_back(z);
  cin >> a;
  root->puzzle.push_back(a);
  cin >> b;
  root->puzzle.push_back(b);
  cin >> c;
  root->puzzle.push_back(c);
  cin >> j;
  root->puzzle.push_back(j);
  cin >> k;
  root->puzzle.push_back(k);
  cin >> l;
  root->puzzle.push_back(l);

  string full = "";

  for (int i = 0; i < root->puzzle.size(); i++) {
    full += root->puzzle[i];
  }
  myset.insert(full);
  nodes.push_back(root);

  while(nodes.size() > 0) {
    vector<Node*> temp = nodes;
    nodes.clear();
    for (int i = 0; i < temp.size(); i++) {
      generateNeighbors(temp[i]);
    }
      
  }
}



