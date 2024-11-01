#include <iostream>
#include "ModuloInventario.h"
#include "ModuloVentas.h"
#include "ModuloPromociones.h"
#include "ModuloHistorialVentas.h"
#include "ModuloReportes.h"

void mostrarMenuPrincipal();

int main() {
    mostrarMenuPrincipal();
    return 0;
}

void mostrarMenuPrincipal() {
    int opcion;
    do {
        std::cout << "----- Menú Principal -----" << std::endl;
        std::cout << "1. Gestión de Inventario" << std::endl;
        std::cout << "2. Registro de Ventas" << std::endl;
        std::cout << "3. Gestión de Promociones" << std::endl;
        std::cout << "4. Historial de Ventas" << std::endl;
        std::cout << "5. Reportes" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Selecciona una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                gestionarInventario();
                break;
            case 2:
                registrarVenta();
                break;
            case 3:
                gestionarPromociones();
                break;
            case 4:
                verHistorialVentas();
                break;
            case 5:
                generarReportes();
                break;
            case 6:
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cout << "Opción no válida, intenta de nuevo." << std::endl;
        }
    } while (opcion != 6);
}

