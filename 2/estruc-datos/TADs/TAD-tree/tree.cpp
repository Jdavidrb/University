/*
Autor: Carlos Ramírez
Implementación Árboles con Estructuras Enlazadas
Noviembre 8 de 2023

 */

#include "tree.h"

Tree::Tree(){
}

Tree::Tree(int v, Tree* l, Tree* r){
    dato = v;
    izq = l;
    der = r;
}
    
int Tree::getSize(){
    int ans = 0;
    if(izq == NULL && der == NULL)
	ans = 1;
    else if(der == NULL)
	ans = 1 + izq->getSize();
    else if(izq == NULL)
	ans = 1 + der->getSize();
    else{
	ans = 1 + izq->getSize() + der->getSize();
    }
    return ans;
}

int Tree::addElements(){
    int ans = 0;
    if(izq == NULL && der == NULL)
	ans = dato;
    else{
	if(izq != NULL)
	    ans += izq->addElements();
	if(der != NULL)
	    ans += der->addElements();
	ans += dato;
    }
    return ans;
}

void Tree::preorder(){
    printf("%d ", dato);
    if(izq != NULL)
	izq->preorder();
    if(der != NULL)
	der->preorder();
}

void Tree::posorder(){
    if(izq != NULL)
	izq->posorder();
    if(der != NULL)
	der->posorder();
    printf("%d ", dato);
}



