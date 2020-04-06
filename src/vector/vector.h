#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>

class Vector {
    public:
        Vector();                                   // default constructor
        Vector(int s);
        Vector(std::initializer_list<int> lst);     // initializer list constructor                      
        ~Vector();                                  // destructor
        
        Vector(const Vector& a);                    // copy constructor
        Vector& operator=(const Vector& a);         // copy assignment

        Vector(Vector&& a);                         // move constructor
        Vector& operator=(Vector&& a);              // move assignment

        int& operator[](int i);
        int& operator[](int i) const;
        int size() const;


    private:
        int* elem_;
        int size_;

};

bool operator==( const Vector& lhs, const Vector& rhs );
bool operator!=( const Vector& lhs, const Vector& rhs );

#endif