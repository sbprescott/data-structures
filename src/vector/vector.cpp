#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "vector.h"

Vector::Vector()
    :elem_{new int[0]},
    size_{0},
    capacity_{0}
{
}

Vector::Vector(int s)
{
    if (s < 0)
    {
        throw std::length_error{"Vector size must be positive."};
    }

    size_ = s;
    capacity_ = s;
    elem_ = new int[s];

    for (int i = 0; i != s; i++)
    {
        elem_[i] = 0;
    }
}

Vector::Vector(std::initializer_list<int> lst)
    :elem_{new int[lst.size()]},
    size_{static_cast<int>(lst.size())},
    capacity_{static_cast<int>(lst.size())}
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
    {
        elem_[i] = a.elem_[i];
    }
}

Vector::Vector(Vector&& a)
    :elem_{a.elem_},
    size_{a.size_}
{
    a.elem_ = nullptr;
    a.size_ = 0;
}

Vector& Vector::operator=(const Vector& a)
{
    int* p = new int[a.size_];
    for (int i = 0; i != a.size_; i++)
    {
        p[i] = a.elem_[i];
    }
    delete[] elem_;
    elem_ = p;
    size_ = a.size_;
    return *this;
}

Vector& Vector::operator=(Vector&& a)
{
    elem_ = a.elem_;
    size_ = a.size_;
    a.elem_ = nullptr;
    a.size_ = 0;
    return *this;
}

void Vector::push_back(int i)
{
    if (size_ == capacity_)
    {
        resize(std::max(2.0, capacity_ * 1.5));
    }

    size_++;
    elem_[size_ - 1] = i;
}

void Vector::resize(int s)
{
    if (s < 0)
    {
        throw std::length_error{"Vector size must be positive."};
    }

    int* temp = new int[s];
    for (int i = 0; i != size_; i++)
    {
        temp[i] = elem_[i];
    }

    delete[] elem_;
    elem_ = temp;

    capacity_ = s;

    // From cppreference.com: If the current size_ is greater than s, 
    // the container is reduced to its first s elements. 
    if (s < size_)
    {
        size_ = s;
    }
}

int Vector::capacity()
{
    return capacity_;
}

int& Vector::operator[](int i)
{
    return elem_[i];
}

int& Vector::operator[](int i) const
{
    return elem_[i];
}

int& Vector::at(int i) {
    // bounds check:
    if (i >= size_) {
        throw std::out_of_range("Index is out of range.");
    }

    return elem_[i];
}

int& Vector::front() {
    // check if empty
    if (size_ == 0) {
        throw std::out_of_range("front() cannot be called on an empty Vector.");
    }
    return elem_[0];
}

int& Vector::back() {
    if (size_ == 0) {
        throw std::out_of_range("back() cannot be called on an empty Vector.");
    }
    return elem_[size_ - 1];
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
        {
            if (lhs[i] != rhs[i]) break;
        }

        // if here, all elements in lhs & rhs are equal
        ret = true;
    }

    return ret;
}

bool operator!=( const Vector& lhs, const Vector& rhs )
{
    return !(lhs == rhs);
}