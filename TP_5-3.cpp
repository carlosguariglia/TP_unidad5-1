/*
3. Implementa un programa que permita realizar operaciones sobre matrices de NxN. 
El programa debe permitir al usuario la selección de alguna de las siguientes operaciones: 

a) Sumar 2 matrices.
b) Restar 2 matrices.
c) Multiplicar 2 matrices.
d) Trasponer una matriz.
e) Mostrar una matriz señalando cuáles son los puntos de silla 
(los puntos de silla de una matriz son aquellos elementos de la misma que 
cumplen ser el mínimo de su fila y el máximo de su columna).
Habrá también dos subprogramas para leer del teclado o mostrar en la pantalla una matriz.

*/

#include <iostream>
using namespace std;

void leerMatriz(int matriz[100][100], int N);
void imprimirMatriz(int matriz[100][100], int N);
void mostrarEstadoMatrices(bool matrizA_cargada, bool matrizB_cargada, int A[100][100], int B[100][100], int N);
void sumarMatrices(int A[100][100], int B[100][100], int C[100][100], int N);
void restarMatrices(int A[100][100], int B[100][100], int C[100][100], int N);
void multiplicarMatrices(int A[100][100], int B[100][100], int C[100][100], int N);
void transponerMatriz(int A[100][100], int T[100][100], int N);
void puntosDeSilla(int matriz[100][100], int N);
void clearConsole();

int main() {
    clearConsole();
    int N;
    cout << "Ingrese el tamaño de la matriz NxN (máximo 100): ";
    cin >> N;

    // Validación del tamaño de la matriz
    if (N <= 0 || N > 100) {
        cout << "Tamaño inválido. Debe ser un número entre 1 y 100." << endl;
        return 1;
    }

    // Declarar matrices
    int A[100][100];
    int B[100][100];
    int C[100][100];
    int T[100][100]; // Para la matriz transpuesta

    // Variables para verificar si las matrices han sido cargadas
    bool matrizA_cargada = false;
    bool matrizB_cargada = false;

    clearConsole();
    int opcion;
    do {
        cout << "\nSeleccione una operación:\n";
        cout << "1. Cargar matriz A\n";
        cout << "2. Cargar matriz B\n";
        cout << "3. Sumar 2 matrices\n";
        cout << "4. Restar 2 matrices\n";
        cout << "5. Multiplicar 2 matrices\n";
        cout << "6. Trasponer una matriz (solo para matriz A)\n";
        cout << "7. Mostrar puntos de silla de una matriz (solo para matriz A)\n";
        cout << "8. Listar matriz A\n";
        cout << "9. Listar matriz B\n";
        cout << "0. Salir\n";
        // Mostrar el estado de las matrices A y B
        cout << "Matriz A: " << (matrizA_cargada ? "Cargada" : "No cargada") << endl;
        cout << "Matriz B: " << (matrizB_cargada ? "Cargada" : "No cargada") << endl;
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese la matriz A:\n";
                leerMatriz(A, N);
                matrizA_cargada = true;
                clearConsole();
                cout << "Matriz A cargada con éxito.\n";
                break;
            case 2:
                cout << "Ingrese la matriz B:\n";
                leerMatriz(B, N);
                matrizB_cargada = true;
                clearConsole();
                cout << "Matriz B cargada con éxito.\n";
                break;
            case 3:
                if (!matrizA_cargada || !matrizB_cargada) {
                    cout << "Error: Matrices A y B deben estar cargadas para realizar la suma.\n";
                    if (!matrizA_cargada) cout << "Desea cargar la matriz A ahora? (s/n): ";
                    if (!matrizB_cargada) cout << "Desea cargar la matriz B ahora? (s/n): ";
                    char cargar;
                    cin >> cargar;
                    if (cargar == 's' || cargar == 'S') {
                        if (!matrizA_cargada) { cout << "Ingrese la matriz A:\n"; leerMatriz(A, N); matrizA_cargada = true; }
                        if (!matrizB_cargada) { cout << "Ingrese la matriz B:\n"; leerMatriz(B, N); matrizB_cargada = true; }
                    }
                }
                if (matrizA_cargada && matrizB_cargada) {
                    sumarMatrices(A, B, C, N);
                    cout << "La matriz resultante de la suma es:\n";
                    imprimirMatriz(C, N);
                }
                break;
            case 4:
                if (!matrizA_cargada || !matrizB_cargada) {
                    cout << "Error: Matrices A y B deben estar cargadas para realizar la resta.\n";
                    if (!matrizA_cargada) cout << "Desea cargar la matriz A ahora? (s/n): ";
                    if (!matrizB_cargada) cout << "Desea cargar la matriz B ahora? (s/n): ";
                    char cargar;
                    cin >> cargar;
                    if (cargar == 's' || cargar == 'S') {
                        if (!matrizA_cargada) { cout << "Ingrese la matriz A:\n"; leerMatriz(A, N); matrizA_cargada = true; }
                        if (!matrizB_cargada) { cout << "Ingrese la matriz B:\n"; leerMatriz(B, N); matrizB_cargada = true; }
                    }
                }
                if (matrizA_cargada && matrizB_cargada) {
                    restarMatrices(A, B, C, N);
                    cout << "La matriz resultante de la resta es:\n";
                    imprimirMatriz(C, N);
                }
                break;
            case 5:
                if (!matrizA_cargada || !matrizB_cargada) {
                    cout << "Error: Matrices A y B deben estar cargadas para realizar la multiplicación.\n";
                    if (!matrizA_cargada) cout << "Desea cargar la matriz A ahora? (s/n): ";
                    if (!matrizB_cargada) cout << "Desea cargar la matriz B ahora? (s/n): ";
                    char cargar;
                    cin >> cargar;
                    if (cargar == 's' || cargar == 'S') {
                        if (!matrizA_cargada) { cout << "Ingrese la matriz A:\n"; leerMatriz(A, N); matrizA_cargada = true; }
                        if (!matrizB_cargada) { cout << "Ingrese la matriz B:\n"; leerMatriz(B, N); matrizB_cargada = true; }
                    }
                }
                if (matrizA_cargada && matrizB_cargada) {
                    multiplicarMatrices(A, B, C, N);
                    cout << "La matriz resultante de la multiplicación es:\n";
                    imprimirMatriz(C, N);
                }
                break;
            case 6:
                if (!matrizA_cargada) {
                    cout << "Error: La matriz A debe estar cargada para realizar la transposición.\n";
                    cout << "Desea cargar la matriz A ahora? (s/n): ";
                    char cargar;
                    cin >> cargar;
                    if (cargar == 's' || cargar == 'S') {
                        cout << "Ingrese la matriz A:\n";
                        leerMatriz(A, N);
                        matrizA_cargada = true;
                    }
                }
                if (matrizA_cargada) {
                    transponerMatriz(A, T, N);
                    cout << "La matriz transpuesta es:\n";
                    imprimirMatriz(T, N);
                }
                break;
            case 7:
                if (!matrizA_cargada) {
                    cout << "Error: La matriz A debe estar cargada para encontrar puntos de silla.\n";
                    cout << "Desea cargar la matriz A ahora? (s/n): ";
                    char cargar;
                    cin >> cargar;
                    if (cargar == 's' || cargar == 'S') {
                        cout << "Ingrese la matriz A:\n";
                        leerMatriz(A, N);
                        matrizA_cargada = true;
                    }
                }
                if (matrizA_cargada) {
                    cout << "La matriz A es:\n";
                    imprimirMatriz(A, N);
                    puntosDeSilla(A, N);
                }
                break;
            case 8: if (matrizA_cargada) {
                    cout << "La matriz A es:\n";
                    imprimirMatriz(A, N);
                }else cout << "Error: La matriz A no esta cargada.\n";
                break;
            case 9: if (matrizB_cargada) {
                    cout << "La matriz B es:\n";
                    imprimirMatriz(B, N);
                }else cout << "Error: La matriz B no esta cargada.\n";
                break;
            case 0:
                cout << "Saliendo del programa...\n";
                break;
            default:
                clearConsole();
                cout << "Opción inválida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}

// Función para leer una matriz desde el teclado
void leerMatriz(int matriz[100][100], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << "Ingrese el valor en la posición [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

// Función para imprimir una matriz en la pantalla
void imprimirMatriz(int matriz[100][100], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para sumar dos matrices
void sumarMatrices(int A[100][100], int B[100][100], int C[100][100], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Función para restar dos matrices
void restarMatrices(int A[100][100], int B[100][100], int C[100][100], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Función para multiplicar dos matrices
void multiplicarMatrices(int A[100][100], int B[100][100], int C[100][100], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Función para transponer una matriz
void transponerMatriz(int A[100][100], int T[100][100], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            T[j][i] = A[i][j];
        }
    }
}

// Función para encontrar y mostrar puntos de silla
void puntosDeSilla(int matriz[100][100], int N) {
    cout << "Puntos de silla (valor, posición):" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int valor = matriz[i][j];
            bool esMinFila = true;
            bool esMaxColumna = true;
            // Verificar si es el mínimo en su fila
            for (int k = 0; k < N; ++k) {
                if (matriz[i][k] < valor) {
                    esMinFila = false;
                    break;
                }
            }
            // Verificar si es el máximo en su columna
            for (int k = 0; k < N; ++k) {
                if (matriz[k][j] > valor) {
                    esMaxColumna = false;
                    break;
                }
            }
            if (esMinFila && esMaxColumna) {
                cout << valor << " en (" << i << ", " << j << ")" << endl;
            }
        }
    }
}

// Función para mostrar el estado de las matrices
void mostrarEstadoMatrices(bool matrizA_cargada, bool matrizB_cargada, int A[100][100], int B[100][100], int N) {
    cout << "Estado de las matrices:\n";
    if (matrizA_cargada) {
        cout << "Matriz A: Cargada\n";
        cout << "Contenido de la matriz A:\n";
        imprimirMatriz(A, N);
    } else {
        cout << "Matriz A: No cargada\n";
    }
    if (matrizB_cargada) {
        cout << "Matriz B: Cargada\n";
        cout << "Contenido de la matriz B:\n";
        imprimirMatriz(B, N);
    } else {
        cout << "Matriz B: No cargada\n";
    }
    cout << endl;
}

void clearConsole() {
    #ifdef __unix__
        system("clear");
    #elif __APPLE__
        system("clear");
    #elif defined(_WIN32) || defined(WIN64)
        system("cls");
    #endif
}