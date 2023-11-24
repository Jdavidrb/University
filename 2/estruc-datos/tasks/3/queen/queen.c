/**
Nombre: Jose David Ruano Burbano
codigo: 8982982
Problema: queen
complejidad de problema: O(1)

La complejidad del problema es constante ya que el numero de operaciones realizadas no depende del tamaño de la entrada.
El bucle principal se ejecuta siempre hasta que se cumple una condicion especifica (cuando todos los valores son cero)
y dentro del bucle el numero de operaciones es siempre seria el mismo.

*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x1, y1, x2, y2, moves, flag = 1;

    while (flag != 0)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        moves = 0;

        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
        {
            flag = 0;
        }
        else
        {

            if (x1 == x2 && y1 == y2)
            {
                flag = 1;
                moves = 0;
            }
            else if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2))
            {
                flag = 1;
                moves++;
            }
            else
            {
                flag = 1;
                moves = 2;
            }

            printf("%d\n", moves);
        }
    }

    return 0;
}
