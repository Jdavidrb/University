/* 
Jose David Ruano Burbano 
Estructura de datos - tarea6 - Rain
Fecha: 11/11/2023

Analisis Complejidad:

El algoritmo tiene una complejidad de O(n) donde n es el numero total de caracteres 
en la representacion simplificada del universo, se hacen n iteraciones para leer los caracteres 
de entrada y Luego, se hacen hasta n iteraciones para recorrer cada caracter y realizar las operaciones 
correspondientes donde en cada iteracion se hace una complejidad de O(1) porque las operaciones de pila
(push, pop y top) son constantes. 
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        string caracters;
        cin >> caracters;
        stack<int> st;
        int n = caracters.size();
        int water = 0;
        for(int j = 0; j < n; j++) {
            if(caracters[j] == '\\') {
                st.push(j);
            
            } else if(caracters[j] == '/' && !st.empty()) {
                int begin = st.top();
                st.pop();
                
                water += j - begin;
            }
        }
        cout << water << endl;
    }
    return 0;
} 

