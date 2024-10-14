#include <iostream>
#include <string>
#include "HashMap/Lista.h"
#include "HashMap/HashMapList.h" 
using namespace std;

// Función hash simple para cadenas
unsigned int hashString(int dni) { // Cambiado a string en lugar de const string&
    unsigned int hash = 0;
    hash=dni%11;
    return hash;
}

int main() {
    unsigned int tamanoTabla = 11; // Tamaño de la tabla hash
    HashMapList<int, string> gestion(tamanoTabla, hashString);

    int opcion, dni;
    string candidato;
    

    do {
        cout << "1. Registrar un voto.\n";
        cout << "2. Verificar a quien votó por su número de candidatoentificación.\n";
        cout << "3. Eliminar un voto.\n";
        cout << "4. Imprimir la lista completa de votos registrados.\n";
        cout << "0. Salir\n";
        cout << "Selecciona una opcion: \n";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el dni: ";
                cin >> dni;
                cout << "Ingrese el nombre del candidato: ";
                cin>>candidato;
                try{
                    gestion.put(dni, candidato);
                    cout << "Voto agregada correctamente.\n";
                }catch(int e){
                    if(e==409)
                        cout << "colision, se agregó a la lista.\n";
                }


                break;

            case 2:
                cout << "Ingrese la dni a buscar: ";
                cin >> dni;
                try {
                    candidato = gestion.get(dni);
                    cout << "candidato de " << dni << ": " << candidato << endl;
                } catch (int e) {
                    if (e == 404) {
                        cout << "Voto no encontrada.\n";
                    } else {
                        cout << "Error: Conflicto en la búsqueda.\n";
                    }
                }
                break;

            case 3:
                cout << "Ingrese la dni a eliminar: ";
                cin >> dni;
                gestion.remove(dni);
                cout << "Voto eliminado correctamente (si existia).\n";
                break;

            case 4:
                cout << "Todos los votos en la gestion:\n";
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
