#include "customer.h"
#include <iterator>

using namespace std;

// default construtor sets the first and last name and the customerId
Customer::Customer() {
  firstName = "";
  lastName = "";
  customerID = 0;
}

Customer::Customer(string first, string last, int custID) {
  firstName = move(first);
  lastName = move(last);
  customerID = custID;
}

// set data from file read
bool Customer::set(istream &in) {
  // eof returns true if there is no data to read from the input file
  if (in.eof()) {
    return false;
  }
  try {
    string tmp;
    getline(in, tmp, ' ');
    if (tmp.empty()) {
      return false;
    }
    customerID = stoi(tmp);
    getline(in, firstName, ' ');
    getline(in, lastName);
  } catch (const char *s) {
    return false;
  }
  return true;
}

// get customer id
int Customer::getCustomerID() const { return customerID; }

// get full name of customer
string Customer::getFullName() const { return firstName + " " + lastName; }

// get first name of customer
string Customer::getFirstName() const { return firstName; }

// set last name of customer
string Customer::getLastName() const { return lastName; }

// function that pushes store history
void Customer::storeHistory(const string &s) { h.push_back(s); }

// function that displays the history
void Customer::showHistory(ostream &out) {
  out << "History for " << getFullName() << endl;
  reverse_copy(h.begin(), h.end(), ostream_iterator<string>(out, "\n"));
  out << "-----End of History for " << getFullName() << "-----" << endl;
}

// function that gets the key for borrow
void Customer::doBorrow(Movie *movie) {
  if (movie != nullptr) {
    int quantity = 1;
    if (borrowed.retrieve(movie->getHashKey(), quantity)) {
      quantity++;
    }
    borrowed.insert(movie->getHashKey(), quantity);
  }
}

// function that gets the key for return
bool Customer::doReturn(Movie *movie) {
  if (movie != nullptr) {
    int quantity = 0;
    if (borrowed.retrieve(movie->getHashKey(), quantity) && quantity > 0) {
      quantity--;
      if (quantity > 0) {
        borrowed.insert(movie->getHashKey(), quantity);
      } else {
        borrowed.remove(movie->getHashKey());
      }
    } else {
      return false;
    }
    return true;
  }
  cerr << "Invalid movie" << endl;
  return false;
};