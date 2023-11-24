/*
 * Autor: Carlos Ramírez
 * Fecha de creación: 18 de Septiembre
 * Fecha última modificación: 18 de Septiembre
 * Versión: 1.0
 * 
 * Archivo encabezado libreria TAD Lista
 * Representación Estructuras Encadenadas Simples
 */

#ifndef __LISTA_H
#define __LISTA_H

#include <stdio.h>
#include <stdlib.h>

/************************
* ESTRUCTURAS DE DATOS *
************************/
struct nodo{
  int dato;
  struct nodo* sig;
};

typedef struct nodo* Lista;
typedef int Elemento;

/************************
* OPERACIONES DEL TAD *
************************/

/* Constructoras */
Lista crearLista();

/* Modificadoras */
Lista anxLista(Lista lst, Elemento elem);

Lista insLista(Lista lst, Elemento elem, int pos);

Lista elimLista(Lista lst, int pos);

/* Analizadoras */
Elemento infoLista(Lista lst, int pos);

int longLista(Lista lst);

int vaciaLista(Lista lst);

int binary(int key);

#endif