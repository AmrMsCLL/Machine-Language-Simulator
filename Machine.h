#ifndef VOLE_MACHINE_MACHINE_H
#define VOLE_MACHINE_MACHINE_H
#include "Register.h"
#include "Memory.h"

class Machine {
private:
    int proCounter;
    Register r;
    Memory m;
    string op;
    string regster;
    string value1;
    string value2;

public:
    void loadfile(string filename);
    void run();
    void decode();
    void execute();
    friend int hexToint(string hexString);

    void Op_code (string convertAdd);
    void converter(string address);
    void store(string address);
    void loadFromemo(string regster, string address);
    void addfloat(string address);
    void load(string regster, string value);
    void move(string address);
    void add(string address);
    void jump(string address);
    void halt(string address);
};


#endif //VOLE_MACHINE_MACHINE_H
