#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Clase comparadora para la cola de prioridad
struct OrderComparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        // Lógica de comparación: ordenar primero por fecha de vencimiento ascendente,
        // y en caso de empate, por cantidad de acero descendente
        if (a.first == b.first) {
            return a.second < b.second; // Ordenar por cantidad de acero descendente en caso de empate en fecha de vencimiento
        }
        return a.first > b.first; // Ordenar por fecha de vencimiento ascendente
    }
};

int main() {
    int numCases;
    cin >> numCases;

    for (int caseNum = 0; caseNum < numCases; ++caseNum) {
        int numOrders;
        cin >> numOrders;

        // Crear una cola de prioridad utilizando pair<int, int> (fecha de vencimiento, cantidad de acero)
        priority_queue<pair<int, int>, vector<pair<int, int>>, OrderComparator> ordersQueue;

        // Leer las órdenes y agregarlas a la cola de prioridad
        for (int i = 0; i < numOrders; ++i) {
            int amount, dueDate;
            cin >> amount >> dueDate;
            ordersQueue.push({dueDate, amount});
        }

        int currentTime = 0;
        int acceptedOrders = 0;

        // Procesar las órdenes
        while (!ordersQueue.empty()) {
            pair<int, int> currentOrder = ordersQueue.top();
            ordersQueue.pop();

            // Verificar si la orden puede ser aceptada
            if (currentTime + currentOrder.second <= currentOrder.first) {
                // Procesar la orden
                ++acceptedOrders;
                currentTime += currentOrder.second;
            }
        }

        // Imprimir el resultado para este caso
        cout << acceptedOrders << endl;

        // Imprimir una línea en blanco entre casos
        if (caseNum < numCases - 1) {
            cout << endl;
        }
    }

    return 0;
}
