#include "QueueByArray.hpp"

void QueueByArray::QueueInit() {
    front = 1;
    rear = 0;
}

void QueueByArray::Push(int v) {
    if (rear == MAX) {
        cout << "Overflow" << endl;
        return;
    }
    array[++rear] = v;
}

int QueueByArray::Pop() {
    if (front > rear) {
        cout << "Queue is Empty" << endl;
        return -99999;
    }
    return array[front++];
}

void QueueByArray::display() {
    cout <<"----["<< front<<","<<rear<<"]-------"<< endl;

    for (int i = front; i <= rear; i++) {
        cout << array[i] << " ";
    }
    cout << endl <<"------------------"<< endl;
}