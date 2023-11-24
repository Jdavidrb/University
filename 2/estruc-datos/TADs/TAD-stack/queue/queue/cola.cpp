/*
Implementación TAD Cola
Octubre 27 de 2023

Versión 1
Listas donde el inicia de la lista es el frente de la cola

Versión 2
listas donde el final de la lista  es el frente de la cola

 */

#include "cola.h"

Queue::Queue(){
}

// Complejidad = O(1) (versión 1)
// Complejidad = O(1) (versión 2)
int Queue::front(){
  // versión 1
  int ans = lis.front();

  // versión 2
  //int ans = lis.back();
  return ans;
}

// Complejidad = O(1) (versión 1)
// Complejidad = O(1) (versión 2)
void Queue::push(int e){
  // versión 1
  lis.push_back(e);

  //versión 2
  //lis.push_front(e);
}

// Complejidad = O(1) (versión 1)
// Complejidad = O(1) (versión 2)
void Queue::pop(){
  // versión 1
  lis.pop_front();

  //versión 2
  //lis.pop_back();
}

// Complejidad = O(1) (versión 1 y 2)
bool Queue::empty(){
  // versión 1 y versión 2
  bool ans = lis.empty();
  return ans;
}



