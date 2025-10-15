#include "TasMax.hpp"

#include "../QueueByLinkedList/QueueByLinkedList.hpp"

TasMax::TasMax() {
    this->sommet = nullptr;
    unverfiedNodes.QueueInit();
}

TasMax::~TasMax() {
    while (!isEmpty()) {
        extractMax();
    }
}

void TasMax::insert(int value) {
    TNode *newNode = new TNode(value);
    if (sommet == nullptr) {
        sommet = newNode;
        return;
    }
    unverfiedNodes.Push(newNode);
    insertInGoodPlace(newNode);
    fixUnverifiedNodes();
}

int TasMax::lengthTas() {
    int length = 0;
    QueueByLinkedList queue;
    queue.QueueInit();
    queue.Push(sommet);
    TNode *current = nullptr;
    while (!queue.isEmpty()) {
        current = queue.Pop();
        length++;
        if (current->getTreeNode()->getLeft()) {
            queue.Push(current->getTreeNode()->getLeft()->getTNode());
            if (current->getTreeNode()->getRight())
                queue.Push(current->getTreeNode()->getRight()->getTNode());
        }
    }
    return length;
}

void TasMax::insertInGoodPlace(TNode *node) {
    QueueByLinkedList queue;
    queue.QueueInit();
    queue.Push(sommet);
    while (!queue.isEmpty()) {
        TNode *current = queue.Pop();
        if (!current->getTreeNode()->getLeft()) {
            current->getTreeNode()->setLeft(node->getTreeNode());
            node->getTreeNode()->setParent(current->getTreeNode());
            return;
        } else {
            queue.Push(current->getTreeNode()->getLeft()->getTNode());
        }
        if (!current->getTreeNode()->getRight()) {
            current->getTreeNode()->setRight(node->getTreeNode());
            node->getTreeNode()->setParent(current->getTreeNode());
            return;
        } else {
            queue.Push(current->getTreeNode()->getRight()->getTNode());
        }
    }
}

void TasMax::fixUnverifiedNodes() {
    while (!unverfiedNodes.isEmpty()) {
        TNode *node = unverfiedNodes.Pop();
        if (node->getTreeNode()->getParent() && node->getTreeNode()->getValue() > node->getTreeNode()->getParent()->getValue()) {
            int temp = node->getTreeNode()->getValue();
            node->getTreeNode()->setValue(node->getTreeNode()->getParent()->getValue());
            node->getTreeNode()->getParent()->setValue(temp);
            unverfiedNodes.Push(node->getTreeNode()->getParent()->getTNode());
            continue;
        }
        if (node->getTreeNode()->getLeft() && node->getTreeNode()->getValue() < node->getTreeNode()->getLeft()->getValue()) {
            int temp = node->getTreeNode()->getValue();
            node->getTreeNode()->setValue(node->getTreeNode()->getLeft()->getValue());
            node->getTreeNode()->getLeft()->setValue(temp);
            unverfiedNodes.Push(node->getTreeNode()->getLeft()->getTNode());
            continue;
        }
        if (node->getTreeNode()->getRight() && node->getTreeNode()->getValue() < node->getTreeNode()->getRight()->getValue()) {
            int temp = node->getTreeNode()->getValue();
            node->getTreeNode()->setValue(node->getTreeNode()->getRight()->getValue());
            node->getTreeNode()->getRight()->setValue(temp);
            unverfiedNodes.Push(node->getTreeNode()->getRight()->getTNode());
        }
    }
}

TNode TasMax::getMax() {
    return *sommet;
}

bool TasMax::isEmpty() {
    return sommet == nullptr;
}

int TasMax::extractMax() {
}

void TasMax::displayTreeAscii(TNode *node, const std::string &prefix, bool isLeft) {
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

void TasMax::display() {
    if (!sommet) {
        std::cout << "Heap is empty." << std::endl;
        return;
    }
    displayTreeAscii(sommet, "", false);
}
