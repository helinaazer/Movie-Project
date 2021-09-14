/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include "classics.h"
#include "customer.h"
#include "movie.h"
#include "movieFactory.h"
#include "store.h"
#include "transactionFactory.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

void testStore1() {
  cout << "Start testStore1" << endl;
  // Should do something more, but lets just read files
  // since each implementation will
  string cfile = "testcommands-1.txt";
  stringstream out;
  ifstream fs(cfile);
  assert(fs.is_open());
  char commandType;
  string discard;
  while (fs >> commandType) {
    out << commandType;
    getline(fs, discard);
    // cout << discard << endl;
  }
  fs.close();
  string result = "IHHBRIBBIH";
  assert(out.str() == result);
  cout << "End testStore1" << endl;
}

void testStore2() {
  cout << "Start testStore2" << endl;
  Customer c;
  int customerID = 1234;
  c.getCustomerID();
  cout << "Testing getCustomerID(): " << customerID << endl;
  string firstName = "Harry";
  c.getFirstName();
  cout << "Testing getFirstName(): " << firstName << endl;
  string lastName = "Potter";
  c.getLastName();
  cout << "Testing getLastName(): " << lastName << endl;
  cout << "End testStore2" << endl;
}

void testStore3() {
  cout << "Start testStore3" << endl;
  Store store2;
  store2.readMovie("ownMoviesTest.txt");
  store2.readCustomers("ownCustomerTest.txt");
  store2.commands("ownCommandsTest.txt");
  cout << "End testStore3" << endl;
}

void testStore4() {
  cout << "Start testStore4" << endl;
  Movie *a = MovieFactory::create(
      "C, 10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942");
  Movie *b = MovieFactory::create(
      "D, 10, Barry Levinson, Same Director Good Morning Vietnam, 1988");
  Movie *d = MovieFactory::create(
      "C, 10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942");
  Movie *e = MovieFactory::create(
      "F, 10, John Landis, National Lampoon's Animal House, 1978");
  assert(*a < *b || *b < *a || *a == *b);
  cout << *a << endl;
  cout << "Testing getStock(): " << a->getStock() << endl;
  cout << "Testing getTitle(): " << a->getTitle() << endl;
  cout << "Testing getDirector(): " << e->getDirector() << endl;
  cout << "Testing getReleaseYear(): " << e->getReleaseYear() << endl;
  cout << "Testing getHashKey(): " << e->getHashKey() << endl;
  cout << "Testing getMediaType(): " << e->getMediaType() << endl;
  cout << "Testing getMovieType(): " << e->getMovieType() << endl;
  cout << *d << endl;
  assert(*a == *d);
  delete b;
  delete a;
  delete d;
  delete e;
  Transaction *t =
      TransactionFactory::createTransaction("B 8000 D F You've Got Mail, 1998");
  Customer *c = new Customer("Harry", "Potter", 1234);
  t->checkCustomerID(c, 1);
  t->getCustomerID();
  delete t;
  CustomerStorage cs;
  cs.addCustomer(c);
  cs.customerIDs();
  cout << "End testStore4" << endl;
}

void testStore5() {
  cout << "Start testStore5" << endl;
  Store store3;
  store3.readMovie("");
  store3.commands("");
  cout << "End testStore5" << endl;
}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;
  Store store;
  store.readMovie("data4movies.txt");
  store.readCustomers("data4customers.txt");
  store.commands("data4commands.txt");
  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

void testAll() {
  testStore1();
  testStore2();
  testStore3();
  testStore4();
  testStore5();
  testStoreFinal();
}
