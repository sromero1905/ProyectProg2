#include "modulohistorialventas.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map> // Para mapear ID de categorías

using namespace std;

void ModuloHistorialVentas::verHistorialVentas() {
    ifstream file("ventas.txt");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo de ventas.\n";
        return;
    }

    string line;
    cout << "--- Historial Completo de Ventas ---\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void ModuloHistorialVentas::buscarPorFecha() {
    string fecha;
    cout << "Ingrese la fecha (ejemplo: 2023-12-31): ";
    getline(cin, fecha);

    ifstream file("ventas.txt");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo de ventas.\n";
        return;
    }

    string line;
    cout << "Ventas en la fecha: " << fecha << "\n";
    while (getline(file, line)) {
        if (line.find(fecha) != string::npos) {
            cout << line << endl;
        }
    }
    file.close();
}

void ModuloHistorialVentas::buscarPorMes(const string& mes) {
    ifstream file("ventas.txt");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo de ventas.\n";
        return;
    }

    string line;
    cout << "Ventas en el mes: " << mes << "\n";
    while (getline(file, line)) {
        if (line.find(mes) != string::npos) {
            cout << line << endl;
        }
    }
    file.close();
}

void ModuloHistorialVentas::buscarPorAnio(const string& anio) {
    ifstream file("ventas.txt");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo de ventas.\n";
        return;
    }

    string line;
    cout << "Ventas en el año: " << anio << "\n";
    while (getline(file, line)) {
        if (line.find(anio) != string::npos) {
            cout << line << endl;
        }
    }
    file.close();
}

void ModuloHistorialVentas::buscarPorCategoria(const string& categoria) {
    ifstream file("ventas.txt");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo de ventas.\n";
        return;
    }

    string line;
    cout << "Ventas de la categoría: " << categoria << "\n";
    while (getline(file, line)) {
        if (line.find(categoria) != string::npos) {
            cout << line << endl;
        }
    }
    file.close();
}

void ModuloHistorialVentas::buscarPorProducto(const string& producto) {
    ifstream file("ventas.txt");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo de ventas.\n";
        return;
    }

    string line;
    cout << "Ventas del producto: " << producto << "\n";
    while (getline(file, line)) {
        if (line.find(producto) != string::npos) {
            cout << line << endl;
        }
    }
    file.close();
}

// Implementación del menú de historial de ventas
void mostrarMenuHistorialVentas() {
    ModuloHistorialVentas historialVentas;
    int opcion;

    do {
        cout << "\n--- Menú Historial de Ventas ---\n";
        cout << "1. Ver historial de todas las ventas\n";
        cout << "2. Buscar ventas por fecha\n";
        cout << "3. Buscar ventas por producto\n";
        cout << "4. Volver al menú principal\n";
        cout << "Selecciona una opción: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1: {
                historialVentas.verHistorialVentas();
                break;
            }
            case 2: {
                historialVentas.buscarPorFecha();
                break;
            }
            case 3: {
                string producto;
                cout << "Ingrese el nombre del producto: ";
                getline(cin, producto);
                historialVentas.buscarPorProducto(producto);
                break;
            }


            case 5:
                cout << "Volviendo al menú principal.\n";
                break;
            default:
                cout << "Opción no válida, intenta de nuevo.\n";
        }
    } while (opcion != 5);
}
