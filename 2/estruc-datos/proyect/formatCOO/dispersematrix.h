/*
autores: Andres Felipe Acosta - Jose David Ruano
Implementaccion por formato coordenado
*/


#ifndef _DISPERSEMATRIX_H
#define _DISPERSEMATRIX_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <climits>
using namespace std;

class DisperseMatrix{

    // Atributos
    private:
    vector<int> valores;
    vector<int> filas;
    vector<int> columnas;
    int maxFila;
    int maxCol;

    int maxVec(vector<int> &);
  
    /************************
    * OPERACIONES DEL TAD *
    ************************/

    public:
    /* Constructoras */
    DisperseMatrix();
    DisperseMatrix(int **, int, int); 
    DisperseMatrix(vector<vector<int>>&);
    DisperseMatrix(const DisperseMatrix&);

    /* Operaciones */
    vector<vector<int>> rebuild();
    int get(int, int);
    list<pair<int, int>> getRowList(int);
    list<pair<int, int>> getColList(int);
    list<pair<int, int>> getDisperseRowList(int);
    list<pair<int, int>> getDisperseColList(int);

    vector<pair<int, int>> getRowVec(int); 
    vector<pair<int, int>> getColVec(int); 
    vector<pair<int, int>> getDisperseRowVec(int); 
    vector<pair<int, int>> getDisperseColVec(int);
    void assign(int, int, int); 
    
    void add(DisperseMatrix &); 
    void printMatrix(const string);
    void productVector(vector<int> &);
    DisperseMatrix operator+(DisperseMatrix&); 
    DisperseMatrix operator*(DisperseMatrix&); 
    bool operator==(DisperseMatrix&);
    int getMax();
    DisperseMatrix getTranspose();
    static DisperseMatrix addMatrixList(list<DisperseMatrix> &);
    void printMatrix2();

};

#endif