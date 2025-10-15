#include <iostream>
#include "../Node/TNode.hpp"
using namespace std;

class QueueByLinkedList {

public:
    void QueueInit();
    void Push(int v);
    int Pop();
    void display();
private:
    TNode* front;
    TNode* rear;
};