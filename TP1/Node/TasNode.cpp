#include "TasNode.hpp"

TasNode::TasNode() {
    this->value = 0;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->tnode = nullptr;
}


int TasNode::getValue() const {
    return value;
}

TasNode *TasNode::getParent() const {
    return parent;
}

void TasNode::setParent(TasNode *parent) {
    this->parent = parent;
}

TasNode *TasNode::getRight() const {
    return right;
}

void TasNode::setRight(TasNode *right) {
    this->right = right;
}

TasNode *TasNode::getLeft() const {
    return left;
}

void TasNode::setLeft(TasNode *left) {
    this->left = left;
}

void TasNode::setValue(int value) {
    this->value = value;
}

void TasNode::setTNode(TNode *tnode) {
    this->tnode = tnode;
}

TNode * TasNode::getTNode() const {
    return tnode;
}
