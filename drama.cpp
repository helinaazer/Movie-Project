#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>

#include "drama.h"

using namespace std;

// default constructor
Drama::Drama() : Movie(Drama::TYPE) {}

// set movie data from file read
istream &Drama::set(istream &in) {
  Movie::set(in);
  string tmp;
  getline(in, tmp, ',');
  releaseYear = stoi(tmp);
  return in;
}

// get hashkey by checking if its empty and returns hashkey
string Drama::getHashKey() {
  if (hashKey.empty()) {
    hashKey = director + " " + title;
  }
  return hashKey;
}

// operator <, checks which movie comes first
bool Drama::operator<(const Movie &movie) const {
  try {
    const auto &d = dynamic_cast<const Drama &>(movie);
    return director < d.director && title < d.title;
  } catch (const bad_cast &b) {
    return Movie::operator<(movie);
  }
  return false;
}

// get the desired output
ostream &Drama::output(ostream &out) const {
  Movie::output(out);
  out << ", " << releaseYear;
  return out;
}