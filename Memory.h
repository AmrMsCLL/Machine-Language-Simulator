#ifndef VOLE_MACHINE_MEMORY_H
#define VOLE_MACHINE_MEMORY_H
#include "Machine.h"
#include "Machine.cpp"
#include <bits/stdc++.h>
using namespace std;


class Memory {
private:
    string address;
public:
    vector <string> cells;
    void fetch(string address);
    Memory();
    friend int hexToint(string hexString);
};

#endif //VOLE_MACHINE_MEMORY_H
