/*
    1. Un archivo de texto contiene información acerca de los productos que
    se venden en un almacén. Lo único que se sabe acerca del número de 
    productos es que no puede superar un cierto valor MaxProductos. 
    De cada producto se guarda información sobre su 
    código identificador (entero positivo), 
    su precio (real) 
    y el número de unidades existentes (entero positivo). 
    
    El formato en el que se guarda la información dentro del archivo es 
    el siguiente:

id1 precio1 unidades1
id2 precio2 unidades2
...
idN precioN unidadesN
‐1

a) Declara un tipo tProducto que represente la información de un producto y
un tipo tLista que mantenga la información de todos los productos.
b) Escribe un subprograma que lea los datos del archivo de texto que almacena
la información, los guarde en la lista y luego los muestre en la pantalla.
c) Escribe un subprograma que encuentre el producto con máximo valor en el
almacén, considerando que el valor del producto i es precioi*unidadesi.
d) Escribe un subprograma que dado un identificador de producto a eliminar
del almacén, lo busque en la lista y lo elimine actualizando la lista como
corresponda.

*/

#include <iostream>
#include <fstream>

using namespace std;

const int MaxProductos = 100;

struct tProducto
{
    int id;
    float precio;
    int unidades;
};

struct tLista
{
    tProducto productos[MaxProductos];  // Lista de productos que tiene un flag (-1) para saber donde termina 
};

void imprimirinventario(tLista lista);
tLista leerarchivo();
void buscarmayorvalor();
void eliminarproducto();
void buscarmayorvalor(tLista lista);
void eliminarproducto(tLista &lista);
void guardarinventario(tLista lista);
void clearConsole();

int main()
{
    int menu=0;
    tLista lista;
    tProducto producto;


    do
    {   
        clearConsole();
        cout << "---------------------------------------------------------------------" << endl;
        cout << "*                     MENU PRINCIPAL                                 *" << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "1. Leer inventario desde archivo e imprimir (el archivo debe existir)" << endl;
        cout << "2. Buscar producto con más valor del inventario)" << endl;
        cout << "3. Eliminar producto del inventario (por nro de ID)" << endl;
        cout << "4. Imprimir inventario" << endl;
        cout << "5. Guardar inventario en archivo" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: " << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cin >> menu;
        clearConsole();
        switch (menu)
        {
        case 1:
            lista = leerarchivo();
            imprimirinventario(lista);
            break;
        case 2:
            buscarmayorvalor(lista);
            break;
        case 3:
            eliminarproducto(lista);
            imprimirinventario(lista);
            break;
        case 4:
            imprimirinventario(lista);
            break;
        case 5:
            guardarinventario(lista);
            break;
        case 0:
            cout << "Gracias por usar el programa" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            cout << "Presione ENTER para volver al menu principal" << endl;
            cin.ignore();
            cin.get();
            break;        
        }
    } while (menu != 0);
    
    return 0;
}


tLista leerarchivo()
{   
    ifstream archivo;
    tLista lista;

    string nombre_archivo="inventario.txt";
    archivo.open(nombre_archivo);

    if(!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo" << endl;
        cout << "El archivo inventario.txt debe existir" << endl;
        cin.ignore();
        cin.get();
        exit(1);
    }
    
    int indice = 0;
    archivo >> lista.productos[indice].id;
    while ( lista.productos[indice].id != -1 )
    {
        archivo >> lista.productos[indice].precio;
        archivo >> lista.productos[indice].unidades;
        indice++;
        archivo >> lista.productos[indice].id;
    }
    archivo.close();

    return lista;
}

void imprimirinventario(tLista lista)
{
    int indice = 0;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|  Inventario                                           |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "| ID \t\t|  Precio \t\t|  Unidades\t|" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    while ( lista.productos[indice].id != -1 )
    {
        cout << "|  " << lista.productos[indice].id << " \t\t|  " << lista.productos[indice].precio << " \t\t\t|  " << lista.productos[indice].unidades << "\t\t|" << endl;
        indice++;
    }
    cout << "|-------------------------------------------------------|" << endl;
    cout << endl;
    cout << "Presione ENTER para volver al menu principal" << endl;
    cin.ignore();
    cin.get();   
}

void buscarmayorvalor(tLista lista)
{
    float max = 0;
    int idmax = -1;
    int indice = 0;
    while ( lista.productos[indice].id != -1 )
    {
        if (lista.productos[indice].precio*lista.productos[indice].unidades > max)
        {
            max = lista.productos[indice].precio*lista.productos[indice].unidades;
            idmax = indice;
        }
        indice++;
    }
    cout << "---------------------------------------------------------------------" << endl;
    cout << "El ID del producto con más valor es: " << lista.productos[idmax].id << endl;
    cout << "Su precio por unidad es: " << lista.productos[idmax].precio << endl;
    cout << "La cantidad de unidades es: " << lista.productos[idmax].unidades << endl;
    cout << "Su valor total es: " << max << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Presione ENTER para volver al menu principal" << endl;
    cin.ignore();
    cin.get();   
}

void eliminarproducto(tLista &lista) 
{
    int id;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Ingrese el ID del producto que desea eliminar: ";
    cin.ignore();
    cin >> id;
    cout << "---------------------------------------------------------------------" << endl;
    int indice=0;
    while ( lista.productos[indice].id != id )
    {   
        indice++;
    }
    if ( lista.productos[indice].id == id )
    {
        while ( lista.productos[indice].id != -1 )
        {
            lista.productos[indice] = lista.productos[indice+1];
            indice++;
        }
        cout << "Se ha borrardo el producto con ID: " << id << endl;
    }
    else
    {
        cout << "ID " << id << " no encontrado" << endl;
        cout << "No se ha podido borrar el producto" <<endl;
    }
    
    cout << "Presione ENTER para volver al menu principal" << endl;
    cin.ignore();
    cin.get();   
}

void guardarinventario(tLista lista)
{
    ofstream archivo;
    string nombre_archivo="inventario.txt";
    archivo.open(nombre_archivo);
    int indice = 0;
    while ( lista.productos[indice].id != -1 )
    {
        archivo << lista.productos[indice].id << endl;
        archivo << lista.productos[indice].precio << endl;
        archivo << lista.productos[indice].unidades << endl;
        indice++;
    }
    archivo << "-1" << endl;
    archivo.close();
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
