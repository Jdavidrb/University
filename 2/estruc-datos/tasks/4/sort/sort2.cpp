#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Comparador {
public:
    Comparador(const string& guia);
    bool operator()(const string& ordenar1, const string& ordenar2);

private:
    string guia_;
};

Comparador::Comparador(const string& guia) {
    this->guia_ = guia;
}

bool Comparador::operator()(const string& ordenar1, const string& ordenar2) {
    int n;
    if (ordenar1.size() < ordenar2.size()) {
        n = ordenar1.size();
    } else {
        n = ordenar2.size();
    }
    
    for (int i = 0; i < n; ++i) {
        string::iterator pos_caracter1 = find(guia_.begin(), guia_.end(), ordenar1[i]);
        string::iterator pos_caracter2 = find(guia_.begin(), guia_.end(), ordenar2[i]);
        if (pos_caracter1 != pos_caracter2) {
            return pos_caracter1 < pos_caracter2;
        }
    }
    return ordenar1.size() < ordenar2.size();
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        string palabra_guia;
        cin >> palabra_guia;
        int n;
        cin >> n;
        vector<string> palabras(n);
        for(int j = 0; j < n; ++j){
            cin >> palabras[j];
        }
        
        sort(palabras.begin(), palabras.end(), Comparador(palabra_guia));

        for(int j = 0; j < n; ++j){
            cout << palabras[j] << endl;
        }
        cout << endl;

    }
    return 0;
        
}
