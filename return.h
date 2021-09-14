#ifndef return_h
#define return_h

#include "returnOrBorrow.h"

class Return : public ReturnOrBorrow {
public: 
    //constructor
    Return() : ReturnOrBorrow('R') { }
    //process of returning movie and update stock and history
    void innerProcess(Movie* movie, Customer* customer) override;
};
#endif /* return_h */