#include "lista.h"

Lista::Lista(){
  act = NULL;
}

void Lista::anxLista(Elemento elem){
  Nodo *tmp, *primero;
  Nodo* nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = nuevo;

  if(act == NULL)
    act = nuevo;
  else{
    tmp = act;
    primero = act;
    while(tmp->sig != primero)
      tmp = tmp->sig;
    tmp->sig = nuevo;
    nuevo->sig = primero;
  }
}

void Lista::insLista(Elemento elem, int pos){
  Nodo *nuevo, *tmp, *primero;
  nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(pos >= 1 && pos <= longLista()){
    if(pos == 1){
      primero = act;
      tmp = act;

      while(tmp->sig != primero){
        tmp = tmp->sig;
      }

      nuevo->sig = act;
      tmp->sig = nuevo;
      act = nuevo;
    }
    else{
      tmp = act;
      for(int i = 0; i < pos - 2; i++)
        tmp = tmp->sig;
      nuevo->sig = tmp->sig;
      tmp->sig = nuevo;
    }
  }
}

void Lista::elimLista(int pos){
  Nodo *tmp, *aux, *elim;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1){
      aux = act;
      act = act->sig;
      tmp = act;

      while(tmp->sig != aux){
        tmp = tmp->sig;
      }
      
      tmp->sig = act;
      delete aux;
    }
    else{
      tmp = act;
      for(int i = 0; i < pos-2; i++)
          tmp = tmp->sig;
      elim = tmp->sig;
      tmp->sig = tmp->sig->sig;
      delete elim;
    }
  }
}

Elemento Lista::infoLista(int pos){
   Nodo* tmp = act;
   
   for(int i = 1; i < pos; i++)
      tmp = tmp->sig;
      
   return tmp->dato;
}

int Lista::longLista(){
  int ans;
  if(vaciaLista())
    ans = 0;
  else{
    Nodo *tmp, *primero;
    int cont = 1;
    tmp = act;
    primero = act;
    
    while(tmp->sig != primero){
      tmp = tmp->sig;
      cont++;
    }
    
    ans = cont;
  }

  return ans;
} 

bool Lista::vaciaLista(){
  return act == NULL;
}
