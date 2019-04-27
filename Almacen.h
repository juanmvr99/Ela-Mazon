#ifndef ALMACEN_H
#define ALMACEN_H

#include "Item.h"
#include <iostream>
#include <vector>
using namespace std;

class Almacen {
    
public:
    string ruta; //direccion del archivo donde esta la vaina (no se si es necesario)
    vector<Item> stock; //para sacar las vainas del archivo y usarlas
    
    Almacen(string ruta) {
        this->ruta = ruta;
    }
    
    void almacenarItem(Item item);
    void retirarItem(Item item);
    void mostrarStock();
};

#endif /* ALMACEN_H */
