//
// Created by ahmad on 11/10/2023.
//

#include "Machine.h"
#include <fstream>
#include <iostream>
using namespace std;

void Machine::loadfile(string filename) {
    string file = filename+".txt";
    ifstream in(file);
    string line;
    if (in.is_open()) {
        while (getline(in, line)) {
            m.cells.push_back(line);
        }
        in.close();
    } else {
        throw("ERROR!!!");
    }

}
