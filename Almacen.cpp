#include "Almacen.h"

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
    
    cout << "se almaceno el articulo " << item.getNombre() << endl;
}

void Almacen::retirarItems(vector<Item> carrito) {
    //cuando ya se haga la compra quitar los items correspondiente del stock y actualizar el archivo
    vector<Item>::iterator i; //iterador para el carrito
    vector<Item>::iterator j; //iterador para el stock
    
    for (i=carrito.begin(); i!=carrito.end(); ++i) {
        for (j=stock.begin(); j!=stock.end(); ++j) {
            if (i->getNombre() == j->getNombre()) {
                stock.erase(j);
                break; //para que borre solo el primero que consiga
            }
        }
    }
    actualizarAlmacen();    
}

void Almacen::actualizarAlmacen() {
    //cuando se hace la compra y se hayan sacado los items del stock se actualiza el archivo con el nuevo stock
    ofstream archivo("almacen.txt"); 
    
    if (!archivo.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo para actualizarlo";
        exit(1);
    }
    archivo << "|---------------------------------------------ALMACEN---------------------------------------------|\n";
    
    vector<Item>::iterator i;
    for (i=stock.begin(); i!=stock.end(); ++i) {
        archivo << "Nombre: " << i->getNombre() << "\n";
        archivo << "Descripcion: " << i->getDescripcion() << "\n";
        archivo << "Peso: " << i->getPeso() << "\n";
        archivo << "Tamano: " << i->getTamano() << "\n";
        archivo << "Proveedor: " << i->getProveedor() << "\n";
        archivo << "-------------------------------------------------\n";
    }
    archivo.close();
}

void Almacen::cargarStock() {
    //carga el archivo almacen.txt a un vector de items (el stock)
    ifstream archivo("almacen.txt"); //abierto en modo lectura
    
    if (!archivo.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo para cargar el stock";
        exit(1);
    }
    
    stock.clear(); //se limpia el stock en caso de que se haya hecho una compra anteriormente en la misma corrida del programa
    
    string line;
    int i = 0;
    string arr[5];
    
    while (getline(archivo, line)) {
        if(line[0] == '|' || line[0] == '-')
            continue; //saltarse las lineas separadoras
        
        size_t pos = line.find(": "); //se busca el : en la linea para copiar desde ahi los datos del item (2 caracteres despues del :)
        if (pos != string::npos) {
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

Item Almacen::buscarEnStock(string nombre) {
    //devuelve una copia del objeto item con el nombre solicitado
    vector<Item>::iterator i;

    for (i=stock.begin(); i!=stock.end(); ++i) {
        if (i->getNombre() == nombre) {
            Item x(i->getNombre(), i->getDescripcion(), i->getPeso(), i->getTamano(), i->getProveedor());
            return x;
        }    
    }
}

bool Almacen::checkDisponible(string nombre) {
    vector<Item>::iterator i;
            
    for (i=stock.begin(); i!=stock.end(); i++) {
        if (i->getNombre() == nombre)
            return true;
    }
    return false;
}

void Almacen::manejarEnvio(string direccion, vector<Item> items) {
    Paquete paquete; 
    //empaquetado de los productos y asignacion del destino
    paquete.empaquetar(items);
    paquete.asignarDireccion(direccion);
    //proceso de envio
    paquete.enviar();
    paquete.llegada();
}
