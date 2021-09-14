#include "comedy.h"
#include <typeinfo>

using namespace std;

// constructor sets the default value for director, title, and year
Comedy::Comedy() : Movie(Comedy::TYPE) {
  director = "";
  title = "";
  releaseYear = 0;
}

// set movie data from file read
istream &Comedy::set(istream &in) {
  Movie::set(in);
  string tmp;
  getline(in, tmp, ',');
  releaseYear = stoi(tmp);
  return in;
}

// get hashkey by checking if its empty and returns hashkey
string Comedy::getHashKey() {
  if (hashKey.empty()) {
    hashKey = title + " " + to_string(releaseYear);
  }
  return hashKey;
}

// operator <, checks which movie comes first
bool Comedy::operator<(const Movie &movie) const {
  try {

    const auto &c = dynamic_cast<const Comedy &>(movie);

    return !(*this == c) || (title < c.title && releaseYear < c.releaseYear);
  } catch (const bad_cast &b) {
    return Movie::operator<(movie);
  }
  return false;
}

// output operator that returns the output wanted
ostream &Comedy::output(ostream &out) const {
  Movie::output(out);
  out << ", " << releaseYear;
  return out;
}