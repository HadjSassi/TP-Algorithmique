#include "QueueByCList.hpp"

void QueueByCList::QueueInit() {
    front = 0;
    rear = MAX-1;
    n = 0;
}

void QueueByCList::Push(int v) {
    if (n == MAX) {
        cout << "Queue is Full" << endl;
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = v;
    n++;
}

int QueueByCList::Pop() {
    if (n == 0) {
        cout << "Queue is Empty" << endl;
        return -99999;
    }
    int value = queue[front];
    front = (front + 1) % MAX;
    n--;
    return value;
}

void QueueByCList::display() {
    cout <<"----["<< front<<","<< n<<","<<rear<<"]-------"<< endl;

    for (int i = 0; i < n; i++) {
        cout << queue[(front + i) % MAX] << " ";
    }
    cout << endl <<"------------------"<< endl;
}