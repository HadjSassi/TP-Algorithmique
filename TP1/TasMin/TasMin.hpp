#include <string>
#include "../Node/TNode.hpp"
#include "../QueueByLinkedList/QueueByLinkedList.hpp"

class TasMin {
    TNode *sommet;
    QueueByLinkedList unverfiedNodes;


public:
    TasMin();
    ~TasMin();
    void insertInGoodPlace(TNode *node);
    void fixUnverifiedNodes();
    void displayTreeAscii(TNode *node, const std::string &prefix, bool isLeft);
    void insert(int value);
    int extractMin();
    int lengthTas();
    TNode getMin();
    bool isEmpty();
    void display();
};
