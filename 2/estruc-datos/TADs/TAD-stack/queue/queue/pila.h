
/*
Implementación Pilas con Listas
Octubre 20 de 2023

 */

#include "cola.h"

class Stack{
  private:
    Queue l;

  public:
    Stack();
    void push(int);
    int peek();
    void pop();
    bool empty();
};
