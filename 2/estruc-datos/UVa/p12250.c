#include <stdio.h>

int main(){
    int i, flag = 1;
    char ans[8];
    char *languages[] = {"HOLA", "HELLO", "HALLO", "BONJOUR", "ZDRAVSTVUJTE"}; 
    char arr[15];
    char *countries[] = {"SPANISH", "ENGLISH", "GERMAN", "ITALIAN", "RUSSIAN"};
    

    /* LEER UNA CADENA DE CARACTERES HASTA QUE SE PRESIONE ENTER */
    scanf("%s", arr);
    
    for (i = 0; i < 5 && flag == 1; i++){
        if (arr == languages[i]){
            
            *ans = countries[i];
            flag = 0;
        }

    }
    printf("%s", ans);


    return 0;
}