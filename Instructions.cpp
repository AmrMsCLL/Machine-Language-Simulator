// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "Instructions.h"
#include "Machine.cpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

Instructions ::Instructions()
{
    proCounter = 0;
}

void Instructions::decode(string address1, string address2)
{
    op = address1[0];
    regster = address1[1];
    value1 = address2[0];
    value2 = address2[1];
    // cout<<op<<"|"<<regster<<"|"<<value1<<"|"<<value2<<"|"<<"\n";
    if (op == "1")                   // load reg r with pattern in memory xy
        loadFromemo(regster, value1, value2);

    else if (op == "2")              // load reg r with pattern in xy
        load(regster, value1, value2);

    else if (op == "3")              // stores pattern in
        if (value1 == "0" && value2 == "0")
            cout << /* "Screen << " << */ (Re.reg[hexToint(regster)]) << endl;
        else
            store(regster, value1, value2);
    else if (op == "4")              // move from value 2 to value 1
        move(value1, value2);

    else if (op == "5")              // add value 1 and value 2 integer
        add(regster, value1, value2);

    else if (op == "B" || op == "b") // jump
        jump(regster, value1, value2);

    else if (op == "C" || op == "c") // stop / halt
        halt();
}

void Instructions::load(string regster, string address, string value2)
{
    Re.reg[hexToint(regster)] = hexToint(address+value2);
}

void Instructions::loadFromemo(string regster, string address, string value2)
{
    Re.reg[hexToint(regster)] = hexToint(instMemo.cells[hexToint(address+value2)]);
}

void Instructions::store(string regster, string address, string value2)
{
    instMemo.cells[hexToint(address+value2)] = intTohex(Re.reg[hexToint(regster)]);
}

void Instructions::move(string address, string address2)
{
    Re.reg[hexToint(address2)] = Re.reg[hexToint(address)];
}

void Instructions::add(string regster, string address, string address2)
{   
    Re.reg[hexToint(regster)] = (Re.reg[hexToint(address)] > pow(2, 8) - 2 ? Re.reg[hexToint(address)] - pow(2, 8) : Re.reg[hexToint(address)]) + (Re.reg[hexToint(address2)] > pow(2, 8) - 2 ? Re.reg[hexToint(address2)] - pow(2, 8) : Re.reg[hexToint(address2)]);
}

void Instructions::jump(string regster, string address, string value2)
{
    if (Re.reg[hexToint(regster)] == Re.reg[0])
        proCounter = hexToint(address+value2);
}

void Instructions::halt()
{ 
    cout << "Program has been halted\n";
    // exit(0);
}