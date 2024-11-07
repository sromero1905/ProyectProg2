// ModuloReportes.cpp
#include "ModuloReportes.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Implementaci�n del constructor de la clase Venta
Venta::Venta(string f, string nc, string p, int c, double pu, double t)
    : fecha(f), nombreCliente(nc), producto(p), cantidad(c), precioUnitario(pu), total(t) {}

// Funci�n para cargar las ventas desde un archivo
vector<Venta> cargarVentas(const string& nombreArchivo) {
    vector<Venta> ventas;
    ifstream archivo(nombreArchivo);

    if (!archivo) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return ventas;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string fecha, nombreCliente, producto;
        int cantidad;
        double precioUnitario, total;

        getline(ss, fecha, ',');
        getline(ss, nombreCliente, ',');
        getline(ss, producto, ',');
        ss >> cantidad;
        ss.ignore();
        ss >> precioUnitario;
        ss.ignore();
        ss >> total;

        ventas.push_back(Venta(fecha, nombreCliente, producto, cantidad, precioUnitario, total));
    }

    archivo.close();
    return ventas;
}

// Men� de reportes
void menuReportes(const vector<Venta>& ventas) {
    int opcion;
    do {
        cout << "----- Men� de Reportes -----\n";
        cout << "1. Reporte por Fecha\n";
        cout << "2. Reporte por Categor�a\n";
        cout << "3. Reporte por Producto\n";
        cout << "4. Volver\n";
        cout << "Selecciona una opci�n: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Submen� para reporte por fecha
                int fechaOpcion;
                cout << "Selecciona la opci�n para el reporte por fecha:\n";
                cout << "1. Por D�a\n";
                cout << "2. Por Mes\n";
                cout << "3. Por A�o\n";
                cout << "Selecciona una opci�n: ";
                cin >> fechaOpcion;

                string fechaInput;
                switch (fechaOpcion) {
                    case 1: // Reporte por D�a
                        cout << "Ingresa la fecha (YYYY-MM-DD): ";
                        cin >> fechaInput;
                        reporteVentasPorDia(ventas, fechaInput);
                        break;
                    case 2: // Reporte por Mes
                        cout << "Ingresa el mes (YYYY-MM): ";
                        cin >> fechaInput;
                        reporteVentasPorMes(ventas, fechaInput);
                        break;
                    case 3: // Reporte por A�o
                        cout << "Ingresa el a�o (YYYY): ";
                        cin >> fechaInput;
                        reporteVentasPorAnio(ventas, fechaInput);
                        break;
                    default:
                        cout << "Opci�n no v�lida.\n";
                        break;
                }
                break;
            }
            case 2: {
                string categoria;
                cout << "Ingresa la categor�a: ";
                cin >> categoria;
                reporteVentasPorCategoria(ventas, categoria);
                break;
            }
            case 3: {
                string producto;
                cout << "Ingresa el producto: ";
                cin >> producto;
                reporteVentasPorProducto(ventas, producto);
                break;
            }
            case 4:
                cout << "Volviendo al men� principal.\n";
                break;
            default:
                cout << "Opci�n no v�lida.\n";
        }
    } while (opcion != 4);
}

// Reporte de ventas por d�a
void reporteVentasPorDia(const vector<Venta>& ventas, const string& fecha) {
    double totalIngresado = 0.0;
    int cantidadTotal = 0;
    for (const Venta& venta : ventas) {
        if (venta.fecha == fecha) {
            cout << "Venta: " << venta.nombreCliente << " - " << venta.producto << " - $" << venta.total << endl;
            totalIngresado += venta.total;
            cantidadTotal += venta.cantidad;
        }
    }
    cout << "Total ingresado: $" << totalIngresado << endl;
    cout << "Cantidad total de productos vendidos: " << cantidadTotal << endl;
}

// Reporte de ventas por mes
void reporteVentasPorMes(const vector<Venta>& ventas, const string& mes) {
    double totalIngresado = 0.0;
    int cantidadTotal = 0;
    for (const Venta& venta : ventas) {
        if (venta.fecha.substr(0, 7) == mes) {  // Compara solo el a�o y el mes (YYYY-MM)
            cout << "Venta: " << venta.nombreCliente << " - " << venta.producto << " - $" << venta.total << endl;
            totalIngresado += venta.total;
            cantidadTotal += venta.cantidad;
        }
    }
    cout << "Total ingresado en el mes " << mes << ": $" << totalIngresado << endl;
    cout << "Cantidad total de productos vendidos en el mes: " << cantidadTotal << endl;
}

// Reporte de ventas por a�o
void reporteVentasPorAnio(const vector<Venta>& ventas, const string& anio) {
    double totalIngresado = 0.0;
    int cantidadTotal = 0;
    for (const Venta& venta : ventas) {
        if (venta.fecha.substr(0, 4) == anio) {  // Compara solo el a�o (YYYY)
            cout << "Venta: " << venta.nombreCliente << " - " << venta.producto << " - $" << venta.total << endl;
            totalIngresado += venta.total;
            cantidadTotal += venta.cantidad;
        }
    }
    cout << "Total ingresado en el a�o " << anio << ": $" << totalIngresado << endl;
    cout << "Cantidad total de productos vendidos en el a�o: " << cantidadTotal << endl;
}

// Reporte de ventas por categor�a
void reporteVentasPorCategoria(const vector<Venta>& ventas, const string& categoria) {
    double totalIngresado = 0.0;
    int cantidadTotal = 0;
    for (const Venta& venta : ventas) {
        if (venta.producto == categoria) {  // Aqu� se puede ajustar a un criterio m�s complejo
            cout << "Venta: " << venta.nombreCliente << " - " << venta.fecha << " - $" << venta.total << endl;
            totalIngresado += venta.total;
            cantidadTotal += venta.cantidad;
        }
    }
    cout << "Total ingresado en la categor�a " << categoria << ": $" << totalIngresado << endl;
    cout << "Cantidad total de productos vendidos en la categor�a: " << cantidadTotal << endl;
}

// Reporte de ventas por producto
void reporteVentasPorProducto(const vector<Venta>& ventas, const string& producto) {
    double totalIngresado = 0.0;
    int cantidadTotal = 0;
    for (const Venta& venta : ventas) {
        if (venta.producto == producto) {
            cout << "Venta: " << venta.nombreCliente << " - " << venta.fecha << " - $" << venta.total << endl;
            totalIngresado += venta.total;
            cantidadTotal += venta.cantidad;
        }
    }
    cout << "Total ingresado por el producto " << producto << ": $" << totalIngresado << endl;
    cout << "Cantidad total de productos vendidos: " << cantidadTotal << endl;
}
