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
    OO.run();
}
