#pragma once
#include <iostream>
#include "../Node/TNode.hpp"
using namespace std;

class QueueByLinkedList {

public:
    void QueueInit();
    void Push(int v);
    void Push(TNode* node);
    TNode* Pop();
    void display();
    bool isEmpty();
private:
    TNode* front;
    TNode* rear;
};