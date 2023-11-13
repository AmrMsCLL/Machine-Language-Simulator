cmake_minimum_required(VERSION 3.24)
project(Machine_Language_Simulator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Machine_Language_Simulator
        Instructions.cpp
        Instructions.h
        Machine.cpp
        Machine.h
        main.cpp
        Memory.cpp
        Memory.h
        Register.cpp
        Register.h)
