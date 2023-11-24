#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Creamos la clase
class torneo{ 
    private:
        string nombre;
        vector<string> equipos;
        vector<int> puntos_obtenidos;
        vector<int> partidos_jugados;
        vector<int> victorias;
        vector<int> empates;
        vector<int> derrotas;
        vector<int> goles_marcados;
        vector<int> goles_encontra;

    public: 
        void inicializacion (string nombre, int T);
        void setNombreEquipo(int indice, string nombreEquipo);
        
        void setPartidosJugados(int indice);
        void setVictorias (int indice);
        void setEmpates (int indice);
        void setDerrotas(int indice);
        void setGolesMarcados(int indice, int goles);
        void setGolesEncontra(int indice, int goles);

        vector<int> getPuntosObtenidos();
        vector<int> getPartidosJugados();
        vector<int> getVictorias();
        vector<int> getEmpates();
        vector<int> getDerrotas();
        vector<int> getGolesMarcados();
        vector<int> getGolesEncontra();
        

        string getNombreEquipo (int indice);
        vector<string> getEquipos();
        void imprimir(string nombreTorneo, int T);

    
};
// definimos las funciones

void torneo::inicializacion (string nombre, int T){
    this ->nombre = nombre;
    this ->equipos = vector<string>(T);
    this ->puntos_obtenidos = vector<int>(T, 0); 
    this ->partidos_jugados = vector<int>(T, 0); 
    this ->victorias = vector<int>(T, 0); 
    this ->empates = vector<int>(T, 0); 
    this ->derrotas = vector<int>(T, 0); 
    this ->goles_marcados = vector<int>(T, 0); 
    this ->goles_encontra = vector<int>(T, 0); 
        
}
void torneo::setNombreEquipo(int indice, string nombreEquipo) {
    equipos[indice] = nombreEquipo;
}

string torneo::getNombreEquipo (int indice){
    return equipos[indice];
}

vector<string> torneo::getEquipos(){
    return equipos;
}

void torneo::setPartidosJugados(int indice){
    partidos_jugados[indice] += 1;
}

void torneo::setVictorias(int indice){
    victorias[indice] += 1;
    puntos_obtenidos[indice] += 3;
}

void torneo::setEmpates(int indice){
    empates[indice] += 1;
    puntos_obtenidos[indice] += 1;
}

void torneo::setDerrotas(int indice){
    derrotas[indice] += 1;
}

void torneo::setGolesMarcados(int indice, int goles){
    goles_marcados[indice] += goles; // Aquí debes sumar los goles, no reemplazarlos.
}

void torneo::setGolesEncontra(int indice, int goles){
    goles_encontra[indice] += goles; // Aquí debes sumar los goles en contra, no reemplazarlos.
}

vector<int> torneo::getPuntosObtenidos(){
    return puntos_obtenidos;
}
vector<int> torneo::getPartidosJugados(){
    return partidos_jugados;
}
vector<int> torneo::getVictorias(){
    return victorias;
}
vector<int> torneo::getEmpates(){
    return empates;
}
vector<int> torneo::getDerrotas(){
    return derrotas;
}
vector<int> torneo::getGolesMarcados(){
    return goles_marcados;
}
vector<int> torneo::getGolesEncontra(){
    return goles_encontra;
}

bool mayorAmenor (int a, int b){
    bool ans = a > b;
    return ans;
}

void torneo::imprimir(string nombreTorneo, int T) {
    cout << nombreTorneo << endl;
    

    // Crear un vector de índices para ordenar los equipos
    vector<int> indices(T);
    for (int i = 0; i < T; ++i) {
        indices[i] = i;
    }

    // Ordenar los equipos según las reglas dadas
    sort(indices.begin(), indices.end(), [this](int a, int b) {
        if (puntos_obtenidos[a] != puntos_obtenidos[b]) {
            return puntos_obtenidos[a] > puntos_obtenidos[b];
        }
        if (victorias[a] != victorias[b]) {
            return victorias[a] > victorias[b];
        }
        if ((goles_marcados[a] - goles_encontra[a]) != (goles_marcados[b] - goles_encontra[b])) {
            return (goles_marcados[a] - goles_encontra[a]) > (goles_marcados[b] - goles_encontra[b]);
        }
        if (goles_marcados[a] != goles_marcados[b]) {
            return goles_marcados[a] > goles_marcados[b];
        }
        if (partidos_jugados[a] != partidos_jugados[b]) {
            return partidos_jugados[a] < partidos_jugados[b];
        }
        return getNombreEquipo(a) < getNombreEquipo(b); 
    });

    
    for (int i = 0; i < T; ++i) {
        int indice = indices[i];
        cout << i + 1 << ") " << getNombreEquipo(indice) << " " << puntos_obtenidos[indice] << "p, " << partidos_jugados[indice] << "g (" << victorias[indice] << "-" << empates[indice] << "-" << derrotas[indice] << "), ";
        cout << (goles_marcados[indice] - goles_encontra[indice]) << "gd (" << goles_marcados[indice] << "-" << goles_encontra[indice] << ")" << endl;
    }

    

}



int main() {
    int N;
    cin >> N;
    cin.ignore(); 
    
    for (int i = 0; i < N; ++i) {
        string nombreTorneo;
        getline(cin, nombreTorneo);

        int T;
        cin >> T;
        cin.ignore();  

        torneo torneoActual; 
        torneoActual.inicializacion(nombreTorneo, T);
        
        // leemos los equipos
        for (int j = 0; j < T; ++j) {
            string nombreEquipo;
            getline(cin, nombreEquipo);

            torneoActual.setNombreEquipo(j, nombreEquipo); 
        }
        int G;
        cin >> G;
        cin.ignore();  

        for(int j = 0; j < G; ++j){
            string info_partido;
            getline(cin, info_partido);

            string equipo1, equipo2, goles1_str, goles2_str;
            int goles1, goles2;

            string:: iterator pos_ast1 = find(info_partido.begin(), info_partido.end(), '#');
            for(string:: iterator it = info_partido.begin(); it != pos_ast1; ++it)
                equipo1 += *it;  // obtenemos equipo 1 de info_partido

            string:: iterator pos_arroba = find(info_partido.begin(), info_partido.end(), '@');
            for(string:: iterator it = pos_ast1 + 1; it != pos_arroba; ++it)
                goles1_str += *it;  // goles equipo 1
            goles1 = stoi(goles1_str);// pasamos a enteros

            string:: iterator pos_ast2 = find(pos_arroba, info_partido.end(), '#');
            for(string:: iterator it = pos_arroba + 1; it != pos_ast2; ++it)
                goles2_str += *it;    // goles equipo 2
            goles2 = stoi(goles2_str);// pasamos a enteros

            for(string:: iterator it = pos_ast2 + 1; it != info_partido.end(); ++it)
                equipo2 += *it; // obtenemos equipo 2 de info_partido

            int indice1, indice2;
            vector<string> equipos = torneoActual.getEquipos();
            
            vector<string>:: iterator in1 = find(equipos.begin(), equipos.end(), equipo1);
            indice1 = in1 - equipos.begin();

            vector<string>:: iterator in2 = find(equipos.begin(), equipos.end(), equipo2);
            indice2 = in2 - equipos.begin();

            // partidos jugados de cada equipo
            torneoActual.setPartidosJugados(indice1);
            torneoActual.setPartidosJugados(indice2);

            // Goles marcados y goles en contra de cada equipo
            torneoActual.setGolesMarcados(indice1, goles1);
            torneoActual.setGolesEncontra(indice1, goles2);

            torneoActual.setGolesMarcados(indice2, goles2);
            torneoActual.setGolesEncontra(indice2, goles1);

            // miras quien gano o quien perdio , o si empataron
            if (goles1 > goles2){
                torneoActual.setVictorias(indice1);
                torneoActual.setDerrotas(indice2);
            }
            else if (goles2 > goles1){
                torneoActual.setVictorias(indice2);
                torneoActual.setDerrotas(indice1);
            }
            else{
                torneoActual.setEmpates(indice1);
                torneoActual.setEmpates(indice2);
            }
            
        }

        

        /*cout << nombreTorneo << endl;

        cout << "equipos: ";
        for (int j = 0; j < T; ++j){
            cout << torneoActual.getEquipos()[j] << " ";
        }
        cout << endl;

        cout << "Puntos obtenidos: ";
        for (int j = 0; j < T; ++j){
            cout << torneoActual.getPuntosObtenidos()[j] << " ";
        }
        cout << endl;

        cout << "Partidos jugados: ";
        for (int j = 0; j < T; ++j){
            cout << torneoActual.getPartidosJugados()[j] << " ";
        }
        cout << endl;

        cout << "Victorias: ";
        for (int j = 0; j < T; ++j){
            cout << torneoActual.getVictorias()[j] << " ";
        }
        cout << endl;

        cout << "Empates: ";
        for (int j = 0; j < T; ++j){
            cout << torneoActual.getEmpates()[j] << " ";
        }
        cout << endl;

        cout << "Derrotas: ";
        for (int j = 0; j < T; ++j){
            cout << torneoActual.getDerrotas()[j] << " ";
        }
        cout << endl;

        cout << "Goles marcados: ";
        for (int j = 0; j < T; ++j){
            cout << torneoActual.getGolesMarcados()[j] << " ";
        }
        cout << endl;

        cout << "Goles en contra: ";
        for (int j = 0; j < T; ++j){
            cout << torneoActual.getGolesEncontra()[j] << " ";
        }
        cout << endl;

        cout << endl;*/
        torneoActual.imprimir(nombreTorneo, T);

        cout << endl;

        



    }
    


    return 0;
}
