#include "history.h"
#include <iostream>
#include <string>

using namespace std;

// set the data from the file read
void History::set(string data) {
  Transaction::set(data);
  istringstream read(data);
  string tmp;
  read >> tmp;
  read >> customerID;
}

// function that processes the transactions
void History::transactionProcess(StoreInventory * /*storeInvenotyr*/,
                                 CustomerStorage *customerStorage) {
  Customer *customer = customerStorage->findCustomer(customerID);
  if (customer != nullptr) {
    customer->showHistory(cout);
  } else {
    cerr << "Customer " << customerID << " could not be found" << endl;
  }
}