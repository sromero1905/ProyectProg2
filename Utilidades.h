#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <string>
#include <vector>

struct Producto {
    std::string nombre;
    int cantidadDisponible;
    double precio;
    bool enPromocion;
    double descuento; // Porcentaje de descuento (por ejemplo, 0.10 para un 10%)
};

// Funciones de manejo de archivos
bool leerArchivo(const std::string &nombreArchivo, std::vector<std::string> &contenido);
void escribirArchivo(const std::string &nombreArchivo, const std::vector<std::string> &contenido);

// Validación de entradas
bool validarEntrada(int &entrada);
bool validarEntradaTexto(std::string &entrada);

// Formateo de datos
std::string alinearTexto(const std::string &texto, int anchura);
std::string formatearDecimal(double numero, int decimales);

#endif // UTILIDADES_H

