/*
Autor: Carlos Ramírez
Fecha: Abril 28 de 2023

Ejemplo de uso del TAD Pila

 */

#include <cstdio>
//#include "vector1/pila.h"
//#include "vector2/pila.h"
//#include "lists/pila.h"
#include "queue/pila.h"

int contarElementos(Stack &p){
    int ans = 0;
    while(!p.empty()){
      printf("%d\n", p.peek());
       ans += 1;
       p.pop();
    }
    return ans;
}

int main(){
   Stack p;
   p.push(10);
   p.push(3);
   p.push(5);
   p.push(2);
   p.push(11);

   int c = contarElementos(p);
   printf("Cantidad de elementos en la pila: %d\n", c);
   if(p.empty())
      printf("La pila quedó vacía\n");
   return 0;
}
