#include "Machine.h"
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

void Machine::loadfile(string filename) {
//    string file = filename+".txt";
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
//            cout<<cell1<<"\n";
cout<<line;
            m.cells[i] = line;

            i++;
        }
        in.close();
    } else {
        throw("ERROR!!!");
    }

}


string hexToint(string hexString){
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
            return "1";
        }

        intValue += hexValue * pow(16, hexString.size() - i - 1);
    }
    cout << "int = : ";//<< intValue << endl;
    return to_string(intValue);
}
