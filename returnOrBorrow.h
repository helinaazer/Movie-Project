#ifndef returnOrBorrow_h
#define returnOrBorrow_h

#include "customer.h"
#include "movie.h"
#include "transaction.h"
#include <string>

using namespace std;

class ReturnOrBorrow : public Transaction {
public:
    //constructor
    explicit ReturnOrBorrow(char t) : Transaction(t) { 
        mediaType = ' ';
        movieType = ' ';
    }
    //set data from the file
    void set(string data) override;
    //getter for media type 
    char getMediaType() { return mediaType; }
    //getter for movie type 
    char getMovieType() { return movieType; }
    //getter for movie data
    string getMovieData() { return movieData; }
    //process for borrowning movie
    virtual void innerProcess(Movie* /*movie*/, Customer* /*customer*/) {};
    //transactions that are processed
    void transactionProcess(StoreInventory* storeInventory, CustomerStorage* customerStorage) override;

protected:
    char mediaType;
    char movieType;
    string movieData;
};
#endif /* ReturnOrBorrow_h */