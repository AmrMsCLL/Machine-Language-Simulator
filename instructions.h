#ifndef VOLE_MACHINE_INSTRUCTIONS_H
#define VOLE_MACHINE_INSTRUCTIONS_H
#include <bits/stdc++.h>
#include "Memory.h"

class instructions {
private:
    Memory memory;
public:
    void Op_code (string convertAdd);
    void converter(string address);
    void store();
    void loadMemory();
    void loadPattern();
    void move();
    void add();
    void jump();
    void halt();
    friend int hexToint(string hexString);
    
};

#endif //VOLE_MACHINE_INSTRUCTIONS_H
