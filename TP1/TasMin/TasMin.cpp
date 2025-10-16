#include "TasMin.hpp"
#include "../QueueByLinkedList/QueueByLinkedList.hpp"
#include <iostream>

TasMin::TasMin() {
    this->sommet = nullptr;
    unverfiedNodes.QueueInit();
}

TasMin::~TasMin() {
    while (!isEmpty()) {
        extractMin();
    }
}

void TasMin::insert(int value) {
    TNode *newNode = new TNode(value);
    if (sommet == nullptr) {
        sommet = newNode;
        return;
    }

    unverfiedNodes.Push(newNode);
    insertInGoodPlace(newNode);
    fixUnverifiedNodes();
}

int TasMin::lengthTas() {
    int length = 0;
    QueueByLinkedList queue;
    queue.QueueInit();
    queue.Push(sommet);

    while (!queue.isEmpty()) {
        TNode *current = queue.Pop();
        length++;
        if (current->getTreeNode()->getLeft())
            queue.Push(current->getTreeNode()->getLeft()->getTNode());
        if (current->getTreeNode()->getRight())
            queue.Push(current->getTreeNode()->getRight()->getTNode());
    }

    return length;
}

void TasMin::insertInGoodPlace(TNode *node) {
    QueueByLinkedList queue;
    queue.QueueInit();
    queue.Push(sommet);

    while (!queue.isEmpty()) {
        TNode *current = queue.Pop();
        if (!current->getTreeNode()->getLeft()) {
            current->getTreeNode()->setLeft(node->getTreeNode());
            node->getTreeNode()->setParent(current->getTreeNode());
            return;
        } else queue.Push(current->getTreeNode()->getLeft()->getTNode());

        if (!current->getTreeNode()->getRight()) {
            current->getTreeNode()->setRight(node->getTreeNode());
            node->getTreeNode()->setParent(current->getTreeNode());
            return;
        } else queue.Push(current->getTreeNode()->getRight()->getTNode());
    }
}

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

TNode TasMin::getMin() {
    return *sommet;
}

bool TasMin::isEmpty() {
    return sommet == nullptr;
}

int TasMin::extractMin() {
    if (isEmpty()) {
        std::cout << "Heap is empty." << std::endl;
        return -1;
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

void TasMin::displayTreeAscii(TNode *node, const std::string &prefix, bool isLeft) {
    if (!node) return;

    std::cout << prefix;
    std::cout << (isLeft ? "├── " : "└── ");
    std::cout << node->getTreeNode()->getValue() << std::endl;

    std::string childPrefix = prefix + (isLeft ? "│   " : "    ");
    if (node->getTreeNode()->getLeft() || node->getTreeNode()->getRight()) {
        if (node->getTreeNode()->getLeft())
            displayTreeAscii(node->getTreeNode()->getLeft()->getTNode(), childPrefix, true);
        if (node->getTreeNode()->getRight())
            displayTreeAscii(node->getTreeNode()->getRight()->getTNode(), childPrefix, false);
    }
}

void TasMin::display() {
    if (!sommet) {
        std::cout << "Heap is empty." << std::endl;
        return;
    }
    displayTreeAscii(sommet, "", false);
}
