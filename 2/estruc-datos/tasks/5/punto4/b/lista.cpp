#include "lista.h"

Lista::Lista(){
  act = NULL;
}



void Lista::insLista(Elemento elem, int pos){
  Nodo *nuevo, *tmp;
  nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(pos >= 1 && pos <= longLista()){
    if(pos == 1){
      nuevo->sig = act;
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
  Nodo *tmp, *elim;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1)
      act = act->sig;
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
  Nodo* tmp = act;
  int cont = 0;

  while(tmp != NULL){
    tmp = tmp->sig;
    cont++;
  }

  return cont;
}

bool Lista::vaciaLista(){
  return act == NULL;
}


void Lista::anxLista(Elemento elem){
  Nodo* tmp;
  Nodo* nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;

  if(act == NULL)
    act = nuevo;
  else{
    tmp = act;
    while(tmp->sig != NULL)
      tmp = tmp->sig;
    tmp->sig = nuevo;
  }
}


Lista Lista::operator - (Lista &l) {
  
  Lista l3;
  

  Nodo *tmp3;
  Nodo *tmp = act;

  while (tmp != NULL) {
    Nodo *tmp2 = l.act;
    int aux = 0;
    bool flag = true;
    while (tmp2 != NULL && flag) {
      if (tmp->dato == tmp2->dato) {
        aux++;
        flag = false;  // cuando se encuentra una coincidencia en la lista2
      }
      tmp2 = tmp2->sig;
    }
    if (aux == 0) {
        
        Nodo *nuevo = new Nodo;
        
        nuevo->dato = tmp->dato;
        nuevo ->sig = NULL;

      if (l3.act == NULL){
        l3.act = nuevo;
      }

      else{
        tmp3 = l3.act;
        while(tmp3->sig != NULL)
          tmp3 = tmp3->sig;
        tmp3->sig = nuevo;

      }
      
    }

    tmp = tmp->sig;
  }

  return l3;
}
