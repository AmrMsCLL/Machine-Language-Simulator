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
    vector<std::string> strings(4);
    istringstream iss(address1);
    istringstream iss2(address2);
    string token;
    int i = 0;
    while (getline(iss, token, ' ') && i < 2)
    {
        strings[i] = token;
        i++;
    }
    while (getline(iss2, token, ' ') && i < 4)
    {
        strings[i] = token;
        i++;
    }
    
    op = strings[0];
    regster = strings[1];
    value1 = strings[2];
    value2 = strings[3];
    string thestring = strings[2];
    string string1 = ""; string1 += thestring[0];
    string string2 = ""; string2 += thestring[1];

    if (op == "1")                   // load reg r with pattern in memory xy
        loadFromemo(regster, value1);

    else if (op == "2")              // load reg r with pattern in xy
        load(regster, value1);

    else if (op == "3")              // stores pattern in
        if (string1 == "0" && string2 == "0")
            cout << /* "Screen << " << */ (Re.reg[hexToint(regster)]) << endl;
        else
            store(regster, value1);
    else if (op == "4")              // move from value 2 to value 1
        move(string1, string2);

    else if (op == "5")              // add value 1 and value 2 integer
        add(regster, string1, string2);

    else if (op == "B" || op == "b") // jump
        jump(regster, value1);

    else if (op == "C" || op == "c") // stop / halt
        halt();
}

void Instructions::load(string regster, string address)
{
    Re.reg[hexToint(regster)] = hexToint(address);
}

void Instructions::loadFromemo(string regster, string address)
{
    Re.reg[hexToint(regster)] = hexToint(instMemo.cells[hexToint(address)]);
}

void Instructions::store(string regster, string address)
{
    instMemo.cells[hexToint(address)] = intTohex(Re.reg[hexToint(regster)]);
}

void Instructions::move(string address, string address2)
{
    Re.reg[hexToint(address2)] = Re.reg[hexToint(address)];
}

void Instructions::add(string regster, string address, string address2)
{   
    Re.reg[hexToint(regster)] = (Re.reg[hexToint(address)] > pow(2, 8) - 2 ? Re.reg[hexToint(address)] - pow(2, 8) : Re.reg[hexToint(address)]) + (Re.reg[hexToint(address2)] > pow(2, 8) - 2 ? Re.reg[hexToint(address2)] - pow(2, 8) : Re.reg[hexToint(address2)]);
}

void Instructions::jump(string regster, string address)
{
    if (Re.reg[hexToint(regster)] == Re.reg[0])
        proCounter = hexToint(address);
}

void Instructions::halt()
{ 
    cout << "Program has been halted\n";
    exit(0);
}