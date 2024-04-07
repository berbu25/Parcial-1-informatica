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

// Función para crear una "cerradura" de matrices y comparar los valores según las condiciones definidas en la clave
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
                cout << "La fila o la columna deben ser positivas" << endl;
            } else {
                clave = agregarDato(condicion, clave, contador);
                contador++;
            }
        } else {
            if (condicion != 0 && condicion != 1 && condicion != -1 && condicion != -3) {
                cout << "Debe ingresar <0> <1> <-1> o <-3>" << endl;
            } else {
                if (condicion != -3) {
                    clave = agregarDato(condicion, clave, contador);
                    contador++;
                } else {
                    if (contador <= 2) {
                        cout << "Debe ingresar al menos 3 condiciones (fila, columna, condicion1)" << endl;
                    } else {
                        false;
                    }
                }
            }
        }
    }

    // Calcular la dimensión de las matrices de la cerradura
    int dimension = (clave[0] > clave[1]) ? clave[0] : clave[1];
    if (dimension % 2 == 0) {
        dimension++;
    }

    // Generar la matriz original y mostrarla
    int** matrizOriginal = reservarMatriz(dimension);
    generarMatriz(matrizOriginal, dimension);
    cout << "Matriz original:" << endl;
    imprimirMatriz(matrizOriginal, dimension);

    // Crear la cerradura y comparar los valores según las condiciones de la clave
    cout << "Cerradura:" << endl;
    int** matrizCerradura = reservarMatriz(dimension);
    for (int i = 0; i < contador - 1; i++) {
        int fila = clave[0] - 1; // La fila indicada por la clave
        int columna = clave[1] - 1; // La columna indicada por la clave
        cout << "Matriz " << i + 1 << " en la posición (" << fila + 1 << ", " << columna + 1 << "):" << endl;
        cout << "Valor: " << matrizOriginal[fila][columna] << endl;
        // Imprimir valores de las matrices según las condiciones de la clave
        for (int j = 2; j < contador; j += 2) {
            int filaComp = clave[j] - 1; // La fila a comparar según la clave
            int columnaComp = clave[j + 1] - 1; // La columna a comparar según la clave
            cout << "Comparacion con la matriz " << (j / 2) + 1 << " en la posicion (" << filaComp + 1 << ", " << columnaComp + 1 << "): ";
            if (matrizOriginal[fila][columna] > matrizOriginal[filaComp][columnaComp]) {
                cout << "matriz1 > matriz" << (j / 2) + 1 << endl;
            } else if (matrizOriginal[fila][columna] < matrizOriginal[filaComp][columnaComp]) {
                cout << "matriz1 < matriz" << (j / 2) + 1 << endl;
            } else {
                cout << "matriz1 = matriz" << (j / 2) + 1 << endl;
            }
        }
    }

    liberarMatriz(matrizOriginal, dimension);
    liberarMatriz(matrizCerradura, dimension);
}

int main() {
    crearCerradura();
    return 0;
}
