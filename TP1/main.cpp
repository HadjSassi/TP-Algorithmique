#include "QueueByArray/QueueByArray.hpp"

int main() {
    QueueByArray queue;
    queue.QueueInit();
    queue.display();
    queue.Push(1);
    queue.display();
    queue.Push(2);
    queue.display();
    queue.Push(3);
    queue.display();
    queue.Pop();
    queue.display();
    queue.Pop();
    queue.display();
    queue.Pop();
    queue.display();
    return 0;
}
