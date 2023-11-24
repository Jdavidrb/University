/*
Implementación Montículos
Noviembre 8 de 2023

 */

#ifndef HEAP_H
#define HEAP_H

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

class Heap{
    vector<int> mont;

    public:
       Heap();
       Heap(vector<int>&);
       int getLeft(int);
       int getRight(int);
       int getParent(int);
       void heapify(int);
       int getMax();
       void deleteMax();
       void addElement(int);
       void print();
       bool empty();
};


#endif
