// ModuloReportes.h
#ifndef MODULOREPORTES_H
#define MODULOREPORTES_H

#include <string>
#include <vector>

using namespace std;

// Declaración de la clase Venta
class Venta {
public:
    string fecha;
    string nombreCliente;
    string producto;
    int cantidad;
    double precioUnitario;
    double total;

    // Constructor de la clase Venta
    Venta(string f, string nc, string p, int c, double pu, double t);
};

// Declaraciones de funciones para los reportes
vector<Venta> cargarVentas(const string& nombreArchivo);
void menuReportes(const vector<Venta>& ventas);
void reporteVentasPorDia(const vector<Venta>& ventas, const string& fecha);
void reporteVentasPorMes(const vector<Venta>& ventas, const string& mes);
void reporteVentasPorAnio(const vector<Venta>& ventas, const string& anio);
void reporteVentasPorCategoria(const vector<Venta>& ventas, const string& categoria);
void reporteVentasPorProducto(const vector<Venta>& ventas, const string& producto);

#endif // MODULOREPORTES_H
