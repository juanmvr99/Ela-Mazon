#ifndef PAQUETE_H
#define PAQUETE_H

#include "Item.h"
#include <iostream>
#include <vector>
#include <windows.h> //para el sleep
using namespace std;

class Paquete {
private:
    string destino;
    vector<Item> contenido;
    string estado;

public:
    Paquete() {
        this->destino = "";
        estado = "En espera";
    }
    void empaquetar(vector<Item> items);
    void asignarDireccion(string direccion);
    void enviar();
    void llegada();
};

#endif /* PAQUETE_H */

