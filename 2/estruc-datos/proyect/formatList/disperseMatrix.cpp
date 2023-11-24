#include "dispersematrix.h"

// constructores

DisperseMatrix :: DisperseMatrix(){}

DisperseMatrix :: DisperseMatrix(int ** matriz, int fila, int columna){
    int i, j;
    maxFila = 0, maxCol = 0;
    for(i=0;i<fila;i++){
        deque<pair<int, int>> tmpValores;
        for(j=0;j<columna;j++){
            if(matriz[i][j] != 0){
                tmpValores.push_back(make_pair(matriz[i][j], j));
            }
        }
        disperse.push_back(tmpValores);
    }
    maxFila = fila;
    maxCol = columna;
}

DisperseMatrix :: DisperseMatrix(vector<vector<int>> & matriz){
    int i, j;
    for(i=0;i<matriz.size();i++){
        deque<pair<int, int>> tmpValores;
        for(j=0;j<matriz[i].size();j++){
            if(matriz[i][j] != 0){
                tmpValores.push_back(make_pair(matriz[i][j], j));
            }
        }
        disperse.push_back(tmpValores);

    }
    maxFila = matriz.size();
    maxCol = matriz[0].size();
}

DisperseMatrix :: DisperseMatrix(const DisperseMatrix &matriz){
    int i, j;

    for(i=0;i<matriz.disperse.size();i++){
        deque<pair<int, int>> tmpValores;
        for(j=0;j<matriz.disperse[i].size();j++){
            tmpValores.push_back(make_pair(matriz.disperse[i][j].first, matriz.disperse[i][j].second));
        }
        disperse.push_back(tmpValores);
    }
    maxFila = matriz.maxFila;
    maxCol = matriz.maxCol;
}

vector<vector<int>> DisperseMatrix::rebuild(){ //CAMBIAR EL ITERADOR
    int i, j;
    vector<vector<int>> matriz(maxFila, vector<int>(maxCol, 0));

    for(i=0;i<disperse.size();i++) {
        for(j=0;j<disperse[i].size();j++){
            matriz[i][disperse[i][j].second] = disperse[i][j].first;
        }
    }

    return matriz;
}

int DisperseMatrix::get(int i, int j) {
    int ans = 0, h;
    for(h=0;h<disperse[i].size();h++){
        if(disperse[i][h].second == j){
            ans = disperse[i][h].first;
        }
    }

    return ans;
}

list<pair<int, int>> DisperseMatrix:: getDisperseRowList(int j) {
    int i;
    list<pair<int, int>> ans;
    for(i=0;i<disperse[j].size();i++){
        ans.push_back(make_pair(disperse[j][i].second, disperse[j][i].first));
    }
    
    return ans;
}

vector<pair<int, int>> DisperseMatrix:: getDisperseRowVec(int j) {
    int i;
    vector<pair<int, int>> ans;
    for(i=0;i<disperse[j].size();i++){
        ans.push_back(make_pair(disperse[j][i].second, disperse[j][i].first));
    }

    return ans;
}

list<pair<int, int>> DisperseMatrix::getDisperseColList(int j) {
    int i, h;
    list<pair<int, int>> ans;
    for(i=0;i<disperse.size();i++){
        for(h=0;h<disperse[i].size();h++){
            if(disperse[i][h].second == j){
                ans.push_back(make_pair(i, disperse[i][h].first));
            }
        }
    }
    
    return ans;
}

vector<pair<int, int>> DisperseMatrix::getDisperseColVec(int j) {
    int i, h;
    vector<pair<int, int>> ans;
    for(i=0;i<disperse.size();i++){
        for(h=0;h<disperse[i].size();h++){
            if(disperse[i][h].second == j){
                ans.push_back(make_pair(i, disperse[i][h].first));
            }
        }
    }
    return ans;
}

list<pair<int, int>> DisperseMatrix::getRowList(int j) {
    int i, h, valor;
    list<pair<int, int>> ans;
    bool flag;
    
    if(j < maxFila){
        for(i=0;i<maxCol;i++){
            flag = true;
            valor = 0;

            for(h=0;h<disperse[j].size() && flag;h++){
                if(disperse[j][h].second == i){
                    valor = disperse[j][h].first;
                    flag = false;
                }
            }

            ans.push_back(make_pair(i, valor));
        }
    }
  
    return ans;
}

vector<pair<int, int>> DisperseMatrix::getRowVec(int j) {
    int i, h, valor;
    vector<pair<int, int>> ans;
    bool flag;
    if(j < maxFila){
        for(i=0;i<maxCol;i++){
            flag = true;
            valor = 0;
            for(h=0;h<disperse[j].size() && flag;h++){
                if(disperse[j][h].second == i){
                    valor = disperse[j][h].first;
                    flag = false;
                }
            }
            ans.push_back(make_pair(i, valor));
        }
    }

    return ans;
}

list<pair<int, int>> DisperseMatrix::getColList(int j){
    int i, h, valor;
    list<pair<int, int>> ans;
    bool flag;
    if(j < maxCol){
        for(i=0;i<maxFila;i++){
            flag = true;
            valor = 0;
            for(h=0;h<disperse[i].size() && flag;h++){
                if(disperse[i][h].second == j){
                    valor = disperse[i][h].first;
                    flag = false;
                }
            }
            ans.push_back(make_pair(i, valor));
        }
    }
    
    return ans;
}

vector<pair<int, int>> DisperseMatrix::getColVec(int j) {
    vector<pair<int, int>> ans;
    int i, h, valor;
    bool flag;
    if(j < maxCol){
        for(i=0;i<maxFila;i++){
            flag = true;
            valor = 0;
            for(h=0;h<disperse[i].size() && flag;h++){
                if(disperse[i][h].second == j){
                    valor = disperse[i][h].first;
                    flag = false;
                }
            }
            ans.push_back(make_pair(i, valor));
        }
    }
    return ans;
}
    
void DisperseMatrix::assign(int i, int j, int valor){
    if(i < maxFila && j < maxCol){
        bool flag = true;
        int h;
        for(h = 0; h < disperse[i].size() && flag; h++){
            if(disperse[i][h].second == j){
                if(valor != 0){
                    disperse[i][h].first = valor;
                }
                else{
                    disperse[i].erase(disperse[i].begin()+h);
                }
                flag = false;
            }
        }

        if(flag && valor != 0){
            pair<int, int> p = make_pair(valor, j);
            int pos = 0;
            while(pos < disperse[i].size() && disperse[i][pos].second < j){
                pos++;
            }
            disperse[i].insert(disperse[i].begin()+pos, p);
        }
    }
}

// FALTA EL ADD
void DisperseMatrix:: add(DisperseMatrix &m){
    vector<deque<pair<int,int>>> disperseCpy = disperse;
    int i, j, count1, count2, valor1, valor2, filas, columnas;
    filas = maxFila , columnas = maxCol;            
    bool flag;
   
    disperse.clear();

    

    for(i=0; i < filas; i++){
        count1 = 0, count2 = 0, flag = true;
        deque<pair<int,int>> aux;
        if(disperseCpy[i].empty()){
            flag = false;
            aux = m.disperse[i];
        }
        else if(m.disperse[i].empty()){
            flag = false;
            aux = disperseCpy[i];
        }
        for(j = 0; j < columnas && flag; j++){
            pair<int,int> auxPair;
            if(disperseCpy[i][count1].second == j)
                valor1 = disperseCpy[i][count1].first;
            else 
                valor1 = 0;
            if(m.disperse[i][count2].second == j)
                valor2 = m.disperse[i][count2].first;
            else 
                valor2 = 0;
            
            int sum = valor1 + valor2;
            auxPair.first = sum;
            auxPair.second = j;
            if(sum != 0)
                aux.push_back(auxPair);
            if(valor1 != 0 && count1 < disperseCpy[i].size() -1) 
                count1++;
            if(valor2 != 0 && count2 < m.disperse[i].size() -1)
                count2++;
        }
        disperse.push_back(aux);
    }
   
}

void DisperseMatrix::printMatrix(string separador) {
    vector<vector<int>> matriz = this->rebuild();
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[i].size(); j++) {
            cout << matriz[i][j];
            if (j != matriz[i].size() - 1) {
                cout << separador;
            }
        }
        cout << endl;
    }
}

int DisperseMatrix :: maxPares(vector<deque<pair<int,int>>> &m){
    int i, j, max;
    max = 0;
    for(i=0;i<m.size();i++){
        for(j=0;j<m[i].size();j++){
            if(max < m[i][j].second){
                max = m[i][j].second;
            }
        }
    }
    max++;
    return max;
}

void DisperseMatrix::productVector(vector<int> & vec){
    int i, j, h, result;

    for(h=0;h<vec.size();h++){
        for(i=0;i<disperse.size();i++){
            for(j=0;j<disperse[i].size();j++){
                if(disperse[i][j].second == h){
                    result = vec[h] * disperse[i][j].first;

                    if(result != 0){
                        disperse[i][j].first = result;
                    }

                    else{
                        disperse[i].erase(disperse[i].begin()+j);
                    }
                }
            }
        }
    }
    
}

DisperseMatrix DisperseMatrix :: operator+(DisperseMatrix &m){
    DisperseMatrix ans;
    int i,j, count1, count2;
    int filas = max(maxFila, m.maxFila), columnas = max(maxCol, m.maxCol);
    ans.maxFila = filas, ans.maxCol = columnas;
    bool flag_j;
    int valor1;
    int valor2;
    for(i = 0; i < filas; i++){ 
        count1 = 0 , count2 = 0;
        deque<pair<int,int>> aux;
        flag_j = true;
        if(i >= maxFila || disperse[i].empty()){
            flag_j = false;
            aux = m.disperse[i];
        }
        else if(i >= m.maxFila || m.disperse[i].empty()){
            flag_j = false;
            aux = disperse[i];
        }
        else if(disperse[i].empty() && m.disperse[i].empty())
        flag_j = false;
        for(j = 0; j < columnas && flag_j; j++){
            pair<int,int> auxPair;
            if(disperse[i][count1].second == j)
                valor1 = disperse[i][count1].first;
            else
                valor1 = 0;
            if(m.disperse[i][count2].second == j)
                valor2 = m.disperse[i][count2].first;
            else
                valor2 = 0;
            int sum = valor1 + valor2;
            auxPair.first = sum;
            auxPair.second = j;
            if(sum != 0  ){
                aux.push_back(auxPair);
            }
            if(valor1 != 0 && count1 < disperse[i].size() -1) 
                count1++;
            if(valor2 != 0 && count2 < m.disperse[i].size() -1)
                count2++;
        }
        ans.disperse.push_back(aux);
    }
    return ans;
}

DisperseMatrix DisperseMatrix::operator*(DisperseMatrix &m) {
    DisperseMatrix ans;
    ans.maxFila = maxFila;
    ans.maxCol = m.maxCol;

    for (int i = 0; i < maxFila; ++i) {
        deque<pair<int, int>> auxVec;

        for (int j = 0; j < m.maxCol; ++j) {
            int sum = 0;

            for (int h = 0; h < disperse[i].size(); ++h) {
                int colIdx = disperse[i][h].second;
                int val1 = disperse[i][h].first;
                int val2 = m.get(colIdx, j);

                sum += val1 * val2;
            }

            if (sum != 0) {
                auxVec.push_back(make_pair(sum, j));
            }
        }

        ans.disperse.push_back(auxVec);
    }

    return ans;
}

bool DisperseMatrix :: operator==(DisperseMatrix &m){
    int i, j;
    bool ans = true;

    if(disperse.size() == m.disperse.size()){
        for(i=0;i<disperse.size() && ans;i++){
            if(disperse[i].size() == m.disperse[i].size()){
                for(j=0;j<disperse[i].size() && ans;j++){
                    if(disperse[i][j].first != m.disperse[i][j].first && disperse[i][j].second != m.disperse[i][j].second){
                        ans = false;
                    }
                }
            }
            else{
                ans = false;
            }
        }
    }
    
    return ans;
}

int DisperseMatrix::getMax() {
    int i, j, ans;
    ans = INT_MIN;
    
    for(i=0;i<disperse.size();i++){
        for(j=0;j<disperse[i].size();j++){
            if(disperse[i][j].first > ans){
                ans = disperse[i][j].first;
            }
        }
    }

    return ans;
}

DisperseMatrix DisperseMatrix::getTranspose() {
    int i, j;
    DisperseMatrix ans;
    ans.maxFila = maxCol;
    ans.maxCol = maxFila;

    for(i=0;i<disperse.size(); i++){
        for(j=0;j<disperse[i].size();j++){
            if(disperse[i][j].second < ans.disperse.size()){
                ans.disperse[disperse[i][j].second].push_back(make_pair(disperse[i][j].first, i));
            }

            else{
                while(disperse[i][j].second >= ans.disperse.size()){
                    ans.disperse.push_back(deque<pair<int, int>>());
                }
                ans.disperse[disperse[i][j].second].push_back(make_pair(disperse[i][j].first, i));
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
        //ans.printMatrix("-");
        iter++;
    }

    return ans;
}


