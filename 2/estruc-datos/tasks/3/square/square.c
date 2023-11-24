
/*

Nombre: Jose David Ruano Burbano
codigo: 8982982
Problema: square
Complejidad de problema: Podria ser O(n^3) o O(n^c) c > 3

El bucle externo se ejecuta t veces.Dentro de este bucle, podemos ver otro bucle que se ejecuta q veces.
Dentro de este último bucle, tenemoa uno anidado triple donde k puede tener un valor maximo de min(m, n)
y los bucles anidados para i y j tambien tienen un rango de valores de min(m, n).
Esto significa que el numero máximo de veces que se ejecutara este bucle anidado triple es min(m, n)^3
Por lo tanto, la complejidad total seria algo como O(t * q * min(m, n)^3).

*/

#include <stdio.h>

int main()
{
    int t, m, n, q, r, c, i, j, k;
    char grid[101][101];
    int caso, consulta, lado_max, flag;

    scanf("%d", &t);
    for (caso = 1; caso <= t; ++caso)
    {
        scanf("%d %d %d", &m, &n, &q);
        printf("%d %d %d\n", m, n, q);
        for (i = 0; i < m; ++i)
        {
            scanf("%s", grid[i]);
        }

        for (consulta = 0; consulta < q; ++consulta)
        {
            scanf("%d %d", &r, &c);
            lado_max = 1;
            flag = 1;
            for (k = 1; k <= m && k <= n && flag; ++k)
            {
                for (i = r - k; i <= r + k && flag; ++i)
                {
                    for (j = c - k; j <= c + k && flag; ++j)
                    {
                        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != grid[r][c])
                        {
                            flag = 0;
                        }
                    }
                }
                if (flag)
                    lado_max = k * 2 + 1;
            }
            printf("%d\n", lado_max);
        }
    }

    return 0;
}
