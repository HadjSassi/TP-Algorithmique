#include <iostream>
#include "../Node/TNode.hpp"
using namespace std;

class StackByLinkedList {

public:
    void stackInit(); //{Initialiser une pile vide}
    void push(int v); //{Insérer une valeur V dans la pile}
    int pop(); // {Supprimer une valeur de la pile, renvoyez-la au résultat de la fonction}
    void display();
private:
    TNode *top;
};