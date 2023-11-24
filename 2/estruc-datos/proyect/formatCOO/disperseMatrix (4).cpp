#include "dispersematrix.h"
#include <iostream>
#include <vector>
#include <string>

DisperseMatrix :: DisperseMatrix(){};

DisperseMatrix::DisperseMatrix(int** mat, int fila, int columna){
    int i, j;
    for(i=0;i<fila;i++){
        for(j=0;j<columna;j++) {
            if(mat[i][j] != 0) {
                valores.push_back(mat[i][j]);
                filas.push_back(i);
                columnas.push_back(j);
            }
        }
    }
    maxFila = fila;
    maxCol = columna;
}

DisperseMatrix :: DisperseMatrix(vector<vector<int>>& mat){
    int i, j;
    for(i=0;i<mat.size();i++){
        for(j=0;j<mat[i].size();j++){
            if(mat[i][j] != 0){ 
                filas.push_back(i);
                columnas.push_back(j);
                valores.push_back(mat[i][j]);
            }
        }
    }
    maxCol = mat[0].size();
    maxFila = mat.size();
}

DisperseMatrix :: DisperseMatrix(const DisperseMatrix &mat){
    int i;
    for(i=0;i<mat.valores.size();i++){
        valores.push_back(mat.valores[i]);
        filas.push_back(mat.filas[i]);
        columnas.push_back(mat.columnas[i]);
    }
    maxFila = mat.maxFila;
    maxCol = mat.maxCol;
}

vector<vector<int>> DisperseMatrix::rebuild(){
    int i, j, count;
    count = 0;
    vector<vector<int>> matriz;
    for(i=0;i<maxFila;i++){
        vector<int> tmp;
        for(j=0;j<maxCol;j++){
            if(!valores.empty() && filas[count] == i && columnas[count] == j && count < valores.size()){
                tmp.push_back(valores[count]);
                count++;
            }
            else{
                tmp.push_back(0);
            }
        }
        matriz.push_back(tmp);
    }
    return matriz;
}

int DisperseMatrix :: get(int i, int j){
    int h, ans = 0;
    for(h=0;h<valores.size();h++){
        if(filas[h] == i && columnas[h] == j){
            ans = valores[h];  
        }
    }   
    return ans;
}

list<pair<int, int>> DisperseMatrix :: getDisperseRowList(int j){
    int i;
    list<pair<int, int>> ans;

    for(i=0;i<valores.size();i++){
        if(filas[i] == j){
            ans.push_back(make_pair(columnas[i], valores[i]));
        }
    }
    return ans;
}
vector<pair<int,int>> DisperseMatrix :: getDisperseRowVec(int j){ 
    int i;
    vector<pair<int,int>> ans;

    for(i=0;i<valores.size();i++){
        if(filas[i] == j){
            ans.push_back(make_pair(columnas[i], valores[i]));
        }  
    }
    return ans;
}

list<pair<int, int>> DisperseMatrix :: getDisperseColList(int j){ 
    int i;
    list<pair<int, int>> ans;

    for(i=0;i<valores.size(); i++){
        if(columnas[i] == j){
            ans.push_back(make_pair(filas[i], valores[i]));
        }
    }
    return ans;
}


vector<pair<int, int>> DisperseMatrix :: getDisperseColVec(int j){ //REVISAR
    int i;
    vector<pair<int, int>> ans;

    for(i=0;i<valores.size(); i++){
        if(columnas[i] == j){
            ans.push_back(make_pair(filas[i], valores[i]));
        }
    }

    return ans;
}


list<pair<int, int>> DisperseMatrix :: getRowList(int j){ //REVISAR
    int i, k;
    list<pair<int, int>> ans;

    for(i=0;i<maxCol;i++){
        ans.push_back(make_pair(i,0));
    }

    if(j<maxFila){
        for(i=0;i<valores.size();i++){
            if(filas[i] == j){
                pair<int, int> tmp;
                tmp.first = columnas[i];
                tmp.second = valores[i];
                
                list<pair<int, int>>::iterator it = ans.begin();
                for(k=0;k<columnas[i];k++){
                    it++;
                }
                *it = tmp;
            }
        }   
    }
    else{
        ans.clear();  
    } 

    return ans;  
}

vector<pair<int, int>> DisperseMatrix :: getRowVec(int j){ //REVISAR
    int i;
    vector<pair<int, int>> ans;

    for(i=0;i<maxCol;i++){
        ans.push_back(make_pair(i,0));
    }

    if(j<maxFila){
        for(i=0;i<valores.size();i++){
            if(filas[i] == j){
                pair<int, int> tmp;
                tmp.first = columnas[i];
                tmp.second = valores[i];
                ans[columnas[i]] = tmp;
            }
        }   
    }
    else{
        ans.clear();
    } 

    return ans;  
}

list<pair<int, int>> DisperseMatrix :: getColList(int j){ //REVISAR
    int i, k;
    list<pair<int, int>> ans;

    for(i=0;i<maxFila;i++){
        pair<int, int> tmp;
        tmp.first = i;
        tmp.second = 0;
        ans.push_back(tmp);
    }
    if(j<maxCol){
        for(i=0;i<valores.size();i++){
            if(columnas[i] == j){
                pair<int, int> tmp;
                tmp.first = filas[i];
                tmp.second = valores[i];
                
                list<pair<int, int>>::iterator it = ans.begin();
                for(k=0;k < filas[i];k++) {
                    it++;
                }
                *it = tmp; 
            }
        }   
    }
    else{
        ans.clear();
    } 

    return ans;  
}

vector<pair<int, int>> DisperseMatrix :: getColVec(int j){ //REVISAR
    int i;
    vector<pair<int, int>> ans;

    for(i=0;i<maxFila;i++){
        pair <int, int> tmp;
        tmp.first = i;
        tmp.second = 0;
        ans.push_back(tmp);
    }

    if(j<maxCol){
        for(i=0;i<valores.size(); i++){
            if(columnas[i] == j){
                pair <int, int> tmp;
                tmp.first = filas[i];
                tmp.second = valores[i];
                ans[filas[i]] = tmp;
            }
        }
    }
    else{
        ans.clear();
    } 

    return ans;
}

void DisperseMatrix::assign(int i, int j, int valor){
    int h, indice;
    bool flag;

    if(i < maxFila && j < maxCol){
        flag = true;
        for(h=0;h<filas.size() && flag;h++){
            if(filas[h] == i && columnas[h] == j){
                if(valor != 0){
                    valores[h] = valor;
                }
                else{
                    valores.erase(valores.begin()+h);
                    filas.erase(filas.begin()+h);
                    columnas.erase(columnas.begin()+h);
                }
                flag = false;
            }
        }

        if(flag && valor != 0){
            indice = 0;
            while(indice < filas.size() && filas[indice] < i){
                indice++;
            }
            valores.insert(valores.begin()+indice, valor);
            filas.insert(filas.begin()+indice, i);
            columnas.insert(columnas.begin()+indice, j);
        }
    }
}//revisar. 


void DisperseMatrix::add(DisperseMatrix &m){
    int i, j, valor1, valor2, suma, fila, columna, f1, c1, f2, c2, indice1, indice2;
    bool flag = true;
    f1 = 0, f2 = 0, suma = 0, indice1 = 0, indice2 = 0;
    vector<int> valorescopy, filascopy, columnascopy;
    valorescopy = valores, filascopy = filas, columnascopy = columnas;

    valores.clear();
    filas.clear();
    columnas.clear();

    for(i=0;i<maxFila;i++){
        c1 = 0;
        c2 = 0;
        for(j=0;j<maxCol;j++){
            valor1 = 0, valor2 = 0;

            if(filascopy[indice1] == f1 && columnascopy[indice1] == c1){
                valor1 = valorescopy[indice1];
            }

            if(m.filas[indice2] == f2 && m.columnas[indice2] == c2){
                valor2 = m.valores[indice2];
            }

            suma = valor1 + valor2;

            if(suma != 0){
                valores.push_back(suma);
                filas.push_back(f2);
                columnas.push_back(c2);
            }

            if(indice1 < valorescopy.size() && valor1 != 0){
                indice1++;
            }

            if(indice2 < m.valores.size() && valor2 != 0){
                indice2++;
            }

            c1++;
            c2++;
        }
        f1++;
        f2++;
    } 
}


void DisperseMatrix::printMatrix(string separador){ 
    int i, j, indice;
    indice = 0;

    for(i=0;i<maxFila;i++){
        for(j=0;j<maxCol;j++){
            if(indice < valores.size() && filas[indice] == i && columnas[indice] == j){
                cout << valores[indice];
                if(j != maxCol-1) cout << separador;
                indice++;
            }
            else{
                cout << 0;
                if(j != maxCol-1) cout << separador;
            }
        }
        cout << endl;
    }
}

void DisperseMatrix::productVector(vector<int> & vec){
    int i, j, result;

    for(i=0;i<vec.size();i++){
        for(j=0;j<valores.size();j++){
            if(columnas[j] == i){
                result = vec[i] * valores[j];
                if(result != 0){
                    valores[j] = result;
                }
                else{
                    valores.erase(valores.begin()+j);
                    filas.erase(filas.begin()+j);
                    columnas.erase(columnas.begin()+j);

                }
            }
            
        }
    }
}

DisperseMatrix DisperseMatrix :: operator+(DisperseMatrix &m){
    DisperseMatrix ans;
    int i, j, valor1, valor2, suma, filasMax, columnasMax, fila2, columna2, f1, c1, f2, c2, indice1, indice2, tmpFila1 , tmpColumna1, tmpFila2, tmpColumna2;
    f1 = 0, c1 = 0, f2 = 0, c2 = 0, suma = 0, indice1 = 0, indice2 = 0;

    filasMax = max(maxFila, m.maxFila), columnasMax = max(maxCol, m.maxCol);
    ans.maxFila = filasMax, ans.maxCol = columnasMax; 
    ans.maxFila = filasMax, ans.maxCol = columnasMax;

    for(i=0;i<filasMax;i++){
        c1 = 0;
        c2 = 0;
        for(j=0;j<columnasMax;j++){
            valor1 = 0, valor2 = 0;

            if(indice1 < filas.size()){
                if(filas[indice1] == f1 && columnas[indice1] == c1){
                    valor1 = valores[indice1];
                    indice1++;
                }
            }     

            if(indice2 < m.filas.size()){
                if(m.filas[indice2] == f2 && m.columnas[indice2] == c2){
                    valor2 = m.valores[indice2];
                    indice2++;
                }
            }

            suma = valor1 + valor2;

            if(suma != 0){
                ans.valores.push_back(suma);
                ans.filas.push_back(f2);
                ans.columnas.push_back(c2);
            }

            c1++;
            c2++;
        }
        
        f1++;
        f2++;
    } 

    return ans;
}

DisperseMatrix DisperseMatrix :: operator*(DisperseMatrix &m){
    DisperseMatrix ans;
    int tmpFilasM1, tmpColumM1, tmpFilasM2, tmpColumM2 , filas1, columnas1, filas2,columnas2, valor1, 
    valor2, multiplicacion, suma, cantidadValores, noCeros, numEliminaciones, cantCerosFilas, aux_i;
    int i, j, h,count_j, count_h;
    int filasMax, columnasMax;
    bool flag_i ,flag_j ;

    tmpFilasM1 = maxFila, tmpFilasM2 = m.maxFila;
    tmpColumM1 = maxCol, tmpColumM2 = m.maxCol;
    filasMax = max(tmpFilasM1, tmpFilasM2), columnasMax = max(tmpColumM1, tmpColumM2);

    ans.maxFila = tmpFilasM1, ans.maxCol = tmpColumM2;

    for(i=0;i<filasMax;i++){
        for(j=0;j<columnasMax;j++){
            suma = 0;
            for(h=0;h<filasMax;h++){
                valor1 = 0, valor2 = 0;
                valor1 = this->get(i,h);
                valor2 = m.get(h,j);
                suma += (valor1 * valor2);

            }
            if(suma != 0){
                ans.valores.push_back(suma);
                ans.filas.push_back(i);
                ans.columnas.push_back(j);
            }
        }
    }

    return ans;
}

bool DisperseMatrix :: operator==(DisperseMatrix &m){
    int i;
    bool ans = true;

    if(valores.size() == m.valores.size()){
        for(i=0;i<valores.size() && ans;i++){
            if(valores[i] == m.valores[i] && filas[i] == m.filas[i] && columnas[i] == m.columnas[i]){
                ans = true;
            }
            else{
                ans = false;
            }

        }
    }
    
    else{
        ans = false;
    }

    return ans;
}

int DisperseMatrix :: getMax(){ 
    int i, ans;
    ans = INT_MIN;
    for(i=0;i<valores.size();i++){
        if(valores[i] > ans) ans = valores[i];
    }
    
    return ans;
}

DisperseMatrix DisperseMatrix :: getTranspose(){
    int i, j, fila, columna;
    fila = maxVec(filas), columna = maxVec(columnas);
    DisperseMatrix ans;
    ans.maxFila = maxCol, ans.maxCol = maxFila;

    ans.valores.push_back(valores[0]);
    ans.filas.push_back(columnas[0]);
    ans.columnas.push_back(filas[0]);

    for(i=1;i<valores.size();i++){
        if(columnas[i] >= ans.filas[i-1]){
            ans.valores.push_back(valores[i]);
            ans.filas.push_back(columnas[i]);
            ans.columnas.push_back(filas[i]);
        }

        else{
            bool encontrado = true;
            for(j=0;j<ans.valores.size() && encontrado;j++){
                if(columnas[i] < ans.filas[j]){
                    ans.valores.insert(ans.valores.begin()+j, valores[i]);
                    ans.filas.insert(ans.filas.begin()+j, columnas[i]);
                    ans.columnas.insert(ans.columnas.begin()+j, filas[i]);
                    encontrado = false;
                }
            }
        }
    }

    return ans;
}    

DisperseMatrix DisperseMatrix :: addMatrixList(list<DisperseMatrix> &matrices){
    list<DisperseMatrix>::iterator iter = matrices.begin();
    DisperseMatrix ans = *iter;
    iter++;

    while(iter != matrices.end()){
        ans = ans + *iter;
        iter++;
    }

    return ans;
}

/* Adicionales */

int DisperseMatrix::maxVec(vector<int> &m){
    int ans, i;
    ans = 0;

    if(!m.empty()){
        ans = m[0];

        for(i=1;i<m.size();i++){
            if(m[i] > ans) ans = m[i];
        }
        ans++;
    }

    return ans;
}