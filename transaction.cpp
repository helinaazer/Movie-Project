#include "transaction.h"
#include <iostream>
#include <string>

using namespace std;

// constructor
Transaction::Transaction(char k) { K = k; }

// destructor
Transaction::~Transaction() = default;

// function to check if customer ID exists
bool Transaction::checkCustomerID(Customer *customer, int id) {
  if (customer == nullptr) {
    ostringstream s;
    s << id;
    cout << "Customer ID " << s.str() << " could not be found." << endl;
    return true;
  }
  return false;
}

// function to set data for command line
void Transaction::set(string data) { update = move(data); }
