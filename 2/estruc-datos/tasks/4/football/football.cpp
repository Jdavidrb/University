/*
Jose David Ruano Burbano
Estructura de datos - Tarea 4 - Football
Fecha: 1/OCT/23

Análisis de complejidad:
Sea n el número total de equipos y P el número total de partidos.

Ciclo de lectura: Se hacen n iteraciones para leer los datos de cada equipo y llenar el vector 'Equipos'.

Ciclo de partidos: Se hacen P iteraciones para cada partido. Dentro de este ciclo, se hacen varias operaciones que involucran 
recorrer todos los equipos (n iteraciones). Esto incluye actualizar las estadísticas del partido para cada equipo y verificar
quién ganó el partido. Por lo tanto, la complejidad dentro del ciclo de partidos es O(n).

Función 'operator <': Se llama n log n veces durante la ordenación del vector 'Equipo'. Cada llamada tiene una complejidad de O(1), 
lo que da una complejidad total de O(n log n).
Impresión de datos: Se hacen n iteraciones para imprimir los datos de cada equipo.

Con esto, lo más costoso es O(n log n) sin embargo tambien deberiamos tener en cuenta P
por lo que la compejidad seria algo asi como O(n log n * P)
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Equipo{
    // atributos 

    private:
    string nombre;
    int puntos_obtenidos, partidos_jugados, victorias, empates, derrotas, diferencia_goles, marcados, encontra;

    //metodos

    public:

    Equipo(); // constructor por defecto
    Equipo(string, int, int, int, int, int, int, int, int); // constructor para un equipo

    void jugarPartido();
    void ganarPartido();
    void empatarPartido();
    void perderPartido();
    void marcarGoles(int);
    void recibirGoles(int);
    void diferenciaGoles(int, int);
    void printInfo(int);
    string getNombre();
    bool operator < (const Equipo &e);

};

// Definicion de los metodos

Equipo:: Equipo(){}

Equipo:: Equipo(string nom, int puntos, int jugados, int vic, int empa, int derro, int dif_goles, int marcados, int encontra){
    nombre = nom;
    puntos_obtenidos = puntos;
    partidos_jugados = jugados;
    victorias = vic;
    empates = empa;
    derrotas = derro;
    diferencia_goles = dif_goles;
    this->marcados = marcados;
    this->encontra = encontra;

}

string Equipo::getNombre(){
    return nombre;
}

void Equipo:: jugarPartido(){
    partidos_jugados++;
}

void Equipo:: ganarPartido(){
    puntos_obtenidos += 3;
    victorias++;
}

void Equipo::empatarPartido(){
    puntos_obtenidos += 1;
    empates++;
}

void Equipo:: perderPartido(){
    puntos_obtenidos += 0;
    derrotas++;
}

void Equipo:: marcarGoles(int goles){
    marcados += goles;
}

void Equipo:: recibirGoles(int goles){
    encontra += goles;
}

void Equipo:: diferenciaGoles(int goles1, int goles2){
    diferencia_goles += goles1 - goles2;

}

void Equipo::printInfo(int posicion) {
    cout << posicion << ") " << nombre << " " << puntos_obtenidos << "p, " << partidos_jugados << "g ("
         << victorias << "-" << empates << "-" << derrotas << "), " << diferencia_goles << "gd (" << marcados
         << "-" << encontra << ")" << endl;
}

// Sobrecargamos el operador sort para que compare datos de la clase equipo de la forma en que queremos ordenar

bool Equipo:: operator < (const Equipo &e){
    bool ans;
    if (puntos_obtenidos != e.puntos_obtenidos)
        ans = puntos_obtenidos > e.puntos_obtenidos;
    else{
        if(victorias != e.victorias)
            ans = victorias  > e.victorias;
        else{
            if (diferencia_goles != e.diferencia_goles)
                ans = diferencia_goles > e.diferencia_goles;
            else{
                if (marcados != e.marcados)
                    ans = marcados > e.marcados;
                else{
                    if (partidos_jugados != e.partidos_jugados)
                        ans = partidos_jugados < e.partidos_jugados;
                    else{
                        if (nombre != e.nombre)
                            ans = nombre < e.nombre;
                    }
                }
            }
        }
    }
    return ans;

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

        vector<Equipo> equipos;

        // leemos los equipos y los almacenamos en un vector de equipos

        for (int j = 0; j < T; ++j) {
            string nombreEquipo;
            getline(cin, nombreEquipo);
            equipos.push_back(Equipo(nombreEquipo, 0, 0, 0 ,0 ,0 ,0 ,0 ,0));
        }
        int G;
        cin >> G;
        cin.ignore();

        for(int j = 0; j < G; ++j){
            string info_partido;
            getline(cin, info_partido);

            // obtenemos la iformacion requerida de cada partido

            string equipo1, equipo2, goles1_str, goles2_str;
            int goles1, goles2;

            string:: iterator pos_ast1 = find(info_partido.begin(), info_partido.end(), '#'); // limite 1 
            for(string:: iterator it = info_partido.begin(); it != pos_ast1; ++it)
                equipo1 += *it;  // obtenemos el nombre del equipo 1 de info_partido

            string:: iterator pos_arroba = find(info_partido.begin(), info_partido.end(), '@'); // limite medio
            for(string:: iterator it = pos_ast1 + 1; it != pos_arroba; ++it)
                goles1 = *it - 48;  // goles equipo 1


            string:: iterator pos_ast2 = find(pos_arroba, info_partido.end(), '#'); // limite 2
            for(string:: iterator it = pos_arroba + 1; it != pos_ast2; ++it)
                goles2 = *it - 48;  // goles equipo 2

            for(string:: iterator it = pos_ast2 + 1; it != info_partido.end(); ++it)
                equipo2 += *it; // obtenemos el nombre del equipo 2 de info_partido



            // Sumar un partido a cada uno
            for(int k = 0; k < equipos.size();++k){
                if (equipos[k].getNombre() == equipo1 || equipos[k].getNombre() == equipo2){
                    equipos[k].jugarPartido();
                
                }

            }

            // Goles marcados -  Goles encontra 
            for(int k = 0; k < equipos.size();++k){
                if (equipos[k].getNombre() == equipo1 ){
                    equipos[k].marcarGoles(goles1);
                    equipos[k].recibirGoles(goles2);
                
                }

            }
            for(int k = 0; k < equipos.size();++k){
                if ( equipos[k].getNombre() == equipo2){
                    equipos[k].marcarGoles(goles2);
                    equipos[k].recibirGoles(goles1);
                
                }

            }
            // Diferencia de goles: 

            for(int k = 0; k < equipos.size();++k){
                if (equipos[k].getNombre() == equipo1){
                    equipos[k].diferenciaGoles(goles1 ,goles2);
                
                }

            }
            for(int k = 0; k < equipos.size();++k){
                if (equipos[k].getNombre() == equipo2){
                    equipos[k].diferenciaGoles(goles2 ,goles1);
                
                }

            }

            // Quien gano -  perdio -  empataron
            if (goles1 > goles2){
                for(int k = 0; k < equipos.size();++k){
                    if (equipos[k].getNombre() == equipo1){
                        equipos[k].ganarPartido();

                    }
                    if (equipos[k].getNombre() == equipo2){
                        equipos[k].perderPartido();
                    }    
                }

            }
            else if (goles2 > goles1){
                for(int k = 0; k < equipos.size();++k){
                    if (equipos[k].getNombre() == equipo2){
                        equipos[k].ganarPartido();
                    }
                    if (equipos[k].getNombre() == equipo1){
                        equipos[k].perderPartido();
                    }    
                }

            }
            else{
                for(int k = 0; k < equipos.size();++k){
                    if (equipos[k].getNombre() == equipo1 || equipos[k].getNombre() == equipo2){
                        equipos[k].empatarPartido();
                
                    }

                }
                
            }



        }

        // ordenamos el vector de equipos ya con la informacion recolectada

        sort(equipos.begin(), equipos.end());


        // imprimimos la salida 

        cout << nombreTorneo << endl;

        for (vector<Equipo>::iterator it = equipos.begin(); it != equipos.end(); ++ it){
            it -> printInfo((it - equipos.begin())+ 1);
        }
        cout << endl;

    }
    return 0;
}    