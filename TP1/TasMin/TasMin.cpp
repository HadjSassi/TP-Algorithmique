#include "TasMin.hpp"

#include "../QueueByLinkedList/QueueByLinkedList.hpp"

void TasMin::fixUnverifiedNodes() {
    while (!unverfiedNodes.isEmpty()) {
        TNode *node = unverfiedNodes.Pop();
        TasNode *t = node->getTreeNode();

        bool changed = false;

        TasNode *parent = t->getParent();
        if (parent && t->getValue() < parent->getValue()) {
            int temp = t->getValue();
            t->setValue(parent->getValue());
            parent->setValue(temp);

            unverfiedNodes.Push(parent->getTNode());
            changed = true;
        }

        TasNode *smallestChild = nullptr;
        if (t->getLeft() && (!smallestChild ))
            smallestChild = t->getLeft();
        if (t->getRight() && (!smallestChild || t->getRight()->getValue() < smallestChild->getValue()))
            smallestChild = t->getRight();

        if (smallestChild && smallestChild->getValue() < t->getValue()) {
            int temp = t->getValue();
            t->setValue(smallestChild->getValue());
            smallestChild->setValue(temp);

            unverfiedNodes.Push(smallestChild->getTNode());
            changed = true;
        }

        if (!changed)
            continue;
    }
}


int TasMin::extractMin() {
    if (!sommet) {
        cout << "Heap is empty." << endl;
        return -1; // or throw an exception
    }

    int minValue = sommet->getTreeNode()->getValue();

    if (!sommet->getTreeNode()->getLeft() && !sommet->getTreeNode()->getRight()) {
        delete sommet;
        sommet = nullptr;
        return minValue;
    }

    QueueByLinkedList queue;
    queue.QueueInit();
    queue.Push(sommet);
    TNode *lastNode = nullptr;
    while (!queue.isEmpty()) {
        lastNode = queue.Pop();
        if (lastNode->getTreeNode()->getLeft())
            queue.Push(lastNode->getTreeNode()->getLeft()->getTNode());
        if (lastNode->getTreeNode()->getRight())
            queue.Push(lastNode->getTreeNode()->getRight()->getTNode());
    }

    sommet->getTreeNode()->setValue(lastNode->getTreeNode()->getValue());

    TasNode *parent = lastNode->getTreeNode()->getParent();
    if (parent) {
        if (parent->getLeft() == lastNode->getTreeNode())
            parent->setLeft(nullptr);
        else if (parent->getRight() == lastNode->getTreeNode())
            parent->setRight(nullptr);
    }
    delete lastNode;

    unverfiedNodes.QueueInit();
    unverfiedNodes.Push(sommet);
    fixUnverifiedNodes();

    return minValue;
}