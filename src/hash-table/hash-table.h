//
// hash-table.h
// -----------------------------------------
// Implements a hash table container for strings
//
// @author Sam Prescott


#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <list>

class hashTable {
    public:
        hashTable(unsigned table_size): table_(table_size),
            size_(0),
            table_size_(table_size) {}
        ~hashTable() {}
        void insert(const std::string &s);
        bool search(const std::string &s);
        int size() const;
  
    private:
        std::vector<std::list<std::string> > table_;
        unsigned size_;
        unsigned table_size_;
        unsigned hash(const std::string &s);
        void rehash();
};
#endif
