/*
Implementación Pilas con Listas
Octubre 20 de 2023

Se usa la última posición del vector como tope

 */

#include "pila.h"

Stack::Stack(){
}

// Complejidad = O(1) amort.
void Stack::push(int e){
  vec.push_back(e);
}

// Complejidad = O(1)
int Stack::peek(){
  int ans = vec[vec.size() - 1];
  return ans;
}

// Complejidad = O(1)
void Stack::pop(){
  vec.pop_back();
}

// Complejidad = O(1)
bool Stack::empty(){
  bool ans = vec.empty();
  return ans;
}
