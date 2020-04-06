#include<algorithm>
#include "vector.h"

Vector::Vector()
    :elem_{new int[0]}, size_{0}
{
}

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

Vector::Vector(const Vector& a)
    :elem_{new int[a.size_]},
    size_{a.size_}
{
    for (int i = 0; i != size_; i++)
        elem_[i] = a.elem_[i];
}

Vector& Vector::operator=(const Vector& a)
{
    int* p = new int[a.size_];
    for (int i = 0; i != a.size_; i++)
        p[i] = a.elem_[i];
    delete[] elem_;
    elem_ = p;
    size_ = a.size_;
    return *this;
}

int& Vector::operator[](int i)
{
    return elem_[i];
}

int& Vector::operator[](int i) const
{
    return elem_[i];
}

int Vector::size() const
{
    return size_;
}

bool operator==( const Vector& lhs, const Vector& rhs )
{
    bool ret = false;

    if (lhs.size() == rhs.size()) {
        for (int i = 0; i != lhs.size(); i++)
            if (lhs[i] != rhs[i]) break;

        // if here, all elements in lhs & rhs are equal
        ret = true;
    }

    return ret;
}

bool operator!=( const Vector& lhs, const Vector& rhs )
{
    return !(lhs == rhs);
}