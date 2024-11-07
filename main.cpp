#include <iostream>
#include "ModuloInventario.h"
#include "ModuloVentas.h"
#include "ModuloPromociones.h"
#include "ModuloHistorialVentas.h"
#include "ModuloReportes.h"

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
        cout << "3. Gesti�n de Promociones\n";
        cout << "4. Historial de Ventas\n";
        cout << "5. Reportes\n";
        cout << "6. Salir\n";
        cout << "Selecciona una opci�n: ";
        cin >> opcion;

        // Ejecuta la opci�n seleccionada
        switch (opcion) {
            case 1:
                gestionarInventario(); // Llama a la funci�n del m�dulo de inventario
                break;
            case 4:
                mostrarMenuHistorialVentas();  // Llama al men� de historial de ventas
                break;
            case 5: {
                Menureporte();

                break;
            }
            case 6:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opci�n no v�lida, intenta de nuevo.\n";
        }
    } while (opcion != 6);
}
