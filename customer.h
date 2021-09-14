#ifndef customer_h
#define customer_h

#include "hashTable.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer {
public:
    //default constructor
    Customer();
    //constructor
    Customer(string first, string last, int custID);
    // copy constructor
    Customer(const Customer &cust) = delete;
    // copy assignment
    Customer &operator=(const Customer &cust) = delete;
    // move assignment
    Customer &operator=(Customer &&cust) = delete;
    // move constructor
    Customer(Customer &&cust) = delete;
    //destructor
    ~Customer() = default;
    //set data from file read
    bool set(istream& in);
    //get customer id
    int getCustomerID() const;
    //get the full name of customer
    string getFullName() const;
    //get first name of customer
    string getFirstName() const;
    //get last name of customer
    string getLastName() const;
    //function for store history
    void storeHistory(const string& s);
    //function to display history
    void showHistory(ostream& out);
    //function to get the key for borrow
    void doBorrow(Movie* movie);
    //function to get the key for return
    bool doReturn(Movie* movie);
private:
    string firstName;
    string lastName;
    int customerID;
    vector<string> h;
    //borrowed movies list for customer
    HashTable<string, int, HashMovie> borrowed;
};
#endif /*customer_h*/
