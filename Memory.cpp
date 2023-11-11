#include "Memory.h"
#include <iostream>
#include <fstream>
using namespace std;

Memory ::Memory(){
    address = '0';
};

string Memory::fetch(int address) {
    return cells[address];
}

