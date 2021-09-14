#ifndef inventory_h
#define inventory_h

#include "transaction.h"

class Inventory : public Transaction {
public:
//constructor. inventory is of type I
Inventory() : Transaction('I') { }
//process the transactions
void transactionProcess(StoreInventory* storeInventory, CustomerStorage* /*customerStorage*/) override;

};
#endif /* inventory_h */