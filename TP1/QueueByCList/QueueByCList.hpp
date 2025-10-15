#include <iostream>
using namespace std;
#define MAX 10000


class QueueByCList {
public:
    void QueueInit(); //{Initialiser une file d'attente vide}
    void Push(int v); //{Ajouter V dans la file}
    int Pop(); //{Prendre une valeur de la file d'attente, renvoyez-la au résultat de la fonction}
    void display();
private:
    int queue[MAX-1];
    int front;
    int rear;
    int n ;
};