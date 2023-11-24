#include <stdio.h>

int main(){
    int t, n, k, p, j, i;
    int caso_actual = 1;

    scanf("%d\n", &t);

    while (caso_actual <= t){
        
        scanf("%d %d %d", &n, &k, &p);
        int arr[n];
        for (i = 0; i < n; i++){
            arr[i] = i + 1;
        }

        for (j = 0; j < p; j++){

            arr[k-1]++;
            if (arr[k-1] > n){
                
                arr[k-1] = 1;
            }


        }
        printf("Case %d: %d\n", caso_actual, arr[k - 1]);

        ++caso_actual;
    }



    return 0;
}