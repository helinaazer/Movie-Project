#include "return.h"

using namespace std;

// process of returning movie and update stock and history
void Return::innerProcess(Movie *movie, Customer *customer) {
  if (customer->doReturn(movie)) {
    movie->increaseStock(1);
    customer->storeHistory(update);
  } else {
    cerr << movie->getHashKey() << " cannot be returned by customer "
         << customer->getCustomerID() << endl;
  }
}