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

int* agregardato(int numerocondicion, int*arregloclave, int longitud){
    int* nuevoarreglo = new int [longitud + 1];
    for(int i = 0; i<=longitud;i++){
        if(i<longitud){
            nuevoarreglo[i]= arregloclave[i];
        }
        else{
            nuevoarreglo[i]=numerocondicion;
        }
    }
    delete[] arregloclave;
    return nuevoarreglo;
}

int generarcerradura(){  //esta funcion genera la cerradura a partir de la clave ingresada por el usuario

    int tamano, contador = 0, condicion;
    cout <<endl<< "Ingrese la clave: "<<endl;
    int *clave = new int[tamano];

    while(true){
        cout << "Ingrese la condicion " << contador + 1 <<": ";
        cin >> condicion;
        if(condicion == -3){
            break;
        }
        if(contador == 0 || contador == 1){ // En las dos primeras iteraciones se ingresa la fila y la columna deben ser >0
            if(condicion<1){
                cout<<"La fila o la columna deben ser positivas";
            }
            else{
                clave = agregardato(condicion,clave,contador);
                contador++;
            }
        }
        else{
            if(condicion!=0 && condicion!=1 && condicion!=-1 && condicion!=-3){     //TENGO DUDA SI ACA ES && O SERIA ||
                cout<<"Estas ingresando una opcion invalida, deber ingresar <0> <1> <-1> o <-3> ";
            }
            else{
                if(condicion!=-3){
                    clave = agregardato(condicion,clave,contador);
                    contador++;
                }
                else{
                    if(contador<=2){
                        cout<<"Minimo debese ingresar 3 condiciones (fila, columna, condicion1) ";
                    }
                    else{
                        false;
                    }
                }
            }
        }
    }
    tamano = contador;
    return *clave;

}


int main() {
    int m;

    do {
        cout << "Ingrese la dimension de la matriz (debe ser impar): ";
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

    generarcerradura();

    return 0;
}
