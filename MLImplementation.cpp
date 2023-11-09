// File: A2_Task3_A_20220032_20220450_MLSimulator.cpp
// Purpose: a machine language simulator
// Authors: Ahmed Mohammed Saber, Amr Mohammed El-Sheriey.
// Section: S4.
// ID's: 20220032 - 20220450 respectively.
// TA: Belal Tarek Hassan.
// Date: 9th of November 2023.
//----------------------------
#include <bits/stdc++.h>
#include <iostream>
#include "MLHeader.h"
using namespace std;

void add1() {
    cout << 1+1;
}

void MLSimulator::rndm() {
    reg[14] = 5;
    cout << reg[14];
}