/*
Implementación Pilas con Listas
Octubre 20 de 2023

Se usa la posición 0 del vector como tope

 */

#include "pila.h"

Stack::Stack(){
}

// Complejidad = O(n)
void Stack::push(int e){
  if(vec.empty())
    vec.push_back(e);
  else
    vec.insert(vec.begin(), e);
}

// Complejidad = O(1)
int Stack::peek(){
  int ans = vec[0];
  return ans;
}

// Complejidad = O(n)
void Stack::pop(){
  vec.erase(vec.begin());
}

// Complejidad = O(1)
bool Stack::empty(){
  bool ans = vec.empty();
  return ans;
}
