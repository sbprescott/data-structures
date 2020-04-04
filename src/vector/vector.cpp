#include<algorithm>
#include "vector.h"

Vector::Vector(int s)
    :elem_{new int[s]}, size_{s}
{
    for (int i = 0; i != s; i++) elem_[i] = 0;
}

Vector::Vector(std::initializer_list<int> lst)
    :elem_{new int[lst.size()]}, size_{static_cast<int>(lst.size())}
{
    std::copy(lst.begin(), lst.end(), elem_);
}

Vector::~Vector() {
    delete[] elem_;
}

int& Vector::operator[](int i)
{
    return elem_[i];
}

int Vector::size() const
{
    return size_;
}