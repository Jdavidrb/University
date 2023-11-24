/*
Jose David Ruano Burbano
Estructura de datos - Tarea 4 - Sort
Fecha: 1/OCT/23

Análisis de complejidad:
Sea n el número total de palabras y m la longitud total de todas las palabras.

Ciclo de lectura: Se hacen n iteraciones para leer los datos de cada palabra y llenar el vector 'palabras'.
Función 'comparador': Se llama n log n veces durante la ordenación del vector 'palabras'. Cada llamada tiene una complejidad 
de O(m^2), ya que en el peor de los casos, puede recorrer toda la longitud de las dos palabras que se están comparando y para
cada carácter, busca su posición en 'palabra_guia' que también tiene una longitud máxima de m. Por lo tanto, la complejidad
total de este bloque es O(log n * m^2 ).
Impresión de datos: Se hacen n iteraciones para imprimir los datos de cada palabra.

Por lo tanto, lo más costoso es log n * m^2 y por eso la complejidad es O(log n * m^2 ).

*/
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string palabra_guia;

bool comparador(const string& ordenar1, const string& ordenar2) {
    int n;
    // para saber hasta que punto se deben comparar los caracteres de las dos palabras
    if (ordenar1.size() < ordenar2.size()) {
        n = ordenar1.size();
    } else {
        n = ordenar2.size();
    }
    bool flag = true;
    bool ans; 

    ans = ordenar1.size() < ordenar2.size(); // es verdadero si la primera palabra es más corta que la segunda, y falso en caso contrario

    // Se recorren los caracteres de las palabras hasta la longitud n. Para cada carácter:

    for (int i = 0; i < n && flag; ++i) {
        string::iterator pos_caracter1 = find(palabra_guia.begin(), palabra_guia.end(), ordenar1[i]);
        string::iterator pos_caracter2 = find(palabra_guia.begin(), palabra_guia.end(), ordenar2[i]);
        if (pos_caracter1 != pos_caracter2) {
            // Si el carácter de la primera palabra viene antes segun palabra_guia, ans se establece en verdadero; de lo contrario, se establece en falso
            ans = pos_caracter1 < pos_caracter2; 
            flag = false;
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    // leemos la palabra guia
    for(int i = 0; i < t; ++i){
        cin >> palabra_guia;
        int n;
        cin >> n;
        vector<string> palabras(n);
        // leemos las palabras a ordenar
        for(int j = 0; j < n; ++j){
            cin >> palabras[j];
        }
        // ordenamos 
        sort(palabras.begin(), palabras.end(), comparador);


        // imprimir la salida

        for(int j = 0; j < n; ++j){
            cout << palabras[j] << endl;
        }
        cout << endl;

    }
    return 0;
}
