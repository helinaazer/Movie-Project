#include "movie.h"
#include "classics.h"
#include "comedy.h"
#include "drama.h"
#include "utility.h"
#include <iostream>
#include <istream>
#include <sstream>
#include <string>

using namespace std;

// operator overload - output
ostream &operator<<(ostream &out, const Movie &movie) {
  return movie.output(out);
}

// set movie data from file read
istream &Movie::set(istream &in) {
  string tmp;
  getline(in, tmp, ',');
  stock = stoi(tmp);
  getline(in, tmp, ',');
  director = Utility::combine(tmp);
  getline(in, tmp, ',');
  title = Utility::combine(tmp);
  return in;
}

// increase stock
bool Movie::increaseStock(int increase) {
  stock += increase;
  return true;
}

// decrease stock
bool Movie::decreaseStock(int decrease) {
  // if stock is already 0, we cannot go below 0
  if (stock <= 0) {
    stock = 0;
    return false;
  }
  stock -= decrease;
  return true;
}

// overloaded operator <, check is lhs < rhs
bool Movie::operator<(const Movie &movie) const {
  return movieType < movie.movieType;
}

// overloaded operator ==, check if two movies are equal
bool Movie::operator==(const Movie &movie) const {
  return movieType == movie.movieType && director == movie.director &&
         title == movie.title && releaseYear == movie.releaseYear;
}

// get desired output
ostream &Movie::output(ostream &out) const {
  out << movieType << ", " << stock << ", " << director << ", " << title;
  return out;
}

// constructor
Movie::Movie(char movieType, char mediaType) {
  this->movieType = movieType;
  this->mediaType = mediaType;
  stock = 0;
  director = "";
  title = "";
  releaseYear = 0;
}
