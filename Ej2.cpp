#include <iostream>
#include <string>
#include "HashMap/HashMap.h" 
using namespace std;

// Función hash simple para cadenas
unsigned int hashString(int clave) { // Cambiado a string en lugar de const string&
    unsigned int hash = 0;
    hash=clave%11;
    return hash;
}

int main() {
    unsigned int tamanoTabla = 11; // Tamaño de la tabla hash
    HashMap<int, string> gestion(tamanoTabla, hashString);

    int opcion, clave;
    string id;

    do {
        cout << "1. Agregar un nuevo empleado.\n";
        cout << "2. Buscar un empleado por su número de identificación.\n";
        cout << "3. Eliminar un empleado del sistema.\n";
        cout << "4. Imprimir la lista completa de empleados.\n";
        cout << "0. Salir\n";
        cout << "Selecciona una opcion: \n";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese la clave: ";
                cin >> clave;
                cout << "Ingrese el nombre: ";
                cin>>id;
                try{
                    gestion.put(clave, id);
                    cout << "Persona agregada correctamente.\n";
                }catch(int e){
                    if(e==409)
                        cout << "colision, intente otra.\n";
                }


                break;

            case 2:
                cout << "Ingrese la clave a buscar: ";
                cin >> clave;
                try {
                    id = gestion.get(clave);
                    cout << "id de " << clave << ": " << id << endl;
                } catch (int e) {
                    if (e == 404) {
                        cout << "Persona no encontrada.\n";
                    } else {
                        cout << "Error: Conflicto en la búsqueda.\n";
                    }
                }
                break;

            case 3:
                cout << "Ingrese la clave a eliminar: ";
                cin >> clave;
                gestion.remove(clave);
                cout << "Persona eliminada correctamente (si existia).\n";
                break;

            case 4:
                cout << "Todas las palabras en el gestion:\n";
                gestion.print(); // Imprimir todas las entradas
                break;

            case 0:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida. Intenta de nuevo.\n";
        }

        cout << endl;

    } while (opcion != 0);

    return 0;
}
