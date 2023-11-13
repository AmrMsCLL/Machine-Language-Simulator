// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "Register.h"

Register ::Register()
{
    for (int i = 0; i < 16; i++)
    {
        reg[i] = 0;
    }
}

int Register::getBitpattern(int r)
{
    return reg[r];
}