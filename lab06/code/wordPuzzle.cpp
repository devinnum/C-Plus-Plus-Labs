#include <iostream>
#include <unordered_set>
#include <fstream>

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            cout << grid[r][c];
        }
        cout << endl;
    }
    return true;
}

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}

int main(int argc, char **argv) {
  unordered_set<string>* map = new unordered_set<string>;
  string xlen;
  for (int i = 0; argv[2][i] != 'x'; i++) {
    xlen += argv[2][i];
  }
  string ylen;
  for (int i = xlen.length() + 1; argv[2][i] != '.'; i++) {
    ylen += argv[2][i];
  }
  int x = stoi(xlen);
  int y = stoi(ylen);
  string token;
  ifstream dic(argv[1]);

  while (dic >> token) {
    dic >> token;
    map->insert(token);
  }

  readInGrid(argv[2], x, y);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 8; k++) {
	for (int l = 3; l < 4; l++) {
	  if (map->find(getWordInGrid(i,j,k,l,500,500)) != map->end() &&
	      getWordInGrid(i,j,k,l,500,500).length()>=3) {
	    string s = getWordInGrid(i,j,k,l,500,500);
	    if (k == 0) {
	      cout << "N (" << i << ", " << j << "): " << s << endl;
	    }
	    else if (k == 1) {
	      cout << "NE(" << i << ", " << j << "): " << s << endl;
	    }
	    else if (k == 2) {
	      cout << "E (" << i << ", " << j << "): " << s << endl;
	    }
	    else if (k == 3) {
	      cout << "SE(" << i << ", " << j << "): " << s << endl;
	    }
	    else if (k == 4) {
	      cout << "S (" << i << ", " << j << "): " << s << endl;
	    }
	    else if (k == 5) {
	      cout << "SW(" << i << ", " << j << "): " << s << endl;
	    }
	    else if (k == 6) {
	      cout << "W (" << i << ", " << j << "): " << s << endl;
	    }
	    else {
	      cout << "NW(" << i << ", " << j << "): " << s << endl;
	    }
	  }
        }
      }
    }
  }
}




