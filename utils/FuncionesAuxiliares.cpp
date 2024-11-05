#include "FuncionesAuxiliares.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

// Funci�n para leer un archivo y almacenar su contenido en un vector
bool leerArchivo(const std::string &nombreArchivo, std::vector<std::string> &contenido) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo para lectura." << std::endl;
        return false;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        contenido.push_back(linea);
    }
    archivo.close();
    return true;
}

// Funci�n para escribir un vector en un archivo
bool escribirArchivo(const std::string &nombreArchivo, const std::vector<std::string> &contenido) {
    std::ofstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return false;
    }

    for (const auto &linea : contenido) {
        archivo << linea << std::endl;
    }
    archivo.close();
    return true;
}

// Funci�n para validar que la entrada del usuario sea un n�mero entero
bool validarEntrada(int &entrada) {
    std::cout << "Ingrese un n�mero entero: ";
    while (!(std::cin >> entrada)) {
        std::cout << "Entrada no v�lida. Intente de nuevo: ";
        std::cin.clear(); // Limpiar el estado de error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar entrada err�nea
    }
    return true;
}

// Funci�n para formatear datos para la salida
std::string formatearDatos(const std::string &dato) {
    std::ostringstream ss;
    ss << std::setw(20) << std::left << dato; // Alineaci�n a la izquierda
    return ss.str();
}
