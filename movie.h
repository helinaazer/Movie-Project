#ifndef movie_h
#define movie_h

#include "utility.h"
#include <string>

using namespace std;

class Movie {
    //operator overload - output
    friend ostream& operator<<(ostream& out, const Movie& movie);
  
  public:
    // destructor
    virtual ~Movie() = default;

    // copy constructor
    Movie(const Movie &movie) = delete;

    // copy assignment
    Movie &operator=(const Movie &movie) = delete;

    // move assignment
    Movie &operator=(Movie &&movie) = delete;

    // move constructor
    Movie(Movie &&movie) = delete;

    // set movie data from file read
    virtual istream& set(istream &in);

    // increase stock
    virtual bool increaseStock(int increase);

    // decrease stock
    virtual bool decreaseStock(int decrease);

    // get the current stock
    int getStock() { return stock; }

    // overloaded operator <, check is lhs < rhs
    virtual bool operator<(const Movie& movie) const;

    // overloaded operator ==, check if two movies are equal
    virtual bool operator==(const Movie& movie) const;

     // get movie type
    char getMovieType() { return movieType; }

    // get title of movie
    string getTitle() { return title; }

    // get director of movie
    string getDirector() { return director; }

    // get release year of movie
    int getReleaseYear() { return releaseYear; }

    // get media type of movie
    char getMediaType() { return mediaType; }

    //get hash key
    virtual string getHashKey() { return title; }
  
  protected: 
    char movieType;
    char mediaType;
    int stock;
    string director;
    string title;
    int releaseYear;
    string hashKey = "";

    // get desired output
    virtual ostream& output(ostream& out) const;

    // constructor
    explicit Movie(char movieType, char mediaType = 'D');
};

#endif /* movie_h */