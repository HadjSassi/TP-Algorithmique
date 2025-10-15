#include "StackByArray.hpp"

#include <iostream>
#include <ostream>

void StackByArray::stackInit() {
    top = 0;
}

void StackByArray::push(int v) {
    if (top == MAX) {
        cout << "Stack is full" << endl;
        return;
    }
    stack[top++] = v;
}

int StackByArray::pop() {
    if (top == 0) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return stack[top--];
}

void StackByArray::display() {
    cout <<"----TOP : "<< top <<"-------"<< endl;

    for (int i = top-1; i >= 0; i--) {
        cout << stack[i] << endl;
    }
    cout <<"------------------"<< endl;
}