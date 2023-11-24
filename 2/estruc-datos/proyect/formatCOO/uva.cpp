#include <iostream>
#include <vector>
#include <string>
#include "dispersematrix.h"

using namespace std;

pair<int,int> cambiarInt(char a, char b){
    pair<int,int> ans;
    ans.first = a - '0', ans.second = b - '0';
    return ans;    
}

vector<int> valoresVec(string row){
    int i;
    vector<int> ans;
    for(i=0;i<row.size();i++){
        ans.push_back(row[i] - '0');
    }
    return ans;
}

void row(DisperseMatrix &matriz, int a, int b){
    int i;
    a--, b--;
    vector<pair<int, int>> filaA = matriz.getRowVec(a);
    vector<pair<int, int>> filaB = matriz.getRowVec(b);

    for(i=0;i<filaA.size();i++){
        matriz.assign(a, filaA[i].first, filaB[i].second);
    }

    for(i=0;i<filaB.size();i++){
        matriz.assign(b, filaB[i].first, filaA[i].second);
    }

}

void col(DisperseMatrix &matriz, int a, int b){
    int i;
    a--, b--;
    vector<pair<int, int>> filaA = matriz.getColVec(a);
    vector<pair<int, int>> filaB = matriz.getColVec(b);

    for(i=0;i<filaA.size();i++){
        matriz.assign(filaA[i].first, a, filaB[i].second);
    }

    for(i=0;i<filaB.size();i++){
        matriz.assign(filaB[i].first, b , filaB[i].second);
    }
}

void inc(DisperseMatrix &matriz, int tam){
    int i, j;
    vector<vector<int>> vecAns(tam, vector<int>(tam, 1));
    DisperseMatrix ans(vecAns);
    matriz.add(ans);

    for(i=0;i<tam;i++){
        vector<pair<int, int>> get;
        get = matriz.getDisperseRowVec(i);
        for(j=0;j<get.size();j++){
            if(get[j].second == 10){
                ans.assign(i, get[j].first, 0);
            }
        }
    }

}

void dec(DisperseMatrix &matriz, int tam){
    int i, j;
    vector<vector<int>> vecAns(tam, vector<int>(tam, -1));
    DisperseMatrix ans(vecAns);
    matriz.add(ans);

    for(i=0;i<tam;i++){
        vector<pair<int, int>> get;
        get = matriz.getDisperseColVec(i);
        for(j=0;j<get.size();j++){
            if(get[i].second == -1){
                matriz.assign(i, get[j].first, 9);
            }
        }
    }
}

DisperseMatrix transpose(DisperseMatrix &matriz){
    DisperseMatrix ans;
    ans = matriz.getTranspose();
    return ans;
}

int main(){
    int casos, tam, i, j, nOperaciones, a, b, nCasos;
    string operador, valores;
    nCasos = 0;
    cin >> casos;

    while(casos > 0){
        cin >> tam;
        vector<vector<int>> matriz;
        for(i=0;i<tam;i++){
            cin >> valores;
            vector<int> filaMatriz = valoresVec(valores);
            matriz.push_back(filaMatriz);
        }

        DisperseMatrix ans(matriz);

        cin >> nOperaciones;
        
        for(i=0;i<nOperaciones;i++){
            cin >> operador;

            if(operador[0] == 'r'){
                cin >> a >> b;
                row(ans,a,b);
            }

            else if(operador[0] == 'c'){
                cin >> a >> b;
                col(ans,a,b);

            }
            else if(operador[0] == 'i'){
                inc(ans,tam);

            }
            else if(operador[0] == 'd'){
                dec(ans,tam);

            }
            else if(operador[0] == 't'){
                ans = ans.getTranspose();
            }
        }
        cout << "Case #" << nCasos << endl;
        ans.printMatrix("");
        cout << endl;
        nCasos++;
        


        casos--;
    }
}