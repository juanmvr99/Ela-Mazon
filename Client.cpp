#include "Client.h"
#include "Almacen.h"

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
