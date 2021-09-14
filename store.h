#ifndef store_h
#define store_h

#include "customerStorage.h"
#include "hashTable.h"
#include "storeInventory.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Store {
public:
    //constructor
    Store();
    //read movie from file
    void readMovie(const string& file);
    //read customer from file
    void readCustomers(const string& file);
    //read and run commands from file
    void commands(const string& file);

private:
    CustomerStorage cust;
    StoreInventory store;
};
#endif /* store_h*/
