//
// Created by ahmad on 11/10/2023.
//

#ifndef VOLE_MACHINE_MEMORY_H
#define VOLE_MACHINE_MEMORY_H
#include <iostream>
#include <vector>
using namespace std;


class Memory {
private:
    string address;
public:
    vector <string> cells;
    void fetch(string address);
    Memory();
};


#endif //VOLE_MACHINE_MEMORY_H
