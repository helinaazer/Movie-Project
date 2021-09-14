#ifndef classics_h
#define classics_h

#include "movie.h"
#include <string>

class Classics : public Movie {

public:
    //constructor
    Classics();
    //overload constructor
    explicit Classics(const string& s);
    //movie type
    static const char TYPE = 'C';
    // set movie data from file read
    istream& set(istream& in) override;

    // get hashkey by checking if its empty and returns hashkey
    string getHashKey() override;

    // operator <, checks which movie comes first 
    bool operator<(const Movie& movie) const override;

    // operator ==, check if movies are the same
    bool operator==(const Movie& movie) const override;
    
protected:
    // get the desired output
    ostream& output(ostream& out) const override;
    // first and last name of major actor
    string majorActor;
    //release data
    int month;
};
#endif /* classics_h */
