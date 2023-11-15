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
    cout << " Welcome to our VOLE_Machine_Smulator =) \n"; // ✌(ツ)
    cout << " This Machine simulates 256 bytes of memory and a CPU that has 16 regisetrs.\n";
    cout << " Menu Of Options (choose number corresponding to option) : \n";
    int choice = 0;
    while (choice != 8)
    {

        // cout << "*- please select a number. ツ : ";
        cout << " 1- load a file.\n";
        cout << " 2- Get the value of a specific cell in the memory.\n";
        cout << " 3- Show the program counter.\n";
        cout << " 4- Show a specific part of the memory.\n";
        cout << " 5- Show the value of a register in the CPU.\n";
        cout << " 6- Show a specific part of the Registers.\n";
        cout << " 7- Execute the loaded file.\n";
        cout << " 8- Clear the memory.\n";
        cout << " 9- Shut down.\n";

        cin >> choice;
        if (choice == 1)
        {
            MAIN.loadfile();
        }
        else if (choice == 2)
        {
            string cell;
            cout << "Enter the number of memory cell that you want (in hexa!!!) : ";
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
            cout << "Enter the start point (in hexa!!!) : ";
            cin >> p1;
            cout << "Enter the end point (in hexa!!!) : ";
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
            cout << "Enter the start point (in hexa!!!) : ";
            cin >> p1;
            cout << "Enter the end point (in hexa!!!) : ";
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
            cout << "Memory Cleared! \n";
        }
        else if (choice == 9)
        {
            break;
        }
    }
    return 0;
}
