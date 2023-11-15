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

string Machine::showStatus(int address)
{
    return I.instMemo.cells[address];
}

void Machine::loadfile(string filename)
{
    // string input;
    // cout << "Enter Filename :";
    // cin >> input;

    // if(intput.find(".txt") == string::npos) // checks if the input already has the .txt extension
    //     input += ".txt"; // adds the .txt extension if not found in input
    ifstream in("test.txt"); //(input);
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
    }
    cout << "Memory    ----> \n";
    for (int i = 0; i < 32; i++)
        cout <<char(65+(i/10))<<" "<<i%10<<" |0x"<< I.instMemo.cells[i] << "|\n";
    cout << "\n";
    cout << "Registers ----> \n";
    for (int i = 0; i < 16; i++)
    {
        cout <<"R"<<" "<<i<< " |0x" <<I.Re.reg[i] << "|\n";
    }
}