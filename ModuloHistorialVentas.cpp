#include "modulohistorialventas.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <limits>

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
    cin.ignore(); // Limpiar cualquier entrada residual
    getline(cin, fecha);

    ifstream file("ventas.txt");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo de ventas.\n";
        return;
    }

    string line;
    bool ventasEncontradas = false;
    cout << "Ventas en la fecha: " << fecha << "\n";
    while (getline(file, line)) {
        // Buscar la fecha al inicio de la l�nea
        if (line.find(fecha) == 0) { // Busca si la l�nea empieza con la fecha
            cout << line << endl;
            ventasEncontradas = true;
        }
    }

    if (!ventasEncontradas) {
        cout << "No se encontraron ventas para la fecha: " << fecha << endl;
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


void mostrarMenuHistorialVentas() {
    ModuloHistorialVentas historialVentas;
    int opcion;

    do {
        cout << "\n--- Men� Historial de Ventas ---\n";
        cout << "1. Ver historial de todas las ventas\n";
        cout << "2. Buscar ventas por fecha\n";
        cout << "3. Buscar ventas por producto\n";
        cout << "4. Volver al men� principal\n";
        cout << "Selecciona una opci�n: ";
        cin >> opcion;

        // Validar la entrada
        if (cin.fail()) {
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora la entrada no v�lida
            cout << "Por favor ingresa un n�mero v�lido.\n";
            continue; // Vuelve a pedir la opci�n
        }

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
                cin.ignore();
                getline(cin, producto);
                historialVentas.buscarPorProducto(producto);
                break;
            }
            case 4:
                cout << "Volviendo al men� principal.\n";
                break;
            default:
                cout << "Opci�n no v�lida, intenta de nuevo.\n";
        }
    } while (opcion != 4);
}
