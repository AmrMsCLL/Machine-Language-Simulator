#ifndef VOLE_MACHINE_MACHINE_H
#define VOLE_MACHINE_MACHINE_H

#include "Register.h"
#include "Memory.h"
#include "Instructions.h"

class Machine
{
private:
    Register r;
    Memory m;
    Instructions I;
    string op;
    string regster;
    string value1;
    string value2;

public:
    Machine();
    void showMemory(string p1, string p2);
    void showRegisters(string p1, string p2);
    void showRegister(string r);
    string showMemorycell(string address);
    string getroCounter();
    void clear();
    void loadfile();
    void execute();
    friend int hexToint(string hexString);
    friend string intTohex(int intNum);
};

#endif