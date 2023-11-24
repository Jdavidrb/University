#include <map>
#include <iostream>

using namespace std;

int main(){
  map<int, int> tabla;

  tabla[0] = 5;
  tabla[3] = 12;
  tabla[6] = 9;
  tabla[9] = 15;
  tabla.insert(pair<int, int>(5, 18));// log n

  cout << "Imprimiendo Tabla" << endl;

  for(map<int, int>::iterator it = tabla.begin(); it != tabla.end(); ++it)
    cout << it->first << " => " << it->second << endl;

  map<int, int> tabla2(tabla.begin(), tabla.end());

  cout << "Imprimiendo Tabla 2" << endl;
  tabla2[5] = 8;
  tabla2[0] = 4;

  for(map<int, int>::iterator it = tabla2.begin(); it != tabla2.end(); ++it)
    cout << it->first << " => " << it->second << endl;

  map<int, int> tabla3(tabla2);
  cout << "Imprimiendo Tabla 3" << endl;
  tabla3[3] = 10;

  for(map<int, int>::iterator it = tabla3.begin(); it != tabla3.end(); ++it)
    cout << it->first << " => " << it->second << endl;

  tabla2.erase(5);
  tabla2[7] = 20;
  tabla2[11] = 24;

  cout << "Imprimiendo Tabla 2" << endl;

  for(map<int, int>::iterator it = tabla2.begin(); it != tabla2.end(); ++it)
    cout << it->first << " => " << it->second << endl;

  map<int, int>::iterator it = tabla2.find(6);
  tabla2.erase(it);

  cout << "Imprimiendo Tabla 2" << endl;

  for(map<int, int>::iterator it = tabla2.begin(); it != tabla2.end(); ++it)
    cout << it->first << " => " << it->second << endl;

  if(tabla2.empty())
    cout << "El mapa tabla2 esta vacio" << endl;
  else
    cout << "El mapa tabla2 no esta vacio" << endl;

  cout << "El tamaño del mapa tabla es " << tabla.size() << endl;
  cout << "El tamaño del mapa tabla2 es " << tabla2.size() << endl;
  cout << "El tamaño del mapa tabla3 es " << tabla3.size() << endl;

  return 0;
}
