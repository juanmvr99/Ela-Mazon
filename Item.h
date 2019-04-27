#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

class Item {
    
private:
    string nombre;
    string descripcion;
    int peso;
    int tamano;
    string proveedor;
    
public:
    Item(string nombre, string descripcion, int peso, int tamano, string proveedor) {
        this->nombre = nombre;
        this->descripcion = descripcion;
        this->peso = peso;
        this->tamano = tamano;
        this->proveedor = proveedor;
    }
    string getNombre() {
        return nombre;
    }
    string getDescripcion() {
        return descripcion;
    }
    int getPeso() {
        return peso;
    }
    int getTamano() {
        return tamano;
    }
    string getProveedor() {
        return proveedor;
    }    
};

#endif /* ITEM_H */

