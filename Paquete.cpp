#include "Paquete.h"

void Paquete::empaquetar(vector<Item> items) {
    contenido = items; 
    estado = "Empaquetado";
}

void Paquete::asignarDireccion(string dir) {
    destino = dir;
    estado = "Con destino fijado";
    cout << "Su paquete ha sido enviado...\n";
    Sleep(1500);
}

void Paquete::enviar() {
    estado = "En transito";
    cout << "Su paquete esta en transito...\n";
    Sleep(1500);
}

void Paquete::llegada() {
    estado = "Entregado";
    cout << "Su paquete ha sido entregado!\n";
}


