#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <initializer_list>
#include <stdexcept>

template<typename T>
class Vector {
    public:
        Vector() {
            elem_ = new T[0];
            size_ = 0;
            capacity_ = 0;
        }

        Vector(int s) {
            if (s < 0) {
                throw std::length_error{"Vector size must be positive."};
            }

            size_ = s;
            capacity_ = s;
            elem_ = new T[s];
        }

        Vector(std::initializer_list<T> lst) {
            elem_ = new T[lst.size()];
            size_ = static_cast<int>(lst.size());
            capacity_ = static_cast<int>(lst.size());
            std::copy(lst.begin(), lst.end(), elem_);
        }

        ~Vector() {
            delete[] elem_;
        }
        
        Vector(const Vector& a) {
            elem_ = new T[a.size_];
            size_ = a.size_;

            for (int i = 0; i != size_; i++) {
                elem_[i] = a.elem_[i];
            }
        }

        Vector(Vector&& a) {
            elem_ = a.elem_;
            size_ = a.size_;
            a.elem_ = nullptr;
            a.size_ = 0;
        }

        Vector& operator=(const Vector& a) {
            T* p = new T[a.size_];
            for (int i = 0; i != a.size_; i++) {
                p[i] = a.elem_[i];
            }
            delete[] elem_;
            elem_ = p;
            size_ = a.size_;
            return *this;
        }

        Vector& operator=(Vector&& a) {
            elem_ = a.elem_;
            size_ = a.size_;
            a.elem_ = nullptr;
            a.size_ = 0;
            return *this;
        }

        void push_back(T t) {
            if (size_ == capacity_) {
                resize(std::max(2.0, capacity_ * 1.5));
            }

            size_++;
            elem_[size_ - 1] = t;
        }

        void resize(int s) {
            if (s < 0) {
                throw std::length_error{"Vector capacity must be positive."};
            }

            int* temp = new T[s];
            for (int i = 0; i != size_; i++) {
                temp[i] = elem_[i];
            }

            delete[] elem_;
            elem_ = temp;

            capacity_ = s;

            // From cppreference.com: If the current size_ is greater than s, 
            // the container is reduced to its first s elements. 
            if (s < size_) {
                size_ = s;
            }
        }

        int capacity() {
            return capacity_;
        }

        int size() const {
            return size_;
        }

        T& operator[](int i) {
            return elem_[i];
        }

        T& operator[](int i) const {
            return elem_[i];
        }

        T& at(int i) {
            // bounds check:
            if (i >= size_) {
                throw std::out_of_range("Index is out of range.");
            }

            return elem_[i];
        }

        T& front() {
            // check if empty
            if (size_ == 0) {
                throw std::out_of_range("front() cannot be called on an empty Vector.");
            }

            return elem_[0];
        }

        T& back() {
            if (size_ == 0) {
                throw std::out_of_range("back() cannot be called on an empty Vector.");
            }

            return elem_[size_ - 1];
        }

    private:
        T* elem_;
        int size_;
        int capacity_;

};

template<typename T> bool operator==(const Vector<T>& lhs, const Vector<T>& rhs) {
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

template<typename T> bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs) {
    return !(lhs == rhs);
}

#endif