#include <iostream>

using namespace std;

void rotar_matriz(int **matriz, int m, int opcion) {
    switch (opcion) {
    case 1:
        // Rotar 90 grados a la derecha
        for (int i = 0; i < m / 2; i++) {
            for (int j = i; j < m - i - 1; j++) {
                // Intercambiar elementos
                int temp = matriz[i][j];
                matriz[i][j] = matriz[m - 1 - j][i];
                matriz[m - 1 - j][i] = matriz[m - 1 - i][m - 1 - j];
                matriz[m - 1 - i][m - 1 - j] = matriz[j][m - 1 - i];
                matriz[j][m - 1 - i] = temp;
            }
        }
        break;
    case 2:
        // Rotar 180 grados
        for (int i = 0; i < m / 2; i++) {
            for (int j = 0; j < m; j++) {
                // Intercambiar elementos
                int temp = matriz[i][j];
                matriz[i][j] = matriz[m - 1 - i][m - 1 - j];
                matriz[m - 1 - i][m - 1 - j] = temp;
            }
        }
        break;
    case 3:
        // Rotar 90 grados a la izquierda
        for (int i = 0; i < m / 2; i++) {
            for (int j = i; j < m - i - 1; j++) {
                // Intercambiar elementos
                int temp = matriz[i][j];
                matriz[i][j] = matriz[j][m - 1 - i];
                matriz[j][m - 1 - i] = matriz[m - 1 - i][m - 1 - j];
                matriz[m - 1 - i][m - 1 - j] = matriz[m - 1 - j][i];
                matriz[m - 1 - j][i] = temp;
            }
        }
        break;
    default:
        cout << "Opción no válida." << endl;
        break;
    }

    // Imprimir la matriz rotada
    cout << "Matriz rotada:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    // Dimensión de la matriz
    int m;

    // Bucle do-while para verificar que m sea impar
    do {
        cout << "Ingrese la dimension de la matriz (debe ser impar): ";
        cin >> m;
    } while (m % 2 == 0);

    // Reservar memoria dinámica para la matriz
    int **matriz = new int*[m]; //Se usa un puntero doble, por ser una matriz de dos dimensiones
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
