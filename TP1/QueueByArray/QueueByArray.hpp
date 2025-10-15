#include <iostream>
#define MAX 10000
using namespace std;

class QueueByArray {
public:
    void QueueInit(); //{Initialiser une file d'attente vide}
    void Push(int v); //{Ajouter V dans la file}
    int Pop(); //{Prendre une valeur de la file d'attente, renvoyez-la au résultat de la fonction}
    void display();
private:
    int front;
    int rear;
    int array[MAX];
};