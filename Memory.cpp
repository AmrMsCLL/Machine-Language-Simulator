//
// Created by ahmad on 11/10/2023.
//

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

