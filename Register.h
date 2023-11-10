#ifndef VOLE_MACHINE_REGISTER_H
#define VOLE_MACHINE_REGISTER_H
#include <bits/stdc++.h>
#include "Machine.h"
#include "Machine.cpp"
using namespace std;


class Register {
private:
    string bitPattern;
    int ReNumber;
public:
    friend int hexToint(string hexString);

};


#endif //VOLE_MACHINE_REGISTER_H
