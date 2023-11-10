#ifndef VOLE_MACHINE_MACHINE_H
#define VOLE_MACHINE_MACHINE_H
#include "Machine.h"
#include "Machine.cpp"
#include "Register.h"
#include "Memory.h"
#include <bits/stdc++.h>

class Machine {
private:
    int proCounter;
    Register r;
    Memory m;

public:
    friend void converter(Register re);
    void loadfile(string filename);
    void decode();
    void execute();
    friend int hexToint(string hexString);
};


#endif //VOLE_MACHINE_MACHINE_H
