#ifndef VOLE_MACHINE_INSTRUCTIONS_H
#define VOLE_MACHINE_INSTRUCTIONS_H
#include "Memory.h"
#include "Register.h"
#include <iostream>
using namespace std;

class Instructions
{
protected:
    string op;
    string regster;
    string value1;
    string value2;

public:
    int proCounter;
    Register Re;
    Memory instMemo;
    Instructions();
    
    void decode(string address1, string address2);
    void load(string regster, string value, string value2);
    void loadFromemo(string regster, string address, string value2);
    void store(string regster, string address, string value2);
    void move(string address, string address2);
    void add(string regster, string address, string address2);
    void jump(string regster, string address, string value2);
    void halt();
};

#endif
