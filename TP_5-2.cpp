/*
2. Escribe un programa que lea del teclado una frase y a continuación
 visualice las palabras de la frase en columna, seguida cada una del número
 de letras que la componen.

*/

#include <iostream>
#include <string>
using namespace std;

void clearConsole();

int main()
{   
    clearConsole();
    string frase;
    int letras = 0;
    int indice = 0;
    cout << "Ingrese una frase" << endl;
    getline(cin, frase);
    
    clearConsole();
    cout << "------------------------------------------" << endl;
    cout << "La frase: " << frase << endl;
    cout << "------------------------------------------" << endl;
    cout << "Palabra              \tCantidad de Letras" << endl;
    cout << "------------------------------------------" << endl;


    while (indice < frase.length())
    {
        if (frase[indice] == ' ')
        {
            cout << "\t          \t" << letras << endl;
            letras = 0;
        }
        else
        {
            cout << frase[indice];
            letras++;
        }
        indice++;
    }
    if (frase[frase.length() - 1] != ' ')   // este if es para chequear si hay un espacio al final de la frase
    {
        cout << "\t          \t" << letras << endl;
    }
    

    return 0;
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