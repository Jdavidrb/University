/* Analisis complejidad punto3 a. operacion insertarListaOrdenada

siendo n la cantidad iteraciones que tendra que hacer para insertar el elemento, en el mejor caso; cuando solo se haga una iteracion la complejidad sera O(1) sin embargo
pensando en el peor caso; la complejidad de la operacion sera O(n2) ya que al no estar implmentada dentro de la interfaz es necesario usar las operaciones de la implementacion, esto
hace que por cada iteracion del bucle haremos n*n como mayor costo dentro del bucle ya sea utilizando infoLista, insLista, AmxLista, los cuales tienen un costo de O(n), y al estar 
dento del bucle, convierte a la complejidad en O(n2).
*/


/*  Analisis complejidad punto3 b. operacion insListaOrdenada

La operacion inslista se asemaja a la del item a, sin embargo al estar implementada dentro de la intefaz, su complejidad en el peor de los casos su complejidad mejora.
siendo n la cantidad iteraciones que tendra que hacer para insertar el elemento, en el mejor caso; cuando solo se haga una iteracion la complejidad sera O(1) sin embargo
pensando en el peor caso; la complejidad de la operacion sera O(n).
*/

#include <iostream> 
#include "lista.h"

using namespace std;



void insertarEnListaOrdenada(Lista &l, int v){
    int i = 1;
    int size = l.longLista();
    bool flag = true;

    while (i <= size && flag)
    {
        if (v > l.infoLista(i) ){
            l.insLista(v , i);
            flag = false;

        }
        else if(l.infoLista(size) > v){
            l.anxLista(v);
            flag = false;
        }
        else{
            i++;
        }
    }
}

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

int main (){

    Lista l;
    
    
    l.anxLista(10);
    l.anxLista(9);
    l.anxLista(7);
    l.anxLista(6);
    l.anxLista(4);
    l.anxLista(3);
    l.anxLista(2);
    l.anxLista(1);

    imprimirLista(l);
    //l.insListaOrdenada(5);

    

    
    insertarEnListaOrdenada(l , -1);
    insertarEnListaOrdenada(l, 8);

    imprimirLista(l);

    insertarEnListaOrdenada(l , -100);

    insertarEnListaOrdenada(l , 100);

     imprimirLista(l);

    return 0;
}
