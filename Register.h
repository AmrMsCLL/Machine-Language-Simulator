#ifndef VOLE_MACHINE_REGISTER_H
#define VOLE_MACHINE_REGISTER_H

#include <iostream>
using namespace std;

class Register
{
private:
    string bitpattern;

public:
    int getBitpattern(int r);
    int reg[16];
    Register();
};

#endif // VOLE_MACHINE_REGISTER_H