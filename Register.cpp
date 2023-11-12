#include "Register.h"

Register ::Register(){
    for(int i = 0 ; i < 16; i++){
        reg[i] = 0;
    }
}

int Register::getBitpattern(int r){
    return reg[r];
}