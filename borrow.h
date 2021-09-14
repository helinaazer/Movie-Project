#ifndef borrow_h
#define borrow_h

#include "returnOrBorrow.h"

 class Borrow : public ReturnOrBorrow {
     public:
     //constructor that represents Borrow as a B
     Borrow() : ReturnOrBorrow('B') { }
     //the process of borrowing movie
     void innerProcess(Movie* movie, Customer* customer) override;

 };
#endif /* borrow_h */