#ifndef hashTable_h
#define hashTable_h

#include "hashNode.h"
#include "movie.h"
#include <functional>
#include <string>

using namespace std;

template <class Key, class Value, class Hash = HashKey<Key>>
class HashTable {
public:
    //constructor
    HashTable() {
        table = new HashNode<Key, Value> * [TABLE_SIZE]();
    }
    // copy constructor
    HashTable(const HashTable &hash) = delete;
    // copy assignment
    HashTable &operator=(const HashTable &hash) = delete;
    // move assignment
    HashTable &operator=(HashTable &&hash) = delete;
    // move constructor
    HashTable(HashTable &&hash) = delete;

    //destructor
    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            HashNode<Key, Value>* it = table[i];
            while (it) {
                HashNode<Key, Value>* j = it;
                it = it->getNext();
                delete j;
            }
            table[i] = nullptr;
        }
        delete[] table;
    }
    
    //function to help with getting customerIDs
    void ForAll(
        function<void(Key, Value)> func) {
        for (int i = 0; i < TABLE_SIZE; i++) {
            HashNode<Key, Value>* it = table[i];
            while (it) {
                HashNode<Key, Value>* j = it;
                func(j->getKey(), j->getValue());
                it = it->getNext();
            }
        }
    }

    //function to insert the key and value into table
    void insert(const Key& k, const Value& v) {
        int hashValue = hashing(k);
        HashNode<Key, Value>* j = nullptr;
        HashNode<Key, Value>* it = table[hashValue];
        while (it && it->getKey() != k) {
            j = it;
            it = it->getNext();
        }
        if (!it) {
            it  = new HashNode<Key, Value>(k, v);
            if (!j) {
                table[hashValue] = it;
            } else {
                j->setNext(it);
            }
        } else {
            it->setValue(v);
        }
    }

    //function that retrieves items by finding its match
    //true if item matches, false if it doesn't
    bool retrieve(const Key& k, Value& v) {
        int hashValue = hashing(k);
        HashNode<Key, Value>* it = table[hashValue];
        while (it) {
            if (it->getKey() == k) {
                v = it->getValue();
                return true;
            }
            it = it->getNext();
        }
        return false;
    }

    //function that finds and removes an item
    void remove(const Key& k) {
        int hashValue = hashing(k);
        HashNode<Key, Value>* j = nullptr;
        HashNode<Key, Value>* it = table[hashValue];
        while (it->getKey() != k && it)  {
            j = it;
            it = it->getNext();
        }
        if (!it) {
            return;
        if(!j) {
            table[hashValue] = it->getNext();
        } else {
            j->setNext(it->getNext());
        }
        delete it;
        }
    }

    //function that gets the key
    int getKeys(Key keys[]) const {
        int in = 0;
        for (int i = 0; i < TABLE_SIZE; i++) {
            HashNode<Key, Value>* it = table[i];
            while (it != nullptr) {
                keys[in++] = it->getKey();
                it = it->getNext();
            }
        }
        return in;
    }

private: 
    HashNode<Key, Value>** table;
    Hash hashing;
};
//sturct for hashMovie
struct HashMovie {
    int operator()(const string& k) const {
        return hash<string>()(k) % TABLE_SIZE;
    }
};
#endif /* hashTable_h */