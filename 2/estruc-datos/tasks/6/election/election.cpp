/* 
Jose David Ruano Burbano 
Estructura de datos - tarea6 - Election
Fecha: 11/11/2023

Analisis Complejidad:

El algoritmo tiene una complejidad de O(t*(n+m)) 
donde t es el número de casos de prueba, n es el número de candidatos y m es el número de votos.

Se hacen t iteraciones para cada caso de prueba luego dentro de cada caso de prueba, 
se hacen n iteraciones para leer los datos de entrada y llenar el mapa posteriormente para cada inserción 
en el mapa se tiene una complejidad de O(log n), pero como las cadenas se insertan n veces, podemos decir que es O(n).
Luego, se hacen m iteraciones para leer los votos y actualizar el conteo de votos para cada candidato en el mapa. 
La operación de búsqueda en el mapa tiene una complejidad de O(log n), pero como estamos buscando las cadenas una vez, 
podemos considerar esta parte como O(m).Finalmente, se itera sobre el mapa para encontrar el ganador lo que es o(n).

Por lo tanto, la complejidad total del algoritmo es O(t*(n+m)).
*/

#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;
int main(){

    int t; 
    string name, party;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        cin.ignore();

        map<string, pair<string, int>> party_candidate;
        for(int j = 0; j < n; j++){
            getline(cin,name);
            getline(cin,party);
            party_candidate[name] = make_pair(party, 0);
        }
        int m;
        cin >> m;
        cin.ignore();

        for(int j = 0; j < m; j++){
            string name_vote;
            getline(cin, name_vote);
            if (party_candidate.find(name_vote) != party_candidate.end()) { 
                party_candidate[name_vote].second++;
            }
        }
        string winner;
        int max_vote = 0;
        int count = 0;
        for (map<string, pair<string, int>> :: iterator it = party_candidate.begin(); it != party_candidate.end(); it++){
            if(it->second.second > max_vote){
                max_vote = it->second.second;
                winner = it->first;
                count = 1;
            } else if(it->second.second == max_vote){
                count++;
            }
        }
        if(count > 1){
            cout << "tie" << endl ;
        }
        else{
            cout << party_candidate[winner].first << endl;
        }
        cout << endl; 
    }
    
    return 0;
}
