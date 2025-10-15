#include "StackByLinkedList.hpp"

//Commented lines here, are just to avoid errors of typemisatch, since we have changed the type of the value form int to TasNode.

void StackByLinkedList::stackInit() {
    top = nullptr;
}


void StackByLinkedList::push(int v) {
    TNode *newNode = new TNode(v);
    newNode->setLink(top);
    top = newNode;
}

int StackByLinkedList::pop() {
    if (top == nullptr) {
        cout << "Stack is empty" << endl;
        return -99999;
    }
    //int value = top->getValue();
    int value = 0;
    TNode *temp = top;
    top = top->getLink();
    delete temp;
    return value;
}

void StackByLinkedList::display() {
    TNode *current = top;
    // cout <<"----TOP : "<< top->getValue() <<"-------"<< endl;
    while (current != nullptr) {
        // cout << current->getValue() <<endl;
        current = current->getLink();
    }
    cout <<"------------------"<< endl;
}