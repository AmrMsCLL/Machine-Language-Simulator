// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Machine.h"
#include "Register.cpp"
#include "Memory.cpp"
#include "Instructions.cpp"

using namespace std;

int main()
{
    Machine MAIN;
    cout << "Welcome in our VOLE_machine :)\n";
    cout << "this Machine has memory of 256 bytes and CPU that has 16 regisetrs\n";
    cout << "This is our menu \n";
    int choice = 0;
    while (choice != 8)
    {

        cout << "\t please select a number :) \n";
        cout << "1- \t loading file\n";
        cout << "2- \t get a value of a cell in the memory\n";
        cout << "3- \t show the program counter\n";
        cout << "4- \t show a specific part of the memory\n";
        cout << "5- \t show a value of a register in the CPU\n";
        cout << "6- \t show a specific part of the Registers\n";
        cout << "7- \t execute the loaded file\n";
        cout << "8- \t Clear the memory\n";
        cout << "9- \t shut down\n";

        cin >> choice;
        if (choice == 1)
        {
            MAIN.loadfile();
        }
        else if (choice == 2)
        {
            string cell;
            cout << "Enter the number of memory cell that you want (in hexa!!!) :";
            cin >> cell;
            MAIN.showMemorycell(cell);
        }
        else if (choice == 3)
        {
            cout << MAIN.getroCounter() << "\n";
        }
        else if (choice == 4)
        {
            string p1, p2;
            cout << "Enter the start point (in hexa!!!)\n";
            cin >> p1;
            cout << "Enter the end point (in hexa!!!)\n";
            cin >> p2;
            MAIN.showMemory(p1, p2);
        }
        else if (choice == 5)
        {
            string R;
            cout << "Enter the number of the register that you want (in hexa!!!) :";
            cin >> R;
            MAIN.showRegister(R);
        }
        else if (choice == 6)
        {
            string p1, p2;
            cout << "Enter the start point (in hexa!!!)\n";
            cin >> p1;
            cout << "Enter the end point (in hexa!!!)\n";
            cin >> p2;
            MAIN.showRegisters(p1, p2);
        }
        else if (choice == 7)
        {
            MAIN.execute();
        }
        else if (choice == 8)
        {
            MAIN.clear();
        }
        else if (choice == 9)
        {
            break;
        }
    }
    return 0;
}
