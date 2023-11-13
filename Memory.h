#ifndef VOLE_MACHINE_MEMORY_H
#define VOLE_MACHINE_MEMORY_H

#include <iostream>
#include <vector>

using namespace std;

class Memory
{
private:
    string address;

public:
    string cells[256];
    string fetch(int address);
    Memory();
};

#endif // VOLE_MACHINE_MEMORY_H