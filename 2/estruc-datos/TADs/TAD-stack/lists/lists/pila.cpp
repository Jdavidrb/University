/*
Implementación Pilas con Listas
Octubre 20 de 2023

 */

#include "pila.h"

Stack::Stack(){

}

// Complejidad = O(1)
void Stack::push(int e){
  if(l.vaciaLista())
    l.anxLista(e);
  else
    l.insLista(e, 1);
}

// Complejidad = O(1)
int Stack::peek(){
  int ans = l.infoLista(1);
  return ans;
}

// Complejidad = O(1)
void Stack::pop(){
  l.elimLista(1);
}

// Complejidad = O(1)
bool Stack::empty(){
  bool ans = l.vaciaLista();
  return ans;
}
