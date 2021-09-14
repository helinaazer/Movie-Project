#include "movieFactory.h"
#include "classics.h"
#include "comedy.h"
#include "drama.h"
#include <iostream>
#include <istream>
#include <sstream>
#include <string>

using namespace std;

// find corresponding movie factory and create the movie object
Movie *MovieFactory::create(string streamLine) {
  Movie *mo = nullptr;
  if (streamLine.length() > 0) {
    istringstream c(streamLine);
    string s;
    c >> s;
    switch (s[0]) {
    case 'D':
      mo = new Drama();
      break;
    case 'C':
      mo = new Classics();
      break;
    case 'F':
      mo = new Comedy();
      break;
    default:
      cerr << "Movie type " << streamLine[0]
           << " is not valid and is unrecognized: " << streamLine << endl;
    }
    if (mo != nullptr) {
      mo->set(c);
    }
  }
  return mo;
}