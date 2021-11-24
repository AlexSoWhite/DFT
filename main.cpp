#include <iostream>
#include "include/Resolver.h"

using namespace std;

vector<string> menu = {
        "1. dpf",
        "2. ddpf",
        "3. dph",
        "4. cascas",
        "5. odpf"
};

int main() {
    srand(time(nullptr));

    bool run = true;

    Resolver resolver = Resolver();

    while (run) {
        for (const auto& a : menu) {
            cout << a << endl;
        }
        int ch;
        cin >> ch;
        char c;
        switch (ch) {
            case 1:
                resolver.resolve(Resolver::DPF);
                break;
            case 2:
                resolver.resolve(Resolver::DDPF);
                break;
            case 3:
                resolver.resolve(Resolver::DPH);
                break;
            case 4:
                resolver.resolve(Resolver::CASCAS);
                break;
            case 5:
                resolver.resolve(Resolver::ODPF);
                break;
            default:
                run = false;
                break;
        }
    }
    return 0;
}
