//
// Created by alex on 24.11.2021.
//

#ifndef UNTITLED5_PRESENTER_H
#define UNTITLED5_PRESENTER_H


#include <complex>
#include <vector>
#include <iostream>

using std::complex;
using std::ostream;
using std::vector;
using std::cout;
using std::endl;

class Presenter {
public:
    Presenter() = default;

    void outputVector(const vector<complex<double>> & i);

    void outputDoubleVector(const vector<vector<complex<double>>> & i);
};


#endif //UNTITLED5_PRESENTER_H
