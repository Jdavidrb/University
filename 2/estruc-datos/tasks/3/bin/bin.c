/*

Nombre: Jose David Ruano Burbano
codigo: 8982982
Problema: bin
complejidad de problema: O(1)

La complejidad del problema es constante, ya que el numero de operaciones realizadas no depende del tamaño de la entrada.
El bucle principal se ejecuta siempre 6 veces y el bucle interno se ejecuta siempre 3 veces por lo que el numero total
de operacionea siempre seria el mismo.

*/
#include <stdio.h>
#include <string.h>

int main()
{
    int botellas[3][3];
    char orden_cajas[6][4] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
    int min_moves, i, j, moves;
    char ans[4];

    while (scanf("%d %d %d %d %d %d %d %d %d",
                 &botellas[0][0], &botellas[0][1], &botellas[0][2],
                 &botellas[1][0], &botellas[1][1], &botellas[1][2],
                 &botellas[2][0], &botellas[2][1], &botellas[2][2]) == 9)
    {
        min_moves = 2147483647;
        for (i = 0; i < 6; i++)
        {
            moves = 0;
            for (j = 0; j < 3; j++)
            {
                if (orden_cajas[i][j] == 'B')
                {
                    moves += botellas[j][1] + botellas[j][2];
                }
                else if (orden_cajas[i][j] == 'G')
                {
                    moves += botellas[j][0] + botellas[j][2];
                }
                else
                {
                    moves += botellas[j][0] + botellas[j][1];
                }
            }
            if (moves < min_moves)
            {
                min_moves = moves;
                strcpy(ans, orden_cajas[i]);
            }
        }
        printf("%s %d\n", ans, min_moves);
    }
    return 0;
}