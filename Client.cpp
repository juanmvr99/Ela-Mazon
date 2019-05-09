#include "Client.h"

void Client::addToCarrito(Item item) {
   
    carrito.push_back(item);
}

void Client::mostrarCarrito() {
    
    if (carrito.empty()) {
        cout << "Su carrito esta vacio\n";
        return;
    }
        
    vector<Item>::iterator i;
    cout << "---Carrito de compras---\n";

    for (i=carrito.begin(); i!=carrito.end(); ++i) {
        cout << "nombre: " << i->getNombre() <<"\n";
    }
}

void Client::deleteFromCarrito(string nombre) {
    
    if (carrito.empty()) {
        cout << "Su carrito esta vacio\n";
        return;
    }
    
    vector<Item>::iterator i;
    for (i=carrito.begin(); i!=carrito.end(); ++i) {
        if(i->getNombre() == nombre) {
            carrito.erase(i);
            cout << "Item borrado con exito \n";
            return;
        }
    }
    
    cout << "El nombre del item ingresado no existe en su carrito \n";
}

void Client::limpiarCarrito() {
    carrito.clear();
}
