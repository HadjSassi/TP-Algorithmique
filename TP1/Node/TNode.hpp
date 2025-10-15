#pragma once
#include "TasNode.hpp"
class TNode {
public:
    TNode();

    TNode(int value);

    TasNode* getTreeNode() const;

    TNode *getLink() const;

    void setLink(TNode *link);

    void setTreeNode(TasNode value);

private:
    TasNode *treeNode;
    TNode *link;
};
