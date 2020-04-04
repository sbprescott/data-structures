#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>

class Vector {
    public:
        Vector(int s);
        ~Vector();
        Vector(std::initializer_list<int> lst);

        int& operator[](int i);
        int size() const;


    private:
        int* elem_;
        int size_;

};

#endif