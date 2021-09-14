#include "transactionFactory.h"

using namespace std;

// function to create new transaction
Transaction *TransactionFactory::createTransaction(const string &ct) {
  Transaction *t = nullptr;
  if (ct.length() > 0) {
    istringstream read(ct);
    string tmp;
    read >> tmp;
    switch (tmp[0]) {
    case 'B':
      t = new Borrow();
      break;
    case 'R':
      t = new Return();
      break;
    case 'H':
      t = new History();
      break;
    case 'I':
      t = new Inventory();
      break;
    default:
      cerr << tmp << " is not a valid command." << endl;
      break;
    }
    if (t != nullptr) {
      t->set(ct);
    }
  }
  return t;
}