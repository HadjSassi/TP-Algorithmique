#include "TNode.hpp"

TNode::TNode(int value) {
    this->value = value;
    this->link = nullptr;
}

int TNode::getValue() const {
    return value;
}

TNode *TNode::getLink() const {
    return link;
}

void TNode::setLink(TNode *link) {
    this->link = link;
}

void TNode::setValue(int value) {
    this->value = value;
}
