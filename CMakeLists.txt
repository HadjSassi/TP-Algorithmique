cmake_minimum_required(VERSION 4.0)
project(Algorithmique)

set(CMAKE_CXX_STANDARD 20)

add_executable(Algorithmique main.cpp)
add_executable(TD1
        TP1/StackByArray/StackByArray.cpp
        TP1/StackByArray/StackByArray.hpp
        TP1/Node/TNode.cpp
        TP1/Node/TNode.hpp
        TP1/StackByLinkedList/StackByLinkedList.cpp
        TP1/StackByLinkedList/StackByLinkedList.hpp
        TP1/main.cpp
        TP1/QueueByArray/QueueByArray.cpp
        TP1/QueueByArray/QueueByArray.hpp
        TP1/QueueByCList/QueueByCList.cpp
        TP1/QueueByCList/QueueByCList.hpp)
