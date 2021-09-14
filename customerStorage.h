#ifndef customerStorage_h
#define customerStorage_h

#include "customer.h"
#include "hashTable.h"

class CustomerStorage {
public:
  // friend ostream& operator<<(ostream& out, const CustomerStorage&
  // customerStorage);

  // constructor
  CustomerStorage();
  // destructor
  ~CustomerStorage();
  // copy constructor
  CustomerStorage(const CustomerStorage &cust) = delete;
  // copy assignment
  CustomerStorage &operator=(const CustomerStorage &cust) = delete;
  // move assignment
  CustomerStorage &operator=(CustomerStorage &&cust) = delete;
  // move constructor
  CustomerStorage(CustomerStorage &&cust) = delete;
  // function that adds customer
  void addCustomer(Customer *customer);
  // function that finds customer
  Customer *findCustomer(int i);
  // function that displays customer ids
  void customerIDs();
  // function to output the sorted movies
  // ostream& output(ostream& out) const;

private:
  // struct for customers
  struct HashCust {
    uint operator()(const int &c) const { return c % TABLE_SIZE; }
  };
  // index customers by the customerID
  HashTable<int, Customer *, HashCust> customers;
};

#endif