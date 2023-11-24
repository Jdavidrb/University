/*
Implementación Pilas con Listas
Octubre 20 de 2023

Colas (se asume que el frente de la cola es el tope de la pila y que la implementación
tiene complejidades O(1))

 */

#include "pila.h"

Stack::Stack(){

}

// Complejidad = O(n)
void Stack::push(int e){
  Queue aux;
  while(!l.empty()){
    aux.push(l.front());
    l.pop();
  }
  
  l.push(e);
  
  while(!aux.empty()){
    l.push(aux.front());
    aux.pop();
  }  
}

// Complejidad = O(1)
int Stack::peek(){
  int ans = l.front();
  return ans;
}

// Complejidad = O(1)
void Stack::pop(){
  l.pop();
}

// Complejidad = O(1)
bool Stack::empty(){
  bool ans = l.empty();
  return ans;
}
