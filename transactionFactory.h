#pragma once
#include "borrow.h"
#include "history.h"
#include "inventory.h"
#include "return.h"
#include "storeInventory.h"
#include "transaction.h"

using namespace std;

class TransactionFactory {
public:
    //function to create new transaction
    static Transaction* createTransaction(const string& ct);
};