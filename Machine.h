#ifndef VOLE_MACHINE_MACHINE_H
#define VOLE_MACHINE_MACHINE_H

#include "Register.h"
#include "Memory.h"
#include "Instructions.h"
// #include "Instructions.cpp"

class Machine
{
private:
    // int proCounter;
    Register r;
    Memory m;
    Instructions I;
    string op;
    string regster;
    string value1;
    string value2;

public:
    Machine();
    string showStatus(int address);
    void loadfile(string filename);
    void execute();
    friend int hexToint(string hexString);
};

#endif // VOLE_MACHINE_MACHINE_H