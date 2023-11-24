/* Complejidad operacion imprimiLista :
Tiene un complejidad lineal de n ya que se recorre hasta su ultimo elemento y en cada iteracion simplemente
el dato de el nodo y luego se imprimie, por lo que su complejidad T(n) = O(n)
siendo n : el numero de elementos en la lista*/

/* Analisis complejidad punto3 a. operacion restarListas

siendo n el tamaño de la lista 1 y m el tamaño de la lista, debido a que tendremos que buscar en lista 2 y tambien al mismo tiempo en la lista dos, la complejidad en principio
se acercara a O(n2), sin embargo cuando debido a no esta implmentado dentro de la interfaz adentro de la matriz hacemos uso de las operaciones de costo n por lo que de este modo 
los mas costoso sera (n*m * n ), por lo que la complejidad se acercaria a O(n3).
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


void restarListas (Lista &l1, Lista &l2){
    
    
    int size1 = l1.longLista();
    int size2 = l2.longLista();
    int i = 1;
    while (i <= size1){
        bool flag = true;
        int j = 1;
        while(j <= size2 && flag){
            if (l1.infoLista(i) == l2.infoLista(j)){
                l1.elimLista(i);
                flag = false;
                size1--; // Actualizar el tamaño de la lista después de la eliminación
            }
            else
                j++; 
        }
        if(flag) // Si no se eliminó ningún elemento, incrementar i
            i++;
    }


}


int main(){

    Lista l1;
    Lista l2;


    l1.anxLista(1);
    l1.anxLista(2);
    

    l2.anxLista(2);
    l2.anxLista(3);
    l2.anxLista(4);
    

    
    imprimirLista(l1);
    imprimirLista(l2);

    restarListas(l1,l2);
    cout << "llego "<< endl;

    imprimirLista(l1);
    imprimirLista(l2);


    return 0;
}