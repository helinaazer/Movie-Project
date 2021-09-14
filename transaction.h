#ifndef transaction_h
#define transaction_h

#include "customer.h"
#include "customerStorage.h"
#include "movie.h"
#include "storeInventory.h"
#include <sstream>
#include <string>

using namespace std;

class Transaction {
public:
    //constructor
    explicit Transaction(char k);
    //destructor
    virtual ~Transaction();
    // copy constructor
    Transaction(const Transaction &transaction) = delete;
    // copy assignment
    Transaction &operator=(const Transaction &transaction) = delete;
    // move assignment
    Transaction &operator=(Transaction &&transaction) = delete;
    // move constructor
    Transaction(Transaction &&transaction) = delete;
    //function to process new transactions
    virtual void transactionProcess(StoreInventory* /*storeInventory*/, CustomerStorage* /*customerStorage*/) {};
    //function to check if customer ID exists
    virtual bool checkCustomerID(Customer* customer, int id);
    //function to set data for command line
    virtual void set(string data);
    //get customer id function
    int getCustomerID() { return customerID; }

protected:
    char K;
    int customerID = -1;
    string update;
};
#endif /* transaction_h */