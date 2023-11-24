/*

Nombre: Jose David Ruano Burbano
codigo: 8982982
Problema: reverse-add
complejidad de problema: O(log(n))

El bucle externo se ejecuta t veces y el bucle interno se ejecuta en O(log(n)) ya
que el número de dígitos de n es log(n). Por lo tanto podriamos decir que la complejidad total es algo como O(t * log(n)).

*/

#include <stdio.h>

int main()
{
    int t, i, contador_suma, flag;
    long long int n, n_invertido, temp;

    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%lld", &n);
        contador_suma = 0;
        flag = 1;
        while (flag != 0 && contador_suma < 1000)
        {
            n_invertido = 0;
            temp = n;
            while (temp > 0)
            {
                n_invertido = (n_invertido * 10) + (temp % 10);
                temp = temp / 10;
            }
            if (n == n_invertido)
            {
                flag = 0;
            }
            else
            {
                flag = 1;
                n = n + n_invertido;
                contador_suma += 1;
            }
        }
        printf("%d %lld\n", contador_suma, n);
    }
    return 0;
}
