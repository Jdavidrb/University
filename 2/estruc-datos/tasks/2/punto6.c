#include <stdio.h>

void algoritmo3(int n)
{
    int i, j, k; // 3

    for (i = 1; i <= n + 2; ++i)

        for (j = 1; j <= i; j++)

            for (k = 0; k < n; k++)
                printf("Vida cruel!!\n");
}
