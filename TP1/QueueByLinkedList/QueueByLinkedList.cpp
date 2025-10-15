#include "QueueByLinkedList.hpp"

void QueueByLinkedList::QueueInit() {
    front = nullptr;
    rear = nullptr;
}

void QueueByLinkedList::Push(int v) {
    TNode* newNode = new TNode(v);
    newNode->setLink(nullptr);
    if (front == nullptr) {
        front = newNode;
        rear = newNode;
    } else {
        rear->setLink(newNode);
        rear = newNode;
    }
}

int QueueByLinkedList::Pop() {
    if (front == nullptr) {
        cout << "Queue is Empty" << endl;
        return -99999;
    }
    int value = front->getValue();
    TNode* temp = front->getLink();
    delete front;
    front = temp;
    return value;
}

void QueueByLinkedList::display() {
    TNode* current = front;
    while (current != nullptr) {
        cout << current->getValue() << " ";
        current = current->getLink();
    }
    cout << endl << "------------------"<< endl;
}