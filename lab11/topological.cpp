#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>

using namespace std;

/**
 * \brief This is the main class
 * Takes in one command line argument
 */
int main(int argc, char** argv) {
  if (argc != 2) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }

  /**
  * Tries to open the file
  */
  ifstream file(argv[1], ifstream::binary);
  if (!file.is_open()) {
    cout << "Unable to open file '" << argv[1] << "'." << endl;
    exit(2);
  }

  /**
  * creates two vectors, one of all of the pre-reqs, and one of the classes that require those prereqs
  */
  string s1, s2;
  vector<string> edges;
  vector<string> bedges;
  while (file >> s1 && file >> s2) {
    edges.push_back(s1);
    bedges.push_back(s2);
  }

  edges.pop_back();
  bedges.pop_back();
  
  vector<string> order;

  /**
  * Iterates through all pre-reqs and if that pre-req doesn't require and pre-reqs then it is added to the class order list
  */
  while (edges.size() > 0) {
    string key = edges[0];
    for (int j = 0; j < edges.size(); j++) {
      if (key == bedges[j]) {
	string first = key;
	string last = bedges[0];
	edges.erase(edges.begin());
        bedges.erase(bedges.begin());
	edges.push_back(first);
	bedges.push_back(last);
	break;
      }
      else if (j == bedges.size() - 1) {
	bool keyorder = false;
	for (int n = 0; n < order.size(); n++) {
	  if (key == order[n]) {
	    keyorder = true;
	    break;
	  }
	}
	if (keyorder == false) {
	  order.push_back(key);
	}
	for (int k = 0; k < edges.size(); k++) {
	  if (edges[k] == key) {
	    edges.erase(edges.begin() + k);
	    //if (bedges.size() == 1) {
	    //order.push_back(bedges[0]);
	    //}
	    bool inedges = false;
	    for (int i = 0; i < edges.size(); i++) {
	      if (bedges[k] == edges[i]) {
		inedges = true;
		break;
	      }
	    }

	    bool inbedges = false;
	    int count = 0;
	    for (int i = 0; i < bedges.size(); i++) {
	      if (bedges[k] == bedges[i]) {
		count++;
	      }
	      if (count > 1) {
		inbedges = true;
		break;
	      }
	    }

	    bool inorder = false;
	    for (int i = 0; i < order.size(); i++) {
	      if (bedges[k] == order[i]) {
		inorder = true;
		break;
	      }
	    }
	    
	    if (inedges == false && inbedges == false && inorder == false) {
	      order.push_back(bedges[k]);
	    }
	      
	    bedges.erase(bedges.begin() + k);
	    k--;
	  }
	}
	
	break;
      }
    }
  }

  for (int i = 0; i < order.size(); i++) {
    cout << order[i] << " ";
  }

  cout << endl;


  

  file.close();
}
