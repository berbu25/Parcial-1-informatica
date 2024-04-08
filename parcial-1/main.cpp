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
void generarMatriz(int** matriz, int m, int rotacion) {
    int k = 1;
    if (rotacion == 0) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i == m / 2 && j == m / 2) {
                    matriz[i][j] = 0;
                } else {
                    matriz[i][j] = k++;
                }
            }
        }
    } else if (rotacion == 90) {
        for (int j = m - 1; j >= 0; j--) {
            for (int i = 0; i < m; i++) {
                if (i == m / 2 && j == m / 2) {
                    matriz[i][j] = 0;
                } else {
                    matriz[i][j] = k++;
                }
            }
        }
    } else if (rotacion == 180) {
        for (int i = m - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == m / 2 && j == m / 2) {
                    matriz[i][j] = 0;
                } else {
                    matriz[i][j] = k++;
                }
            }
        }
    } else if (rotacion == 270) {
        for (int j = 0; j < m; j++) {
            for (int i = m - 1; i >= 0; i--) {
                if (i == m / 2 && j == m / 2) {
                    matriz[i][j] = 0;
                } else {
                    matriz[i][j] = k++;
                }
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
    cout << endl;
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

    // Generar la matriz original (con la que se trabaja la cerradura) y mostrarla
    int** matrizOriginal = reservarMatriz(dimension);
    generarMatriz(matrizOriginal, dimension, 0);
    cout << "\nMatriz base para esta clave:" << endl;
    imprimirMatriz(matrizOriginal, dimension);

    // Imprimir todos los elementos del arreglo clave, incluyendo -3
    cout << "Elementos del arreglo clave:" << endl;
    for (int i = 0; i < contador; ++i) {
        cout << clave[i] << " ";
    }
    cout << endl;

    cout <<"\nCantidad de elementos en la clave: "<<contador<<endl<<endl;

    // Crear matrices adicionales según la cantidad de elementos en la clave
    int*** matricesAdicionales = new int**[contador - 1];
    for (int i = 0; i < contador - 1; ++i) {
        matricesAdicionales[i] = reservarMatriz(dimension);
        int rotacion;
        cout << "Ingrese la cantidad de grados de rotacion para la matriz " << i + 1 << " (0, 90, 180, 270): ";
        cin >> rotacion;
        generarMatriz(matricesAdicionales[i], dimension, rotacion);
    }

    // Imprimir las matrices adicionales
    for (int i = 0; i < contador - 1; ++i) {
        cout << "Matriz " << i + 1 << " generada a partir de la matriz base con rotacion:" << endl;
        imprimirMatriz(matricesAdicionales[i], dimension);
    }

    // Liberar memoria de las matrices adicionales
    for (int i = 0; i < contador - 1; ++i) {
        liberarMatriz(matricesAdicionales[i], dimension);
    }
    delete[] matricesAdicionales;

    liberarMatriz(matrizOriginal, dimension);
}

int main() {
    crearCerradura();
    return 0;
}
