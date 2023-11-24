/*
Jose David Ruano Burbano
Estructura de datos - Tarea 4 - Givers
Fecha: 1/OCT/2023

Análisis de complejidad:
Sea n el número total de personas y G el número total de regalos.

Ciclo de lectura: Se hacen n iteraciones para leer los datos de cada persona y llenar el vector 'nombres'.
Ciclo de regalos: Se hacen G iteraciones para cada regalo. Dentro de este ciclo, se hacen varias operaciones que involucran recorrer 
todas las personas (n iteraciones). Esto incluye actualizar las estadísticas del regalo para cada persona y verificar quién hizo el regalo.
Por lo tanto, la complejidad dentro del ciclo de regalos es O(n), y como este ciclo se ejecuta G veces, la complejidad total de este bloque 
es O(n*G).
Impresión de datos: Se hacen n iteraciones para imprimir los datos de cada persona.

Por lo tanto, lo más costoso es n * G y por eso la complejidad es O(n * G).
*/

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <cstring> 

using namespace std;
int main() {
    // variables

    int n;
    int d; 
    char nombre[14]; 
    char nombre2[14]; 
    int n_regalos; 
    vector<string> nombres;

    //contadores
    int i, j, k, l;
    // auxiliares
    int aux1;
    int aux2;

    
    while(scanf("%d", &n) != EOF){ // leemos hasta que se ingrese EOF

        // almacenamos los nombres de quienes participan y inicializamos

        for (i = 0; i < n; ++i) {
            
            
            scanf("%s", nombre);
            nombres.push_back(string(nombre));

        }
        vector<int> dinero_dado(n,0); // dinero que dan
        vector<int> dinero_recibido(n,0); // dinero que reciben
        aux1 = 0;
        aux2 = 0;

        // leemos la informacion de cada participante

        for (i = 0; i < n; ++i){

            

            scanf("%s %d %d", nombre, &d, &n_regalos);
            
            bool flag = false;

            for (j = 0; j < n && !flag; ++j){
                if (strcmp(nombre, nombres[j].c_str()) == 0){ // Buscamos el nombre del amigo en los participantes
                    aux1 = j; // almacenamos su indice para trabajar luego con el
                    flag = true;
                }
            }

            // Reiniciamos la variable nombre para luego almacenar otro nombre
            
            for (int i = 0; i < sizeof(nombre)/sizeof(nombre[0]); i++) {
                nombre[i] = '\0';
            }
            
            // guardamos las personas a quien le va a regalar en un vector aparte

            vector<string> personas_a_regalar; 
            
            for (j = 0; j < n_regalos; ++j){
                scanf("%s", nombre2);
                personas_a_regalar.push_back(string(nombre2));

            }

            // Hacemos las respectivas operaciones para las personas a las que se le regalo

            for (k = 0; k < n_regalos; ++k){
                
                flag = false;
                for (l = 0; l < n && !flag; ++l){
                    if (personas_a_regalar[k] == nombres[l]){ // buscamos el indice del amigo al que se le va regalar 
                        aux2 = l;
                        dinero_recibido[aux2] += d/n_regalos; // le sumamos el dinero recibido a ese amigo encontrado
                        flag = true;
                    }
                    
                }
        
            }
            
            // Reiniciamos la variable nombre2 para luego almacenar mas nombres 

            for (int i = 0; i < sizeof(nombre2)/sizeof(nombre2[0]); i++){
                nombre2[i] = '\0';
            }

            // sumamos el dinero dado del amigo quien regalo

            if(n_regalos > 0)
                dinero_dado[aux1] = (d/n_regalos)* n_regalos;
            
        }

        // imprimimos la salida
        int ans;
        for (ans = 0; ans < n; ++ans)
            cout << nombres[ans] << " " << dinero_recibido[ans] - dinero_dado[ans]<< endl;

        cout << endl;



        // limpiamos memoria de los vectores 
        nombres.clear();
        dinero_dado.clear();
        dinero_recibido.clear();
    
    }

    return 0;
}
