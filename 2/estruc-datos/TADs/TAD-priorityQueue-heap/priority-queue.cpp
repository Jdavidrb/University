/*
Autor: Carlos Ramírez
Implementación Colas de Prioridad con Montículos
Mayo 19 de 2023

 */

#include "priority-queue.h"

PriorityQueue::PriorityQueue(){
}

// Complejidad = O(log n)
void PriorityQueue::push(int e){
    h.addElement(e);
}

// Complejidad = O(log n)
void PriorityQueue::pop(){
    h.deleteMax();
}

// Complejidad = O(1)
int PriorityQueue::top(){
    int ans = h.getMax();
    return ans;
}

// Complejidad = O(1)
bool PriorityQueue::empty(){
    bool ans = h.empty();
    return ans;
}
