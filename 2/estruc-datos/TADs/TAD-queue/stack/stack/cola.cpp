/*
Implementación TAD Cola
Octubre 27 de 2023

Pilas (alguna implementación con operaciones con complejidad O(1))

 */

#include "cola.h"

Queue::Queue(){
}

// Complejidad = O(n)
int Queue::front(){
  Stack aux;

  while(!col.empty()){
    aux.push(col.peek());
    col.pop();
  }

 int ans =  aux.peek();

 while(!aux.empty()){
    col.push(aux.peek());
    aux.pop();
  }
  return ans;
}

// Complejidad = O(1)
void Queue::push(int e){
  col.push(e);
}

// Complejidad = O(n)
void Queue::pop(){
  Stack aux;

  while(!col.empty()){
    aux.push(col.peek());
    col.pop();
  }

  col.pop();

 while(!aux.empty()){
    col.push(aux.peek());
    aux.pop();
  }
}

// Complejidad = O(1)
bool Queue::empty(){
  bool ans = col.empty();
  return ans;
}



