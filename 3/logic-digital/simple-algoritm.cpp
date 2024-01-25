#include <iostream>
#include <vector>
using namespace std;
// Función para sumar números pares en una lista
int sumarPares(vector<int> lista) {
    int suma = 0;
    for(int i = 0; i < lista.size(); i++) {
        if(lista[i] % 2 == 0) {
            suma += lista[i];
        }
    }
    return suma;
}

int main() {
    vector<int> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sumaDePares = sumarPares(numeros);
    cout << "La suma de los números pares es: " << sumaDePares << endl;
    return 0;
}

// maincra
// soy tonto
// soy aun mas retrasao