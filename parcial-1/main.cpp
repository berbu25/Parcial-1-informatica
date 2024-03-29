#include <iostream>

using namespace std;

int main() {
    // Dimensión de la matriz
    int m;

    // Bucle do-while para verificar que m sea impar
    do {
        cout << "Ingrese la dimensión de la matriz (debe ser impar): ";
        cin >> m;
    } while (m % 2 == 0);

    // Reservar memoria dinámica para la matriz
    int *matriz = new int[m];
    for (int i = 0; i < m; i++) {
        matriz[i] = new int[m];
    }

    // Llenar la matriz con números en orden
    int k = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == m / 2 && j == m / 2) {
                // Casilla central vacía
                matriz[i][j] = 0;
            } else {
                matriz[i][j] = k++;
            }
        }
    }

    // Imprimir la matriz
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Liberar memoria dinámica
    for (int i = 0; i < m; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
