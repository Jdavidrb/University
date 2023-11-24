#include <stdio.h>

int main(){
    int t, n1, n2, i = 0;
    scanf("%d", &t);
    while (i < t){
        scanf("%d %d", &n1 ,&n2);
        if (n1 == n2){

            printf("=\n");
        }
        else if (n1 < n2){
            printf("<\n");
        }
        else{
            printf(">\n");
        }
        ++i;
    }   
    return 0;
}