//
// Created by ahmad on 11/10/2023.
//

#ifndef VOLE_MACHINE_MACHINE_H
#define VOLE_MACHINE_MACHINE_H
#include "Register.h"
#include "Memory.h"


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
    friend string hexToint(string hexString);
};


#endif //VOLE_MACHINE_MACHINE_H
