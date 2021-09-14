#include "classics.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <vector>

using namespace std;

// constructor. sets manjor actor to empty string and month to 0
Classics::Classics() : Movie(Classics::TYPE) {
  majorActor = "";
  month = 0;
}

// set movie data from file read
istream &Classics::set(istream &in) {
  Movie::set(in);
  string tmp;
  getline(in, tmp);
  vector<string> s = Utility::splitString(Utility::combine(tmp), ' ');
  majorActor = s[0] + " " + s[1];
  // stoi converts from string to integer
  month = stoi(s[2]);
  releaseYear = stoi(s[3]);
  return in;
}

// get hashkey by checking if its empty and returns hashkey
string Classics::getHashKey() {
  if (hashKey.empty()) {
    hashKey =
        to_string(month) + " " + to_string(releaseYear) + " " + majorActor;
  }
  return hashKey;
}

// operator <, checks which movie comes first
bool Classics::operator<(const Movie &movie) const {
  try {
    const auto &c = dynamic_cast<const Classics &>(movie);
    return month < c.month && releaseYear < c.releaseYear &&
           majorActor < c.majorActor;
  } catch (const bad_cast &b) {
    return Movie::operator<(movie);
  }
  return false;
}

// operator ==, check if movies are the same
bool Classics::operator==(const Movie &movie) const {
  bool e = Movie::operator==(movie);
  try {
    const auto &cs = dynamic_cast<const Classics &>(movie);
    e &= majorActor == cs.majorActor;
  } catch (const bad_cast &b) {
    return e;
  }
  return e;
}

// get the desired output
ostream &Classics::output(ostream &out) const {
  Movie::output(out);
  out << ", " << majorActor << ", " << month << " " << releaseYear;
  return out;
}
