/* Analisis complejidad punto3 b. operacion - 

siendo n el tamaño de la lista 1 y m el tamaño de la lista 2, debido a que tendremos que buscar en lista 2 y tambien al mismo tiempo en la lista dos, la complejidad en principio
se acercara a O(n2), sin embargo cuando debido a estar implmentado dentro de la interfaz hacemos uso de los punteros, bajando la complejidad en el mayor costo a O(n2).
*/
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


int main(){

    Lista l1;
    Lista l2;
    
    l1.anxLista(1);
    l1.anxLista(2);
    
    l1.anxLista(5);
    l2.anxLista(2);
    l2.anxLista(3);
    l2.anxLista(4);

    
    Lista l3 = l1 - l2 ;

    imprimirLista(l3);
    imprimirLista(l1);
    imprimirLista(l2);
    

    return 0;
}