#include "inventory.h"

using namespace std;

// process the transactions
void Inventory::transactionProcess(StoreInventory *storeInventory,
                                   CustomerStorage * /*customerStorage*/) {
  cout << "The Current Inventory: " << endl;
  cout << *storeInventory << endl;
}
