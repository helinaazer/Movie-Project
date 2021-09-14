#ifndef hashNode_h
#define hashNode_h

#include "movie.h"
#include <string>

using namespace std;

const int TABLE_SIZE = 25;

template <class Key, class Value>
class HashNode {
public:
    //constructor that sets t, s, and next
    HashNode(Key kk, const Value& vv) : 
        v(vv), 
        n(nullptr) {
            k = move(kk);
            //v = move(vv);
        }

    //setter function to set the value
    void setValue(Value v) {
        HashNode::v=v;
    }

    //setter function to set next
    void setNext(HashNode* n) {
        HashNode::n=n;
    }

    //getter function to get the key
    Key getKey() const {
        return k;
    }

    //getter function to get the value
    Value getValue() const {
        return v;
    }

    //getter function to get next
    HashNode* getNext() const {
        return n;
    }

private:
    Key k;
    Value v;
    HashNode* n;
};
//hash key struct
template <class Key>
//struct for hashKey
struct HashKey {
    int operator()(const Key& k) const {
        return static_cast<int>(k) % TABLE_SIZE;
    }
};

#endif /* hashNode_h */