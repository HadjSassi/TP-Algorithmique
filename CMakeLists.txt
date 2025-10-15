cmake_minimum_required(VERSION 4.0)
project(Algorithmique)

set(CMAKE_CXX_STANDARD 20)

add_executable(Algorithmique main.cpp)
add_executable(TD1
        TP1/StackByArray/StackByArray.cpp
        TP1/StackByArray/StackByArray.hpp
        TP1/main.cpp)
