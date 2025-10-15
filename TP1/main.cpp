#include "StackByLinkedList/StackByLinkedList.hpp"

int main() {
    StackByLinkedList stack;
    stack.stackInit();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.display();
    stack.pop();
    stack.display();
    return 0;
}
