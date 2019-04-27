#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
using namespace std;

class Client {
private:
    string nombre;
    string apellido;
    string direccion;
    
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
};

#endif /* CLIENT_H */

