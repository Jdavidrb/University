#include <stdio.h>

void algoritmo5(unsigned int n)
{
    int i = n;    // 1
    while (i > 0) // n/(n/4) + 1
    {
        printf("%d\n", i); // n/(n/4)
        i -= n / 4;        // n/(n/4)
    }
}

int main()
{
    int n = 1;
    algoritmo5(n);
    return 0;
}