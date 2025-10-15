#pragma once
class TNode;

class TasNode {
public:
    TasNode();

    int getValue() const;

    TasNode *getLeft() const;

    void setLeft(TasNode *left);

    TasNode *getRight() const;

    void setRight(TasNode *right);

    TasNode *getParent() const;

    void setParent(TasNode *parent);

    void setValue(int value);

    void setTNode(TNode *tnode);

    TNode *getTNode() const;

private:
    int value;
    TasNode *left;
    TasNode *right;
    TasNode *parent;
    TNode *tnode;
};
