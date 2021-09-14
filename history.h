#ifndef history_h
#define history_h

#include "transaction.h"

using namespace std;

class History : public Transaction {
public:
    //constructor
    History() : Transaction('H') { }
    //set the data from the file read
    void set(string data) override;
    //process the transactions
    void transactionProcess(StoreInventory* /*storeInventory*/, CustomerStorage* customerStorage) override;
};
#endif /* history_h */ 