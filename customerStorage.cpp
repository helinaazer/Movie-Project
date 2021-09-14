#include "customerStorage.h"

using namespace std;

// constructor
CustomerStorage::CustomerStorage() = default;

// destructor
CustomerStorage::~CustomerStorage() {
  customers.ForAll([](int, Customer *v) { delete v; });
}

// function that adds customer
void CustomerStorage::addCustomer(Customer *customer) {
  if ((customer != nullptr) && (customer->getCustomerID() != 0)) {
    customers.insert(customer->getCustomerID(), customer);
  }
}

// function that finds customer
Customer *CustomerStorage::findCustomer(int i) {
  Customer *customer;
  return customers.retrieve(i, customer) ? customer : nullptr;
}

// function that displays customer ids
void CustomerStorage::customerIDs() {

  int i = 0;
  customers.ForAll([&i](int, Customer *v) {
    cout << i << ": " << v->getCustomerID() << "\n";
    ++i;
  });
}
