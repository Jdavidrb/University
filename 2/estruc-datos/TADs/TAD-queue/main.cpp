/*
Autor: Carlos Ramírez
Fecha: Abril 28 de 2023

Ejemplo de uso de la implementación del TAD Cola

 */

#include <cstdio>
#include <queue>
#include <string>
//#include "stack/cola.h"
//#include "vectors/cola.h"
#include "lists/cola.h"

class Estudiante{
   public:
      string nombre, codigo;
      double nota;

      Estudiante(){}
      Estudiante(string n, string c, double d){
	nombre = n;
	codigo = c;
	nota = d;
      }
};

void imprimirElementos(Queue &c){
  while(!c.empty()){
     printf("%d\n",  c.front());
     c.pop();
  }
}

void imprimirElementos(queue<int> &que){
  while(!que.empty()){
      printf("%d\n",  que.front());
      que.pop();
  }
}

double promedioEstudiantes(queue<Estudiante> &q){
   double ans = 0;
   int tam = q.size();
   Estudiante est;
   while(!q.empty()){
      est = q.front();
      ans += est.nota;
      q.pop();
   }

   ans /= tam;
   return ans;
}

int main(){
   Queue c;
   c.push(1);
   c.push(4);
   c.push(6);
   c.push(8);
   imprimirElementos(c);
   if(c.empty()){
      printf("El profesor dijo la verdad y la cola quedó vaciá\n");
   }
   else{
      printf("El profesor mintió y creo que no sabe de estructuras\n");
   }

   queue<int> q;
   q.push(4);
   q.push(10);
   q.push(8);
   q.push(7);
   q.push(9);
   imprimirElementos(q);

   queue<Estudiante> colaEst;
   colaEst.push(Estudiante("Cartman", "3323232", 1.5));
   colaEst.push(Estudiante("Butters", "4434343", 4.5));
   colaEst.push(Estudiante("Kyle", "111111", 3.5));
   colaEst.push(Estudiante("Kenny", "2221211", 2.5));

   double res = promedioEstudiantes(colaEst);
   printf("Promedio = %.3f\n", res);
   return 0;
}
