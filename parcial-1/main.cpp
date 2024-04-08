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

// Función para rotar una matriz en 90 grados en sentido horario
void rotarMatriz(int** matriz, int m) {
    // Crear una matriz temporal para almacenar la matriz rotada
    int** matrizRotada = reservarMatriz(m);

    // Realizar la rotación
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matrizRotada[j][m - 1 - i] = matriz[i][j];
        }
    }

    // Copiar la matriz rotada de vuelta a la matriz original
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = matrizRotada[i][j];
        }
    }

    // Liberar la memoria de la matriz temporal
    liberarMatriz(matrizRotada, m);
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
    generarMatriz(matrizOriginal, dimension);
    cout << "\nMatriz base para esta clave:" << endl;
    imprimirMatriz(matrizOriginal, dimension);

    // Imprimir todos los elementos del arreglo clave, incluyendo -3
    cout << "Elementos del arreglo clave:" << endl;
    for (int i = 0; i < contador; ++i) {
        cout << clave[i] << " ";
    }
    cout << endl;

    cout <<"\nCantidad de elementos en la clave: "<<contador << endl;

    // Generar la matriz 2 original (la que se va a rotar)
    int** matriz2 = reservarMatriz(dimension);
    generarMatriz(matriz2, dimension);

    // Realizar las comparaciones entre los valores en la posición dada por la clave en las matrices rotadas
    cout << "\nComparaciones entre los valores en la posición dada por la clave en las matrices rotadas:" << endl;
    bool claveCumplida = false;

    for (int i = 0; i < 4; ++i) {
        int fila = clave[0] - 1; // Restamos 1 porque las filas y columnas se cuentan desde 1 en la clave
        int columna = clave[1] - 1;
        int valorA = matrizOriginal[fila][columna];
        int valorB = matriz2[fila][columna];
        int condicionComparacion = clave[2]; // La primera condición de comparación después de fila y columna

        // Verificar si la clave se cumple en la posición dada
        bool resultadoComparacion = false;
        if (condicionComparacion == 1) {
            resultadoComparacion = (valorA > valorB);
        } else if (condicionComparacion == 0) {
            resultadoComparacion = (valorA == valorB);
        } else if (condicionComparacion == -1) {
            resultadoComparacion = (valorA < valorB);
        }

        if (resultadoComparacion) {
            cout << "La restricción se cumplió en la comparación " << i + 1 << ": Matriz original vs Matriz 2 rotada " << (i * 90) << "°: Cumple" << endl;
            claveCumplida = true;
            break; // Si la clave se cumple, salir del bucle
        }

        // Rotar la matriz 2 para la próxima iteración
        rotarMatriz(matriz2, dimension);

        // Imprimir la matriz 2 rotada
        if(((i + 1) * 90)<271){ //para que solo se imprima la rotacion hasta 270 por que se estaba haciendo hasta 360
            cout << "Matriz 2 rotada " << ((i + 1) * 90) << "°:" << endl;
            imprimirMatriz(matriz2, dimension);
        }
    }

    if (!claveCumplida) {
        cout << "No se cumplió la clave en ninguna rotación de la matriz 2" << endl;

        // Si la clave no se cumple en ninguna rotación de la matriz 2, intentar rotar la matriz 1
        for (int i = 0; i < 4; ++i) {
            // Rotar la matriz 1
            rotarMatriz(matrizOriginal, dimension);

            // Imprimir la matriz 1 rotada
            cout << "Matriz 1 rotada " << ((i + 1) * 90) << "°:" << endl;
            imprimirMatriz(matrizOriginal, dimension);

            // Comparar la matriz 1 rotada con la matriz 2 rotada
            int fila = clave[0] - 1;
            int columna = clave[1] - 1;
            int valorA = matrizOriginal[fila][columna];
            int valorB = matriz2[fila][columna];
            int condicionComparacion = clave[2];

            bool resultadoComparacion = false;
            if (condicionComparacion == 1) {
                resultadoComparacion = (valorA > valorB);
            } else if (condicionComparacion == 0) {
                resultadoComparacion = (valorA == valorB);
            } else if (condicionComparacion == -1) {
                resultadoComparacion = (valorA < valorB);
            }

            if (resultadoComparacion) {
                cout << "La restricción se cumplió en la comparación " << i + 1 << ": Matriz 1 rotada vs Matriz 2 rotada " << (i * 90) << "°: Cumple" << endl;
                claveCumplida = true;
                break; // Si la clave se cumple, salir del bucle
            }
        }
    }

    if (!claveCumplida) {
        cout << "No se cumplió la clave en ninguna rotación" << endl;
    }

    // Liberar memoria de las matrices
    liberarMatriz(matrizOriginal, dimension);
    liberarMatriz(matriz2, dimension);
}

int main() {
    crearCerradura();
    return 0;
}
