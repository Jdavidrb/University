/* 
Jose David Ruano Burbano 
Estructura de datos - tarea6 - Stones
Fecha: 12/11/2023

Analisis Complejidad:

El algoritmo tiene una complejidad de tiempo de O(n) donde n es el numero total 
de caracteres en la cadena de entrada. se hacen n iteraciones 
para leer los caracteres de entrada y luego se hacen hasta n iteraciones para recorrer 
cada caracter y realizar las operaciones correspondientes.

En cada iteracion se hace una complejidad de constante porque las operaciones de deque 
(push_front, push_back) son constantes. Ademas, el bucle final que imprime el orden 
de las piedras tambien tiene una complejidad de O(n).

Por lo tanto, la complejidad total del tiempo es O(n) + O(n) + O(n) = O(3n).
*/

#include <iostream>
#include <string>
#include  <deque>
#include <stack>


using namespace std;

int main(){

    string line;
    while(getline(cin, line)){

        int num_rock = 2;
        int n = line.size();
        deque<int> order;
        deque<int> aux_order;
        char next_move;
        int i = 0;

        if(line[i] == 'r') order.push_back(1);
        else aux_order.push_front(1);

        while(i < n-1){
            next_move = line[i+1];
            if(next_move == 'r'){
                order.push_back(num_rock);

            }
            else{
                aux_order.push_front(num_rock);
            }
            num_rock++; 
            i++;
        }
        int rock;
        for(int l = 0; l < aux_order.size(); l++){
            rock = aux_order[l];
            order.push_back(rock);
        }
            
        for(int j = 0; j < order.size(); j++)
            cout<< order[j] << endl;
        cout<< endl;

    }
    return 0;
}