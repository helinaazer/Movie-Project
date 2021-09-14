#include "borrow.h"
#include <algorithm>
#include <iterator>

using namespace std;

// the process of borrowing movie
void Borrow::innerProcess(Movie *movie, Customer *customer) {
  if (!movie->decreaseStock(1)) {
    cerr << "There are not enough of " << movieData << endl;
  } else {
    customer->storeHistory(update);
    customer->doBorrow(movie);
  }
}