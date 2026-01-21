#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include "heap.h"
#include "node.h"

using namespace std;

void decoder(string bits, map<string, string> map, string& path, string& decoded) {
  for (int i = 0; i <= bits.length(); i++) {
    if (map.find(path) == map.end()) {
      if (bits[i] == '0') {
	path = path + "0";
      }
      else {
	path = path + "1";
      }
    }

    else {
      decoded = decoded + map.find(path)->second;
      path = "";
      i--;
    }
  }
}

  
  /*for (std::map<string, string>::iterator it = map.begin(); it != map.end(); it++) {
    for (int i = 0; i < it->second.length(); i++) {
      if (it->second[i] == '0') {
	if (root->left == NULL) {
	  root->left = new Node();
	}
	if (it->second[i] == it->second.back()) {
	  root->left->value = it->first[0];
	}
	else{
	  decoder(root->left, map);
	}
      }
      else {
	if (root->right == NULL) {
	  root->right = new Node();
	}
	if (it->second[i] == it->second.back()) {
	  root->right->value = it->first[0];
	}
	else {
	  decoder(root->right, map);
	}
      }
    }
    }*/
  


// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }


    map<string, string> premap;
    map<string, string> charmap;
    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code

	premap.insert(pair<string, string>(prefix, character));
	charmap.insert(pair<string, string>(character, prefix));
        //cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
    }

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }


    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    string path = "";
    string& passpath = path;
    string dec = "";
    string& decstring = dec;
      
    
    decoder(allbits, premap, passpath, decstring);
    cout << decstring << endl;
	  
    // close the file before exiting
    file.close();

    return 0;
}


