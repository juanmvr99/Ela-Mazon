#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <vector>
#include "Item.h"
using namespace std;

class Client {
private:
    string nombre;
    string apellido;
    string direccion;
    vector<Item> carrito;
    
public:
    Client(string nombre, string apellido, string direccion) {
        this->nombre = nombre;
        this->apellido = apellido;
        this->direccion = direccion;
    }
    string getNombre() {
        return nombre;
    }
    string getApellido() {
        return apellido;
    }
    string getDireccion() {
        return direccion;
    }
    vector<Item> getCarrito() {
        return carrito;
    }
    void addToCarrito(Item item);
    void mostrarCarrito();
    void deleteFromCarrito(string nombre);
};

#endif /* CLIENT_H */

