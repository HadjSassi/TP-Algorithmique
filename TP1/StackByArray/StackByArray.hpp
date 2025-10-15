#define MAX 1000
#include <iostream>
using namespace std;
class StackByArray {
public:
    void stackInit(); //{Initialiser une pile vide}
    void push(int v); //{Insérer une valeur V dans la pile}
    int pop(); // {Supprimer une valeur de la pile, renvoyez-la au résultat de la fonction}
    void display();
private:
    int stack[MAX];
    int top; //{Stocker l'index du dernier élément de la pile}

};