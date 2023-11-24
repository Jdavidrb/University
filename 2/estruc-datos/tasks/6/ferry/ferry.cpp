/* 
Jose David Ruano Burbano 
Estructura de datos - tarea6 - Ferry
Fecha: 10/11/2023

Analisis Complejidad:

El algoritmo tiene una complejidad de O(n) donde n es el número total de autos que llegan al ferry. 
Ya que se hacen n iteraciones para leer los datos de entrada y llenar las colas ‘left’ y ‘right’ y 
luego se hacen hasta n iteraciones para sacar los autos de las colas y simular el cruce del ferry.
Cada iteración tiene una complejidad de O(1) porque las operaciones de cola son constantes.
Finalmente se imprime el resultado por cada caso de prueba.
*/


#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
using namespace std;



int main(){
    int c;
    cin >> c;
    for(int i = 0; i < c; i++){
        int l, m;
        cin >> l >> m;
        l *= 100; 

        queue<int> left, right;
        for (int j = 0; j < m; j++){
            int length;
            string side;
            cin >> length >> side;

            if(side == "left"){
                left.push(length);
            }
            else{
                right.push(length);
            }
        }
        int cont = 0;
        bool flag = true; // true left right false
        while(!left.empty() || !right.empty()){
            int space = l;

            if(flag){
                while(!left.empty() && left.front() <= space){
                    space -= left.front();
                    left.pop();
                }
                flag = false;
            }
            else{
                while(!right.empty() && right.front() <= space){
                    space -= right.front();
                    right.pop();
                }
                flag = true;
            }
            cont++;
        }
        cout << cont << endl;
    }

    return 0;
}
