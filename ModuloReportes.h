#ifndef MODULOREPORTES_H
#define MODULOREPORTES_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Clase Venta
class Venta {
public:
    string fecha;
    string producto;
    int cantidad;
    double precioUnitario;
    double total;

    Venta(string f, string p, int c, double pu, double t)
        : fecha(f), producto(p), cantidad(c), precioUnitario(pu), total(t) {}
};

// Funciones para cargar ventas y generar reportes
vector<Venta> cargarVentas();
void encontrarProductoMasYMenosVendido(const unordered_map<string, int>& productosVendidos, string& productoMasVendido, string& productoMenosVendido);

// Funciones de reporte
void reporteVentasPorDia(const vector<Venta>& ventas, const string& fecha);
void reporteVentasPorMes(const vector<Venta>& ventas, const string& mes);
void reporteVentasPorAnio(const vector<Venta>& ventas, const string& anio);
void Menureporte();

#endif // MODULOREPORTES_H
