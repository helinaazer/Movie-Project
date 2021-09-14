#include "store.h"
#include "movieFactory.h"
#include "transactionFactory.h"

using namespace std;

// constructor
Store::Store() = default;

// read movie from file
void Store::readMovie(const string &file) {
  if (file.empty()) {
    cout << "The movie file could not be found." << endl;
  }
  ifstream read(file);
  string s;
  // read the next line of the file and create a new movie
  while (getline(read, s)) {
    Movie *movie = MovieFactory::create(s);
    if (movie != nullptr) {
      store.addMovie(movie);
    }
  }
  read.close();
}

// read customer from file
void Store::readCustomers(const string &file) {
  if (file.empty()) {
    cerr << "The customer file could not be found." << endl;
  }
  ifstream read(file);
  string s;
  while (!read.eof()) {
    auto *customer = new Customer();
    if (customer->set(read)) {
      cust.addCustomer(customer);
    } else {
      delete customer;
    }
  }
  read.close();
}

// read and run commands from file
void Store::commands(const string &file) {
  if (file.empty()) {
    cout << "The commands file could not be found." << endl;
  }
  ifstream read(file);
  string s;
  while (getline(read, s)) {
    Transaction *transaction = TransactionFactory::createTransaction(s);
    if (transaction != nullptr) {
      transaction->transactionProcess(&store, &cust);
      delete transaction;
    }
  }
  read.close();
}