#include "QueueByCList/QueueByCList.hpp"

int main() {
    QueueByCList queue;
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
