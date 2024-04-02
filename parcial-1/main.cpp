#include <iostream>

using namespace std;

int** reservarMatriz(int m) {
    int** matriz = new int*[m];
    for (int i = 0; i < m; i++) {
        matriz[i] = new int[m];
    }
    return matriz;
}

void liberarMatriz(int** matriz, int m) {
    for (int i = 0; i < m; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void generarMatriz(int** matriz, int m) {
    int k = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == m / 2 && j == m / 2) {
                matriz[i][j] = 0;
            } else {
                matriz[i][j] = k++;
            }
        }
    }
}

void imprimirMatriz(int** matriz, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void rotarMatriz(int** matriz, int m, int opcion) {
    int** matrizRotada = reservarMatriz(m);
    switch (opcion) {
    case 1:
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                matrizRotada[j][m - 1 - i] = matriz[i][j];
            }
        }
        break;
    case 2:
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                matrizRotada[m - 1 - i][m - 1 - j] = matriz[i][j];
            }
        }
        break;
    case 3:
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                matrizRotada[m - 1 - j][i] = matriz[i][j];
            }
        }
        break;
    default:
        cout << "Opción no válida." << endl;
        liberarMatriz(matrizRotada, m);
        return;
    }
    imprimirMatriz(matrizRotada, m);
    liberarMatriz(matrizRotada, m);
}

int main() {
    int m;
    do {
        cout << "Ingrese la dimensión de la matriz (debe ser impar): ";
        cin >> m;
    } while (m % 2 == 0);

    int** matrizOriginal = reservarMatriz(m);
    generarMatriz(matrizOriginal, m);
    imprimirMatriz(matrizOriginal, m);

    int opcion;
    do {
        cout << "¿Desea rotar la matriz? (1: 270 grados, 2: 180 grados, 3: 90 grados, 0: No rotar): ";
        cin >> opcion;
    } while (opcion < 0 || opcion > 3);

    if (opcion != 0) {
        rotarMatriz(matrizOriginal, m, opcion);
    }

    liberarMatriz(matrizOriginal, m);

    return 0;
}
