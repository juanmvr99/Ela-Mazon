#include "Almacen.h"
#include <iostream>
#include <fstream>

void Almacen::almacenarItem(Item item) {
    //aqui el item se va a guardar en el archivo del almacen
    ofstream archivo("almacen.txt", ios::app); //archivo para escribir en append (se crea o se abre en la carpeta del proyecto)
    
    if (!archivo.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo para ingresar el item";
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

//carga el archivo almacen.txt a un vector de items
void Almacen::cargarStock() {
    ifstream archivo("almacen.txt"); //abierto en modo lectura
    
    if (!archivo.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo para cargar el stock";
        exit(1);
    }
    
    string line;
    string nombre, desc, peso, tam, prov;
    int i = 0;
    string arr[5];
    
    while (getline(archivo, line)) {
        if(line[0] == '|' || line[0] == '-')
            continue; //saltarse las lineas separadoras
        
        size_t pos = line.find(": "); //se busca el : en la linea para copiar desde ahi los datos del item (2 caracteres despues del :)
        if (pos != string::npos && !archivo.eof()) {
            pos += 2 ;
            line = line.substr(pos);
            arr[i] = line;
            if (i == 4) {   //cuando se hayan copiado todos los atributos del item se crea un objeto y se mete al stock
                Item x(arr[0], arr[1], stoi(arr[2]) , stoi(arr[3]), arr[4]);
                stock.push_back(x);
                i = -1; //reiniciar cuenta
            }
            i++;
        }
    }
    archivo.close();
}

void Almacen::mostrarStock() {
    
    cargarStock();
    vector<Item>::iterator i;
    cout << "---Lista de productos---\n\n";

    for (i=stock.begin(); i!=stock.end(); ++i) {
        cout << "nombre: " << i->getNombre() <<"\n";
        cout << "descripcion: " << i->getDescripcion() <<"\n";
        cout << "peso: " << i->getPeso() <<"\n";
        cout << "tamano: " << i->getTamano() <<"\n";
        cout << "proveedor: " << i->getProveedor() <<"\n";
        cout << "------------------------------------\n";
    }
}

