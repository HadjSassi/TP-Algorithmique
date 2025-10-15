class TNode {
public:
    TNode(int value);
    int getValue() const;
    TNode *getLink() const;
    void setLink(TNode *link);
    void setValue(int value);
private:
    int value;
    TNode *link;
};