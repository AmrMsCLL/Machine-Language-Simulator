#include "Machine.h"
// #include "Instructions.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

Machine :: Machine(){
    I.proCounter = 0;
    I.instMemo = m;
    I.Re = r;
}



void Machine::loadfile(string filename) {
    ifstream in("test.txt");
    string line;
    int j = 0;

    if (in.is_open()) {
        while (getline(in , line)) {
            string cell1, cell2, cell3;
                int cnt = 0;
            for(int i =0; i < line.size(); i++){
                if(line[i] == '0' && line[i+1] == 'x')i++;

                else{
                    if(cnt < 3)
                      cell1 +=  line[i];
                
                    else
                        cell2 += line[i];
                      cnt++;
                    }
            }
            if(cell1.front() == ' ')
                cell1.erase(0, 1);
            if(cell2.front() == ' ')
                cell2.erase(0, 1);
            // cout<<cell1<<"|"<<cell2<<"\n";
            I.instMemo.cells[j] = cell1;
            I.instMemo.cells[j+1] = cell2;

            j+=2;
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

void Machine::run() {
    I.proCounter = -2;
    while(I.proCounter < 16){
        I.proCounter+=2;
        I.Op_code(I.instMemo.cells[I.proCounter],I.instMemo.cells[I.proCounter+1] );


    }
     for(int i = 0; i < 16; i++)
        cout<<I.instMemo.cells[i]<<" | ";
    cout<<"\n";
    for (int i = 0; i < 16; ++i) {
        cout << I.Re.reg[i] << " ";
    }
}