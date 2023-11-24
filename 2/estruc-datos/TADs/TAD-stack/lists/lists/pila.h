
/*
Implementación Pilas con Listas
Octubre 20 de 2023

 */

#include "lista.h"

class Stack{
  private:
    Lista l;

  public:
    Stack();
    void push(int);
    int peek();
    void pop();
    bool empty();
};
