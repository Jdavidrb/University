/*
Implementación TAD Cola
Octubre 27 de 2023

Listas

 */

#include "pila.h"

using namespace std;

class Queue{
  private:
    Stack col;

  public:
    Queue();
    int front();
    void push(int);  // enqueue
    void pop();         // dequeue
    bool empty();   // vaciaCola
};  
