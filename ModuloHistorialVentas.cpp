#include "ModuloHistorialVentas.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Implementaci�n de las funciones del historial de ventas
void ModuloHistorialVentas::verHistorialVentas() {
    ifstream file("ventas.txt");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo de ventas.\n";
        return;
    }

    string line;
    cout << "Historial de Ventas:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void ModuloHistorialVentas::buscarPorFecha() {
    int opcionFecha;
    string fecha;
    cout << "1. Buscar por fecha exacta\n";
    cout << "2. Buscar por mes\n";
    cout << "3. Buscar por a�o\n";
    cout << "Selecciona una opci�n: ";
    cin >> opcionFecha;
    cin.ignore(); // Limpiar el buffer de entrada

    switch (opcionFecha) {
        case 1: {
            cout << "Ingrese la fecha exacta (YYYY-MM-DD): ";
            getline(cin, fecha);
            buscarPorFechaExacta(fecha);
            break;
        }
        case 2: {
            cout << "Ingrese el mes (YYYY-MM): ";
            getline(cin, fecha);
            buscarPorMes(fecha);
            break;
        }
        case 3: {
            cout << "Ingrese el a�o (YYYY): ";
            getline(cin, fecha);
            buscarPorAnio(fecha);
            break;
        }
        default:
            cout << "Opci�n no v�lida.\n";
    }
}

void ModuloHistorialVentas::buscarPorFechaExacta(const string& fecha) {
    ifstream file("ventas.txt");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo de ventas.\n";
        return;
    }

    string line;
    cout << "Ventas en la fecha exacta: " << fecha << "\n";
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
    cout << "Ventas en el a�o: " << anio << "\n";
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
    cout << "Ventas de la categor�a: " << categoria << "\n";
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

// Implementaci�n del men� de historial de ventas
void mostrarMenuHistorialVentas() {
    ModuloHistorialVentas historialVentas;
    int opcion;

    do {
        cout << "\n--- Men� Historial de Ventas ---\n";
        cout << "1. Ver historial de todas las ventas\n";
        cout << "2. Buscar ventas por fecha\n";
        cout << "3. Buscar ventas por producto\n";
        cout << "4. Buscar ventas por categor�a\n";
        cout << "5. Volver al men� principal\n";
        cout << "Selecciona una opci�n: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1: {
                cout << "\n--- Historial Completo de Ventas ---\n";
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
            case 4: {
                string categoria;
                cout << "Ingrese el nombre de la categor�a: ";
                getline(cin, categoria);
                historialVentas.buscarPorCategoria(categoria);
                break;
            }
            case 5:
                cout << "Volviendo al men� principal.\n";
                break;
            default:
                cout << "Opci�n no v�lida, intenta de nuevo.\n";
        }
    } while (opcion != 6);
}

