#include <cstdlib>
#include <iostream>
#include <windows.h>

#include "Item.h"
#include "Almacen.h"

using namespace std;

Almacen almacen("rutadelarchivoxd");

void cargarInfoArticulo() {
    string proveedor, nombre, descripcion;
    int peso, tamano, cantidad;
    
    system("clear");
    /*cout << "Ingrese el nombre del proveedor del articulo \n";
    cin >> proveedor;
    cout << "Ingrese el nombre del articulo \n";
    cin >> nombre;
    cout << "Ingrese la descripcion del articulo \n";
    cin >> descripcion;
    cout << "Ingrese el peso del articulo \n";
    cin >> peso;
    cout << "Ingrese las dimensiones del articulo \n";
    cin >> tamano;
    cout << "Cuantos articulos de este tipo desea ingresar? \n";
    cin >> cantidad;*/

    //Item articulo(nombre, descripcion, peso, tamano, proveedor);
    Item articulo("vibrador", "vibra xd", 14, 27, "tu mama");
    Item articulo2("anal beads", "te las metes por el ano", 54, 78, "tu tia");
    almacen.almacenarItem(articulo);
    almacen.almacenarItem(articulo2);
    almacen.mostrarStock();
    getchar(); getchar();
}

int main() {
    int op;
    
    do {
        system("clear");
        cout << "Seleccione una opcion \n" <<
                "1. Ingresar un producto al almacen \n" <<
                "2. Realizar una compra \n" <<
                "0. Salir del programa \n";
        cin >> op;

        switch (op) {

            case 1: {  
                cargarInfoArticulo();
            }
            break;

            case 2: {
                
            }
            break;

            case 0: {
                exit(0);
            } 
            
            default: {
                cout << "Opcion invalida, por favor presione enter e ingrese una opcion valida \n";
                getchar(); getchar();
            }
        }
        
        system("clear");
    } while (op != 0);

    return 0;
}

