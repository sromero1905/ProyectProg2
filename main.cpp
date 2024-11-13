#include <iostream>
#include "ModuloInventario.h"
#include "ModuloVentas.h"
#include "ModuloPromociones.h"
#include "ModuloHistorialVentas.h"
#include "ModuloReportes.h"
#include <limits>

using namespace std;

void mostrarMenuPrincipal();

int main() {
    mostrarMenuPrincipal();
    return 0;
}
void mostrarMenuPrincipal() {
    int opcion;
    do {
        cout << "----- Menú Principal -----\n";
        cout << "1. Gestión de Inventario\n";
        cout << "2. Registro de Ventas\n";
        cout << "3. Historial de Ventas\n";
        cout << "4. Reportes\n";
        cout << "5. Salir\n";
        cout << "Selecciona una opción: ";
        cin >> opcion;

        // Validar la entrada
        if (cin.fail()) {
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora la entrada no válida
            cout << "Por favor ingresa un número válido.\n";
            continue; // Vuelve a pedir la opción
        }

        // Ejecuta la opción seleccionada
        switch (opcion) {
            case 1:
                gestionarInventario(); // Llama a la función del módulo de inventario
                break;
            case 2: {
                // Gestión de Ventas
                ModuloVentas moduloVentas;
                moduloVentas.mostrarMenuVentas(); // Llama al menú de ventas
                break;
            }
            case 3:
                mostrarMenuHistorialVentas();  // Llama al menú de historial de ventas
                break;
            case 4:
                Menureporte(); // Llama al menú de reportes
                break;
            case 5:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no válida, intenta de nuevo.\n";
        }
    } while (opcion != 5);
}
