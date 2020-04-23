#include "vector.h"
#include <iostream>
#include <limits>

Vector merge_wiki(Vector left, Vector right) {
    Vector result;

    int i = 0;
    int j = 0;
    for(int k = 0; i < left.size() && j < right.size(); ++k) {
        if (left[i] < right[j]) {
            result.push_back(left[i]);
            ++i;
        } else {
            result.push_back(right[j]);
            ++j;
        }
    }

    for (; i < left.size(); ++i) {
        result.push_back(left[i]);
    }

    for (; j < right.size(); ++j) {
        result.push_back(right[j]);
    }

    return result;
}

Vector merge_sort_wiki(Vector v) {
    if (v.size() <=1) {
        return v;
    }

    Vector left;  // new Vector objects created on the heap per
    Vector right; // each recursive call -> significant overhead

    for (int i = 0; i < v.size(); ++i) {
        if (i < v.size()/2) {
            left.push_back(v[i]);
        } else {
            right.push_back(v[i]);
        }
    }

    left = merge_sort_wiki(left); // calls copy()
    right = merge_sort_wiki(right); // calls copy()

    return merge_wiki(left, right);
}

void merge_CLRS(Vector& A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    Vector L(n1 + 1);
    Vector R(n2 + 1);

    for (int i = 0; i < n1; ++i) {
        L[i] = A[p + i];
    }

    for (int j = 0; j < n2; ++j) {
        R[j] = A[q + j + 1];
    }

    L[n1] = std::numeric_limits<int>::max();
    R[n2] = std::numeric_limits<int>::max();

    int i = 0;
    int j = 0;
    for (int k = p; k <= r; ++k) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
        }
    }
}

void merge_sort_CLRS(Vector& A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort_CLRS(A, p, q);
        merge_sort_CLRS(A, q + 1, r);
        merge_CLRS(A, p, q, r);
    }
}

int main() {
    Vector v{2,1,4,3,5};
    merge_sort_CLRS(v, 0, 4);
    if (v == Vector{1,2,3,4,5}) {
        std::cout << "sorted\n";
    }
}