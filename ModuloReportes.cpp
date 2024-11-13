#include "ModuloReportes.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <limits>

// Cargar ventas desde archivo de texto
vector<Venta> cargarVentas() {
    vector<Venta> ventas;
    ifstream archivo("ventas.txt");
    string linea;

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string fecha, producto, cantidadStr, precioUnitarioStr, totalStr;

        // Separar datos por comas
        getline(ss, fecha, ',');
        getline(ss, producto, ',');
        getline(ss, cantidadStr, ',');
        getline(ss, precioUnitarioStr, ',');
        getline(ss, totalStr, ',');

        // Convertir los valores de cantidad, precio unitario y total
        int cantidad = stoi(cantidadStr);
        double precioUnitario = stod(precioUnitarioStr);
        double total = stod(totalStr);

        // Crear la venta y agregarla al vector
        ventas.emplace_back(fecha, producto, cantidad, precioUnitario, total);
    }

    archivo.close();
    return ventas;
}

// Encontrar el producto más y menos vendido
void encontrarProductoMasYMenosVendido(const unordered_map<string, int>& productosVendidos, string& productoMasVendido, string& productoMenosVendido) {
    int maxVentas = 0, minVentas = INT_MAX;

    for (const auto& item : productosVendidos) {
        if (item.second > maxVentas) {
            maxVentas = item.second;
            productoMasVendido = item.first;
        }
        if (item.second < minVentas) {
            minVentas = item.second;
            productoMenosVendido = item.first;
        }
    }
}

// Reporte de ventas por día
void reporteVentasPorDia(const vector<Venta>& ventas, const string& fecha) {
    int totalProductos = 0;
    double totalRecaudado = 0.0;
    unordered_map<string, int> productosVendidos;

    for (const Venta& venta : ventas) {
        if (venta.fecha == fecha) {
            totalProductos += venta.cantidad;
            totalRecaudado += venta.total;
            productosVendidos[venta.producto] += venta.cantidad;
        }
    }

    string productoMasVendido, productoMenosVendido;
    encontrarProductoMasYMenosVendido(productosVendidos, productoMasVendido, productoMenosVendido);

    cout << "Reporte de ventas para el dia " << fecha << ":\n";
    cout << "Total de productos vendidos: " << totalProductos << "\n";
    cout << "Total recaudado: $" << totalRecaudado << "\n";
    cout << "Producto mas vendido: " << productoMasVendido << "\n";
    cout << "Producto menos vendido: " << productoMenosVendido << "\n";
}

// Reporte de ventas por mes
void reporteVentasPorMes(const vector<Venta>& ventas, const string& mes) {
    int totalProductos = 0;
    double totalRecaudado = 0.0;
    unordered_map<string, int> productosVendidos;

    for (const Venta& venta : ventas) {
        if (venta.fecha.substr(0, 7) == mes) {
            totalProductos += venta.cantidad;
            totalRecaudado += venta.total;
            productosVendidos[venta.producto] += venta.cantidad;
        }
    }

    string productoMasVendido, productoMenosVendido;
    encontrarProductoMasYMenosVendido(productosVendidos, productoMasVendido, productoMenosVendido);

    cout << "Reporte de ventas para el mes " << mes << ":\n";
    cout << "Total de productos vendidos: " << totalProductos << "\n";
    cout << "Total recaudado: $" << totalRecaudado << "\n";
    cout << "Producto mas vendido: " << productoMasVendido << "\n";
    cout << "Producto menos vendido: " << productoMenosVendido << "\n";
}

// Reporte de ventas por año
void reporteVentasPorAnio(const vector<Venta>& ventas, const string& anio) {
    int totalProductos = 0;
    double totalRecaudado = 0.0;
    unordered_map<string, int> productosVendidos;

    for (const Venta& venta : ventas) {
        if (venta.fecha.substr(0, 4) == anio) {
            totalProductos += venta.cantidad;
            totalRecaudado += venta.total;
            productosVendidos[venta.producto] += venta.cantidad;
        }
    }

    string productoMasVendido, productoMenosVendido;
    encontrarProductoMasYMenosVendido(productosVendidos, productoMasVendido, productoMenosVendido);

    cout << "Reporte de ventas para el año " << anio << ":\n";
    cout << "Total de productos vendidos: " << totalProductos << "\n";
    cout << "Total recaudado: $" << totalRecaudado << "\n";
    cout << "Producto mas vendido: " << productoMasVendido << "\n";
    cout << "Producto menos vendido: " << productoMenosVendido << "\n";
}

void Menureporte() {
    vector<Venta> ventas = cargarVentas();
    int opcion;
    string fecha, mes, anio;

    do {
        cout << "\nMenu de Reportes:\n";
        cout << "1. Reporte por dia\n";
        cout << "2. Reporte por mes\n";
        cout << "3. Reporte por anio\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Verificar si la entrada es un número válido
        if (cin.fail()) {
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada no válida
            cout << "Por favor, ingrese un número válido.\n";
            continue; // Volver a pedir la opción
        }

        switch (opcion) {
            case 1:
                cout << "Ingrese la fecha (YYYY-MM-DD): ";
                cin >> fecha;
                reporteVentasPorDia(ventas, fecha);
                break;
            case 2:
                cout << "Ingrese el mes (YYYY-MM): ";
                cin >> mes;
                reporteVentasPorMes(ventas, mes);
                break;
            case 3:
                cout << "Ingrese el anio (YYYY): ";
                cin >> anio;
                reporteVentasPorAnio(ventas, anio);
                break;
            case 4:
                cout << "Saliendo del menu de reportes.\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 4);
}
