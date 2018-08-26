// hash-table.cc
// ----------------------------------------
// An implementation of hashTable using separate chaining
//
// @author Sam Prescott

#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

#include "hash-table.h"

hashTable::~hashTable() {}

void hashTable::insert(const std::string & s) {
    std::list<std::string> & inlist = table_[hash(s)];
    // search for string
    if(search(s)) {
        return; // if string is already in hashTable, return
    } else {
        // otherwise add string to vector
        inlist.push_back(s);
        size_++; // increment size
        // TODO rehash here?
        return;
    }
}

bool hashTable::search(const std::string & s) {
    std::list<std::string> &  hList = table_[hash(s)];
    return find( hList.begin( ), hList.end( ), s ) != hList.end();
}

unsigned hashTable::hash(const std::string &s) {
    std::hash<std::string> string_hash;
    return string_hash(s) % table_size_; //mod by table size to ensure bounds
}

void hashTable::rehash() {
}

