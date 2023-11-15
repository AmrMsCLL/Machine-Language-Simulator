// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "Memory.h"
#include <iostream>
#include <fstream>

using namespace std;

Memory ::Memory()
{
    address = '0';
    for(int i =0 ; i < 256; i++){
        cells[i] = '0';
    }
};

string Memory::fetch(int address)
{
    return cells[address];
}