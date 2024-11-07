#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
using namespace std;

// Clase Venta
class Venta {
public:
    string fecha;
    string nombreCliente;
    string producto;
    int cantidad;
    double precioUnitario;
    double total;

    Venta(string f, string nc, string p, int c, double pu, double t)
        : fecha(f), nombreCliente(nc), producto(p), cantidad(c), precioUnitario(pu), total(t) {}
};

// Función para cargar las ventas desde un archivo
vector<Venta> cargarVentas() {
    vector<Venta> ventas;
    string nombreArchivo = "ventas.txt";

    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return ventas;
    }

    string linea;
    while (getline(archivo, linea)) {
        if (!linea.empty()) {
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
    }

    archivo.close();
    return ventas;
}

// Función para encontrar el producto más y menos vendido
void encontrarProductoMasYMenosVendido(const unordered_map<string, int>& productosVendidos, string& productoMasVendido, string& productoMenosVendido) {
    int maxVentas = 0, minVentas = INT_MAX;

    for (const auto& [producto, cantidad] : productosVendidos) {
        if (cantidad > maxVentas) {
            maxVentas = cantidad;
            productoMasVendido = producto;
        }
        if (cantidad < minVentas) {
            minVentas = cantidad;
            productoMenosVendido = producto;
        }
    }
}

// Reporte de ventas por día
void reporteVentasPorDia(const vector<Venta>& ventas, const string& fecha) {
    double totalIngresado = 0.0;
    int cantidadTotal = 0;
    unordered_map<string, int> productosVendidos;
    bool ventasEncontradas = false;

    for (const Venta& venta : ventas) {
        if (venta.fecha == fecha) {
            cout << "Venta: " << venta.nombreCliente << " - " << venta.producto << " - $" << venta.total << endl;
            totalIngresado += venta.total;
            cantidadTotal += venta.cantidad;
            productosVendidos[venta.producto] += venta.cantidad;
            ventasEncontradas = true;
        }
    }

    if (!ventasEncontradas) {
        cout << "No se encontraron ventas para la fecha " << fecha << endl;
    } else {
        cout << "Total ingresado: $" << totalIngresado << endl;
        cout << "Cantidad total de productos vendidos: " << cantidadTotal << endl;

        string productoMasVendido, productoMenosVendido;
        encontrarProductoMasYMenosVendido(productosVendidos, productoMasVendido, productoMenosVendido);

        cout << "Producto más vendido: " << productoMasVendido << endl;
        cout << "Producto menos vendido: " << productoMenosVendido << endl;
    }
}

// Reporte de ventas por mes
void reporteVentasPorMes(const vector<Venta>& ventas, const string& mes) {
    double totalIngresado = 0.0;
    int cantidadTotal = 0;
    unordered_map<string, int> productosVendidos;

    for (const Venta& venta : ventas) {
        if (venta.fecha.substr(0, 7) == mes) {
            totalIngresado += venta.total;
            cantidadTotal += venta.cantidad;
            productosVendidos[venta.producto] += venta.cantidad;
        }
    }

    if (productosVendidos.empty()) {
        cout << "No se encontraron ventas para el mes " << mes << endl;
    } else {
        cout << "Total ingresado en el mes " << mes << ": $" << totalIngresado << endl;
        cout << "Cantidad total de productos vendidos en el mes: " << cantidadTotal << endl;

        string productoMasVendido, productoMenosVendido;
        encontrarProductoMasYMenosVendido(productosVendidos, productoMasVendido, productoMenosVendido);

        cout << "Producto más vendido en el mes: " << productoMasVendido << endl;
        cout << "Producto menos vendido en el mes: " << productoMenosVendido << endl;
    }
}

// Reporte de ventas por año
void reporteVentasPorAnio(const vector<Venta>& ventas, const string& anio) {
    double totalIngresado = 0.0;
    int cantidadTotal = 0;
    unordered_map<string, int> productosVendidos;

    for (const Venta& venta : ventas) {
        if (venta.fecha.substr(0, 4) == anio) {
            totalIngresado += venta.total;
            cantidadTotal += venta.cantidad;
            productosVendidos[venta.producto] += venta.cantidad;
        }
    }

    if (productosVendidos.empty()) {
        cout << "No se encontraron ventas para el año " << anio << endl;
    } else {
        cout << "Total ingresado en el año " << anio << ": $" << totalIngresado << endl;
        cout << "Cantidad total de productos vendidos en el año: " << cantidadTotal << endl;

        string productoMasVendido, productoMenosVendido;
        encontrarProductoMasYMenosVendido(productosVendidos, productoMasVendido, productoMenosVendido);

        cout << "Producto más vendido en el año: " << productoMasVendido << endl;
        cout << "Producto menos vendido en el año: " << productoMenosVendido << endl;
    }
}
// Menú principal
void Menureporte() {
    vector<Venta> ventas = cargarVentas();
    int opcion;
    string fecha, mes, anio;

    do {
        cout << "\nMenu de reportes:" << endl;
        cout << "1. Reporte de ventas por dia" << endl;
        cout << "2. Reporte de ventas por mes" << endl;
        cout << "3. Reporte de ventas por anio" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

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
                cout << "Ingrese el año (YYYY): ";
                cin >> anio;
                reporteVentasPorAnio(ventas, anio);
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);
}
