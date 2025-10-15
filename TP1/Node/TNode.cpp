#include "TNode.hpp"

TNode::TNode(int value){
    this->treeNode = new TasNode();
    this->treeNode->setValue(value);
    treeNode->setTNode(this);
    this->link = nullptr;
}

TNode::TNode() : treeNode(), link(nullptr) {
    treeNode->setTNode(this);
}

TasNode* TNode::getTreeNode() const {
    return treeNode;
}

TNode *TNode::getLink() const {
    return link;
}

void TNode::setLink(TNode *link) {
    this->link = link;
}

void TNode::setTreeNode(TasNode value) {
    this->treeNode = &value;
}
