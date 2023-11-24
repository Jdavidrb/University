/*
Implementación TAD Cola
Octubre 27 de 2023

Versión 1
Vectores donde la posición 0 es el frente de la cola

Versión 2
Vectores donde la última posición es el frente de la cola

 */

#include "cola.h"

Queue::Queue(){
}

// Complejidad = O(1) (versión 1)
// Complejidad = O(1) (versión 2)
int Queue::front(){
  // versión 1
  //int ans = vec[0];

  // versión 2
  int ans = vec[vec.size() - 1];
  return ans;
}

// Complejidad = O(1) (versión 1)
// Complejidad = O(n) (versión 1)
void Queue::push(int e){
  // versión 1
  //vec.push_back(e);

  //versión 2
  if(!vec.empty())
    vec.insert(vec.begin(), e);
  else
    vec.push_back(e);
}

// Complejidad = O(n) (versión 1)
// Complejidad = O(1) (versión 2)
void Queue::pop(){
  // versión 1
  //vec.erase(vec.begin());

  //versión 2
  vec.pop_back();
}

// Complejidad = O(1) (versión 1 y 2)
bool Queue::empty(){
  // versión 1 y versión 2
  bool ans = vec.empty();
  return ans;
}



