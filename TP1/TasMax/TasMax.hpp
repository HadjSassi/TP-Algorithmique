#include <vector>

#include "../Node/TNode.hpp"
#include "../QueueByLinkedList/QueueByLinkedList.hpp"
using namespace std;

class TasMax {
protected:
    TNode *sommet;
    QueueByLinkedList unverfiedNodes;

public:
    TasMax();

    virtual ~TasMax();

    void insert(int value);

    int lengthTas();

    void insertInGoodPlace(TNode *node);

    virtual void fixUnverifiedNodes();

    TNode getMax();

    int extractMax();

    void display();

    void displayTreeAscii(TNode *node, const std::string &prefix, bool isLeft);

    bool isEmpty();


};