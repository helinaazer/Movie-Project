#include "storeInventory.h"
#include <iostream>

using namespace std;

// overload operator
ostream &operator<<(ostream &out, const StoreInventory &storeInventory) {
  storeInventory.output(out);
  return out;
}

// constructor
StoreInventory::StoreInventory() { types = 3; }

// destructor
StoreInventory::~StoreInventory() {
  for (int i = 0; i < MAX_TYPES; i++) {
    for (int j = 0; j < count[i]; j++) {
      if (sort[i][j] != nullptr) {
        delete sort[i][j];
      }
    }
  }
}

// function to find movies in the inventory
Movie *StoreInventory::findMovie(const string &find) {
  Movie *mo = nullptr;
  movieMap.retrieve(find, mo);
  return mo;
}

// function to add movies to the inventory
void StoreInventory::addMovie(Movie *mo) {
  if (mo != nullptr) {
    movieMap.insert(mo->getHashKey(), mo);
    addSorted(mo);
  }
}

// add movies in a sorted way
void StoreInventory::addSorted(Movie *mo) {
  int t = accepted(mo->getMovieType());
  if (t >= 0) {
    int s = 0;
    while ((s < count[t]) && *sort[t][s] < *mo) {
      s++;
    }
    if (s < count[t]) {
      for (int i = count[t]; i > s; i--) {
        sort[t][i] = sort[t][i - 1];
      }
    }
    count[t]++;
    sort[t][s] = mo;
  }
}

// checks if movie type is an accepted type
int StoreInventory::accepted(char movieType) {
  switch (movieType) {
  case 'F':
    return 0;
  case 'D':
    return 1;
  case 'C':
    return 2;
  default:
    cerr << "Invalid! " << movieType << " is not recognized";
  }
  return -1;
}

// function to output the sorted movies
ostream &StoreInventory::output(ostream &out) const {
  for (int i = 0; i < types; i++) {
    for (int j = 0; j < count[i]; j++) {
      out << *sort[i][j] << endl;
    }
  }
  return out;
}
