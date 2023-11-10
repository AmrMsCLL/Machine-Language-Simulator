#include "Machine.h"
#include <bits/stdc++.h>
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
    cout << "int = : ";//<< intValue << endl;
    return intValue;
}