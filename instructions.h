//
// Created by ahmad on 11/10/2023.
//

#ifndef VOLE_MACHINE_INSTRUCTIONS_H
#define VOLE_MACHINE_INSTRUCTIONS_H
#include "Memory.h"

class instructions {
private:
    Memory memory;
public:
    void Op_code (string convertAdd);
    void converter(string address);
    void store();
    void load();
    void move();
    void add();
    void jump();
    void halt();
};


#endif //VOLE_MACHINE_INSTRUCTIONS_H
