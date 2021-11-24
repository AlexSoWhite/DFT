//
// Created by alex on 24.11.2021.
//

#include "../include/Presenter.h"

ostream& operator << (ostream& o, complex<double> a) {
    o << "(";

    if (
        static_cast<double>(a.real()) - static_cast<int>(a.real()) > 0.1
        ||
        static_cast<double>(a.real()) == static_cast<int>(a.real())
    ) {
        o << a.real();
    } else {
        o << round(a.real());
    }

    if (
        static_cast<double>(a.imag()) - static_cast<int>(a.imag()) > 0.1
        ||
        static_cast<double>(a.imag()) == static_cast<int>(a.imag())
    ) {
        o << ((a.imag() >= 0) ? " + " : " - ") << std::abs(a.imag());
    } else {
        o << ((a.imag() >= 0) ? " + " : " - ") << std::abs(round(a.imag()));
    }

    o << "j)";
    return o;
}

void Presenter::outputVector(const vector<complex<double>> &i) {
    cout << "[ ";
    for (auto a: i) {
        cout << a << " ";
    }
    cout << "]" << endl;
}

void Presenter::outputDoubleVector(const vector<vector<complex<double>>> &i) {
    for (auto &line: i) {
        for (auto e: line) {
            cout << e << " ";
        }
        cout << endl;
    }
}