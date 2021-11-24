//
// Created by alex on 24.11.2021.
//

#ifndef UNTITLED5_RESOLVER_H
#define UNTITLED5_RESOLVER_H


#include "../include/Generator.h"
#include "../include/Presenter.h"

class Resolver {
    Generator generator;
    Presenter presenter;
    vector<complex<double>> tempI;
    vector<vector<complex<double>>> tempID;
    vector<complex<double>> tempR;
    vector<vector<complex<double>>> tempRD;
    char waiter;
public:
    Resolver() {
        generator = Generator();
        presenter = Presenter();
    }
    enum TASKS {
        DPF,
        DPH,
        DDPF,
        CASCAS,
        ODPF
    };
    void resolve(TASKS);
};


#endif //UNTITLED5_RESOLVER_H
