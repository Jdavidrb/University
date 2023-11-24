/*
Autor: Carlos Ramírez
Implementación Árboles con Estructuras Enlazadas
Noviembre 8 de 2023

 */

#ifndef TREE_H
#define TREE_H

#include <cstdio>
#include <cstdlib>

class Tree{
     int dato;
     Tree *izq, *der;

    public:
        Tree();
	Tree(int, Tree*, Tree*);
        Tree getLeft();
        Tree getRight();
        int getValue();
	int getSize();
        int addElements();
	void preorder();
	void posorder();
};

#endif
