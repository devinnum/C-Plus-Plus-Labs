#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);
vector<string> finaldests;

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE

    string startcity = dests[0];
    dests.erase(dests.begin());
    float minpath = computeDistance(me, startcity, dests);

    cout << "Minimum path has distance " << minpath << ": ";
    printRoute(startcity, finaldests);    
    
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
    sort(dests.begin(), dests.end());
    float mindist = 999999999;
    vector<string> minroute = dests;
    
    do {
      float totaldist = 0;
      for (int i = 0; i < dests.size() - 1; i++) {
        totaldist += me.getDistance(dests[i], dests[i+1]);
      }
      totaldist += me.getDistance(start, dests[0]);
      totaldist += me.getDistance(dests[dests.size() - 1], start);
      if (totaldist < mindist) {
	mindist = totaldist;
	minroute = dests;
      }
    } while(next_permutation(dests.begin(), dests.end()));

    finaldests = minroute;
    return mindist;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
  cout << start << " -> ";
  for (int i = 0; i < dests.size(); i++) {
    cout << dests[i] << " -> ";
  }
  cout << start << endl;
}
