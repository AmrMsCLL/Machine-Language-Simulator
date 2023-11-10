#include "Memory.h"
#include "Machine.h"
#include "Machine.cpp"
#include <bits/stdc++.h>
using namespace std;

Memory::Memory(){
    address = '0';
};

void Memory::fetch(string address) {
    int add = hexToint(address);
    cout << cells[add];
}