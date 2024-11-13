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
        cout << "----- Men� Principal -----\n";
        cout << "1. Gesti�n de Inventario\n";
        cout << "2. Registro de Ventas\n";
        cout << "3. Historial de Ventas\n";
        cout << "4. Reportes\n";
        cout << "5. Salir\n";
        cout << "Selecciona una opci�n: ";
        cin >> opcion;

        // Validar la entrada
        if (cin.fail()) {
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora la entrada no v�lida
            cout << "Por favor ingresa un n�mero v�lido.\n";
            continue; // Vuelve a pedir la opci�n
        }

        // Ejecuta la opci�n seleccionada
        switch (opcion) {
            case 1:
                gestionarInventario(); // Llama a la funci�n del m�dulo de inventario
                break;
            case 2: {
                // Gesti�n de Ventas
                ModuloVentas moduloVentas;
                moduloVentas.mostrarMenuVentas(); // Llama al men� de ventas
                break;
            }
            case 3:
                mostrarMenuHistorialVentas();  // Llama al men� de historial de ventas
                break;
            case 4:
                Menureporte(); // Llama al men� de reportes
                break;
            case 5:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opci�n no v�lida, intenta de nuevo.\n";
        }
    } while (opcion != 5);
}
