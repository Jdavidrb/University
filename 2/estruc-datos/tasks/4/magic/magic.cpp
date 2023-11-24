/*
Jose David Ruano Burbano
Estructura de datos - Tarea 4 - Magic
Fecha: 1/OCT/23

Análisis de complejidad:
Sea n el número total de cartas y L la longitud total de todas las palabras que se deben deletrear. 

Ciclo de lectura: Se hacen n iteraciones para leer los datos de cada carta y llenar el vector 'mazo'.
Ciclo de palabras: Se hacen L iteraciones para cada palabra. Dentro de este ciclo, se hacen varias operaciones que 
involucran recorrer todas las cartas (n iteraciones). Esto incluye actualizar las estadísticas del mazo para cada 
carta y verificar el identificador. Por lo tanto, la complejidad dentro del ciclo de palabras es O(n), y como este 
ciclo se ejecuta L veces, la complejidad total de este bloque es O(n*L).

Impresión de datos: Se hacen n iteraciones para imprimir los datos de cada carta.

Por lo tanto, lo más costoso es n * L y por eso la complejidad es O(n * L).
*/


#include <iostream>
#include <cstdio>
#include <vector>
#include <string>


int main (){
    // Variables
    using namespace std;
    int n = 1;
    string identificador;
    string carta;
    
    bool flag = true;
    while (flag){
        scanf ("%d", &n);
        if (n == 0){
            flag = false; // cuando se lea un 0 deja de leer
        }
        else{
            vector<string> mazo (n ," -"); // Inicializamos el vector donde agregaremos las cartas
            int pos = 0; 
            for(int i = 0; i < n && flag; i++){
                cin >> identificador >> carta;
                int j = 0;
               
                while (j < carta.length()){
                    if (mazo[pos] == "-"){
                        j++;
                    }
                    if (j == carta.length()){
                        mazo[pos] = identificador;
                    }
                    pos++;
                    if (pos == n) {
                        pos = 0; // Vuelve al inicio del mazo cuando llegas al final
                    }
                        
                }
        
            }
            // Imprimir salida

            for (int i = 0 ; i < n; i++){
                cout << mazo[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}