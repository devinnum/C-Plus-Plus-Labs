#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  (insert(root, x))->value = x;
}

AVLNode* AVLTree::insert(AVLNode*& n, const string& x) {

  if (n == NULL) {
    n = new AVLNode();
    return n;
  }

  if (x == n->value) {
    return n;
  }

  else if (x < n->value) {
    if (n->left == NULL) {
      cout << "adding 1 to " << n->value << endl;
      n->height++;
      n->left = new AVLNode();
      balance(n);
      return n->left;
    }
    
    else {
      AVLNode* temp = insert(n->left, x);
      cout << "addding left tree height of " << n->left->height <<"to " << n->value << endl;
      n->height = 1 + n->left->height;
      cout << "new value is " << n->height << endl;
      balance(n);
      return temp;
    }
  }

  else if (x > n->value) {
    if (n->right == NULL) {
      cout << "adding 1 to " << n->value << endl;
      n->height++;
      cout << "new value is " << n->height<< endl;
      n->right = new AVLNode();
      balance(n);
      return n->right;
    }
    
    else {
      AVLNode* temp = insert(n->right, x);
      cout << "adding right tree height of " << n->right->height <<  "to " << n->value << endl;
      n->height = 1 + n->right->height;
      cout << "new value is " << n->height << endl;
      balance(n);
      return temp;
    }
  }
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  if (find(root, x) == NULL) {
    return false;
  }

  else {
    return true;
  }
}

AVLNode* AVLTree::find(AVLNode* n, const string& x) const {
  if (n == NULL) {
    return NULL;
  }

  if (n->value == x) {
    return n;
  }

  if (x < n->value) {
    return find(n->left, x);
  }

  if (x > n->value) {
    return find(n->right, x);
  }
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
  if (root == NULL) {
    return 0;
  }
  return numNodes(root);
}

int AVLTree::numNodes(AVLNode* n) const {
  if (n->left == NULL && n->right == NULL) {
    return 1;
  }

  if (n->left != NULL && n->right != NULL) {
    return 1 + numNodes(n->left) + numNodes(n->right);
  }

  else if (n->left != NULL) {
    return 1 + numNodes(n->left);
  }

  else {
    return 1 + numNodes(n->right);
  }
}
  

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
  cout << "current node " << n->value << endl;
  cout << height(n->right) << " " << height(n->left) << endl;
    // YOUR IMPLEMENTATION GOES HERE
  if (height(n->left) > (height(n->right)+1) && height(n->left->left) >
      height(n->left->right)) {
    cout << "should rotate right" << endl;
    rotateRight(n);
  }

  else if (height(n->right) > (height(n->left)+1) && height(n->right->right) >
	   height(n->right->left)) {
    cout << "should rotate left" << endl;
    cout << n->value << endl;
    rotateLeft(n);
  }

  else if (height(n->left) > (height(n->right)+1) && height(n->left->left) <
	   height(n->left->right)) {
    cout << "should rotate left then right" << endl;
    rotateLeft(n->left);
    rotateRight(n);
  }
  
  else if (height(n->right) > (height(n->left)+1) && height(n->right->right) <
	   height(n->right->left)) {
    cout << "should rotate right then left" << endl;
    cout << n->value << endl;
    cout << n->right->value << endl;
    rotateRight(n->right);
    cout << "right done" << endl;
    cout << root->value << endl;
    rotateLeft(n);
  }

  
}

AVLNode*& AVLTree::findParentNode(AVLNode*& n, const string& x) {
  if (n->left->value == x) {
    return n;
  }

  else if (n->right->value == x) {
    return n;
  }

  else if (x < n->value) {
    return findParentNode(n->left, x);
  }

  else {
    return findParentNode(n->right, x);
  }
}

AVLNode*& AVLTree::findParentPointer(AVLNode*& n, const string& x) {
  
  if (n->left->value == x) {
    return n;
  }

  else if (n->right->value == x) {
    return n;
  }

  else if (x < n->value) {
    return findParentPointer(n->left, x);
  }

  else {
    return findParentPointer(n->right, x);
  }
}

// rotateLeft performs a single rotation on node n with its right child.
void AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  if (n == root) {
    AVLNode* temp = n->right->left;
    n->right->left = n;
    n = n->right;
    n->left->right = temp;
    n->left->height = n->right->height;
    
  }

  else {
    AVLNode*& parent = (findParentPointer(root, n->value));
    cout << parent->value << endl;



    
    AVLNode* temp = n->right->left;
    n->right->left = n;
    parent = n->right;
    parent->left->right = temp;
    n->height = n->right->right->height;
  }
}

// rotateRight performs a single rotation on node n with its left child.
void AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  if (n == root) {
    n->height = n->left->left->height;
    AVLNode* temp = n->left->right;
    n->left->right = n;
    n = n->left;
    n->right->left = temp;
    n->right->height = n->left->height;
  }

  else {
    AVLNode* parent = (findParentPointer(root, n->value));
    cout << parent->value<< endl;

    
    AVLNode* temp = n->left->right;
    n->left->right = n;
    parent->right = n->left;
    parent->right->right->left = temp;
    n->height = n->left->left->height;
  }
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
