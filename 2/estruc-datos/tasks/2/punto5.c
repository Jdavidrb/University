#include <math.h>
#include <stdio.h>

int algoritmo2(int n)
{
    int res = 1, i, j;
    for (i = 1; i <= 3 * n; i += 5)    // techo de 3n/5 + 1
        for (j = 0; j <= sqrt(n); j++) // techo de (3n/5 + 1) * sqrt(n)+1
            res += n;                  // techo de ((3n/5 + 1) * sqrt(n)+1 ) -1
    return res;                        // 1
}
int main()
{
    int result = algoritmo2(3);
    printf("Resultado: %d\n", result);
    return 0;
}
