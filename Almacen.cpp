#include "Almacen.h"
#include <iostream>
#include <fstream>

void Almacen::almacenarItem(Item item) {
    //aqui el item se va a guardar en el archivo del almacen
    ofstream archivo("almacen.txt", ios::app); //archivo para escribir en append (se crea o se abre en la carpeta del proyecto)
    
    if (!archivo.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo";
        exit(1);
    }
    archivo << "Nombre: " << item.getNombre() << "\n";
    archivo << "Descripcion: " << item.getDescripcion() << "\n";
    archivo << "Peso: " << item.getPeso() << "\n";
    archivo << "Tamano: " << item.getTamano() << "\n";
    archivo << "Proveedor: " << item.getProveedor() << "\n";
    archivo << "-------------------------------------------------\n";
    archivo.close();    
    
    stock.push_back(item);
    cout << "se almaceno el articulo " << item.getNombre() << endl;
}

void Almacen::retirarItem(Item item) {
    
}

void Almacen::mostrarStock() {
    vector<Item>::iterator i;
    
    for (i=stock.begin(); i!=stock.end(); ++i) {
        cout << i->getNombre() <<"\n";
    }
}

