//
// Created by alex on 24.11.2021.
//

#include "../include/Resolver.h"
#include "../include/Methods.h"
#include <iostream>

using std::cin;

void Resolver::resolve(Resolver::TASKS task) {

    if (task == DPF || task == DPH || task == ODPF) {
        tempI = generator.createVector();
        presenter.outputVector(tempI);
        cin >> waiter;
        tempR = task == DPF ? algorithms::dpf(tempI) :
                task == DPH? algorithms::dph(tempI) : algorithms::odpf(tempI);
        presenter.outputVector(tempR);
        cout << endl;
        tempR.clear();
        tempI.clear();
    } else if (task == DDPF || task == CASCAS) {
        tempID = generator.createDoubleVector();
        presenter.outputDoubleVector(tempID);
        cin >> waiter;
        tempRD = task == DDPF ? algorithms::ddpf(tempID) : algorithms::cascas(tempID);
        presenter.outputDoubleVector(tempRD);
        cout << endl;
        tempID.clear();
        tempRD.clear();
    }
}
