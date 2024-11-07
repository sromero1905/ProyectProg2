#ifndef FUNCIONES_AUXILIARES_H
#define FUNCIONES_AUXILIARES_H

#include <string>
#include <vector>

bool leerArchivo(const std::string &nombreArchivo, std::vector<std::string> &contenido);
bool escribirArchivo(const std::string &nombreArchivo, const std::vector<std::string> &contenido);
bool validarEntrada(int &entrada);
std::string formatearDatos(const std::string &dato);

#endif // FUNCIONES_AUXILIARES_H
