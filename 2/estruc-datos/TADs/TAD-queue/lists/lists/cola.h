/*
Implementación TAD Cola
Octubre 27 de 2023

Listas

 */

#include <list>

using namespace std;

class Queue{
  private:
    list<int> lis;

  public:
    Queue();
    int front();
    void push(int);  // enqueue
    void pop();         // dequeue
    bool empty();   // vaciaCola
};  
