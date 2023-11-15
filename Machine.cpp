// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "Machine.h"
// #include "Instructions.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

Machine ::Machine()
{
    I.proCounter = 0;
    I.instMemo = m;
    I.Re = r;
}



void Machine::loadfile()
{
    string input;
    cout << "Enter Filename :";
    cin >> input;

    if(input.find(".txt") == string::npos) // checks if the input already has the .txt extension
        input += ".txt"; // adds the .txt extension if not found in input
    ifstream in(input); //(input);
    string line;
    int j = 0;

    if (in.is_open())
    {
        while (getline(in, line))
        {
            string cell1, cell2, cell3;
            int cnt = 0;
            // cout<<line<<" | ";
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] == '0' && line[i+1] == 'x')
                    i++;

                else
                {
                    if (cnt < 3)
                        cell1 += line[i];

                    else
                        cell2 += line[i];
                    cnt++;
                }
            }
            for(int i = 0 ; i < cell1.size(); i++){
                if(cell1[i] == ' ')cell1.erase(i, 1);
            }
            for(int i = 0 ; i < cell2.size(); i++){
                if(cell2[i] == ' ')cell2.erase(i, 1);
            }


            I.instMemo.cells[j] = cell1;
            I.instMemo.cells[j + 1] = cell2;
            j += 2;
        

    }
            in.close();

    }
        else
    {
        throw("ERROR!!!");
    }
}

int hexToint(string hexString)
{
    int intValue = 0;
    while (hexString.front() == ' ')
        hexString.erase(0, 1);
    while (hexString.back() == ' ')
        hexString.pop_back();
    for (int i = 0; i < hexString.size(); i++)
    {
        char hexChar = hexString[i];
        int hexValue;
        if (hexChar == ' ')
            continue;
        if (hexChar >= '0' && hexChar <= '9')
            hexValue = hexChar - '0';
        else if (hexChar >= 'A' && hexChar <= 'F')
            hexValue = hexChar - 'A' + 10;
        else if (hexChar >= 'a' && hexChar <= 'f')
            hexValue = hexChar - 'a' + 10;
        else
        {
            cout << "Err." << endl;
            exit(0);
        }
        intValue += hexValue * pow(16, hexString.size() - i - 1);
    }
    return intValue;
}

string intTohex(int intNum)
{
    string hexStr = "0123456789ABCDEF";
    string result = "";
    while (intNum != 0)
    {
        result = hexStr[intNum % 16] + result;
        intNum /= 16;
    }
    if(result == "")result= "0";
    return result;
}

void Machine::execute()
{
    I.proCounter = -2;
    while (I.proCounter < 32)
    {
        I.proCounter += 2;
        I.decode(I.instMemo.cells[I.proCounter], I.instMemo.cells[I.proCounter + 1]);
        if(I.instMemo.cells[I.proCounter] == "C0" && I.instMemo.cells[I.proCounter+1] == "00"){
            I.proCounter++;
            break;
        }
    }
    cout << "\n";

}

string Machine::showMemorycell(string address){
    return I.instMemo.cells[hexToint(address)];
}

string Machine::getroCounter(){
    return intTohex(I.proCounter);
}

void Machine::showMemory(string p1, string p2){
    cout << "Memory    ----> \n";
    for (int i = hexToint(p1); i <= hexToint(p2); i++){
        cout <<"cell "<<(intTohex(i).size() == 1 ? "0"+intTohex(i) : intTohex(i))<<" |0x"<< I.instMemo.cells[i] << "|\n";
    }
}

void Machine::showRegisters(string p1, string p2){
    cout << "Registers ----> \n";
    for (int i = hexToint(p1); i <= hexToint(p2); i++)
    {
        cout <<"R"<<" "<<i<< " |0x" <<I.Re.reg[i] << "|\n";
    }
}

void Machine::showRegister(string r){
    cout<<I.Re.reg[hexToint(r)]<<"\n";
}

void Machine::clear(){
    for(int i = 0; i < 256; i++)
        I.instMemo.cells[i] = '0';
}