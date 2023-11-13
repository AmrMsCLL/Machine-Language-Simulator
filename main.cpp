// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Machine.h"
// #include "Machine.cpp"
#include "Register.cpp"
#include "Memory.cpp"
#include "Instructions.cpp"

int main() {
    Machine OO;
    OO.loadfile("asda");
    OO.execute();
}
