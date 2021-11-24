//
// Created by alex on 24.11.2021.
//

#ifndef UNTITLED5_GENERATOR_H
#define UNTITLED5_GENERATOR_H


#include <complex>
#include <vector>

using std::vector;
using std::complex;

class Generator {
    vector<int> possible;
public:

    Generator() {
        possible = {3, 4, 6, 8, 12};
    };

    vector<complex<double>> createVector(int size) {
        vector<complex<double>> result;
        result.reserve(size);
        for (int i = 0; i < size; i++) {
            result.emplace_back(-15 + random() % 30);
        }
        return result;
    }

    vector<complex<double>> createVector() {
        int size = possible.at(random() % possible.size());
        vector<complex<double>> result;
        result.reserve(size);
        for (int i = 0; i < size; i++) {
            result.emplace_back(-15 + random() % 30);
        }
        return result;
    }

    vector<vector<complex<double>>> createDoubleVector() {
        int m = possible.at(random() % possible.size());
        int n = possible.at(random() % possible.size());
        vector<vector<complex<double>>> result;
        result.reserve(m);
        for (int i = 0; i < m; i++ ) {
            result.push_back(createVector(n));
        }
        return result;
    }
};

#endif //UNTITLED5_GENERATOR_H
