#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Machine.h"
#include "Machine.cpp"
#include "Register.cpp"
#include "Memory.cpp"

int main() {
    Machine m;
    m.loadfile("asda");
    m.run();
}