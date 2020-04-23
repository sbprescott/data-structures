#include "vector.h"
#include <iostream>

int partition(Vector& v, int p, int r) {
    int x = v[r]; // this is our partition
    int i = p -1;
    for (int j = p; j < r; ++j) {
        if (v[j] <= x) {
            ++i;
            // swap v[i] with v[j]
            int tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
        }
    }
    // now swap v[i + 1] and v[r] to ensure pivot is in its place
    int tmp = v[i + 1];
    v[i + 1] = v[r];
    v[r] = tmp;
    return i + 1;
}

void quick_sort(Vector& v, int p, int r) {
    // base case:
    if (p < r) {
        int q = partition(v, p, r);
        quick_sort(v, p, q - 1);
        quick_sort(v, q + 1, r);
    }
}
