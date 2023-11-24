/*
Jose David Ruano Burbano
Tarea 4 - Didit
Fecha: 1/OCT/23 

Análisis de complejidad:
Sea n el número total de problemas resueltos por los tres amigos. 

Ciclo de lectura: Se hacen n iteraciones para leer los problemas resueltos por cada amigo y llenar los vectores 'amigo1', 'amigo2' y 'amigo3'.
Función 'existeEnVector': Se llama hasta 3n veces y cada llamada tiene una complejidad de O(n), lo que da una complejidad total de O(3n^2).
Función 'eliminarRepetidos': Se llama 3 veces y cada llamada tiene una complejidad de O(n log n) para ordenar el vector y O(n^2) para eliminar duplicados, lo que da una complejidad total de O(3n^2).
Impresión de datos: Se hacen hasta 3n iteraciones para imprimir los problemas únicos resueltos por cada amigo.

Por lo tanto, lo más costoso es 3n^2 y por eso la complejidad es O(n^2).
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// funcion para ver si un valor existe o no en un vector

bool existeEnVector(vector<int> vec, int valor) {
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] == valor) {
            return true;
        }
    }
    return false;
}

// funcion para ordenar y eliminar elementos repetidos del vector, para asi evitar errores en la salida

vector<int> eliminarRepetidos(vector<int> vec) {

    // Ordenar el vector
    sort(vec.begin(), vec.end());

    // Eliminar duplicados
    for (vector<int>::iterator i = vec.begin(); i != vec.end(); ++i) {
        for (vector<int>::iterator j = i + 1; j != vec.end(); ) {
            if (*i == *j) {
                j = vec.erase(j);
            } else {
                ++j;
            }
        }
    }

    

    return vec;
}


int main() {
    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {

        vector<int> amigo1, amigo2, amigo3;
        int S1, S2, S3;

        // lectura de los problemas resueltos por cada amigo

        cin >> S1;
        for(int i = 0; i < S1; i++) {
            int problema;
            cin >> problema;
            amigo1.push_back(problema);
        }

        cin >> S2;
        for(int i = 0; i < S2; i++) {
            int problema;
            cin >> problema;
            amigo2.push_back(problema);
        }

        cin >> S3;
        for(int i = 0; i < S3; i++) {
            int problema;
            cin >> problema;
            amigo3.push_back(problema);
        }

        
        // Econtramos los problemas únicos de cada amigo, y los agregamos al vector ganador del respectivo amigo

        vector<int> gan1, gan2, gan3;

        // si no existe en el vector de los otros amigos se agrega ese problema ya que es unico

        for (int i = 0; i < S1; i++) {
            if (!existeEnVector(amigo2, amigo1[i]) && !existeEnVector(amigo3, amigo1[i])) {
                gan1.push_back(amigo1[i]);
            }
        }


        for (int i = 0; i < S2; i++) {
            if (!existeEnVector(amigo1, amigo2[i]) && !existeEnVector(amigo3, amigo2[i])) {
                gan2.push_back(amigo2[i]);
            }
        }

        for (int i = 0; i < S3; i++) {
            if (!existeEnVector(amigo1, amigo3[i]) && !existeEnVector(amigo2, amigo3[i])) {
                gan3.push_back(amigo3[i]);
            }
        }

        // eliminamos repetidos con la funcion que hemos creado anteriormente

        gan1 = eliminarRepetidos(gan1);
        gan2 = eliminarRepetidos(gan2);
        gan3 = eliminarRepetidos(gan3);

        // impresion de la salida

        cout << "Case #" << i + 1 << ":" << endl;

        // verificacion de ganador o de empate entre los amigos

        if (gan1.size() >= gan2.size() && gan1.size() >= gan3.size()) {
            cout << "1 " << gan1.size();
            for (int j = 0; j < gan1.size(); j++) {
                cout << " " << gan1[j];
            }
            cout << endl;
        }

        if (gan2.size() >= gan1.size() && gan2.size() >= gan3.size()) {
            cout << "2 " << gan2.size();
            for (int j = 0; j < gan2.size(); j++) {
                cout << " " << gan2[j];
            }
            cout << endl;
        }

        if (gan3.size() >= gan1.size() && gan3.size() >= gan2.size()) {
            cout << "3 " << gan3.size();
            for (int j = 0; j < gan3.size(); j++) {
                cout << " " << gan3[j];
            }
            cout << endl;
        }
    }
    return 0;
}
