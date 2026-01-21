#include "heap.h"
#include "node.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <map>
#include <string>

using namespace std;

void encoder(Node* root, map<char, string>& map, string& path) {
  if (root->value != '\0') {
    map.insert(pair<char, string>(root->value, path));
  }
  else { 
    path = path + "0";
    encoder(root->left, map, path);
    path.pop_back();
    path = path + "1";
    encoder(root->right, map, path);
    path.pop_back();
  }
}

int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // read in characters one by one, until reading fails (we hit the end of the file)
    char g;
    map<char, int> chars;
    while (file.get(g)) {
      if (chars.find(g) == chars.end()) {
	if (g >= 0x20 && g<= 0x7e) {
	  chars.insert(pair<char, int>(g, 1));
	}
      }
      else {
	chars.find(g)->second++;
      }
    }

    heap h;

    for (std::map<char, int>::iterator it = chars.begin(); it != chars.end(); it++) {
      Node* node = new Node();
      node->value = it->first;
      node->count = it->second;
      h.insert(node);
    }

    while (h.size() > 1) {
      Node* node = new Node();
      node->count = h.findMin();
      node->left = h.deleteMin();
      node->count += h.findMin();
      node->right = h.deleteMin();
      h.insert(node);
    }

    map<char, string> encodedmap;
    map<char, string>& map = encodedmap;
    string path = "";
    string& passpath = path;
    encoder(h.findMinNode(), map, passpath);
    int bitlength = 0;

    for (std::map<char, string>::iterator it = map.begin(); it != map.end(); it++) {
      if (it->first == 0x20) {
	cout <<"space " << it->second << endl;
      }
      else {
	cout << it->first << " " << it->second << endl;
      }
      bitlength += (it->second.size() * chars.find(it->first)->second);
    }

    cout << "----------------------------------------" << endl;

    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);
    while (file.get(g)) {
      cout << map.find(g)->second << " ";
    }

    cout << endl;

    cout << "----------------------------------------" << endl;

    cout << "There are a total of " << h.findMinNode()->count << " symbols that are encoded." << endl;

    cout << "There are " << map.size() << " distinct symbols used." << endl;

    cout << "There were " << 8 * h.findMinNode()->count << " bits in the original file." << endl;

    cout << "There were " << bitlength << " bits in the compressed file." << endl;
    
    cout << "This gives us a compression ratio of " << static_cast<double>(8 * h.findMinNode()->count) / static_cast<double>(bitlength) << endl;

    cout << "The cost of the Huffman tree is " << static_cast<double>(bitlength) / static_cast<double>(h.findMinNode()->count) << " bits per character." << endl;    

    // a nice pretty separator
    //cout << "----------------------------------------" << endl;

    // once we hit the end of the file we are marked as "failed", so clear that
    // then "seek" to the beginning of the file to start again
    

    // Read the file again, and print to the screen
    //while (file.get(g)) {
    //  cout << g;
    //}

    // close the file
    file.close();

    

    return 0;
}


  
  
    
