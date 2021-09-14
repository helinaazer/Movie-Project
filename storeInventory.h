#ifndef inventory_hpp
#define inventory_hpp

#include "hashTable.h"
#include "movie.h"
#include <cstdio>
#include <vector>

using namespace std;

class StoreInventory {
    //overload operator
    friend ostream& operator<<(ostream& out, const StoreInventory& storeInventory);
public:
    //constructor()
    StoreInventory();
    //destructor
    ~StoreInventory(); 
    // copy constructor
    StoreInventory(const StoreInventory &inv) = delete;
    // copy assignment
    StoreInventory &operator=(const StoreInventory &inv) = delete;
    // move assignment
    StoreInventory &operator=(StoreInventory &&inv) = delete;
    // move constructor
    StoreInventory(StoreInventory &&inv) = delete;
    //function to find movies in the inventory
    Movie* findMovie( const string& find);
    //function to add movies to the inventory
    void addMovie(Movie* mo);

private: 
    //add movies in a sorted way
    void addSorted(Movie* mo);
    //checks if movie type is an accepted type
    int accepted(char movieType);
    //function to output the sorted movies
    ostream& output(ostream& out) const;
    static const int MAX_TYPES = 10;
    int count[MAX_TYPES] = {0};
    Movie* sort[MAX_TYPES][100] = {nullptr};
    //types of movies we can have: F, D, C
    int types;
    //hashtable that has movies that have hashkey
    HashTable<string, Movie*, HashMovie> movieMap;
};
#endif /* storeInventory */
