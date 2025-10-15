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
void QueueByLinkedList::Push(TNode* node) {
    node->setLink(nullptr);
    if (front == nullptr) {
        front = node;
        rear = node;
    } else {
        rear->setLink(node);
        rear = node;
    }
}

TNode* QueueByLinkedList::Pop() {
    if (front == nullptr) {
        cout << "Queue is Empty" << endl;
        return nullptr;
    }
    TNode* value = front;
    TNode* temp = front->getLink();
    front = temp;
    return value;
}

void QueueByLinkedList::display() {
    TNode* current = front;
    while (current != nullptr) {
        cout << current->getTreeNode()->getValue() << " ";
        current = current->getLink();
    }
    cout << endl << "------------------"<< endl;
}

bool QueueByLinkedList::isEmpty() {
    return front == nullptr;
}
