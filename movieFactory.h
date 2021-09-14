#ifndef movieFactory_h
#define movieFactory_h

#include "movie.h"

using namespace std;

class MovieFactory {
public:
    //find corresponding movie factory and create the movie object
    static Movie* create(string streamLine);
};
#endif /* movieFactory.h */