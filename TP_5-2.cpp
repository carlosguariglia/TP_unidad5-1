/*
2. Escribe un programa que lea del teclado una frase y a continuación
 visualice las palabras de la frase en columna, seguida cada una del número
 de letras que la componen.

*/

#include <iostream>
#include <string>
using namespace std;

void clearConsole();
void contarletras(string frase, int letras, int indice);

int main()
{   
    clearConsole();
    string frase;
    int letras = 0;
    int indice = 0;
    int menu = 0;
    do 
    {
        clearConsole();
        cout << "---------------------------------------------------------------------" << endl;
        cout << "*                     MENU PRINCIPAL                                 *" << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "1. Ingresar una frase para contar las letras de cada palabra" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: " << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cin >> menu;
        clearConsole();
        switch (menu)
        {
        case 1:
            contarletras(frase, letras, indice);
            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            cout << "Presione ENTER para volver al menu principal" << endl;
            cin.ignore();
            cin.get();
            break;
        }
    } while (menu != 0);
    return 0;
}

void contarletras(string frase, int letras, int indice)
{   
    clearConsole();
    cin.ignore();
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
    cout << "------------------------------------------" << endl;
    cout << "Presione ENTER para volver al menu principal" << endl;
    cin.get();
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