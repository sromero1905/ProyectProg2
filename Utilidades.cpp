#include "Utilidades.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <limits>

bool leerArchivo(const std::string &nombreArchivo, std::vector<std::string> &contenido) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) return false;

    std::string linea;
    while (std::getline(archivo, linea)) {
        contenido.push_back(linea);
    }
    archivo.close();
    return true;
}

void escribirArchivo(const std::string &nombreArchivo, const std::vector<std::string> &contenido) {
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (const auto &linea : contenido) {
            archivo << linea << std::endl;
        }
        archivo.close();
    }
}

// Validación de entrada numérica
bool validarEntrada(int &entrada) {
    while (!(std::cin >> entrada)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada inválida. Ingrese un número entero: ";
        return false;
    }
    return true;
}

// Validación de texto (evita caracteres especiales)
bool validarEntradaTexto(std::string &entrada) {
    for (char c : entrada) {
        if (!isalnum(c) && c != ' ') {
            std::cout << "Texto inválido. Ingrese solo letras y números." << std::endl;
            return false;
        }
    }
    return true;
}

// Alinear texto para visualización en consola
std::string alinearTexto(const std::string &texto, int anchura) {
    std::stringstream ss;
    ss << std::left << std::setw(anchura) << texto;
    return ss.str();
}

// Formatear decimales para precios
std::string formatearDecimal(double numero, int decimales) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(decimales) << numero;
    return out.str();
}
