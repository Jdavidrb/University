/*
Autor: Carlos Ramírez
Implementación Colas de Prioridad con Montículos
Mayo 19 de 2023

 */

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <cstdio>
#include <cstdlib>
#include "heap.h"

class PriorityQueue{
    Heap h;

    public:
        PriorityQueue();
        void push(int);
        void pop();
	int top();
        bool empty();
};

#endif
