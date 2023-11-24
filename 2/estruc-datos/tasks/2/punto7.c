#include <stdio.h>

int algoritmo4(int k, int *A, int n)
{
    int suma = 0, contador = 0; // 2
    int i, j, h, flag;          // 4
    for (i = 0; i < n; i++)     // n + 1
    {
        j = i;                     // n
        flag = 1;                  // n
        while (j < n && flag == 1) // sumatoria de j = 0 , n - 1 de j + 2 --------- 2n
        {
            if (A[j] == k) // sumatoria de j = 0 , n - 1 de j + 1  -------- n
            {
                contador++; // 0 ------n
                flag = 0;   // 0 ----n
            }
            else // lo mismo que if------0
            {
                for (h = n - 1; h >= j; h--) // minimusculoso------ 0
                {
                    suma += A[h]; // minimusculoso ---- 0
                }
            }

            ++j; // lo mismno q ifsa ------ n
        }
    }

    return contador; // 1
}

int algoritmo4(int k, int *A, int n);

int main()
{
    int A[] = {1, 2, 3}; // Un arreglo de ejemplo
    int n = 3;           // Longitud del arreglo
    int k = 3;           // Valor a buscar
    int resultado;

    resultado = algoritmo4(k, A, n);

    printf("El valor %d se encontró %d veces en el arreglo.\n", k, resultado);

    return 0;
}
