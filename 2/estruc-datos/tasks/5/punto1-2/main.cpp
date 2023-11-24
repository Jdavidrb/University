/* Analisis complejidad punto1. Operacion imprimirLiata

Siendo n el numero de elementos, Podemos ver que se itera a travez de cada elemento, sin embargo por cada iteracion del bucle tambien hacemos n iteraciones con infoLista,
por esta razon, podriamos decir que la complejidad de esta operacion es O(n**2)*/

/* Analisis complejidad punto2. Operacion obtenerIgualesModulo

Siendo 
Vemos que necesitamos recorres la lista dado en donde hacemos n iteraciones sim ebargo de igual forma en cada iteracion se usa la operacion infoLista que por cada vez
que se llame se hara n veces. por lo que al final lo mas grande va a ser n*n siendo n el tamaño del vector y el otro n el costo de la operacion infolista, por ende la complejidad es
O(n**2)*/




#include "lista.h"
#include <cstdio>
#include <iostream>
using namespace std;

void imprimirLista(Lista &lis){ 
    int i;
    int size = lis.longLista();
    int ans;
    for(i = 1; i <= size-1; i++){
        ans = lis.infoLista(i);
        cout << ans << "," << " ";
        
    }
    cout << lis.infoLista(size);
    cout << endl;
}

void obtenerIgualesModulo(Lista &lis, int v, int k){
    int size = lis.longLista();
    int ans = 0;
    int i;
    int valor;
    int modulo; 
    int data;

    modulo = v % k;

    for(i = 1; i <= size; i++){
        valor = lis.infoLista(i);
        data = valor % k;
        
        if (data == modulo){
            ++ans;
        }
        
    }
    cout << ans;
}


int main(){

    Lista lis;

    lis.anxLista(11);
    lis.anxLista(23);
    lis.anxLista(17);
    lis.anxLista(94);
    lis.anxLista(45);
    lis.anxLista(33);
    lis.anxLista(38);
    lis.anxLista(16);
    
    imprimirLista(lis);

    obtenerIgualesModulo(lis, 24, 7);

    return 0;
}