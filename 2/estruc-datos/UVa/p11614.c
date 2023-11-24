#include <stdio.h>

int main() {
    int t, j;
    int n;
    int aux , floor ;

    scanf("%d", &t);

    int i = 0;
    while (i < t) {
        scanf("%d", &n); 
        aux = 0;
        floor = 0;
        for (j = 1; aux < n; j++) {
            aux = aux + j;
            
            ++floor;
        }
        if (aux > n) {
            --floor;
        }
        printf("%d\n", floor); 

        ++i;
    }
    return 0;
}
