#include <iostream>

using namespace std;

// Función para reservar memoria para una matriz de tamaño m x m
int** reservarMatriz(int m) {
    int** matriz = new int*[m];
    for (int i = 0; i < m; i++) {
        matriz[i] = new int[m];
    }
    return matriz;
}

// Función para liberar memoria de una matriz
void liberarMatriz(int** matriz, int m) {
    for (int i = 0; i < m; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

// Función para generar una matriz con números ascendentes, con el centro en 0
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

// Función para imprimir una matriz
void imprimirMatriz(int** matriz, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para rotar una matriz en 90 grados en el sentido de las agujas del reloj
void rotarMatriz(int** matriz, int m) {
    int** matrizRotada = reservarMatriz(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matrizRotada[j][m - 1 - i] = matriz[i][j];
        }
    }
    // Copiar la matriz rotada a la matriz original
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = matrizRotada[i][j];
        }
    }
    liberarMatriz(matrizRotada, m);
}

// Función para agregar un dato al final de un arreglo
int* agregarDato(int numero, int* arreglo, int longitud) {
    int* nuevoArreglo = new int[longitud + 1];
    for (int i = 0; i < longitud; i++) {
        nuevoArreglo[i] = arreglo[i];
    }
    nuevoArreglo[longitud] = numero;
    delete[] arreglo;
    return nuevoArreglo;
}

// Función para generar una "cerradura" de matrices a partir de una clave ingresada por el usuario
void crearCerradura() {
    int contador = 0, condicion;
    cout << "Ingrese la clave: (La condicion 1 es la fila y la condicion 2 es la columna)" << endl;
    int* clave = new int[contador];

    // Leer las condiciones de entrada del usuario
    while (true) {
        cout << "Ingrese la condicion " << contador + 1 << ": ";
        cin >> condicion;
        if (condicion == -3) {
            break;
        }
        if (contador == 0 || contador == 1) {
            if (condicion < 1) {
                cout << "La fila o la columna deben ser positivas";
            } else {
                clave = agregarDato(condicion, clave, contador);
                contador++;
            }
        } else {
            if (condicion != 0 && condicion != 1 && condicion != -1 && condicion != -3) {
                cout << "Estás ingresando una opción inválida. Debes ingresar <0>, <1>, <-1> o <-3>" << endl;
            } else {
                if (condicion != -3) {
                    clave = agregarDato(condicion, clave, contador);
                    contador++;
                } else {
                    if (contador <= 2) {
                        cout << "Debes ingresar al menos 3 condiciones (fila, columna, condicion1)" << endl;
                    } else {
                        break;
                    }
                }
            }
        }
    }

    // Determinar la dimensión de las matrices para la cerradura
    int dimension;
    if (clave[0] > clave[1]) {
        dimension = clave[0];
    } else {
        dimension = clave[1];
    }
    if (dimension % 2 == 0) {
        dimension += 1; // Si la dimensión es par, agregar uno para que sea impar
    }

    // Generar las matrices y alinearlas usando su elemento central 0
    for (int c = contador - 1; c > 0; c--) {
        int** matriz = reservarMatriz(dimension);
        generarMatriz(matriz, dimension);
        cout << "Matriz " << contador - c << ":" << endl;
        imprimirMatriz(matriz, dimension);
        rotarMatriz(matriz, dimension);
        cout << endl;
        liberarMatriz(matriz, dimension);
    }

    delete[] clave;
}

int main() {
    int m;
    do {
        cout << "Ingrese la dimension de la matriz (debe ser impar): ";
        cin >> m;
    } while (m % 2 == 0);

    int** matrizOriginal = reservarMatriz(m);
    generarMatriz(matrizOriginal, m);
    cout << "Matriz Original:" << endl;
    imprimirMatriz(matrizOriginal, m);
    liberarMatriz(matrizOriginal, m);

    crearCerradura();

    return 0;
}
