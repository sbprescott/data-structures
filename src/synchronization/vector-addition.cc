// Note: g++ requires -pthread linking option in order for std::thread to work

#include <thread>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <limits>

#include "barrier.h"

struct t_data {
    int max;
    int tid;
};

void max(Barrier& bar, std::vector<int>& vec, struct t_data data, 
         const int num_rounds, const int num_threads) {

    for (int i = 0; i < num_rounds; i++) {
        if (data.tid < (num_threads / std::pow(2.0, i))) {
            //threads may proceed
        
            // only allow (num_threads/2^round_num) threads for each round
            int index0 = std::pow(2.0, i) * (data.tid * 2);
            int index1 = std::pow(2.0, i) * (data.tid * 2 + 1);

            if (data.max < vec[index0]) data.max = vec[index0];

            if (data.max < vec[index1]) data.max = vec[index1];

            // update vec
            vec[index0] = data.max;
        }

        // threads wait in barrier
        bar.wait();
    }

}

int main() {
    std::vector<int> numvec;
 
    // read N numbers from stdin
    int n = 0; // always initialize with declaration
    for (std::string line; getline(std::cin, line);) {
        if (std::cin.eof() || line.length() == 0) break;
        else {
            n++;
            numvec.push_back(stoi(line));
            std::cout << numvec.back() << std::endl;
        }
    }

    int num_threads = n/2;
    int num_rounds = std::log2(n);

    Barrier bar(num_threads); // barrier must be shared amongst threads, pass by reference
    std::vector<std::thread> thread_vec;

    std::cout << "starting  " << num_threads << " threads" << std::endl;
    for (int i = 0; i < num_threads; i++) {
        struct t_data data;
        data.max = std::numeric_limits<int>::lowest();
        data.tid = i;
    
        // use std::ref() to pass pointer behind the scenes
        thread_vec.push_back(std::thread(max, std::ref(bar), std::ref(numvec), data, 
                                         num_rounds, num_threads)); 
    }

    for (auto& t: thread_vec) t.join();

    std::cout << numvec[0] << std::endl;
        
    return 0;
}
