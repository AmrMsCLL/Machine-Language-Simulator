#include "Machine.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

void Machine::loadfile(string filename) {

    ifstream in("test.txt");
    string line;
    int i = 0;
    if (in.is_open()) {
        while (getline(in , line)) {
            string cell1, cell2, cell3;
            for(int i =0; i < line.size(); i++){
                if(line[i] == '0' && line[i+1] == 'x')i++;

                else{

                      cell1 +=  line[i];
                    }
            }
            m.cells[i] = cell1;

            i++;
        }
        in.close();
    } else {
        throw("ERROR!!!");
    }

}

int hexToint(string hexString){
    int intValue = 0;

    for(int i = 0; i < hexString.size(); i++) {
        char hexChar = hexString[i];
        int hexValue;
        if(hexChar >= '0' && hexChar <= '9')
            hexValue = hexChar - '0';

        else if(hexChar >= 'A' && hexChar <= 'F')
            hexValue = hexChar - 'A' + 10;

        else if(hexChar >= 'a' && hexChar <= 'f')
            hexValue = hexChar - 'a' + 10;
        else {
            cout << "Err." << endl;
            return 1;
        }

        intValue += hexValue * pow(16, hexString.size() - i - 1);
    }
    return intValue;
}

float hexToFloat(string hexString) {
    unsigned int intValue = 0;

    for(int i = 0; i < hexString.size(); i++) {
        char hexChar = hexString[i];
        int hexValue;
        if(hexChar >= '0' && hexChar <= '9')
            hexValue = hexChar - '0';

        else if(hexChar >= 'A' && hexChar <= 'F')
            hexValue = hexChar - 'A' + 10;

        else if(hexChar >= 'a' && hexChar <= 'f')
            hexValue = hexChar - 'a' + 10;
        else {
            cout << "Err." << endl;
            return 1;
        }

        intValue += hexValue * pow(16, hexString.size() - i - 1);
    }
    float floatValue;
    memcpy(&floatValue, &intValue, sizeof(floatValue));
    return floatValue;
}

void Machine::Op_code(string convertAdd) {
    vector<std::string> strings(4);
    istringstream iss(convertAdd);
    string token;
    int i =0;
    while(getline(iss, token, ' ')) {
        strings[i] = token;
        i++;
    }
    op = strings[0];
    regster = strings[1];
    value1 = strings[2];
    value2 = strings[3];
//    cout<<op<<" "<<regster<<" "<<value1<<" "<<value2<<"\n"
    if(op == "1") // load reg r with pattern in memory xy
        loadFromemo(regster, value1);
    
    else if(op == "2") // load reg r with pattern in xy
        load(regster, value1);
    
    else if(op == "3") // stores pattern in 
        store(regster, value1);                         // doesnt work good 
    
    else if (op == "4") // move from value 2 to value 1
        move(value1, value2);
    
    else if (op == "5") // add value 1 and value 2 integer
        add(regster, value1, value2);
    
    else if (op == "6") // add value 1 and value 2 float
        addfloat(regster, value1, value2);              // doesnt work good
    
    else if (op == "B" || op == "b") // jump
        jump(regster, value1);
    
    else if (op == "C" || op == "c") // stop / halt
        halt();
}

void Machine::load(string regster, string address) {
    r.reg[hexToint(regster)] = hexToint(address);
}

void Machine::loadFromemo(string regster, string address) {
    r.reg[hexToint(regster)] = r.reg[hexToint(value1)];
}

void Machine::store(string regster, string address) {
    if(r.reg[hexToint(value1)] == 0 && r.reg[hexToint(value2)] == 0)
        cout << r.reg[hexToint(regster)] << endl;
    else
        m.cells[hexToint(address)] = r.reg[hexToint(regster)]; 
}

void Machine::move(string address, string address2) {
    r.reg[hexToint(address2)] = r.reg[hexToint(address)]; 
}

void Machine::add(string regster, string address, string address2) {
    r.reg[hexToint(regster)] = r.reg[hexToint(value1)] + r.reg[hexToint(value2)];
}

void Machine::addfloat(string regster, string address, string address2) {
    r.reg[hexToint(regster)] = hexToFloat(value1) + hexToFloat(value2);
} // doesnt work :)

void Machine::jump(string regster, string address) {

}

void Machine::halt() { // works but i dont know if it should work like that ?
    exit(0);
}

void Machine::run() {
    for(int i = 0; i < 16; i++)
        Op_code(m.cells[i]);
    for(int i = 0; i < 16; i++)
        cout<<m.cells[i]<<" ";
    cout<<"\n";
    for (int i = 0; i < 16; ++i) {
        cout<<r.reg[i]<<" ";
    }
}
