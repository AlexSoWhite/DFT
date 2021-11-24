//
// Created by alex on 24.11.2021.
//

#ifndef UNTITLED5_METHODS_H
#define UNTITLED5_METHODS_H

#include <vector>
#include <cmath>

namespace algorithms {

    using namespace std;

    vector<complex<double>> dpf(const vector<complex<double>> & input) {
        uint sz = input.size();
        vector<complex<double>> result;
        result.reserve(sz);
        for (uint k = 0; k < sz; k++) {
            complex<double> locsum = complex<double>(0,0);
            for (uint i = 0; i < sz; i++) {
                locsum += complex<double>(
                        cos(-2*M_PI*i*k/sz),
                        sin(-2*M_PI*i*k/sz)
                ) * complex<double>(input.at(i));
            }
            result.emplace_back(locsum);
        }
        return result;
    }

    vector<complex<double>> odpf(const vector<complex<double>> & input) {
        uint sz = input.size();
        vector<complex<double>> result;
        result.reserve(sz);
        for (uint i = 0; i < sz; i++) {
            complex<double> locsum = complex<double>(0,0);
            for (uint k = 0; k < sz; k++) {
                locsum += complex<double>(
                        cos(2*M_PI*i*k/sz),
                        sin(2*M_PI*i*k/sz)
                ) * input.at(k) / complex<double>(sz);
            }
            result.emplace_back(locsum);
        }
        return result;
    }

    vector<complex<double>> dph(const vector<complex<double>> & input) {
        uint sz = input.size();
        vector<complex<double>> result;
        result.reserve(sz);
        for (uint k = 0; k < sz; k++) {
            complex<double> locsum = complex<double>(0,0);
            for (uint i = 0; i < sz; i++) {
                locsum += complex<double>(
                        cos(2*M_PI*i*k/sz)+
                        sin(2*M_PI*i*k/sz)
                ) * complex<double>(input.at(i));
            }
            result.emplace_back(locsum);
        }
        return result;
    }

    vector<vector<complex<double>>> ddpf (const vector<vector<complex<double>>> & input) {
    // at first solve pdf at lines, then at columns
    vector<vector<complex<double>>> a;
    a.reserve(input.size());

    uint M = input.size(); // rows
    uint N = input[0].size(); // cols
    for (int k = 0; k < M; k++) {
        a.emplace_back(vector<complex<double>>(N));
        for (int l = 0; l < N; l++) {
            complex<double> locsum(0,0);
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    locsum += complex<double>(
                        cos(-2*M_PI*(double(i)*k/M + double(j)*l/N)),
                        sin(-2*M_PI*(double(i)*k/M + double(j)*l/N))
                    ) * complex<double>(input.at(i).at(j));
                }
            }
            a[k][l] = locsum;
        }
    }

return a;
}

vector<vector<complex<double>>> cascas (const vector<vector<complex<double>>> & input) {
    // at first solve pdf at lines, then at columns
    vector<vector<complex<double>>> a;
    a.reserve(input.size());

    uint M = input.size(); // rows
    uint N = input[0].size(); // cols
    for (int k = 0; k < M; k++) {
    a.emplace_back(vector<complex<double>>(N));
        for (int l = 0; l < N; l++) {
            complex<double> locsum(0,0);
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    locsum += complex<double>(
                            cos(2*M_PI*(double(i)*k/M)) +
                    sin(2*M_PI*(double(i)*k/M))
                    ) * complex<double> (
                            cos(2*M_PI*(double(j)*l/N)) +
                    sin(2*M_PI*(double(j)*l/N))
                    ) * complex<double>(input.at(i).at(j));
                }
            }
            a[k][l] = locsum;
        }
    }
    return a;
    }
}


#endif //UNTITLED5_METHODS_H
