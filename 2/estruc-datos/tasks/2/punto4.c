#include <stdio.h>
int main()
{
    int n = 10;
    algoritmo1(n);
    return 0;
}

void algoritmo1(int n)
{
    int i, j = 1; // 1
    for (i = 1; i < n * n; i = i * 3)// log_3(n*n)+1
    {                              
        int suma = i + j;          // log_3(n*n)
        printf("Suma %d\n", suma); // log_3(n*n)
        ++j;                       // log_3(n*n)
    }
}



