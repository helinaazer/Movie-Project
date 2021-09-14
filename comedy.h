#ifndef comedy_h
#define comedy_h

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "movie.h"

using namespace std;

class Comedy: public Movie {
  public:
    // constructor
    Comedy();

    // movie type
    static const char TYPE = 'F';

    // set movie data from file read
    istream& set(istream &in) override;

    // get hashkey by checking if its empty and returns hashkey
    string getHashKey() override;

    // operator <, checks which movie comes first 
    bool operator<(const Movie& movie) const override;

  protected:
    // get the desired output
    ostream& output(ostream& out) const override;
};

#endif /*comedy_h */