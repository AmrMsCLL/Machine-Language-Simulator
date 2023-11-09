// File: A2_Task3_A_20220032_20220450_MLSimulator.cpp
// Purpose: a machine language simulator
// Authors: Ahmed Mohammed Saber, Amr Mohammed El-Sheriey.
// Section: S4.
// ID's: 20220032 - 20220450 respectively.
// TA: Belal Tarek Hassan.
// Date: 9th of November 2023.
//----------------------------
#ifndef DESKTOP_OOP_P2
#define DESKTOP_OOP_P2
#include <bits/stdc++.h>

using namespace std;

class MLSimulator {
protected:
    string input;
    vector<int> reg = vector<int>(16);
    vector<int> mem = vector<int>(256);

    void intTohex();
    void hexToint();
    void intTobin();
    void binToint();

public:

    void rndm();
    void loadCell();
    void loadPattern();
    void storeCell();
    void writeToScreen();
    void movePattern();
    void addTwoComplement();
    void addFloatingPoint();
    void jump();
    void halt();

};  

#endif 