#include <cstdlib>
#include <iostream>

#include "Item.h"
#include "Almacen.h"
#include "Client.h"

using namespace std;

Almacen almacen("rutadelarchivoxd");

void cargarInfoArticulo() {
    string proveedor, nombre, descripcion;
    int peso, tamano, cantidad;
    //getline es para que no explote si le metes espacios al string
    system("clear");
    
    cout << "Ingrese el nombre del proveedor del articulo \n";
    getline(cin, proveedor);
    cout << "Ingrese el nombre del articulo \n";
    getline(cin, nombre);
    cout << "Ingrese la descripcion del articulo \n";
    getline(cin, descripcion);
    cout << "Ingrese el peso del articulo \n";
    cin >> peso;
    cout << "Ingrese las dimensiones del articulo \n";
    cin >> tamano;
    cout << "Cuantos articulos de este tipo desea ingresar? \n";
    cin >> cantidad;
    cin.ignore(); //limpiar buffer

    Item articulo(nombre, descripcion, peso, tamano, proveedor);
    /*Item articulo("vibrador", "vibra xd", 14, 27, "tu mama");
    Item articulo2("anal beads", "te las metes por el ano", 54, 78, "tu tia");
    almacen.almacenarItem(articulo);
    almacen.almacenarItem(articulo2);*/
    //almacen.mostrarStock();
    almacen.almacenarItem(articulo);
    getchar();
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
        cin.ignore(); //limpiar el buffer del input anterior
        
        switch (op) {

            case 1: {  
                cargarInfoArticulo();
            }
            break;

            case 2: {
                system("clear");
                string nombre, apellido, direccion, nombreItem;
                int opC, ans;
                
               /* cout << "Ingrese sus datos de cliente\n";
                cout << "Nombre: ";
                cin >> nombre;
                cout << "\nApellido: ";
                cin >> apellido;
                cin.ignore();
                cout << "\nDireccion: ";
                getline(cin, direccion);
                
                Client cliente(nombre, apellido, direccion);*/
                Client cliente("thanos", "anos", "verano"); //mientras tanto
                
                do {
                    system("clear");
                    cout << "1. Ver la lista de productos \n";
                    cout << "2. Ver su carrito \n";
                    cout << "3. Retirar item del carrito \n";
                    cout << "4. Ir a checkout \n";
                    cout << "0. Regresar \n";
                    cin >> opC;
                    cin.ignore(); //limpiar el buffer del input anterior
                    
                    switch(opC) {
                        case 1: {
                            almacen.cargarStock();
                            almacen.mostrarStock();
                            cout << "\nIngrese el nombre exacto del producto para agregar al carrito \n";
                            getline(cin, nombreItem);
                            //buscar en stock el producto que tenga el nombre y meterlo en el carrito
                            if (almacen.checkDisponible(nombreItem)) {
                                cliente.addToCarrito(almacen.buscarEnStock(nombreItem));
                                cout << "Item agregado al carrito con exito\n";
                            } else {
                                cout << "El item ingresado no esta disponible o no existe\n";
                            }

                            getchar();
                        }
                        break;
                        
                        case 2: {
                            cliente.mostrarCarrito();
                            getchar();
                        } 
                        break;
                        
                        case 3: {
                            cliente.mostrarCarrito();
                            if (!cliente.getCarrito().empty()) {
                                cout << "Ingrese el nombre del item a eliminar \n";
                                getline(cin, nombre);
                                cliente.deleteFromCarrito(nombre);
                            }
                            
                            getchar();
                        }
                        break;
                        
                        case 4: {
                            cliente.mostrarCarrito();
                            if (!cliente.getCarrito().empty()) {
                                cout << "Desea proceder a comprar estos items? \n";
                                cout << "1. Si \n";
                                cout << "2. No \n";
                                cin >> ans;
                                cin.ignore(); //limpiar buffer
                                if (ans == 1) {
                                    almacen.retirarItems(cliente.getCarrito());
                                    cout << "\nSu compra se realizo con exito, a continuacion se mostrara el proceso de transito de su paquete\n";
                                    almacen.manejarEnvio(cliente.getDireccion(), cliente.getCarrito());
                                    cliente.limpiarCarrito(); 
                                } else if (ans != 2) 
                                    cout << "Opcion invalida\n";
                            }
                            getchar();
                        }
                        break;
                        
                        case 0: {
                        }
                        break;
                        
                        default: {
                            cout << "Opcion invalida, por favor presione enter e ingrese una opcion valida \n";
                            getchar();
                        }
                    }
                } while (opC != 0);    
            }
            break;

            case 0: {
                exit(0);
            } 
            
            default: {
                cout << "Opcion invalida, por favor presione enter e ingrese una opcion valida \n";
                getchar();
            }
        }
        
        system("clear");
    } while (op != 0);

    return 0;
}