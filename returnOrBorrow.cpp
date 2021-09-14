#include "returnOrBorrow.h"
#include <algorithm>

using namespace std;

// transactions that are processed
void ReturnOrBorrow::transactionProcess(StoreInventory *storeInventory,
                                        CustomerStorage *customerStorage) {
  Customer *customer = customerStorage->findCustomer(customerID);
  if (customer != nullptr) {
    Movie *movie = storeInventory->findMovie(movieData);
    if (movie == nullptr) {
      cerr << "Movie " << movieData << " could not be found." << endl;
      return;
    }
    if (mediaType != movie->getMediaType()) {
      cerr << "Movie " << movieData << " is not available for mediaType "
           << mediaType << endl;
      return;
    }
    if (movieType != movie->getMovieType()) {
      cerr << "Movie " << movieData << " is not available for movieType "
           << movieType << endl;
      return;
    }
    innerProcess(movie, customer);
  } else {
    cerr << "Customer " << customerID << " could not be found." << endl;
  }
}

// set data from the file
void ReturnOrBorrow::set(string data) {
  Transaction::set(data);
  istringstream read(data);
  string tmp;
  read >> tmp;
  read >> customerID;
  read >> mediaType;
  read >> movieType;
  getline(read, movieData);
  movieData.erase(remove(movieData.begin(), movieData.end(), ','),
                  movieData.end());
  Utility::combine(movieData);
}