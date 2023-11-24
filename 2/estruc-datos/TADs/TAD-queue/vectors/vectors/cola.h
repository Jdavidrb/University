/*
Implementación TAD Cola
Octubre 27 de 2023

Vectores

 */

#include <vector>

using namespace std;

class Queue{
  private:
    vector<int> vec;

  public:
    Queue();
    int front();
    void push(int);  // enqueue
    void pop();         // dequeue
    bool empty();   // vaciaCola
};  
